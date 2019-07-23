function 1Dheat(iter, n, alpha, dx, dt, bc0, ic, bc1)
    % Initialize temp distribution array
    uk0 = zeros(1, n);
    uk1 = zeros(1, n);
    
    uk0(1) = bc0;
    uk0(n) = bc1;
    for i = 2:n-1
        uk0(i) = ic;
    end
    
    % For the # of time iterations provided, calculate temperature
    % distribution and print results.
    for i = 1:iter
        uk1 = update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1);
        if(isnan(uk1(1)))
            disp('Error. r > 0.5')
            return
        else
            fprintf("%i: \t", i)
            disp(uk1)
            uk0(i) = uk1(i);
        end
    end
    
end

function uk1 = update_solution_ftcs(n, uk1, uk0, alpha, dx, dt, bc0, bc1)
    r = alpha * dt/dx^2;

    % Sanity check for stability
    if r > 0.5
        uk1(1) = nan;
        return
    end

    % FTCS update algorithm
    for i = 2:n-1
        uk1(i) = r*uk0(i+1) + (1-2*r)*uk0(i) + r*uk0(i-1);
    end

    % Enforce boundary conditions
    uk1(1) = bc0;
    uk1(n) = bc1;
end
