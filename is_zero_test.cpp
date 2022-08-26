<<<<<<< HEAD
#include "square_functions_and_constants.h"

void test_is_zero()
{
    FILE* file_is_zero_test = fopen ("is_zero_test.txt", "a+");

    int quantity_of_tests = 0, num_of_test = 0, test_ans   =  0, answer = 0, passed_test = 0;
    double number = 0;

    fscanf(file_is_zero_test, "%d", &quantity_of_tests);

    for (num_of_test = 0; num_of_test < quantity_of_tests ; num_of_test++)
    {
        number = 0, answer = 0, test_ans = 0;

        fscanf(file_is_zero_test, "%lf %d", &number, &answer);

        test_ans = is_zero(number);

        if (answer != test_ans)
        {
            INF_ABOUT_ERROR();
            printf("Problem in %d test\n Gotten %d\n Expected %d\n", num_of_test + 1,
                    test_ans, answer);
        }
        else
        {
            passed_test++;
        }
    }

    fclose(file_is_zero_test);

    printf("\n %d success of %d tests\n\n", passed_test, quantity_of_tests);
    getchar();
}
=======
#include "square_functions_and_constants.hpp"

void test_is_zero()
{
    FILE* file_is_zero_test = fopen("is_zero_test.txt", "a+");
    int quantity_of_tests = 0, num_of_test = 1;
    double number = 0;
    int   test   =  0, answer = 0, passed_test = 0;
    fscanf(file_is_zero_test, "%d", &quantity_of_tests);

    for (num_of_test = 0; num_of_test < quantity_of_tests ; num_of_test++)
    {
        number = 0, answer = 0, test = 0;

        fscanf(file_is_zero_test, "%lf %d", &number, &answer);

        test = is_zero(number);

        if (answer != test)
        {
            INF_ABOUT_ERROR();
            printf("Problem in %d test\n Gotten %d\n Expected %d\n", num_of_test + 1,
                    test, answer);
        }
        else
        {
            passed_test++;
        }
    }

    fclose(file_is_zero_test);

    printf("\n %d success of %d tests\n\n", passed_test, quantity_of_tests);
    getchar();
}
>>>>>>> b8080c2fcdfd336f9aa1de950307ef42ef947de9
