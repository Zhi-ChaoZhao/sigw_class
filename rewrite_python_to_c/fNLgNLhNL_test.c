// gcc -o fNLgNLhNL_test fNLgNLhNL_test.c fNLgNLhNL.c omega_functions.c  -lm -lgsl
#include <stdio.h>
#include <math.h>
#include "fNLgNLhNL.h"
#include "omega_functions.h"
#include <stdlib.h> // Add this line


int main() {
    spline_function_initial_all();
    zOpar myzOpar_my;
    myzOpar_my.sigma = 1.0;
    myzOpar_my.k_ = 1.0;
    myzOpar_my.A = 1.0;
    myzOpar_my.nu_s = 1.0;
    myzOpar_my.FNL = 1.0;
    myzOpar_my.FNLls = myzOpar_my.FNL;
    myzOpar_my.GNL = 0.;
    myzOpar_my.GNLlss = myzOpar_my.GNL;
    myzOpar_my.GNLlls = myzOpar_my.GNL;
    myzOpar_my.HNL = 0.;
    myzOpar_my.HNLlsss = myzOpar_my.HNL;
    myzOpar_my.HNLllss = myzOpar_my.HNL;
    myzOpar_my.HNLllls = myzOpar_my.HNL;
    myzOpar_my.Fa = sqrt(myzOpar_my.FNL * myzOpar_my.FNL * myzOpar_my.A);
    myzOpar_my.Ga = fabs(myzOpar_my.GNL) * myzOpar_my.A;
    myzOpar_my.Ha = sqrt(myzOpar_my.HNL * myzOpar_my.HNL * myzOpar_my.A * myzOpar_my.A * myzOpar_my.A);
    // printf("Define myzOpar_my successfully\n");
    // printf("ob: %e\n", ob(myzOpar_my));
    // printf("ng1: %e\n", ng1(myzOpar_my));
    // printf("total: %e\n", total(myzOpar_my));

    // randomly generate k_, A, FNL. the range is :
    // k_: from 1e-4 to 1e2.05
    // A: from 1e-9 to 1
    // FNL: from 0 to 100
    // k_ and A are randomly in logspace, FNL is randomly in linspace
    // then print the k_, A, FNL, ob, ng1, total to a file named "fNLgNLhNL_test.txt", with 100000 lines.

    FILE *fp = fopen("fNLgNLhNL_test.txt", "w");
    for (int i = 0; i < 100000; i++) {
        myzOpar_my.k_ = pow(10, -4 + (rand() / (double)RAND_MAX) * (2.05 + 4));
        myzOpar_my.A = pow(10, -9 + (rand() / (double)RAND_MAX) * 9);
        myzOpar_my.FNL = (rand() / (double)RAND_MAX) * 100;
        myzOpar_my.FNLls = myzOpar_my.FNL;

        // printf("k_: %e, A: %e, FNL: %e\n", myzOpar_my.k_, myzOpar_my.A, myzOpar_my.FNL);
        fprintf(fp, "%e %e %e %e %e %e\n", myzOpar_my.k_, myzOpar_my.A, myzOpar_my.FNL, ob(myzOpar_my), ng1(myzOpar_my), total(myzOpar_my));
    }
    fclose(fp); 



    return 0;
}