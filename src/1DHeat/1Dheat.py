import sys
# ---------------------------------------------------
# int n         = Number of Temperature Samples
# double uk1[n] = New Temperatures Across x-Axis
# double uk0[n] = Old Temperatures Across x-Axis
# double alpha  = Thermal Diffusity
# double dx     = Spacing in Space
# double dt     = Spacing in Time
# double bc0    = Beginning Boundary Condition (x = 0)
# double bc1    = Ending Boundary Condition (x = L_x)
# ---------------------------------------------------- 


def update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1):
    r = alpha * dt / (dx ** 2);

    # Sanity check for stability
    if (r > 0.5): 
	return False

    # FTCS update algorithm
    for i in range(1, n-1):
        uk1[i] = r*uk0[i+1] + (1-2*r)*uk0[i] + r*uk0[i-1]

    # Enforce boundary conditions
    uk1[0] = bc0
    uk1[n-1] = bc1

    return True


def main():	
	if(len(sys.argv) < 9):
		print("Error. Incorrect Execution Format. Please Execute As:")
		print("-----------------------------------------------------")
		print("./<exec> <# Time Iterations> <# Temp Samples> <Thermal Diffusity> <Spacing in Space>\\")
		print("<Spacing in Time> <Beginning Boundary Condition> <Init. Temp. (Constant Throughout)> <End Boundary Condition>")
		exit(1)

	iterations = int(sys.argv[1])
	n = int(sys.argv[2])
	alpha = float(sys.argv[3])
	dx = float(sys.argv[4])
	dt = float(sys.argv[5])
	bc0 = float(sys.argv[6])
	ic = float(sys.argv[7])
	bc1 = float(sys.argv[8])

	uk1 = [None] * n
	uk0 = [None] * n
	
	# Initalize temp distribution array
	uk0[0] = bc0;
	uk0[n-1] = bc1;
	for i in range(1, n-1):
		uk0[i] = ic

	# For the number of time iterations provided, calculate temperature distribution
	# and print results
	for i in range(0, iterations):
		if(update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1)):
			print str(i+1) + ":\t  ",
			for j in range(0, n):
				print "{0:.4f}".format(uk1[j]) + " ", 
				uk0[j] = uk1[j]
			
			print("")
		else:
			print("Error. r > 0.5")
			exit(1)
	

if __name__ == "__main__":
	main()
