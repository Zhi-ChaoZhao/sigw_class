from plotfunc import Omega,readdata
import numpy as np
s = 1.0
A_star = 1.0
f_NL = 1.0
k_ = 1.0

k_ = 12.10976
A_star = 3.543613e-06
f_NL = 78.30992

readdata(sigma=s)
myOmega = Omega(k_=k_,sigma=s,A=A_star,FNL=f_NL)
ob = myOmega.ob()
ng1 = myOmega.ng1()
total = myOmega.total()
F1G2H1 = myOmega.F1G2H1()

# fofstar,ob = C_call_ob(sigma=s,A=A_star,FNL=f_NL)
# fofstar,ob2 = C_call_ob(sigma=s,A=A_star*10000,FNL=f_NL)

# fofstar,ng1_over_total = C_call_ng1_over_total(sigma=s,A=A_star,FNL=f_NL)

print("ob: ", ob)
print("ng1: ", ng1)
print("total: ", total)
print("F1G2H1: ", F1G2H1)