#include <stdio.h>
#include <float.h>
#include <assert.h>
#include <stdbool.h>
//!@file
const char END_INPUT = 'q';
/**
assign some number to number, check the buff on not number symbols
*\param [out] num -- assigned number
*\return -- symbol of exit 'q', else 0
*/
char get_number (double* const num);

/**
 solve linear equation
 *\param [in] b    - coefficient of equation ax^2 + bx + c = 0
 *\param [in] c    - coefficient of equation ax^2 + bx + c = 0
 *\param [out] solution - 2 roots and quantity of roots
 */
void solve_linear_equation (const double b, const double c, struct Result* const solution);

/*!
Solve square equation
\param [in] parameters  -- struct with parameters for ax^2 + bx + c = 0
\param [out] solution   -- struct with 2 roots, and quantity of roots
*/
void solve_square_equation (const struct Param* const parameters, struct Result* const solution);

/**
clear buff from trash
 */
void clear_of_buff (void);

/**
accept, handle and assign number to coefficients a, b, c
*\param [out] parameters -- struct with parameters
*\return symbol of exit if user input 'q', else 0
*/
char input_parameters (struct Param* const parameters);

/**
print invite and information about exit
*/
void invite_to_input (void);

/**
choose right version of answer
*\param [in] roots -- struct with 2 roots and quantity of roots
*/
void output (struct Result* const solution);

/**
compare the number module with epsilon
*\param [in] num -- number for comparing
*\return boolean true if number are comparing with zero, else return false
*/
int is_zero(const double num);

/**
print menu with variants of functions of program
*\param [out] choice -- return user choice
*/
void menu (int* const choice);

/**
testing solution of square equation with data from txt file
*/
void test_square_equation();

/**
testing solution of linear equation with data from txt file
*/
void test_linear_equation();

/**
testing comparing with zero with data from txt file
*/
void test_is_zero();

/**
suggestion for exit
* \param [in] exit_test-- symbol for comparing with exit symbol 'q'
*\return boolean true if user want to exit, else return false
*/
int want_to_exit (char exit_test);

/**
function with basic code for solving square equation
*/
void solver_of_square_eq();

/**
Message about error, point line, path and function where error happen
*/
#define INF_ABOUT_ERROR()                                                  \
            printf("Wrong result in %d line, %s path, %s function \n",   \
                   __LINE__, __FILE__, __PRETTY_FUNCTION__);

/// for comfortable work with roots
enum quantity_of_roots
{
    ZERO_ROOT = 0, ///< Indicates on absence of roots
    ONE_ROOT  = 1, ///< Indicates on presence of one root
    TWO_ROOTS = 2, ///< Indicates on presence of two root
    INF_ROOTS = 3  ///< Indicates on presence of infinity root
};

///for convenient work with user choice
enum menu_varieties
{
    SOLVE_SQUARE_EQUATION = 1, ///< Indicate, what user want to solve square equation
    TEST_SQUARE_EQUATION  = 2, ///< Indicate, what user want to test a square equation solver
    TEST_LINEAR_EQUATION  = 3, ///< Indicate, what user want to test a linear equation solver
    TEST_IS_ZERO          = 4, ///< Indicate, what user want to test comparing with zero
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

