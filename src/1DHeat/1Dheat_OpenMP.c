#include <stdio.h>
#include <stdlib.h>

/* ---------------------------------------------------
int n         = Number of Temperature Samples
double uk1[n] = New Temperatures Across x-Axis
double uk0[n] = Old Temperatures Across x-Axis
double alpha  = Thermal Diffusity
double dx     = Spacing in Space
double dt     = Spacing in Time
double bc0    = Beginning Boundary Condition (x = 0)
double bc1    = Ending Boundary Condition (x = L_x)
---------------------------------------------------- */
int update_solution_ftcs(int n, double *uk1, const double *uk0, double alpha, double dx, double dt, double bc0, double bc1){
    double r = alpha * dt / (dx * dx);

    // Sanity check for stability
    if (r > 0.5) return 0;

    //FTCS update algorithm
    #pragma omp parallel num_threads(n-2) private(tid) shared(uk1, uk0, r){
        int i = omp_get_thread_num();    // Thread numbers will range from 0 to n-3
        uk1[i+1] = r*uk0[i+2] + (1-2*r)*uk0[i+1] + r*uk0[i];
     }

    // Enforce boundary conditions
    uk1[0] = bc0;
    uk1[n-1] = bc1;

    return 1;
}

int main(int argc, char** argv){
	
	if(argc < 9){
		printf("Error. Incorrect Execution Format. Please Execute As: \n");
		printf("----------------------------------------------------- \n");
		printf("./<exec> <# Time Iterations> <# Temp Samples> <Thermal Diffusity> <Spacing in Space> \\ \n");
		printf("<Spacing in Time> <Beginning Boundary Condition> <Init. Temp. (Constant Throughout)> <End Boundary Condition> \n");
		exit(1);
	}

	int iter = atoi(argv[1]);
	int n = atoi(argv[2]);
	double alpha = atof(argv[3]);
	double dx = atof(argv[4]);
	double dt = atof(argv[5]);
	double bc0 = atof(argv[6]);
	double ic = atof(argv[7]);
	double bc1 = atof(argv[8]);

	int i;
	int j;

	double uk1[n];
	double uk0[n];
	
	//Initalize temp distribution array
	uk0[0] = bc0;
	uk0[n-1] = bc1;
	for(i = 1; i < n-1; ++i)
		uk0[i] = ic;

	// For the number of time iterations provided, calculate temperature distribution
	// and print results
	for(i = 0; i < iter; ++i){
		if(update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1)){
			printf("%i:\t  ", i+1);
			for(j = 0; j < n; ++j){
				printf("%0.4f ", uk1[j]);
				uk0[j] = uk1[j];
			}
			printf("\n");
		}else{
			printf("Error. r > 0.5\n");
			exit(1);
		}
	}

return 0;
}
