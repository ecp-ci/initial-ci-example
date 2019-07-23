#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

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


bool update_solution_ftcs(int n, double *uk1, const double *uk0, double alpha, double dx, double dt, double bc0, double bc1){
    double r = alpha * dt / (dx * dx);

    // Sanity check for stability
    if (r > 0.5) return false;

    //FTCS update algorithm
    for(int i = 1; i < n-1; ++i)
        uk1[i] = r*uk0[i+1] + (1-2*r)*uk0[i] + r*uk0[i-1];

    // Enforce boundary conditions
    uk1[0] = bc0;
    uk1[n-1] = bc1;

    return true;
}

int main(int argc, char* argv[]){

        if(argc < 9){
                cout << "Error. Incorrect Execution Format. Please Execute As: \n";
                cout << "----------------------------------------------------- \n";
                cout << "./<exec> <# Time Iterations> <# Temp Samples> <Thermal Diffusity> <Spacing in Space> \\ \n";
                cout << "<Spacing in Time> <Beginning Boundary Condition> <Init. Temp. (Constant Throughout)> <End Boundary Condition> \n";
                exit(1);
        }

        int iter = stoi(argv[1]);
        int n = stoi(argv[2]);
        double alpha = stod(argv[3]);
        double dx = stod(argv[4]);
        double dt = stod(argv[5]);
        double bc0 = stod(argv[6]);
        double ic = stod(argv[7]);
        double bc1 = stod(argv[8]);

        double uk1[n];
        double uk0[n];

        //Initalize temp distribution array
        uk0[0] = bc0;
        uk0[n-1] = bc1;
        for(int i = 1; i < n-1; ++i)
                uk0[i] = ic;

        // For the number of time iterations provided, calculate temperature distribution
        // and print results
        cout << fixed;
        cout << setprecision(4);
        for(int i = 0; i < iter; ++i){
                if(update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1)){
                        cout << i+1 << ":\t  ";
                        for(int j = 0; j < n; ++j){
                                cout << uk1[j] << " ";
                                uk0[j] = uk1[j];
                        }
                        cout << endl;
                }else{
                        cout << "Error. r > 0.5" << endl;
                        exit(1);
                }
        }

return 0;
}
