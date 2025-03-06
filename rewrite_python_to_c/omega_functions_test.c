#include <stdio.h>
#include <math.h>
#include <gsl/gsl_spline.h>
#include "omega_functions.h"


int main() {
    FILE *file;
    double x;
    double y;
    char filename[256];
    gsl_interp_accel *acc = gsl_interp_accel_alloc();
    spline_function_initial_all();
    printf("All the splines initialized successfully\n");

    for (int i = 0; i < 777; i++) {
        x = -13.54 + i * (9 / 776.0);
        x = pow(10, x);

        // Test spline_B
        y = evaluate_spline_B(x);
        snprintf(filename, sizeof(filename), "./testdat/B.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);
    }
    for (int i = 0; i < 777; i++) {
        x = -4.0 + i * (6.05 / 776.0);
        x = pow(10, x);

        // Test spline_Omega_G
        y = evaluate_spline_Omega_G(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_G.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_H
        y = evaluate_spline_Omega_H(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_H2
        y = evaluate_spline_Omega_H2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_H2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_H3
        y = evaluate_spline_Omega_H3(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_H3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R
        y = evaluate_spline_Omega_R(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_RH
        y = evaluate_spline_Omega_RH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_RH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_RH2
        y = evaluate_spline_Omega_RH2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_RH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R2
        y = evaluate_spline_Omega_R2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_R2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R2H
        y = evaluate_spline_Omega_R2H(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_R2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R3
        y = evaluate_spline_Omega_R3(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_R3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C
        y = evaluate_spline_Omega_C(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_C.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CH
        y = evaluate_spline_Omega_CH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CH2
        y = evaluate_spline_Omega_CH2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CR
        y = evaluate_spline_Omega_CR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CRH
        y = evaluate_spline_Omega_CRH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CR2
        y = evaluate_spline_Omega_CR2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2
        y = evaluate_spline_Omega_C2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_C2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2H
        y = evaluate_spline_Omega_C2H(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_C2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2R
        y = evaluate_spline_Omega_C2R(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_C2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C3
        y = evaluate_spline_Omega_C3(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_C3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z
        y = evaluate_spline_Omega_Z(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_Z.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZH
        y = evaluate_spline_Omega_ZH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_ZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZH2
        y = evaluate_spline_Omega_ZH2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_ZH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZR
        y = evaluate_spline_Omega_ZR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_ZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZRH
        y = evaluate_spline_Omega_ZRH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_ZRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZR2
        y = evaluate_spline_Omega_ZR2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_ZR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z2
        y = evaluate_spline_Omega_Z2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_Z2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z2H
        y = evaluate_spline_Omega_Z2H(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_Z2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z2R
        y = evaluate_spline_Omega_Z2R(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_Z2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z3
        y = evaluate_spline_Omega_Z3(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_Z3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P
        y = evaluate_spline_Omega_P(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PH
        y = evaluate_spline_Omega_PH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PH2
        y = evaluate_spline_Omega_PH2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PR
        y = evaluate_spline_Omega_PR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PRH
        y = evaluate_spline_Omega_PRH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PR2
        y = evaluate_spline_Omega_PR2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PC
        y = evaluate_spline_Omega_PC(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PCH
        y = evaluate_spline_Omega_PCH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PCH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PCR
        y = evaluate_spline_Omega_PCR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PCR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2
        y = evaluate_spline_Omega_P2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2H
        y = evaluate_spline_Omega_P2H(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2R
        y = evaluate_spline_Omega_P2R(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PC2
        y = evaluate_spline_Omega_PC2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PC2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2C
        y = evaluate_spline_Omega_P2C(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P2C.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P3
        y = evaluate_spline_Omega_P3(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_N
        y = evaluate_spline_Omega_N(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_N.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NH
        y = evaluate_spline_Omega_NH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NH2
        y = evaluate_spline_Omega_NH2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NR
        y = evaluate_spline_Omega_NR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NRH
        y = evaluate_spline_Omega_NRH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NR2
        y = evaluate_spline_Omega_NR2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NZH
        y = evaluate_spline_Omega_NZH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NZR
        y = evaluate_spline_Omega_NZR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_N2R
        y = evaluate_spline_Omega_N2R(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_N2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZ
        y = evaluate_spline_Omega_CZ(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZ.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZH
        y = evaluate_spline_Omega_CZH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZH2
        y = evaluate_spline_Omega_CZH2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZHp
        y = evaluate_spline_Omega_CZHp(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZHp.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZR
        y = evaluate_spline_Omega_CZR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZRH
        y = evaluate_spline_Omega_CZRH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2Z
        y = evaluate_spline_Omega_C2Z(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_C2Z.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2ZH
        y = evaluate_spline_Omega_C2ZH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_C2ZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZ2
        y = evaluate_spline_Omega_CZ2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZ2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZ2H
        y = evaluate_spline_Omega_CZ2H(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_CZ2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZ
        y = evaluate_spline_Omega_PZ(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PZ.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZH
        y = evaluate_spline_Omega_PZH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZR
        y = evaluate_spline_Omega_PZR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZC
        y = evaluate_spline_Omega_PZC(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PZC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZCH
        y = evaluate_spline_Omega_PZCH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PZCH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2Z
        y = evaluate_spline_Omega_P2Z(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P2Z.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZ2
        y = evaluate_spline_Omega_PZ2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PZ2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NC
        y = evaluate_spline_Omega_NC(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NCH
        y = evaluate_spline_Omega_NCH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NCH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NCR
        y = evaluate_spline_Omega_NCR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NCR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NCZH
        y = evaluate_spline_Omega_NCZH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NCZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NC2
        y = evaluate_spline_Omega_NC2(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_NC2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PN
        y = evaluate_spline_Omega_PN(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PN.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PNH
        y = evaluate_spline_Omega_PNH(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PNH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PNR
        y = evaluate_spline_Omega_PNR(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PNR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PNC
        y = evaluate_spline_Omega_PNC(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_PNC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2N
        y = evaluate_spline_Omega_P2N(x);
        snprintf(filename, sizeof(filename), "./testdat/Omega_P2N.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);
    }
}
