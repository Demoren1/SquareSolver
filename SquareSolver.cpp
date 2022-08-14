#include <stdio.h>
#include <math.h>

int main(void){
    double x1=0, x2=0;
    int a=0, b=0, c=0, D=0;

    printf("Input coefficients for equation a*x^2+b*x+c=0 \n");
    printf("(or q for exit)\n");

    while (scanf("%d %d %d", &a, &b, &c)==3){
            if (a==0){                                                         //Если уравнение оказалось не квадратным
                    x1=x2=(float)(-c)/b;
                    printf("This is not square equation, the root is %.3f\n", x1);
            }                                                                  //Уравнение оказалось квадратным
            else{
                D=b*b-4*a*c;
                if (D>0){                                                      //Дискриминат больше 0
                    D = pow(D,0.5);
                    x1=(-b-D)/(2*(float)a);
                    x2=(-b+D)/(2*(float)a);
                    printf ("The roots of equation are %.3f and %.3f\n", x1, x2);
                }
                else if (D==0){                                                //Дискриминат равен 0
                        x1=x2=((float)-b)/(2*(float)a);
                        printf("The root of equation is %.3f\n", x1);
                }
                else                                                           //Дискриминат меньше 0
                    printf("The equation haven't roots in R\n");
            }

            printf("Input coefficients for equation a*x^2+b*x+c=0 \n");
            printf("(or q for exit)\n");
    }

    return 0;
}
