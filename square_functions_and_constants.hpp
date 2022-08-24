const char END_INPUT = 'q';

char get_number(double* x);
void solve_linnar_equation(double b, double c, struct Result*);
void solve_square_equation(struct Param*, struct Result*);
void clear_of_buff (void);
char input_parameters (struct Param*);
void invite_to_input (void);
void output(struct Result);
int is_zero(double u);
void menu(double* choice);
void test_square_equation();
#define INF_ABOUT_ERROR                                                  \
            printf("Wrong result in %d line, %s path, %s function \n",   \
                   __LINE__, __FILE__, __PRETTY_FUNCTION__);


enum quantity_of_roots
{
    ZERO_ROOT,
    ONE_ROOT,
    TWO_ROOTS,
    INF_ROOTS
};
enum menu_varieties
{
    SOLVE_SQUARE_EQUATION = 1,
    TEST_SQUARE_EQUATION  = 2,
    EXIT                  = 3
};

struct Param
{   double a;
    double b;
    double c;
};

struct Result
{
    double root1;
    double root2;
    int n_roots;
};
