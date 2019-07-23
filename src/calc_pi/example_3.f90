function calc_pi(num_intervals) result(pi)
    integer, intent(in) :: num_intervals
    real                :: pi, h, sum_pi, x

    h = 1.0 / real(num_intervals)
    sum_pi = 0.0

    do i=0,num_intervals-1
        x = h * (real(i) + 0.5)
        sum_pi = sum_pi + (4.0 / (1.0 + x*x))
    end do

    pi = h * sum_pi

end function calc_pi

program calculate_pi
    real :: PI_REF, pi, error
    integer :: num_intervals
    character(100) :: num_ints

    PI_REF = 3.141592653589793238462643

    IF(COMMAND_ARGUMENT_COUNT().NE.1)THEN
        WRITE(*,*)'ERROR, ONE COMMAND-LINE ARGUMENTS REQUIRED, STOPPING'
        STOP
    ENDIF

    CALL GET_COMMAND_ARGUMENT(1, num_ints)
    READ(num_ints,*)num_intervals

    PRINT '(1X, A, I2, A, 1X)', 'calculating pi using ', num_intervals, ' intervals'

    pi = calc_pi(num_intervals)
    error = ABS(pi - PI_REF)

    PRINT '(1X, A, F17.15, A, F17.15)', "pi is approximately ", pi, ", Error is ", error
end program calculate_pi
