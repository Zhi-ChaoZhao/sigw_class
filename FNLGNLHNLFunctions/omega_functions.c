#include <stdio.h>
#include "omega_functions.h"
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>
#define zzc_B_DATA_POINTS 10000
#define zzc_OMEGA_DATA_POINTS 10000

gsl_interp_accel *acc; // 全局的 gsl_interp_accel 对象

void initialize_accel() {
    acc = gsl_interp_accel_alloc();
}

void free_accel() {
    gsl_interp_accel_free(acc);
}

double zzc_f_ggf[zzc_B_DATA_POINTS];
double zzc_B_ggf[zzc_B_DATA_POINTS];
//'Omega_G', 'Omega_H', 'Omega_H2', 'Omega_H3', 'Omega_R', 'Omega_RH', 'Omega_RH2', 'Omega_R2', 'Omega_R2H', 'Omega_R3', 'Omega_C', 'Omega_CH', 'Omega_CH2', 'Omega_CR', 'Omega_CRH', 'Omega_CR2', 'Omega_C2', 'Omega_C2H', 'Omega_C2R', 'Omega_C3', 'Omega_Z', 'Omega_ZH', 'Omega_ZH2', 'Omega_ZR', 'Omega_ZRH', 'Omega_ZR2', 'Omega_Z2', 'Omega_Z2H', 'Omega_Z2R', 'Omega_Z3', 'Omega_P', 'Omega_PH', 'Omega_PH2', 'Omega_PR', 'Omega_PRH', 'Omega_PR2', 'Omega_PC', 'Omega_PCH', 'Omega_PCR', 'Omega_P2', 'Omega_P2H', 'Omega_P2R', 'Omega_PC2', 'Omega_P2C', 'Omega_P3', 'Omega_N', 'Omega_NH', 'Omega_NH2', 'Omega_NR', 'Omega_NRH', 'Omega_NR2', 'Omega_NZH', 'Omega_NZR', 'Omega_N2R', 'Omega_CZ', 'Omega_CZH', 'Omega_CZH2', 'Omega_CZHp', 'Omega_CZR', 'Omega_CZRH', 'Omega_C2Z', 'Omega_C2ZH', 'Omega_CZ2', 'Omega_CZ2H', 'Omega_PZ', 'Omega_PZH', 'Omega_PZR', 'Omega_PZC', 'Omega_PZCH', 'Omega_P2Z', 'Omega_PZ2', 'Omega_NC', 'Omega_NCH', 'Omega_NCR', 'Omega_NCZH', 'Omega_NC2', 'Omega_PN', 'Omega_PNH', 'Omega_PNR', 'Omega_PNC', 'Omega_P2N'
// Define a dictionary to store the data for each Omega function
typedef struct {
    double k_temp[zzc_OMEGA_DATA_POINTS];
    double v_temp[zzc_OMEGA_DATA_POINTS];
} OmegaData;

// Define the OmegaData structures for each Omega function
OmegaData Data_B;
OmegaData Data_Omega_G;
OmegaData Data_Omega_H;
OmegaData Data_Omega_H2;
OmegaData Data_Omega_H3;
OmegaData Data_Omega_R;
OmegaData Data_Omega_RH;
OmegaData Data_Omega_RH2;
OmegaData Data_Omega_R2;
OmegaData Data_Omega_R2H;
OmegaData Data_Omega_R3;
OmegaData Data_Omega_C;
OmegaData Data_Omega_CH;
OmegaData Data_Omega_CH2;
OmegaData Data_Omega_CR;
OmegaData Data_Omega_CRH;
OmegaData Data_Omega_CR2;
OmegaData Data_Omega_C2;
OmegaData Data_Omega_C2H;
OmegaData Data_Omega_C2R;
OmegaData Data_Omega_C3;
OmegaData Data_Omega_Z;
OmegaData Data_Omega_ZH;
OmegaData Data_Omega_ZH2;
OmegaData Data_Omega_ZR;
OmegaData Data_Omega_ZRH;
OmegaData Data_Omega_ZR2;
OmegaData Data_Omega_Z2;
OmegaData Data_Omega_Z2H;
OmegaData Data_Omega_Z2R;
OmegaData Data_Omega_Z3;
OmegaData Data_Omega_P;
OmegaData Data_Omega_PH;
OmegaData Data_Omega_PH2;
OmegaData Data_Omega_PR;
OmegaData Data_Omega_PRH;
OmegaData Data_Omega_PR2;
OmegaData Data_Omega_PC;
OmegaData Data_Omega_PCH;
OmegaData Data_Omega_PCR;
OmegaData Data_Omega_P2;
OmegaData Data_Omega_P2H;
OmegaData Data_Omega_P2R;
OmegaData Data_Omega_PC2;
OmegaData Data_Omega_P2C;
OmegaData Data_Omega_P3;
OmegaData Data_Omega_N;
OmegaData Data_Omega_NH;
OmegaData Data_Omega_NH2;
OmegaData Data_Omega_NR;
OmegaData Data_Omega_NRH;
OmegaData Data_Omega_NR2;
OmegaData Data_Omega_NZH;
OmegaData Data_Omega_NZR;
OmegaData Data_Omega_N2R;
OmegaData Data_Omega_CZ;
OmegaData Data_Omega_CZH;
OmegaData Data_Omega_CZH2;
OmegaData Data_Omega_CZHp;
OmegaData Data_Omega_CZR;
OmegaData Data_Omega_CZRH;
OmegaData Data_Omega_C2Z;
OmegaData Data_Omega_C2ZH;
OmegaData Data_Omega_CZ2;
OmegaData Data_Omega_CZ2H;
OmegaData Data_Omega_PZ;
OmegaData Data_Omega_PZH;
OmegaData Data_Omega_PZR;
OmegaData Data_Omega_PZC;
OmegaData Data_Omega_PZCH;
OmegaData Data_Omega_P2Z;
OmegaData Data_Omega_PZ2;
OmegaData Data_Omega_NC;
OmegaData Data_Omega_NCH;
OmegaData Data_Omega_NCR;
OmegaData Data_Omega_NCZH;
OmegaData Data_Omega_NC2;
OmegaData Data_Omega_PN;
OmegaData Data_Omega_PNH;
OmegaData Data_Omega_PNR;
OmegaData Data_Omega_PNC;
OmegaData Data_Omega_P2N;


gsl_spline* load_data(OmegaData *data, char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < zzc_OMEGA_DATA_POINTS; i++) {
        if (fscanf(file, "%lf %lf", &data->k_temp[i], &data->v_temp[i]) != 2) {
            perror("Error reading file");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }
    fclose(file);
    gsl_interp_accel *acc = gsl_interp_accel_alloc();
    gsl_spline *spline = gsl_spline_alloc(gsl_interp_linear, zzc_OMEGA_DATA_POINTS);
    gsl_spline_init(spline, data->k_temp, data->v_temp, zzc_OMEGA_DATA_POINTS);
    return spline;
}

gsl_spline* spline_B;
gsl_spline* spline_Omega_G;
gsl_spline* spline_Omega_H;
gsl_spline* spline_Omega_H2;
gsl_spline* spline_Omega_H3;
gsl_spline* spline_Omega_R;
gsl_spline* spline_Omega_RH;
gsl_spline* spline_Omega_RH2;
gsl_spline* spline_Omega_R2;
gsl_spline* spline_Omega_R2H;
gsl_spline* spline_Omega_R3;
gsl_spline* spline_Omega_C;
gsl_spline* spline_Omega_CH;
gsl_spline* spline_Omega_CH2;
gsl_spline* spline_Omega_CR;
gsl_spline* spline_Omega_CRH;
gsl_spline* spline_Omega_CR2;
gsl_spline* spline_Omega_C2;
gsl_spline* spline_Omega_C2H;
gsl_spline* spline_Omega_C2R;
gsl_spline* spline_Omega_C3;
gsl_spline* spline_Omega_Z;
gsl_spline* spline_Omega_ZH;
gsl_spline* spline_Omega_ZH2;
gsl_spline* spline_Omega_ZR;
gsl_spline* spline_Omega_ZRH;
gsl_spline* spline_Omega_ZR2;
gsl_spline* spline_Omega_Z2;
gsl_spline* spline_Omega_Z2H;
gsl_spline* spline_Omega_Z2R;
gsl_spline* spline_Omega_Z3;
gsl_spline* spline_Omega_P;
gsl_spline* spline_Omega_PH;
gsl_spline* spline_Omega_PH2;
gsl_spline* spline_Omega_PR;
gsl_spline* spline_Omega_PRH;
gsl_spline* spline_Omega_PR2;
gsl_spline* spline_Omega_PC;
gsl_spline* spline_Omega_PCH;
gsl_spline* spline_Omega_PCR;
gsl_spline* spline_Omega_P2;
gsl_spline* spline_Omega_P2H;
gsl_spline* spline_Omega_P2R;
gsl_spline* spline_Omega_PC2;
gsl_spline* spline_Omega_P2C;
gsl_spline* spline_Omega_P3;
gsl_spline* spline_Omega_N;
gsl_spline* spline_Omega_NH;
gsl_spline* spline_Omega_NH2;
gsl_spline* spline_Omega_NR;
gsl_spline* spline_Omega_NRH;
gsl_spline* spline_Omega_NR2;
gsl_spline* spline_Omega_NZH;
gsl_spline* spline_Omega_NZR;
gsl_spline* spline_Omega_N2R;
gsl_spline* spline_Omega_CZ;
gsl_spline* spline_Omega_CZH;
gsl_spline* spline_Omega_CZH2;
gsl_spline* spline_Omega_CZHp;
gsl_spline* spline_Omega_CZR;
gsl_spline* spline_Omega_CZRH;
gsl_spline* spline_Omega_C2Z;
gsl_spline* spline_Omega_C2ZH;
gsl_spline* spline_Omega_CZ2;
gsl_spline* spline_Omega_CZ2H;
gsl_spline* spline_Omega_PZ;
gsl_spline* spline_Omega_PZH;
gsl_spline* spline_Omega_PZR;
gsl_spline* spline_Omega_PZC;
gsl_spline* spline_Omega_PZCH;
gsl_spline* spline_Omega_P2Z;
gsl_spline* spline_Omega_PZ2;
gsl_spline* spline_Omega_NC;
gsl_spline* spline_Omega_NCH;
gsl_spline* spline_Omega_NCR;
gsl_spline* spline_Omega_NCZH;
gsl_spline* spline_Omega_NC2;
gsl_spline* spline_Omega_PN;
gsl_spline* spline_Omega_PNH;
gsl_spline* spline_Omega_PNR;
gsl_spline* spline_Omega_PNC;
gsl_spline* spline_Omega_P2N;

void spline_function_initial_all() {
    initialize_accel();
    spline_B = load_data(&Data_B, "FNLGNLHNLFunctions/dat/B.dat");
    spline_Omega_G = load_data(&Data_Omega_G, "FNLGNLHNLFunctions/dat/Omega_G.dat");
    spline_Omega_H = load_data(&Data_Omega_H, "FNLGNLHNLFunctions/dat/Omega_H.dat");
    spline_Omega_H2 = load_data(&Data_Omega_H2, "FNLGNLHNLFunctions/dat/Omega_H2.dat");
    spline_Omega_H3 = load_data(&Data_Omega_H3, "FNLGNLHNLFunctions/dat/Omega_H3.dat");
    spline_Omega_R = load_data(&Data_Omega_R, "FNLGNLHNLFunctions/dat/Omega_R.dat");
    spline_Omega_RH = load_data(&Data_Omega_RH, "FNLGNLHNLFunctions/dat/Omega_RH.dat");
    spline_Omega_RH2 = load_data(&Data_Omega_RH2, "FNLGNLHNLFunctions/dat/Omega_RH2.dat");
    spline_Omega_R2 = load_data(&Data_Omega_R2, "FNLGNLHNLFunctions/dat/Omega_R2.dat");
    spline_Omega_R2H = load_data(&Data_Omega_R2H, "FNLGNLHNLFunctions/dat/Omega_R2H.dat");
    spline_Omega_R3 = load_data(&Data_Omega_R3, "FNLGNLHNLFunctions/dat/Omega_R3.dat");
    spline_Omega_C = load_data(&Data_Omega_C, "FNLGNLHNLFunctions/dat/Omega_C.dat");
    spline_Omega_CH = load_data(&Data_Omega_CH, "FNLGNLHNLFunctions/dat/Omega_CH.dat");
    spline_Omega_CH2 = load_data(&Data_Omega_CH2, "FNLGNLHNLFunctions/dat/Omega_CH2.dat");
    spline_Omega_CR = load_data(&Data_Omega_CR, "FNLGNLHNLFunctions/dat/Omega_CR.dat");
    spline_Omega_CRH = load_data(&Data_Omega_CRH, "FNLGNLHNLFunctions/dat/Omega_CRH.dat");
    spline_Omega_CR2 = load_data(&Data_Omega_CR2, "FNLGNLHNLFunctions/dat/Omega_CR2.dat");
    spline_Omega_C2 = load_data(&Data_Omega_C2, "FNLGNLHNLFunctions/dat/Omega_C2.dat");
    spline_Omega_C2H = load_data(&Data_Omega_C2H, "FNLGNLHNLFunctions/dat/Omega_C2H.dat");
    spline_Omega_C2R = load_data(&Data_Omega_C2R, "FNLGNLHNLFunctions/dat/Omega_C2R.dat");
    spline_Omega_C3 = load_data(&Data_Omega_C3, "FNLGNLHNLFunctions/dat/Omega_C3.dat");
    spline_Omega_Z = load_data(&Data_Omega_Z, "FNLGNLHNLFunctions/dat/Omega_Z.dat");
    spline_Omega_ZH = load_data(&Data_Omega_ZH, "FNLGNLHNLFunctions/dat/Omega_ZH.dat");
    spline_Omega_ZH2 = load_data(&Data_Omega_ZH2, "FNLGNLHNLFunctions/dat/Omega_ZH2.dat");
    spline_Omega_ZR = load_data(&Data_Omega_ZR, "FNLGNLHNLFunctions/dat/Omega_ZR.dat");
    spline_Omega_ZRH = load_data(&Data_Omega_ZRH, "FNLGNLHNLFunctions/dat/Omega_ZRH.dat");
    spline_Omega_ZR2 = load_data(&Data_Omega_ZR2, "FNLGNLHNLFunctions/dat/Omega_ZR2.dat");
    spline_Omega_Z2 = load_data(&Data_Omega_Z2, "FNLGNLHNLFunctions/dat/Omega_Z2.dat");
    spline_Omega_Z2H = load_data(&Data_Omega_Z2H, "FNLGNLHNLFunctions/dat/Omega_Z2H.dat");
    spline_Omega_Z2R = load_data(&Data_Omega_Z2R, "FNLGNLHNLFunctions/dat/Omega_Z2R.dat");
    spline_Omega_Z3 = load_data(&Data_Omega_Z3, "FNLGNLHNLFunctions/dat/Omega_Z3.dat");
    spline_Omega_P = load_data(&Data_Omega_P, "FNLGNLHNLFunctions/dat/Omega_P.dat");
    spline_Omega_PH = load_data(&Data_Omega_PH, "FNLGNLHNLFunctions/dat/Omega_PH.dat");
    spline_Omega_PH2 = load_data(&Data_Omega_PH2, "FNLGNLHNLFunctions/dat/Omega_PH2.dat");
    spline_Omega_PR = load_data(&Data_Omega_PR, "FNLGNLHNLFunctions/dat/Omega_PR.dat");
    spline_Omega_PRH = load_data(&Data_Omega_PRH, "FNLGNLHNLFunctions/dat/Omega_PRH.dat");
    spline_Omega_PR2 = load_data(&Data_Omega_PR2, "FNLGNLHNLFunctions/dat/Omega_PR2.dat");
    spline_Omega_PC = load_data(&Data_Omega_PC, "FNLGNLHNLFunctions/dat/Omega_PC.dat");
    spline_Omega_PCH = load_data(&Data_Omega_PCH, "FNLGNLHNLFunctions/dat/Omega_PCH.dat");
    spline_Omega_PCR = load_data(&Data_Omega_PCR, "FNLGNLHNLFunctions/dat/Omega_PCR.dat");
    spline_Omega_P2 = load_data(&Data_Omega_P2, "FNLGNLHNLFunctions/dat/Omega_P2.dat");
    spline_Omega_P2H = load_data(&Data_Omega_P2H, "FNLGNLHNLFunctions/dat/Omega_P2H.dat");
    spline_Omega_P2R = load_data(&Data_Omega_P2R, "FNLGNLHNLFunctions/dat/Omega_P2R.dat");
    spline_Omega_PC2 = load_data(&Data_Omega_PC2, "FNLGNLHNLFunctions/dat/Omega_PC2.dat");
    spline_Omega_P2C = load_data(&Data_Omega_P2C, "FNLGNLHNLFunctions/dat/Omega_P2C.dat");
    spline_Omega_P3 = load_data(&Data_Omega_P3, "FNLGNLHNLFunctions/dat/Omega_P3.dat");
    spline_Omega_N = load_data(&Data_Omega_N, "FNLGNLHNLFunctions/dat/Omega_N.dat");
    spline_Omega_NH = load_data(&Data_Omega_NH, "FNLGNLHNLFunctions/dat/Omega_NH.dat");
    spline_Omega_NH2 = load_data(&Data_Omega_NH2, "FNLGNLHNLFunctions/dat/Omega_NH2.dat");
    spline_Omega_NR = load_data(&Data_Omega_NR, "FNLGNLHNLFunctions/dat/Omega_NR.dat");
    spline_Omega_NRH = load_data(&Data_Omega_NRH, "FNLGNLHNLFunctions/dat/Omega_NRH.dat");
    spline_Omega_NR2 = load_data(&Data_Omega_NR2, "FNLGNLHNLFunctions/dat/Omega_NR2.dat");
    spline_Omega_NZH = load_data(&Data_Omega_NZH, "FNLGNLHNLFunctions/dat/Omega_NZH.dat");
    spline_Omega_NZR = load_data(&Data_Omega_NZR, "FNLGNLHNLFunctions/dat/Omega_NZR.dat");
    spline_Omega_N2R = load_data(&Data_Omega_N2R, "FNLGNLHNLFunctions/dat/Omega_N2R.dat");
    spline_Omega_CZ = load_data(&Data_Omega_CZ, "FNLGNLHNLFunctions/dat/Omega_CZ.dat");
    spline_Omega_CZH = load_data(&Data_Omega_CZH, "FNLGNLHNLFunctions/dat/Omega_CZH.dat");
    spline_Omega_CZH2 = load_data(&Data_Omega_CZH2, "FNLGNLHNLFunctions/dat/Omega_CZH2.dat");
    spline_Omega_CZHp = load_data(&Data_Omega_CZHp, "FNLGNLHNLFunctions/dat/Omega_CZHp.dat");
    spline_Omega_CZR = load_data(&Data_Omega_CZR, "FNLGNLHNLFunctions/dat/Omega_CZR.dat");
    spline_Omega_CZRH = load_data(&Data_Omega_CZRH, "FNLGNLHNLFunctions/dat/Omega_CZRH.dat");
    spline_Omega_C2Z = load_data(&Data_Omega_C2Z, "FNLGNLHNLFunctions/dat/Omega_C2Z.dat");
    spline_Omega_C2ZH = load_data(&Data_Omega_C2ZH, "FNLGNLHNLFunctions/dat/Omega_C2ZH.dat");
    spline_Omega_CZ2 = load_data(&Data_Omega_CZ2, "FNLGNLHNLFunctions/dat/Omega_CZ2.dat");
    spline_Omega_CZ2H = load_data(&Data_Omega_CZ2H, "FNLGNLHNLFunctions/dat/Omega_CZ2H.dat");
    spline_Omega_PZ = load_data(&Data_Omega_PZ, "FNLGNLHNLFunctions/dat/Omega_PZ.dat");
    spline_Omega_PZH = load_data(&Data_Omega_PZH, "FNLGNLHNLFunctions/dat/Omega_PZH.dat");
    spline_Omega_PZR = load_data(&Data_Omega_PZR, "FNLGNLHNLFunctions/dat/Omega_PZR.dat");
    spline_Omega_PZC = load_data(&Data_Omega_PZC, "FNLGNLHNLFunctions/dat/Omega_PZC.dat");
    spline_Omega_PZCH = load_data(&Data_Omega_PZCH, "FNLGNLHNLFunctions/dat/Omega_PZCH.dat");
    spline_Omega_P2Z = load_data(&Data_Omega_P2Z, "FNLGNLHNLFunctions/dat/Omega_P2Z.dat");
    spline_Omega_PZ2 = load_data(&Data_Omega_PZ2, "FNLGNLHNLFunctions/dat/Omega_PZ2.dat");
    spline_Omega_NC = load_data(&Data_Omega_NC, "FNLGNLHNLFunctions/dat/Omega_NC.dat");
    spline_Omega_NCH = load_data(&Data_Omega_NCH, "FNLGNLHNLFunctions/dat/Omega_NCH.dat");
    spline_Omega_NCR = load_data(&Data_Omega_NCR, "FNLGNLHNLFunctions/dat/Omega_NCR.dat");
    spline_Omega_NCZH = load_data(&Data_Omega_NCZH, "FNLGNLHNLFunctions/dat/Omega_NCZH.dat");
    spline_Omega_NC2 = load_data(&Data_Omega_NC2, "FNLGNLHNLFunctions/dat/Omega_NC2.dat");
    spline_Omega_PN = load_data(&Data_Omega_PN, "FNLGNLHNLFunctions/dat/Omega_PN.dat");
    spline_Omega_PNH = load_data(&Data_Omega_PNH, "FNLGNLHNLFunctions/dat/Omega_PNH.dat");
    spline_Omega_PNR = load_data(&Data_Omega_PNR, "FNLGNLHNLFunctions/dat/Omega_PNR.dat");
    spline_Omega_PNC = load_data(&Data_Omega_PNC, "FNLGNLHNLFunctions/dat/Omega_PNC.dat");
    spline_Omega_P2N = load_data(&Data_Omega_P2N, "FNLGNLHNLFunctions/dat/Omega_P2N.dat");
}
// ... existing code ...

double evaluate_spline(gsl_spline *spline, double k, gsl_interp_accel *acc) {
    double log_k = log10(k);
    double log_result = gsl_spline_eval(spline, log_k, acc);
    return pow(10, log_result);
}

double evaluate_spline_special_for_linear(gsl_spline *spline, double k, gsl_interp_accel *acc) {
    double result = gsl_spline_eval(spline, k, acc);
    return result;
}

double evaluate_spline_B(double k) {
    
    double result = evaluate_spline_special_for_linear(spline_B, k, acc);

    return result;
}

double evaluate_spline_Omega_G(double k) {
    
    double result = evaluate_spline(spline_Omega_G, k, acc);

    return result;
}

double evaluate_spline_Omega_H(double k) {
    
    double result = evaluate_spline(spline_Omega_H, k, acc);

    return result;
}

double evaluate_spline_Omega_H2(double k) {
    
    double result = evaluate_spline(spline_Omega_H2, k, acc);

    return result;
}

double evaluate_spline_Omega_H3(double k) {
    
    double result = evaluate_spline(spline_Omega_H3, k, acc);

    return result;
}

double evaluate_spline_Omega_R(double k) {
    
    double result = evaluate_spline(spline_Omega_R, k, acc);

    return result;
}

double evaluate_spline_Omega_RH(double k) {
    
    double result = evaluate_spline(spline_Omega_RH, k, acc);

    return result;
}

double evaluate_spline_Omega_RH2(double k) {
    
    double result = evaluate_spline(spline_Omega_RH2, k, acc);

    return result;
}

double evaluate_spline_Omega_R2(double k) {
    
    double result = evaluate_spline(spline_Omega_R2, k, acc);

    return result;
}

double evaluate_spline_Omega_R2H(double k) {
    
    double result = evaluate_spline(spline_Omega_R2H, k, acc);

    return result;
}

double evaluate_spline_Omega_R3(double k) {
    
    double result = evaluate_spline(spline_Omega_R3, k, acc);

    return result;
}

double evaluate_spline_Omega_C(double k) {
    
    double result = evaluate_spline(spline_Omega_C, k, acc);

    return result;
}

double evaluate_spline_Omega_CH(double k) {
    
    double result = evaluate_spline(spline_Omega_CH, k, acc);

    return result;
}

double evaluate_spline_Omega_CH2(double k) {
    
    double result = evaluate_spline(spline_Omega_CH2, k, acc);

    return result;
}

double evaluate_spline_Omega_CR(double k) {
    
    double result = evaluate_spline(spline_Omega_CR, k, acc);

    return result;
}

double evaluate_spline_Omega_CRH(double k) {
    
    double result = evaluate_spline(spline_Omega_CRH, k, acc);

    return result;
}

double evaluate_spline_Omega_CR2(double k) {
    
    double result = evaluate_spline(spline_Omega_CR2, k, acc);

    return result;
}

double evaluate_spline_Omega_C2(double k) {
    
    double result = evaluate_spline(spline_Omega_C2, k, acc);

    return result;
}

double evaluate_spline_Omega_C2H(double k) {
    
    double result = evaluate_spline(spline_Omega_C2H, k, acc);

    return result;
}

double evaluate_spline_Omega_C2R(double k) {
    
    double result = evaluate_spline(spline_Omega_C2R, k, acc);

    return result;
}

double evaluate_spline_Omega_C3(double k) {
    
    double result = evaluate_spline(spline_Omega_C3, k, acc);

    return result;
}

double evaluate_spline_Omega_Z(double k) {
    
    double result = evaluate_spline(spline_Omega_Z, k, acc);

    return result;
}

double evaluate_spline_Omega_ZH(double k) {
    
    double result = evaluate_spline(spline_Omega_ZH, k, acc);

    return result;
}

double evaluate_spline_Omega_ZH2(double k) {
    
    double result = evaluate_spline(spline_Omega_ZH2, k, acc);

    return result;
}

double evaluate_spline_Omega_ZR(double k) {
    
    double result = evaluate_spline(spline_Omega_ZR, k, acc);

    return result;
}

double evaluate_spline_Omega_ZRH(double k) {
    
    double result = evaluate_spline(spline_Omega_ZRH, k, acc);

    return result;
}

double evaluate_spline_Omega_ZR2(double k) {
    
    double result = evaluate_spline(spline_Omega_ZR2, k, acc);

    return result;
}

double evaluate_spline_Omega_Z2(double k) {
    
    double result = evaluate_spline(spline_Omega_Z2, k, acc);

    return result;
}

double evaluate_spline_Omega_Z2H(double k) {
    
    double result = evaluate_spline(spline_Omega_Z2H, k, acc);

    return result;
}

double evaluate_spline_Omega_Z2R(double k) {
    
    double result = evaluate_spline(spline_Omega_Z2R, k, acc);

    return result;
}

double evaluate_spline_Omega_Z3(double k) {
    
    double result = evaluate_spline(spline_Omega_Z3, k, acc);

    return result;
}

double evaluate_spline_Omega_P(double k) {
    
    double result = evaluate_spline(spline_Omega_P, k, acc);

    return result;
}

double evaluate_spline_Omega_PH(double k) {
    
    double result = evaluate_spline(spline_Omega_PH, k, acc);

    return result;
}

double evaluate_spline_Omega_PH2(double k) {
    
    double result = evaluate_spline(spline_Omega_PH2, k, acc);

    return result;
}

double evaluate_spline_Omega_PR(double k) {
    
    double result = evaluate_spline(spline_Omega_PR, k, acc);

    return result;
}

double evaluate_spline_Omega_PRH(double k) {
    
    double result = evaluate_spline(spline_Omega_PRH, k, acc);

    return result;
}

double evaluate_spline_Omega_PR2(double k) {
    
    double result = evaluate_spline(spline_Omega_PR2, k, acc);

    return result;
}

double evaluate_spline_Omega_PC(double k) {
    
    double result = evaluate_spline(spline_Omega_PC, k, acc);

    return result;
}

double evaluate_spline_Omega_PCH(double k) {
    
    double result = evaluate_spline(spline_Omega_PCH, k, acc);

    return result;
}

double evaluate_spline_Omega_PCR(double k) {
    
    double result = evaluate_spline(spline_Omega_PCR, k, acc);

    return result;
}

double evaluate_spline_Omega_P2(double k) {
    
    double result = evaluate_spline(spline_Omega_P2, k, acc);

    return result;
}

double evaluate_spline_Omega_P2H(double k) {
    
    double result = evaluate_spline(spline_Omega_P2H, k, acc);

    return result;
}

double evaluate_spline_Omega_P2R(double k) {
    
    double result = evaluate_spline(spline_Omega_P2R, k, acc);

    return result;
}

double evaluate_spline_Omega_PC2(double k) {
    
    double result = evaluate_spline(spline_Omega_PC2, k, acc);

    return result;
}

double evaluate_spline_Omega_P2C(double k) {
    
    double result = evaluate_spline(spline_Omega_P2C, k, acc);

    return result;
}

double evaluate_spline_Omega_P3(double k) {
    
    double result = evaluate_spline(spline_Omega_P3, k, acc);

    return result;
}

double evaluate_spline_Omega_N(double k) {
    
    double result = evaluate_spline(spline_Omega_N, k, acc);

    return result;
}

double evaluate_spline_Omega_NH(double k) {
    
    double result = evaluate_spline(spline_Omega_NH, k, acc);

    return result;
}

double evaluate_spline_Omega_NH2(double k) {
    
    double result = evaluate_spline(spline_Omega_NH2, k, acc);

    return result;
}

double evaluate_spline_Omega_NR(double k) {
    
    double result = evaluate_spline(spline_Omega_NR, k, acc);

    return result;
}

double evaluate_spline_Omega_NRH(double k) {
    
    double result = evaluate_spline(spline_Omega_NRH, k, acc);

    return result;
}

double evaluate_spline_Omega_NR2(double k) {
    
    double result = evaluate_spline(spline_Omega_NR2, k, acc);

    return result;
}

double evaluate_spline_Omega_NZH(double k) {
    
    double result = evaluate_spline(spline_Omega_NZH, k, acc);

    return result;
}

double evaluate_spline_Omega_NZR(double k) {
    
    double result = evaluate_spline(spline_Omega_NZR, k, acc);

    return result;
}

double evaluate_spline_Omega_N2R(double k) {
    
    double result = evaluate_spline(spline_Omega_N2R, k, acc);

    return result;
}

double evaluate_spline_Omega_CZ(double k) {
    
    double result = evaluate_spline(spline_Omega_CZ, k, acc);

    return result;
}

double evaluate_spline_Omega_CZH(double k) {
    
    double result = evaluate_spline(spline_Omega_CZH, k, acc);

    return result;
}

double evaluate_spline_Omega_CZH2(double k) {
    
    double result = evaluate_spline(spline_Omega_CZH2, k, acc);

    return result;
}

double evaluate_spline_Omega_CZHp(double k) {
    
    double result = evaluate_spline(spline_Omega_CZHp, k, acc);

    return result;
}

double evaluate_spline_Omega_CZR(double k) {
    
    double result = evaluate_spline(spline_Omega_CZR, k, acc);

    return result;
}

double evaluate_spline_Omega_CZRH(double k) {
    
    double result = evaluate_spline(spline_Omega_CZRH, k, acc);

    return result;
}

double evaluate_spline_Omega_C2Z(double k) {
    
    double result = evaluate_spline(spline_Omega_C2Z, k, acc);

    return result;
}

double evaluate_spline_Omega_C2ZH(double k) {
    
    double result = evaluate_spline(spline_Omega_C2ZH, k, acc);

    return result;
}

double evaluate_spline_Omega_CZ2(double k) {
    
    double result = evaluate_spline(spline_Omega_CZ2, k, acc);

    return result;
}

double evaluate_spline_Omega_CZ2H(double k) {
    
    double result = evaluate_spline(spline_Omega_CZ2H, k, acc);

    return result;
}

double evaluate_spline_Omega_PZ(double k) {
    
    double result = evaluate_spline(spline_Omega_PZ, k, acc);

    return result;
}

double evaluate_spline_Omega_PZH(double k) {
    
    double result = evaluate_spline(spline_Omega_PZH, k, acc);

    return result;
}

double evaluate_spline_Omega_PZR(double k) {
    
    double result = evaluate_spline(spline_Omega_PZR, k, acc);

    return result;
}

double evaluate_spline_Omega_PZC(double k) {
    
    double result = evaluate_spline(spline_Omega_PZC, k, acc);

    return result;
}

double evaluate_spline_Omega_PZCH(double k) {
    
    double result = evaluate_spline(spline_Omega_PZCH, k, acc);

    return result;
}

double evaluate_spline_Omega_P2Z(double k) {
    
    double result = evaluate_spline(spline_Omega_P2Z, k, acc);

    return result;
}

double evaluate_spline_Omega_PZ2(double k) {
    
    double result = evaluate_spline(spline_Omega_PZ2, k, acc);

    return result;
}

double evaluate_spline_Omega_NC(double k) {
    
    double result = evaluate_spline(spline_Omega_NC, k, acc);

    return result;
}

double evaluate_spline_Omega_NCH(double k) {
    
    double result = evaluate_spline(spline_Omega_NCH, k, acc);

    return result;
}

double evaluate_spline_Omega_NCR(double k) {
    
    double result = evaluate_spline(spline_Omega_NCR, k, acc);

    return result;
}

double evaluate_spline_Omega_NCZH(double k) {
    
    double result = evaluate_spline(spline_Omega_NCZH, k, acc);

    return result;
}

double evaluate_spline_Omega_NC2(double k) {
    
    double result = evaluate_spline(spline_Omega_NC2, k, acc);

    return result;
}

double evaluate_spline_Omega_PN(double k) {
    
    double result = evaluate_spline(spline_Omega_PN, k, acc);

    return result;
}

double evaluate_spline_Omega_PNH(double k) {
    
    double result = evaluate_spline(spline_Omega_PNH, k, acc);

    return result;
}

double evaluate_spline_Omega_PNR(double k) {
    
    double result = evaluate_spline(spline_Omega_PNR, k, acc);

    return result;
}

double evaluate_spline_Omega_PNC(double k) {
    
    double result = evaluate_spline(spline_Omega_PNC, k, acc);

    return result;
}

double evaluate_spline_Omega_P2N(double k) {
    
    double result = evaluate_spline(spline_Omega_P2N, k, acc);

    return result;
}

// Do not use this function
#if 0
int main() {
    FILE *file;
    double x;
    double y;
    char filename[256];
    
    spline_function_initial_all();
    printf("All the splines initialized successfully\n");

    for (int i = 0; i < 777; i++) {
        x = -13.54 + i * (9 / 776.0);
        x = pow(10, x);

        // Test spline_B
        y = gsl_spline_eval(spline_B, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/B.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);
    }

    for (int i = 0; i < 777; i++) {
        x = -4.0 + i * (6.05 / 776.0);

        // Test spline_Omega_G
        y = gsl_spline_eval(spline_Omega_G, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_G.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_H
        y = gsl_spline_eval(spline_Omega_H, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_H2
        y = gsl_spline_eval(spline_Omega_H2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_H2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_H3
        y = gsl_spline_eval(spline_Omega_H3, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_H3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R
        y = gsl_spline_eval(spline_Omega_R, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_RH
        y = gsl_spline_eval(spline_Omega_RH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_RH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_RH2
        y = gsl_spline_eval(spline_Omega_RH2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_RH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R2
        y = gsl_spline_eval(spline_Omega_R2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_R2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R2H
        y = gsl_spline_eval(spline_Omega_R2H, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_R2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_R3
        y = gsl_spline_eval(spline_Omega_R3, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_R3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C
        y = gsl_spline_eval(spline_Omega_C, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_C.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CH
        y = gsl_spline_eval(spline_Omega_CH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CH2
        y = gsl_spline_eval(spline_Omega_CH2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CR
        y = gsl_spline_eval(spline_Omega_CR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CRH
        y = gsl_spline_eval(spline_Omega_CRH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CR2
        y = gsl_spline_eval(spline_Omega_CR2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2
        y = gsl_spline_eval(spline_Omega_C2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_C2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2H
        y = gsl_spline_eval(spline_Omega_C2H, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_C2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2R
        y = gsl_spline_eval(spline_Omega_C2R, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_C2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C3
        y = gsl_spline_eval(spline_Omega_C3, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_C3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z
        y = gsl_spline_eval(spline_Omega_Z, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_Z.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZH
        y = gsl_spline_eval(spline_Omega_ZH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_ZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZH2
        y = gsl_spline_eval(spline_Omega_ZH2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_ZH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZR
        y = gsl_spline_eval(spline_Omega_ZR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_ZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZRH
        y = gsl_spline_eval(spline_Omega_ZRH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_ZRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_ZR2
        y = gsl_spline_eval(spline_Omega_ZR2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_ZR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z2
        y = gsl_spline_eval(spline_Omega_Z2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_Z2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z2H
        y = gsl_spline_eval(spline_Omega_Z2H, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_Z2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z2R
        y = gsl_spline_eval(spline_Omega_Z2R, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_Z2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_Z3
        y = gsl_spline_eval(spline_Omega_Z3, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_Z3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P
        y = gsl_spline_eval(spline_Omega_P, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PH
        y = gsl_spline_eval(spline_Omega_PH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PH2
        y = gsl_spline_eval(spline_Omega_PH2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PR
        y = gsl_spline_eval(spline_Omega_PR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PRH
        y = gsl_spline_eval(spline_Omega_PRH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PR2
        y = gsl_spline_eval(spline_Omega_PR2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PC
        y = gsl_spline_eval(spline_Omega_PC, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PCH
        y = gsl_spline_eval(spline_Omega_PCH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PCH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PCR
        y = gsl_spline_eval(spline_Omega_PCR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PCR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2
        y = gsl_spline_eval(spline_Omega_P2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2H
        y = gsl_spline_eval(spline_Omega_P2H, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2R
        y = gsl_spline_eval(spline_Omega_P2R, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PC2
        y = gsl_spline_eval(spline_Omega_PC2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PC2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2C
        y = gsl_spline_eval(spline_Omega_P2C, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P2C.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P3
        y = gsl_spline_eval(spline_Omega_P3, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P3.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_N
        y = gsl_spline_eval(spline_Omega_N, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_N.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NH
        y = gsl_spline_eval(spline_Omega_NH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NH2
        y = gsl_spline_eval(spline_Omega_NH2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NR
        y = gsl_spline_eval(spline_Omega_NR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NRH
        y = gsl_spline_eval(spline_Omega_NRH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NR2
        y = gsl_spline_eval(spline_Omega_NR2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NR2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NZH
        y = gsl_spline_eval(spline_Omega_NZH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NZR
        y = gsl_spline_eval(spline_Omega_NZR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_N2R
        y = gsl_spline_eval(spline_Omega_N2R, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_N2R.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZ
        y = gsl_spline_eval(spline_Omega_CZ, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZ.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZH
        y = gsl_spline_eval(spline_Omega_CZH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZH2
        y = gsl_spline_eval(spline_Omega_CZH2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZH2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZHp
        y = gsl_spline_eval(spline_Omega_CZHp, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZHp.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZR
        y = gsl_spline_eval(spline_Omega_CZR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZRH
        y = gsl_spline_eval(spline_Omega_CZRH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZRH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2Z
        y = gsl_spline_eval(spline_Omega_C2Z, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_C2Z.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_C2ZH
        y = gsl_spline_eval(spline_Omega_C2ZH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_C2ZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZ2
        y = gsl_spline_eval(spline_Omega_CZ2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZ2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_CZ2H
        y = gsl_spline_eval(spline_Omega_CZ2H, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_CZ2H.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZ
        y = gsl_spline_eval(spline_Omega_PZ, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PZ.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZH
        y = gsl_spline_eval(spline_Omega_PZH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZR
        y = gsl_spline_eval(spline_Omega_PZR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PZR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZC
        y = gsl_spline_eval(spline_Omega_PZC, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PZC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZCH
        y = gsl_spline_eval(spline_Omega_PZCH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PZCH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_P2Z
        y = gsl_spline_eval(spline_Omega_P2Z, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P2Z.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PZ2
        y = gsl_spline_eval(spline_Omega_PZ2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PZ2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NC
        y = gsl_spline_eval(spline_Omega_NC, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NCH
        y = gsl_spline_eval(spline_Omega_NCH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NCH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NCR
        y = gsl_spline_eval(spline_Omega_NCR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NCR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NCZH
        y = gsl_spline_eval(spline_Omega_NCZH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NCZH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_NC2
        y = gsl_spline_eval(spline_Omega_NC2, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_NC2.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PN
        y = gsl_spline_eval(spline_Omega_PN, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PN.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PNH
        y = gsl_spline_eval(spline_Omega_PNH, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PNH.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PNR
        y = gsl_spline_eval(spline_Omega_PNR, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PNR.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PNZH
        y = gsl_spline_eval(spline_Omega_PNC, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_PNC.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);

        // Test spline_Omega_PN2
        y = gsl_spline_eval(spline_Omega_P2N, x, acc);
        snprintf(filename, sizeof(filename), "FNLGNLHNLFunctions/testdat/Omega_P2N.dat");
        file = fopen(filename, "a");
        fprintf(file, "%e %e\n", x, y);
        fclose(file);
    }
}


#endif
