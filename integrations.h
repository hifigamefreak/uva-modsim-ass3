/* Joost Hekman (5887232)
 * Modelleren & Simuleren Assignment 3: Euler and Runge Kutta in C
 */
 typedef struct param {
	int N;
} param;

int Euler(double t0, double t1, double dt, double * y0, double * y1, int N, int
f(double, double *, double *, void *), void * params);

int RungeKutta2(double t0, double t1, double dt, double * y0, double * y1, int N,
int f(double, double *, double *, void *), void * params);

int RungeKutta4(double t0, double t1, double dt, double * y0, double * y1, int N,
int f(double, double *, double *, void *), void * params);

