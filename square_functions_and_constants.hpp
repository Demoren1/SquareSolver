#include <stdio.h>
#include <math.h>
#include <cmath>   // for isfinite
#include <float.h>
#include <assert.h>
#include <stdbool.h>
const char END_INPUT = 'q';

char get_number(double* x);

/**
 * @file
 * @brief
 */
/**
 solve linear equation
 *\param[in] b    - coefficient of equation ax^2 + bx + c = 0
 *\param[in] c    - coefficient of equation ax^2 + bx + c = 0
 *\param[out] sol - 2 roots and quantity of roots
 *\return
 *\note
 */
void solve_linear_equation(const double b, const double c, struct Result* sol);

/*!
Solve square equation
\param[in] parameters  -- struct with parameters for ax^2 + bx + c = 0
\param[out] roots      -- struct with 2 roots, and quantity of roots
*/
void solve_square_equation(const struct Param*const parameters, struct Result*const roots);

/**
clear buff from trash
 */
void clear_of_buff (void);

/**
accept, handle and assign number to coefficients a, b, c
*\param[out] parameters -- struct with parameters
*\return symbol of exit if user input 'q', else 0
*/
char input_parameters (struct Param* parameters);

/**
print invite and information about exit
*/
void invite_to_input (void);

/**
choose right version of answer
*\param[in] roots -- struct with 2 roots and quantity of roots
*/
void output(struct Result* solution);

/**
compare the number module with epsilon
*\param[in] u -- number for comparing
*\return boolean true if number are comparing with zero, else return false
*/
int is_zero(const double u);

/**
print menu with variants of functions of program
*\param[out] choice -- return user choice
*/
void menu(int* choice);

/**
code, what testing solution of square equation
*/
void test_square_equation();

void test_linear_equation();

void test_is_zero();

/**
suggestion for exit
*\return boolean true if user want to exit, else return false
*/
int want_to_exit(char exit_test);

/**
function with basic code for solving square equation
*/
void solver_of_square_eq();
#define INF_ABOUT_ERROR()                                                  \
            printf("Wrong result in %d line, %s path, %s function \n",   \
                   __LINE__, __FILE__, __PRETTY_FUNCTION__);

enum quantity_of_roots
{
    ZERO_ROOT = 0, ///< Indicates on absence of roots
    ONE_ROOT  = 1, ///< Indicates on presence of one root
    TWO_ROOTS = 2, ///< Indicates on presence of two root
    INF_ROOTS = 3  ///< Indicates on presence of infinity root
};

enum menu_varieties
{
    SOLVE_SQUARE_EQUATION = 1, ///< Indicate, what user want to solve square equation
    TEST_SQUARE_EQUATION  = 2, ///< Indicate, what user want to test a square equation solver
    TEST_LINEAR_EQUATION  = 3, ///< Indicate, what user want to test a linear equation solver
    TEST_IS_ZERO   = 4, ///< Indicate, what user want to test comparing with zero
    EXIT                  = 5  ///< Indicate, what user want to  exit from program
};

/**
Contain parameters for square equation
*/
struct Param
{   double a; ///< parameter a for equation ax^2 + bx +c = 0
    double b; ///< parameter b for equation ax^2 + bx +c = 0
    double c; ///< parameter c for equation ax^2 + bx +c = 0
};

/**
Contain roots and quantity of roots
*/
struct Result
{
    double root1; ///< first root of equation ax^2 + bx +c = 0
    double root2; ///< second root of equation ax^2 + bx +c = 0
    int n_roots;  ///< quantity of roots of equation ax^2 + bx +c = 0
};

void input_tests(struct Param* input_t, int number_of_test);
void output_tests(struct Result* output_t, int number_of_test);

