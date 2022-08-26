#include <stdio.h>
#include <math.h>
#include <cmath>   // for isfinite
#include <float.h>
#include <assert.h>
#include "square_functions_and_constants.hpp"

void solver_of_square_eq()
{
    struct Result solution  = {0, 0, -1};
    struct Param parameters = {0, 0,  0};
    bool is_ran_solver_eq   = true;

    while (is_ran_solver_eq)
    {
        invite_to_input();
        if (input_parameters(&parameters) == END_INPUT)
        {
            is_ran_solver_eq = false;
            break;
        }
        solve_square_equation(&parameters ,&solution);
        output(&solution);
    }
}
