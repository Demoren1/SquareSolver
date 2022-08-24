#include <stdio.h>
#include <math.h>
#include <cmath>   // for isfinite
#include <float.h>
#include <assert.h>
#include "square_functions_and_constants.hpp"
void solve_linnar_equation(double b, double c, struct Result* sol)
{
    assert (sol != NULL);
    assert (std::isfinite(b));
    assert (std::isfinite(c));

    if (is_zero(b))
    {
        sol->n_roots = (is_zero(c)) ? INF_ROOTS : ZERO_ROOT;
    }
    else
    {
        sol->root1 = (-c) / b;
        sol->n_roots = 1;
    }
}

void solve_square_equation(struct Param* par, struct Result* sol)
{
    assert (par != NULL);
    assert (sol != NULL);
    assert (std::isfinite(par->a));
    assert (std::isfinite(par->b));
    assert (std::isfinite(par->c));

    double a = par->a, b = par->b, c = par->c;
    double D = 0, sqrt_D = 0;
    double double_a = 2*a;

    if (is_zero(a))
    {
        solve_linnar_equation(b, c, sol);
    }
    else
    {
        D = b * b - 4 * a * c;

        if (D > 0)
        {
            sqrt_D = sqrt(D);
            sol->root1 = (-b - sqrt_D) / double_a;
            sol->root2 = (-b + sqrt_D) / double_a;
            sol->n_roots = 2;
        }
        else if (is_zero(D))
        {
            sol->root1 = (-b) / double_a;
            sol->n_roots = 1;
        }
        else
        {
            sol->n_roots = 0;
        }
    }
}
int is_zero(double u)
{
    return (fabs(u) <= FLT_EPSILON);
}


