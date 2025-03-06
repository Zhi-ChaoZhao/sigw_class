#ifndef FNLGNLHNL_H
#define FNLGNLHNL_H

typedef struct {
    double sigma;
    double k_;
    double A;
    double nu_s;
    double FNL;
    double FNLls;
    double GNL;
    double GNLlss;
    double GNLlls;
    double HNL;
    double HNLlsss;
    double HNLllss;
    double HNLllls;
    double Fa;
    double Ga;
    double Ha;
} zOpar;

extern double ob(zOpar myzOpar);
extern double ng1(zOpar myzOpar);
extern double total(zOpar myzOpar);

#endif // FNLGNLHNL_H