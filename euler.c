/* Joost Hekman (5887232)
 * Modelleren & Simuleren Assignment 3: Euler and Runge Kutta in C
 */
#include <stdlib.h>
#include <stdio.h>
#include "integrations.h"

int f1(double t, double * y, double * dy, void * params) {
    dy[0] = 1.0;
    return 0;
}

int f2(double t, double * y, double * dy, void * params) {
    dy[0] = t;
    return 0;
}

int f3(double t, double * y, double * dy, void * params) {
    dy[0] = y[0];
    return 0;
}

int f4(double t, double * y, double * dy, void * params) {
    dy[0] = y[0] * y[0];
    return 0;
}

/* Ininitalisation method */
int ftest(double t, double * y, double * dy, void * params) {
    int i = 0;
    struct param *pp = params;

    for(i = 0; i < ((*pp).N); i++) {
    dy[i] = 0.1 * y[i];
    }

return 0;
}

/* Main function */
int main(void) {
    int dt = 0;
    double res1[1];
    double res2[1];
    double res3[1];
    double res4[1];
    double res5[1];
    double res6[1];
    double res7[1];
    double res8[1];
    double res9[1];
    double res10[1];
    double res11[1];
    double res12[1];
    double res13[1];
    double res14[1];
    double res15[1];

    double in2[2] = {100, 200};
    double in3[2] = {100, 200};
    double in4[2] = {100, 200};

    // y' = 1 
    puts("\nResult of y' = 1 with y(0) = 0 integrated from t = 0 to 10 with dt = 1");
    double i1[1] = {0};
    Euler(0, 10, 1, i1, res1, 1, f1, NULL);
    printf("Using Euler: %f\n", res1[0]);

    double i2[1] = {0};
    RungeKutta2(0, 10, 1, i2, res2, 1, f1, NULL);
    printf("Using Runge Kutta 2: %f\n", res2[0]);

    double i3[1] = {0};
    RungeKutta4(0, 10, 1, i3, res3, 1, f1, NULL);
    printf("Using Runge Kutta 4: %f\n", res3[0]);

    // y' = t 
    puts("\nResult of y' = t with y(0) = 0 integrated from t = 0 to 10 with dt = 1");
    double i4[1] = {0};
    Euler(0, 10, 1, i4, res4, 1, f2, NULL);
    printf("Using Euler: %f\n", res4[0]);

    double i5[1] = {0};
    RungeKutta2(0, 10, 1, i5, res5, 1, f2, NULL);
    printf("Using Runge Kutta 2: %f\n", res5[0]);

    double i6[1] = {0};
    RungeKutta4(0, 10, 1, i6, res6, 1, f2, NULL);
    printf("Using Runge Kutta 4: %f\n", res6[0]);

    // y' = y 
    puts("\nResult of y' = y with y(0) = 1 integrated from t = 0 to 5 with dt = 0.5");
    double i7[1] = {1};
    Euler(0, 5, 0.5, i7, res7, 1, f3, NULL);
    printf("Using Euler: %f\n", res7[0]);

    double i8[1] = {1};
    RungeKutta2(0, 5, 0.5, i8, res8, 1, f3, NULL);
    printf("Using Runge Kutta 2: %f\n", res8[0]);

    double i9[1] = {1};
    RungeKutta4(0, 5, 0.5, i9, res9, 1, f3, NULL);
    printf("Using Runge Kutta 4: %f\n", res9[0]);

    // y' = y * y 
    puts("\nResult of y' = y * y with y(0) = 1 integrated from t = -1 to 1 with dt = 0.01");
    double i10[1] = {1};
    Euler(-1, 1, 0.01, i10, res10, 1, f4, NULL);
    printf("Using Euler: %f\n", res10[0]);

    double i11[1] = {1};
    RungeKutta2(-1, 1, 0.01, i11, res11, 1, f4, NULL);
    printf("Using Runge Kutta 2: %f\n", res11[0]);

    double i12[1] = {1};
    RungeKutta4(-1, 1, 0.01, i12, res12, 1, f4, NULL);
    printf("Using Runge Kutta 4: %f\n", res12[0]);

    puts("\nResult of y' = y * y with y(0) = -1 integrated from t = 1 to 10 with dt = 0.1");
    double i13[1] = {-1};
    Euler(1, 10, 0.1, i10, res13, 1, f4, NULL);
    printf("Using Euler: %f\n", res13[0]);

    double i14[1] = {-1};
    RungeKutta2(1, 10, 0.1, i14, res14, 1, f4, NULL);
    printf("Using Runge Kutta 2: %f\n", res14[0]);

    double i15[1] = {-1};
    RungeKutta4(1, 10, 0.1, i15, res15, 1, f4, NULL);
    printf("Using Runge Kutta 4: %f\n", res15[0]);

    //Some testing with variable dt
    puts("\nNow using y'= 0.1y, and testing it for different functions and values of dt\n");

    for(dt = 1; dt <= 80; dt += 5) {
        double real_dt = dt / 10.0;

        //Only use relevant values of dt: don't end up with partial intervals
        if(!(80 % dt == 0))
            continue;

        //We're interested in 0.1 and from thereon 0.5, 1, 2, etc.
        if(dt == 1)
            dt = 0;
                
        double in[1] = {100}, in2[1] = {100}, in3[1] = {100};
        double res_e[1], res_rk2[1], res_rk4[1];
        Euler(0,8,real_dt,in, res_e, 1, ftest, NULL);
        RungeKutta2(0, 8, real_dt, in2, res_rk2, 1, ftest, NULL);
        RungeKutta4(0, 8, real_dt, in3, res_rk4, 1, ftest, NULL);
        printf("DT = %f\n", real_dt);
        printf("Euler: %f error:(%f%%)\n", res_e[0], 100.0 - (res_e[0] / 223.0 * 100));
        printf("RK2: %f error:(%f%%)\n", res_rk2[0], 100.0 - (res_rk2[0] / 223.0 * 100));
        printf("RK4: %f error:(%f%%)\n\n", res_rk4[0], 100.0 - (res_rk4[0] / 223.0 * 100));
    }
    return 0;
}

