/* Bas Vlaszaty (5783445) & Joost Hekman (5887232)
 * Modelleren & Simuleren Assignment 3: Euler and Runge Kutta in C
 */

#include <stdio.h>
#include "integrations.h"

int Euler(double t0, double t1, double dt, double * y0, double * y1, int N, 
    int f(double t, double * y, double * dy, void * params), void * params) {

    double dy[N];
    int i = 0, j = 0;
    int num_steps = ((t1 - t0) / dt);
    double *temp_res;
    
    /* Pass through the N parameter */
    struct param p;
    p.N = N;

    temp_res = y0;
    for(i = 0; i < N; i++) {
        for(j = 1; j <= num_steps; j++) {
            f(t0 + (j - 1) * dt, temp_res, dy, &p);
            temp_res[i] = temp_res[i] + dy[i] * dt;
        }

    y1[i] = temp_res[i];
    }

    return 0;
}

int RungeKutta2(double t0, double t1, double dt, double * y0, double * y1,
   int N, int f(double t, double * y, double * dy, void * params),
	void * params) {

    int i = 0, j = 0;
    double dy[N], dy_2[N];
    int num_steps = ((t1 - t0) / dt);
    double *temp_res;
    double tempY[N];
    
    /* Pass through the N parameter */
    struct param p;
    p.N = N;
    
    temp_res = y0;
    for(i = 0; i < N; i++) {
        for(j = 1; j <= num_steps; j++) {
            f(t0 + (j - 1) * dt, temp_res, dy, &p);
            tempY[i] = temp_res[i] + dy[i] * dt;
            f(t0 + j * dt, tempY, dy_2, &p);
            temp_res[i] = temp_res[i] + 0.5 * (dy[i] + dy_2[i]) * dt;
        }
        y1[i] = temp_res[i];
    }

    return 0;
}



int RungeKutta4(double t0, double t1, double dt, double * y0, double * y1, int N,
   int f(double, double *, double *, void *), void * params) {
   
    int i = 0, j = 0;
    double dy_1st[N], dy_2nd[N], dy_3rd[N], dy_4th[N];
    double est_1, est_2, est_3, est_4;
    int num_steps = ((t1 - t0) / dt);
    double *temp_res;
    double temp_res2[N];
    
    /* Pass through the N parameter */
    struct param p;
    p.N = N;
    
    temp_res = y0;
    
    /* Use calculated estimates to find each solution */
    for(i = 0; i < N; i++) {
        for(j = 1; j <= num_steps; j++) {
        
                /* Calculate the 4 estimators */
                f(t0 + (j - 1) * dt, temp_res, dy_1st, &p);
                est_1 = dy_1st[i] * dt;
 
                temp_res2[i] = temp_res[i] + 0.5 * est_1;
                f(t0 + (j - 1) * dt + 0.5 * dt, temp_res2, dy_2nd, &p);
                est_2 = dy_2nd[i] * dt;
               
                temp_res2[i] = temp_res[i] + 0.5 * est_2;
                f(t0 + (j - 1) * dt + 0.5 * dt, temp_res2, dy_3rd, &p);
                est_3 = dy_3rd[i] * dt;
               
                temp_res2[i] = temp_res[i] + est_3;
                f(t0 + (j - 1) * dt + dt, temp_res2, dy_4th, &p);
                est_4 = dy_4th[i] * dt;

                /* Combine estimators */
                temp_res[i] = temp_res[i] + (est_1 + 2 * est_2 + 2 * est_3 + est_4) / 6;

        }
            
        y1[i] = temp_res[i];
    }
    
    return 0;
}

