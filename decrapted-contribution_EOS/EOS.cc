#include <cmath>
#include <iostream>

using namespace std;

double geff_rho_h(double T) {
  double a[12] = {1.,  1.117240,     3.12672E-01,
                  -4.68049E-02, -2.65004E-02, -1.19760E-03,
                  1.82812E-04,  1.36436E-04,  8.55051E-05,
                  1.22840E-05,  3.82259E-07,  -6.87035E-09};

  double b[12] = {1.43382E-02,  1.37559E-02,  2.92108E-03,
                  -5.38533E-04, -1.62496E-04, -2.87906E-05,
                  -3.84278E-06, 2.78776E-06,  7.40342E-07,
                  1.17210E-07,  3.72499E-09,  -6.74107E-11};

  double t = log(T);
  double x = 1;
  double temp1 = 0, temp2 = 0;
  for (int i = 0; i < 12; i++) {
    temp1 += a[i] * x;
    temp2 += b[i] * x;
    x *= t;
  }

  return temp1 / temp2;
}

double ratio(double T) {
  double a[12] = {1.,  6.07869E-01,  -1.54485E-01,
                  -2.24034E-01, -2.82147E-02, 2.90620E-02,
                  6.86778E-03,  -1.05E-03, -1.69104E-04,
                  1.06301E-05,  1.69528E-06,  -9.33311E-08};

  double b[12] = {7.07388E+01,  9.18011E+01,  3.31892E+01,
                  -1.39779E+00, -1.52558E+00, -1.97857E-02,
                  -1.60146E-01, 8.22615E-05,  2.02651E-02,
                  -1.82134E-05, 7.83943E-05,  7.13518E-05};

  double t = log(T);
  double x = 1;
  double temp1 = 0, temp2 = 0;
  for (int i = 0; i < 12; i++) {
    temp1 += a[i] * x;
    temp2 += b[i] * x;
    x *= t;
  }

  return temp1 / temp2 + 1;
}

double geff_s_h(double T) { return 1 / ratio(T) * geff_rho_h(T); }
double fr(double x) {
  return exp(-1.04855 * x) *
         (1 + 1.03757 * x + 0.508630 * x * x + 0.0893988 * x * x * x);
}

double br(double x) {
  return exp(-1.03149 * x) *
         (1 + 1.03317 * x + 0.398264 * x * x + 0.0648056 * x * x * x);
}

double fs(double x) {
  return exp(-1.04190 * x) *
         (1. + 1.03400 * x + 0.456426 * x * x + 0.0595248 * x * x * x);
}

double bs(double x) {
  return exp(-1.03365 * x) *
         (1. + 1.03397 * x + 0.342548 * x * x + 0.0506182 * x * x * x);
}

double Sfit(double x) {
  return 1. +
         7. / 4. * exp(-1.0419 * x) *
             (1. + 1.034 * x + 0.456426 * x * x + 0.0595249 * x * x * x);
}

double geff_rho_l(double T, double p1 = 1, double p2 = 1) {
  double me = 511e-6, mmu = 0.1056, mpi0 = 0.135, mpip = 0.140, m1 = 0.5,
         m2 = 0.77, m3 = 1.2, m4 = 2.0;

  return 2.030 + 1.353 * pow(Sfit(me / T), 4. / 3.) + 3.495 * fr(me / T) +
         3.446 * fr(mmu / T) + 1.05 * br(mpi0 / T) + 2.08 * br(mpip / T) +
         4.165 * br(m1 / T) + 30.55 * br(m2 / T) + 89.4 * br(p2 * m3 / T) +
         8209 * br(p2 * m4 / T);
}

double geff_s_l(double T, double p1 = 1, double p2 = 1) {
  double me = 511e-6, mmu = 0.1056, mpi0 = 0.135, mpip = 0.140, m1 = 0.5,
         m2 = 0.77, m3 = 1.2, m4 = 2.0;

  return 2.008 + 1.923 * pow(Sfit(me / T), 1.) + 3.442 * fs(me / T) +
         3.468 * fs(mmu / T) + 1.034 * bs(mpi0 / T) + 2.068 * bs(mpip / T) +
         4.160 * bs(m1 / T) + 30.55 * bs(m2 / T) + 90 * bs(p2 * m3 / T) +
         6209 * br(p2 * m4 / T); // p1*181.7*bs(p2*m3/T);
}

double geff_rho(double T) {
  if (T < 0.12)
    return geff_rho_l(T);
  return geff_rho_h(T);
}
double geff_s(double T) {
  if (T < 0.12)
    return geff_s_l(T);
  return geff_s_h(T);
}

int main() {

  for (double T = 1e-6; T < 1e15; T *= 1.1) {
    cout << T << " " << geff_rho(T) << " " << geff_s(T) << endl;
  }
}
