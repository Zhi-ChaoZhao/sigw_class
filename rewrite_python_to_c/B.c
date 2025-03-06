#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <gsl/gsl_interp.h>
#include <gsl/gsl_spline.h>

#define DATA_POINTS 10000

double f_ggf[zzc_B_DATA_POINTS];
double B_ggf[zzc_B_DATA_POINTS];

void load_data() {
    FILE *file = fopen("ggf.dat", "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < zzc_B_DATA_POINTS; i++) {
        if (fscanf(file, "%lf %lf", &f_ggf[i], &B_ggf[i]) != 2) {
            perror("Error reading file");
            fclose(file);
            exit(EXIT_FAILURE);
        }
    }

    fclose(file);
}


gsl_interp_accel *acc;
gsl_spline *spline;

void initialize_interpolation() {
    acc = gsl_interp_accel_alloc();
    spline = gsl_spline_alloc(gsl_interp_linear, zzc_B_DATA_POINTS);
    gsl_spline_init(spline, f_ggf, B_ggf, zzc_B_DATA_POINTS);
}

double interpolate(double x) {
    if (x <= f_ggf[0]) {
        return B_ggf[0];
    }
    if (x >= f_ggf[zzc_B_DATA_POINTS - 1]) {
        return B_ggf[zzc_B_DATA_POINTS - 1];
    }
    return gsl_spline_eval(spline, x, acc);
}

void B(double x, double *result) {
    *result = interpolate(x);
}

void free_interpolation() {
    gsl_spline_free(spline);
    gsl_interp_accel_free(acc);
}

int main() {
    load_data();
    initialize_interpolation(); // Initialize interpolation

    double f_low = 2.83417588723006e-14;
    double f_high = 2.6275163539064474e9;
    int total_points = 9988;
    double log_f_low = log10(f_low);
    double log_f_high = log10(f_high);
    double step = (log_f_high - log_f_low) / total_points;
    for (int i = 0; i < total_points; i++) {
        double log_f = log_f_low + i * step;
        double f = pow(10, log_f);
        double B = interpolate(f);
        printf("%e %e\n", f, B);
    }

    free_interpolation(); // Free interpolation resources
    return 0;
}
