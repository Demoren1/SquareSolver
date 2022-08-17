#include <stdio.h>
#include <math.h>

double test_num(void);      //check number on integrity, if int - return
int main(void)
{
    char exit = 'A';
    double x1 = 0, x2 = 0, a = 0, b = 0, c = 0, D = 0;

    printf("Input coefficients for equation a*x^2+b*x+c=0 \n");

    printf("a=");
    a = test_num();
    printf("b=");
    b = test_num();
    printf("c=");
    c = test_num();

    while ( 1 )
    {
            if (a == 0 && b == 0)
                printf("%s", (c == 0) ? "x belong R" : "x belong empty set");
            else if (a == 0)
            {                                                                  //IF equation isn't square
                    x1 = x2 = (-c) / b;
                    printf("This is not square equation, the root is %.3f\n", x1);
            }                                                                  //IF equation is square
            else
            {
                D = b * b - 4 * a * c;

                if (D > 0)
                {                                                               //if discriminate > 0
                    D = pow(D, 0.5);
                    x1 = (-b -D) / (2 * a);
                    x2 = (-b + D)/(2 * a);

                    printf ("The roots of equation are %.3f and %.3f\n", x1, x2);
                }
                else if (D == 0)
                {                                                               //if discriminate == 0
                        x1 = x2 =  (-b) / (2 * a);

                        printf("The root of equation is %.3f\n", x1);
                }
                else                                                            //if discriminate < 0
                    printf("The equation haven't roots in R\n");
            }

            while (getchar() != '\n')
                    continue;

            printf("\n\nInput coefficients for equation a*x^2+b*x+c=0 \n");
            printf("Input q if want to continue, else press enter\n");

            exit = getchar();
            if(exit == 'q')
                break;
            else if (exit == '\n');
            else
                while (getchar() != '\n')
                    continue;

            printf("a=");
            a = test_num();
            printf("b=");
            b = test_num();
            printf("c=");
            c = test_num();

    }

    return 0;
}

double test_num(void)
{
    char ch = 'A';
    double x = 0;

    while(scanf("%lf", &x) != 1)
    {
        while ( (ch = getchar() ) != '\n')
            putchar(ch);

        printf(" is not number, please input int number: ");
    }

    return x;
}
