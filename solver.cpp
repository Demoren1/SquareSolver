#include "square_functions_and_constants.hpp"
void solve_linear_equation(const double b, const double c, struct Result* solution)
{
    assert (solution != NULL);
    assert (std::isfinite(b));
    assert (std::isfinite(c));

    if (is_zero(b))
    {
        solution->n_roots = (is_zero(c)) ? INF_ROOTS : ZERO_ROOT;
    }
    else
    {
        solution->root1 = (-c) / b;
        solution->n_roots = ONE_ROOT;
    }
}

void solve_square_equation(const struct Param* const parameters, struct Result* const  solution)
{
    assert (parameters != NULL);
    assert (solution   != NULL);
    assert (std::isfinite(parameters->a));
    assert (std::isfinite(parameters->b));
    assert (std::isfinite(parameters->c));

    double D = 0, sqrt_D = 0;
    double double_a = 2*parameters->a;

    if (is_zero(parameters->a))
    {
        solve_linear_equation(parameters->b, parameters->c, solution);
    }
    else
    {
        D = parameters->b * parameters->b - 4 * parameters->a * parameters->c;

        if (D > 0)
        {
            sqrt_D = sqrt(D);
            solution->root1 = (-parameters->b - sqrt_D) / double_a;
            solution->root2 = (-parameters->b + sqrt_D) / double_a;
            solution->n_roots = 2;
        }
        else if (is_zero(D))
        {
            solution->root1 = (-parameters->b) / double_a;
            solution->n_roots = 1;
        }
        else
        {
            solution->n_roots = ZERO_ROOT;
        }
    }
}
int is_zero(const double number)
{
    return (fabs(number) <= FLT_EPSILON);
}


