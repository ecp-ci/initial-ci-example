# int n         = Number of Temperature Samples
# double uk1[n] = New Temperatures Across x-Axis
# double uk0[n] = Old Temperatures Across x-Axis
# double alpha  = Thermal Diffusity
# double dx     = Spacing in Space
# double dt     = Spacing in Time
# double bc0    = Beginning Boundary Condition (x = 0)
# double bc1    = Ending Boundary Condition (x = L_x)

function update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1)
    r = alpha * dt / (dx ^ 2)
    
    # Sanity Check for Stability
    if r > 0.5
        return false
    end
    
    # FTCS Update Algorithm
    for i = 2:n-1
        uk1[i] = r*uk0[i+1] + (1-2*r)*uk0[i] + r*uk0[i-1] 
    end
    
    #Enforce Boundary Conditions
    uk1[1] = bc0
    uk1[n] = bc1
    return true
end

function main()
    if length(ARGS) < 8
        println("Error. Incorrect Execution Format. Please Execute As: \n")
        println("----------------------------------------------------- \n")
        println("./<exec> <# Time Iterations> <# Temp Samples> <Thermal Diffusity> <Spacing in Space>\\ \n")
        println("<Spacing in Time> <Beginning Boundary Condition> <Init. Temp. (Constant Throughout)> <End Boundary Condition> \n");
        exit(1)
    end
    
    iter  = parse(Int64,   ARGS[1])
    n     = parse(Int64,   ARGS[2])
    alpha = parse(Float64, ARGS[3])
    dx    = parse(Float64, ARGS[4])
    dt    = parse(Float64, ARGS[5])
    bc0   = parse(Float64, ARGS[6])
    ic    = parse(Float64, ARGS[7])
    bc1   = parse(Float64, ARGS[8])
    
    uk1 = zeros(Float64, n)
    uk0 = zeros(Float64, n)
    
    # Initialize temp distribution array
    uk0[1] = bc0
    uk0[n] = bc1
    for i in 2:n-1
        uk0[i] = ic
    end
    
    # For the number of time iterations provided, calculate temperature distribution
    # and print results
    for i in 1:iter
        if update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1)
            print(i + ":\t")
            for j in 1:n
                print(uk1[j], " ")
            end
                println("")
        else
            println("Error. r > 0.5\n")
            exit(1)
        end
    end
    
end

main()
