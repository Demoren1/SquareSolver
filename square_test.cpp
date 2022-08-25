#include <stdio.h>
#include <math.h>
#include <cmath>   // for isfinite
#include <float.h>
#include <assert.h>
#include "square_functions_and_constants.hpp"
#define QUANTITY_OF_TESTS  10
void error_test(int num);
void passed_test(int num);
void input_tests(struct Param* input_t, int number_of_test);
void output_tests(struct Result* output_t, int number_of_test);

void test_square_equation()
{
    FILE* file_input_tests;
    FILE* file_output_tests;
    file_input_tests  = fopen("input_test.txt", "a+");
    file_output_tests = fopen("output_test.txt", "a+");

    for (int passed_tests = 0; passed_tests < 7; )
    {
        double x1 = 0, x2 = 0, a = 0, b = 0, c = 0;
        int n_roots = 0;

        struct Param test_parameters = {0, 0, 0};
        struct Result test_roots     = {0, 0, 0};
        struct Result test_solution  = {0, 0, 0};

        //input_tests (&test_parameters, passed_tests);
        //output_tests(&test_roots,     passed_tests);

        fscanf(file_input_tests, "%lf %lf %lf", &a, &b, &c);
        fscanf(file_output_tests, "%lf %lf %d", &x1, &x2, &n_roots);

        printf("%f, %f, %f \n", a, b, c);

        test_parameters = {a, b, c};
        test_roots      = {x1, x2, n_roots};

        solve_square_equation(&test_parameters, &test_solution);

        if (test_solution.n_roots == test_roots.n_roots     &&
            is_zero(test_solution.root1 - test_roots.root1) &&
            is_zero (test_solution.root2 - test_roots.root2))
        {
            passed_test(++passed_tests);
        }
        else
        {
            INF_ABOUT_ERROR
            error_test(++passed_tests);
            printf("Gotten x1 = %lg, x2 =%lg, n_roots = %d", test_solution.root1,
                   test_solution.root2, test_solution,n_roots);

        }
    }
    fclose(file_input_tests);
    fclose(file_output_tests);
    getchar();
}

void input_tests(struct Param* input_t, int number_of_test)
{
    struct Param test_parameters[QUANTITY_OF_TESTS];

    test_parameters[0] = {1,    0,    -4};
    test_parameters[1] = {1,  -12,    35};
    test_parameters[2] = {1, -0.9,  0.18};
    test_parameters[3] = {0,    0,     0};
    test_parameters[4] = {0,    0,     1};
    test_parameters[5] = {0,  0.3,  0.15};
    test_parameters[6] = {2,  -25,   12};

    *(input_t) = test_parameters[number_of_test];
}

void output_tests(struct Result* output_t, int number_of_test)
{
    struct Result test_output[QUANTITY_OF_TESTS];  //!

    test_output[0] = {   -2,   2,  2};
    test_output[1] = {    5,   7,  2};
    test_output[2] = {  0.3, 0.6,  2};
    test_output[3] = {    0,   0,  3};
    test_output[4] = {    0,   0,  0};
    test_output[5] = { -0.5,   0,  1};
    test_output[6] = {  0.5,  12,  2};


    *(output_t) = test_output[number_of_test];
}




void error_test(int num)
{
    printf("Error in %d test\n", num);
}

void passed_test(int num)
{
    printf("%d test passed\n", num);
}
