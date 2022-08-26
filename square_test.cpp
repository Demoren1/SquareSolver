#include "square_functions_and_constants.h"

void error_in_test(int num, struct Result* const test_solution, struct Result* const roots);

void test_square_equation()
{
    FILE* file_square_tests = fopen("input_test.txt", "a+");
    int quantity_of_tests = 0, success_tests = 0;

    fscanf(file_square_tests, "%d", &quantity_of_tests);

    for (int num_of_test = 0; num_of_test < quantity_of_tests; num_of_test++ )
    {
        double x1 = 0, x2 = 0, a = 0, b = 0, c = 0;
        int n_roots = 0;

        struct Param test_parameters = {0, 0, 0};
        struct Result test_roots     = {0, 0, 0};
        struct Result test_solution  = {0, 0, 0};

        if (fscanf(file_square_tests, "%lf %lf %lf  %lf  %lf        %d",
                                        &a, &b, &c, &x1, &x2, &n_roots) != 6)
        {
            printf("Fatal error in tests numbers\n");
            INF_ABOUT_ERROR();
            break;
        }

        test_parameters = {a, b, c};
        test_roots      = {x1, x2, n_roots};

        solve_square_equation(&test_parameters, &test_solution);

        if (test_solution.n_roots == test_roots.n_roots     &&
            is_zero(test_solution.root1 - test_roots.root1) &&
            is_zero (test_solution.root2 - test_roots.root2))
        {
            ++success_tests;
        }
        else
        {
            INF_ABOUT_ERROR()
            error_in_test (num_of_test, &test_solution, &test_roots);

        }
    }

    printf ("\n%d success of %d tests\n\n", success_tests, quantity_of_tests);

    fclose (file_square_tests);
    getchar();
}

void error_in_test(int num, struct Result* test_solution, struct Result* test_roots)
{
    printf("Error in %d test\n", num);
    printf("Gotten   x1 = %lg, x2 = %lg, n_roots = %d\n", test_solution->root1,
            test_solution->root2, test_solution->n_roots);
    printf("Expected x1 = %lg, x2 = %lg, n_roots = %d\n", test_roots->root1,
            test_roots->root2, test_roots->n_roots);

}

void passed_test(int num)
{
    printf("%d test passed\n", num);
}
