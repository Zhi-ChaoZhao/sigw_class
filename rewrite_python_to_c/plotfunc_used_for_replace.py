def Gs(self):
    return 2*OmG[self.sigma](self.k_)

def F2(self):
    return 8*(2*OmC[self.sigma](self.k_) + OmH[self.sigma](self.k_) + 2*OmZ[self.sigma](self.k_))

def F4(self):
    return 8*(2*OmN[self.sigma](self.k_) + 4*OmP[self.sigma](self.k_) + OmR[self.sigma](self.k_))

def G1(self):
    return 24*OmG[self.sigma](self.k_)

def G2(self):
    return 12*(6*OmC2[self.sigma](self.k_) + 9*OmG[self.sigma](self.k_) + 2*OmH2[self.sigma](self.k_) + 6*OmZ2[self.sigma](self.k_))

def G3(self):
    return 72*(6*OmC2[self.sigma](self.k_) + 12*OmCZH[self.sigma](self.k_) + 3*OmG[self.sigma](self.k_) + 2*OmH2[self.sigma](self.k_) + 6*OmZ2[self.sigma](self.k_))

def G4(self):
    return 18*(36*OmC2[self.sigma](self.k_) + 144*OmCZH[self.sigma](self.k_) + 9*OmG[self.sigma](self.k_) + 12*OmH2[self.sigma](self.k_) + 36*OmNR[self.sigma](self.k_) + 36*OmP2[self.sigma](self.k_) + 72*OmPN[self.sigma](self.k_) + 36*OmPR[self.sigma](self.k_) + 4*OmR2[self.sigma](self.k_) + 36*OmZ2[self.sigma](self.k_))

def H2(self):
    return 96*(6*OmC[self.sigma](self.k_) + 4*OmC3[self.sigma](self.k_) + 3*OmH[self.sigma](self.k_) + OmH3[self.sigma](self.k_) + 6*OmZ[self.sigma](self.k_) + 4*OmZ3[self.sigma](self.k_))

def H4(self):
    return 1152*(36*OmC2R[self.sigma](self.k_) + 144*OmCZHp[self.sigma](self.k_) + 96*OmCZRH[self.sigma](self.k_) + 18*OmN[self.sigma](self.k_) + 18*OmN2R[self.sigma](self.k_) + 72*OmNC2[self.sigma](self.k_) + 144*OmNCZH[self.sigma](self.k_) + 48*OmNH2[self.sigma](self.k_) + 16*OmNR2[self.sigma](self.k_) + 36*OmP[self.sigma](self.k_) + 72*OmP2N[self.sigma](self.k_) + 36*OmP2R[self.sigma](self.k_) + 16*OmP3[self.sigma](self.k_) + 48*OmPC2[self.sigma](self.k_) + 48*OmPH2[self.sigma](self.k_) + 144*OmPNR[self.sigma](self.k_) + 16*OmPR2[self.sigma](self.k_) + 144*OmPZ2[self.sigma](self.k_) + 288*OmPZCH[self.sigma](self.k_) + 9*OmR[self.sigma](self.k_) + OmR3[self.sigma](self.k_) + 6*OmRH2[self.sigma](self.k_) + 36*OmZ2R[self.sigma](self.k_))

def F2G1(self):
    return 48*(2*OmC[self.sigma](self.k_) + 2*OmCH[self.sigma](self.k_) + 4*OmCZ[self.sigma](self.k_) + OmH[self.sigma](self.k_) + 2*OmZ[self.sigma](self.k_) + 2*OmZH[self.sigma](self.k_))

def F2G2(self):
    return 24*(6*OmC[self.sigma](self.k_) + 12*OmCH[self.sigma](self.k_) + 6*OmCR[self.sigma](self.k_) + 24*OmCZ[self.sigma](self.k_) + 3*OmH[self.sigma](self.k_) + 12*OmNC[self.sigma](self.k_) + 12*OmNH[self.sigma](self.k_) + 12*OmPC[self.sigma](self.k_) + 12*OmPH[self.sigma](self.k_) + 24*OmPZ[self.sigma](self.k_) + 2*OmRH[self.sigma](self.k_) + 6*OmZ[self.sigma](self.k_) + 12*OmZH[self.sigma](self.k_) + 6*OmZR[self.sigma](self.k_))

def F1H1(self):
    return 96*(2*OmC[self.sigma](self.k_) + OmH[self.sigma](self.k_) + 2*OmZ[self.sigma](self.k_))

def F3H1(self):
    return 192*(4*OmCZHp[self.sigma](self.k_) + 2*OmN[self.sigma](self.k_) + 4*OmP[self.sigma](self.k_) + OmR[self.sigma](self.k_))

def F2H2(self):
    return 192*(6*OmC2R[self.sigma](self.k_) + 72*OmCZHp[self.sigma](self.k_) + 18*OmN[self.sigma](self.k_) + 12*OmNC2[self.sigma](self.k_) + 8*OmNH2[self.sigma](self.k_) + 36*OmP[self.sigma](self.k_) + 8*OmPC2[self.sigma](self.k_) + 8*OmPH2[self.sigma](self.k_) + 24*OmPZ2[self.sigma](self.k_) + 9*OmR[self.sigma](self.k_) + OmRH2[self.sigma](self.k_) + 6*OmZ2R[self.sigma](self.k_))

def F1H3(self):
    return 2304*(6*OmC2R[self.sigma](self.k_) + 36*OmCZHp[self.sigma](self.k_) + 8*OmCZRH[self.sigma](self.k_) + 6*OmN[self.sigma](self.k_) + 12*OmNC2[self.sigma](self.k_) + 12*OmNCZH[self.sigma](self.k_) + 8*OmNH2[self.sigma](self.k_) + 12*OmP[self.sigma](self.k_) + 8*OmPC2[self.sigma](self.k_) + 8*OmPH2[self.sigma](self.k_) + 24*OmPZ2[self.sigma](self.k_) + 24*OmPZCH[self.sigma](self.k_) + 3*OmR[self.sigma](self.k_) + OmRH2[self.sigma](self.k_) + 6*OmZ2R[self.sigma](self.k_))

def G1H2(self):
    return 576*(6*OmC[self.sigma](self.k_) + 6*OmC2H[self.sigma](self.k_) + 12*OmC2Z[self.sigma](self.k_) + 12*OmC2ZH[self.sigma](self.k_) + 4*OmC3[self.sigma](self.k_) + 6*OmCH[self.sigma](self.k_) + 4*OmCH2[self.sigma](self.k_) + 12*OmCZ[self.sigma](self.k_) + 12*OmCZ2[self.sigma](self.k_) + 12*OmCZ2H[self.sigma](self.k_) + 8*OmCZH2[self.sigma](self.k_) + 3*OmH[self.sigma](self.k_) + OmH3[self.sigma](self.k_) + 6*OmZ[self.sigma](self.k_) + 6*OmZ2H[self.sigma](self.k_) + 4*OmZ3[self.sigma](self.k_) + 6*OmZH[self.sigma](self.k_) + 4*OmZH2[self.sigma](self.k_))

def G2H2(self):
    return 288*(18*OmC[self.sigma](self.k_) + 36*OmC2H[self.sigma](self.k_) + 72*OmC2Z[self.sigma](self.k_) + 72*OmC2ZH[self.sigma](self.k_) + 12*OmC3[self.sigma](self.k_) + 36*OmCH[self.sigma](self.k_) + 24*OmCH2[self.sigma](self.k_) + 18*OmCR[self.sigma](self.k_) + 8*OmCR2[self.sigma](self.k_) + 24*OmCRH[self.sigma](self.k_) + 72*OmCZ[self.sigma](self.k_) + 72*OmCZ2[self.sigma](self.k_) + 72*OmCZ2H[self.sigma](self.k_) + 48*OmCZH2[self.sigma](self.k_) + 72*OmCZR[self.sigma](self.k_) + 9*OmH[self.sigma](self.k_) + 3*OmH3[self.sigma](self.k_) + 36*OmNC[self.sigma](self.k_) + 144*OmNCH[self.sigma](self.k_) + 72*OmNCR[self.sigma](self.k_) + 36*OmNH[self.sigma](self.k_) + 24*OmNRH[self.sigma](self.k_) + 36*OmNZH[self.sigma](self.k_) + 36*OmNZR[self.sigma](self.k_) + 24*OmP2C[self.sigma](self.k_) + 36*OmP2H[self.sigma](self.k_) + 72*OmP2Z[self.sigma](self.k_) + 36*OmPC[self.sigma](self.k_) + 72*OmPCH[self.sigma](self.k_) + 36*OmPCR[self.sigma](self.k_) + 36*OmPH[self.sigma](self.k_) + 72*OmPNC[self.sigma](self.k_) + 144*OmPNH[self.sigma](self.k_) + 24*OmPRH[self.sigma](self.k_) + 72*OmPZ[self.sigma](self.k_) + 144*OmPZC[self.sigma](self.k_) + 144*OmPZH[self.sigma](self.k_) + 72*OmPZR[self.sigma](self.k_) + 2*OmR2H[self.sigma](self.k_) + 6*OmRH[self.sigma](self.k_) + 18*OmZ[self.sigma](self.k_) + 36*OmZ2H[self.sigma](self.k_) + 12*OmZ3[self.sigma](self.k_) + 36*OmZH[self.sigma](self.k_) + 24*OmZH2[self.sigma](self.k_) + 18*OmZR[self.sigma](self.k_) + 8*OmZR2[self.sigma](self.k_) + 24*OmZRH[self.sigma](self.k_))

def F1G1H1(self):
    return 192*(6*OmC[self.sigma](self.k_) + 3*OmC2H[self.sigma](self.k_) + 6*OmC2Z[self.sigma](self.k_) + 6*OmCH[self.sigma](self.k_) + 2*OmCH2[self.sigma](self.k_) + 12*OmCZ[self.sigma](self.k_) + 6*OmCZ2[self.sigma](self.k_) + 3*OmH[self.sigma](self.k_) + 6*OmZ[self.sigma](self.k_) + 3*OmZ2H[self.sigma](self.k_) + 6*OmZH[self.sigma](self.k_) + 2*OmZH2[self.sigma](self.k_))

def F1G2H1(self):
    return 288*(6*OmC[self.sigma](self.k_) + 6*OmC2H[self.sigma](self.k_) + 12*OmC2Z[self.sigma](self.k_) + 12*OmCH[self.sigma](self.k_) + 4*OmCH2[self.sigma](self.k_) + 6*OmCR[self.sigma](self.k_) + 4*OmCRH[self.sigma](self.k_) + 24*OmCZ[self.sigma](self.k_) + 12*OmCZ2[self.sigma](self.k_) + 12*OmCZR[self.sigma](self.k_) + 3*OmH[self.sigma](self.k_) + 12*OmNC[self.sigma](self.k_) + 24*OmNCH[self.sigma](self.k_) + 12*OmNH[self.sigma](self.k_) + 6*OmNZH[self.sigma](self.k_) + 12*OmPC[self.sigma](self.k_) + 12*OmPCH[self.sigma](self.k_) + 12*OmPH[self.sigma](self.k_) + 24*OmPZ[self.sigma](self.k_) + 24*OmPZC[self.sigma](self.k_) + 24*OmPZH[self.sigma](self.k_) + 2*OmRH[self.sigma](self.k_) + 6*OmZ[self.sigma](self.k_) + 6*OmZ2H[self.sigma](self.k_) + 12*OmZH[self.sigma](self.k_) + 4*OmZH2[self.sigma](self.k_) + 6*OmZR[self.sigma](self.k_) + 4*OmZRH[self.sigma](self.k_))

def Glike(self):
    return 2*Power(self.A,2)*Power(1 + 3*self.A*self.GNL,4)*OmG[self.sigma](self.k_) + 8*Power(self.A,3)*Power(1 + 3*self.A*self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmH[self.sigma](self.k_) + 24*Power(self.A,4)*Power(self.GNL,2)*Power(1 + 3*self.A*self.GNL,2)*OmH2[self.sigma](self.k_) + 96*Power(self.A,5)*Power(self.HNL + 3*self.A*self.GNL*self.HNL,2)*OmH3[self.sigma](self.k_) + 8*Power(self.A,4)*Power(self.FNL + 6*self.A*self.HNL,4)*OmR[self.sigma](self.k_) + 72*Power(self.A,6)*Power(self.GNL,4)*OmR2[self.sigma](self.k_) + 576*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmR2H[self.sigma](self.k_) + 1152*Power(self.A,8)*Power(self.HNL,4)*OmR3[self.sigma](self.k_) + 48*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmRH[self.sigma](self.k_) + 192*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmRH2[self.sigma](self.k_)
    
def Clike(self):
    return 16*Power(self.A,3)*Power(1 + 3*self.A*self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmC[self.sigma](self.k_) + 72*Power(self.A,4)*Power(self.GNL,2)*Power(1 + 3*self.A*self.GNL,2)*OmC2[self.sigma](self.k_) + 576*Power(self.A,5)*self.GNL*(1 + 3*self.A*self.GNL)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmC2H[self.sigma](self.k_) + 1152*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmC2R[self.sigma](self.k_) + 384*Power(self.A,5)*Power(self.HNL + 3*self.A*self.GNL*self.HNL,2)*OmC3[self.sigma](self.k_) + 96*Power(self.A,4)*self.GNL*(1 + 3*self.A*self.GNL)*Power(self.FNL + 6*self.A*self.HNL,2)*OmCH[self.sigma](self.k_) + 384*Power(self.A,5)*self.GNL*(1 + 3*self.A*self.GNL)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmCH2[self.sigma](self.k_) + 144*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmCR[self.sigma](self.k_) + 2304*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmCR2[self.sigma](self.k_) + 1152*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmCRH[self.sigma](self.k_)

def Zlike(self):
    return 16*Power(self.A,3)*Power(1 + 3*self.A*self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmZ[self.sigma](self.k_) + 72*Power(self.A,4)*Power(self.GNL,2)*Power(1 + 3*self.A*self.GNL,2)*OmZ2[self.sigma](self.k_) + 576*Power(self.A,5)*self.GNL*(1 + 3*self.A*self.GNL)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmZ2H[self.sigma](self.k_) + 1152*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmZ2R[self.sigma](self.k_) + 384*Power(self.A,5)*Power(self.HNL + 3*self.A*self.GNL*self.HNL,2)*OmZ3[self.sigma](self.k_) + 96*Power(self.A,4)*self.GNL*(1 + 3*self.A*self.GNL)*Power(self.FNL + 6*self.A*self.HNL,2)*OmZH[self.sigma](self.k_) + 384*Power(self.A,5)*self.GNL*(1 + 3*self.A*self.GNL)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmZH2[self.sigma](self.k_) + 144*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmZR[self.sigma](self.k_) + 2304*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmZR2[self.sigma](self.k_) + 1152*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmZRH[self.sigma](self.k_)

def Plike(self):
    return 32*Power(self.A,4)*Power(self.FNL + 6*self.A*self.HNL,4)*OmP[self.sigma](self.k_) + 648*Power(self.A,6)*Power(self.GNL,4)*OmP2[self.sigma](self.k_) + 6912*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmP2C[self.sigma](self.k_) + 10368*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmP2H[self.sigma](self.k_) + 41472*Power(self.A,8)*Power(self.HNL,4)*OmP2R[self.sigma](self.k_) + 18432*Power(self.A,8)*Power(self.HNL,4)*OmP3[self.sigma](self.k_) + 288*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmPC[self.sigma](self.k_) + 1536*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmPC2[self.sigma](self.k_) + 3456*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmPCH[self.sigma](self.k_) + 10368*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmPCR[self.sigma](self.k_) + 288*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmPH[self.sigma](self.k_) + 1536*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmPH2[self.sigma](self.k_) + 648*Power(self.A,6)*Power(self.GNL,4)*OmPR[self.sigma](self.k_) + 18432*Power(self.A,8)*Power(self.HNL,4)*OmPR2[self.sigma](self.k_) + 6912*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmPRH[self.sigma](self.k_)
    
def Nlike(self):
    return 16*Power(self.A,4)*Power(self.FNL + 6*self.A*self.HNL,4)*OmN[self.sigma](self.k_) + 20736*Power(self.A,8)*Power(self.HNL,4)*OmN2R[self.sigma](self.k_) + 288*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmNH[self.sigma](self.k_) + 1536*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmNH2[self.sigma](self.k_) + 648*Power(self.A,6)*Power(self.GNL,4)*OmNR[self.sigma](self.k_) + 18432*Power(self.A,8)*Power(self.HNL,4)*OmNR2[self.sigma](self.k_) + 6912*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmNRH[self.sigma](self.k_) + 1728*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmNZH[self.sigma](self.k_) + 10368*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmNZR[self.sigma](self.k_)

def CZlike(self):
    return 1152*Power(self.A,5)*self.GNL*(1 + 3*self.A*self.GNL)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmC2Z[self.sigma](self.k_) + 6912*Power(self.A,6)*self.GNL*(1 + 3*self.A*self.GNL)*Power(self.HNL,2)*OmC2ZH[self.sigma](self.k_) + 192*Power(self.A,4)*self.GNL*(1 + 3*self.A*self.GNL)*Power(self.FNL + 6*self.A*self.HNL,2)*OmCZ[self.sigma](self.k_) + 1152*Power(self.A,5)*self.GNL*(1 + 3*self.A*self.GNL)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmCZ2[self.sigma](self.k_) + 6912*Power(self.A,6)*self.GNL*(1 + 3*self.A*self.GNL)*Power(self.HNL,2)*OmCZ2H[self.sigma](self.k_) + 864*Power(self.A,5)*Power(self.GNL,3)*(1 + 3*self.A*self.GNL)*OmCZH[self.sigma](self.k_) + 4608*Power(self.A,6)*self.GNL*(1 + 3*self.A*self.GNL)*Power(self.HNL,2)*OmCZH2[self.sigma](self.k_) + 768*Power(self.A,5)*self.HNL*Power(self.FNL + 6*self.A*self.HNL,3)*OmCZHp[self.sigma](self.k_) + 3456*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmCZR[self.sigma](self.k_) + 18432*Power(self.A,7)*Power(self.HNL,3)*(self.FNL + 6*self.A*self.HNL)*OmCZRH[self.sigma](self.k_)

def PZlike(self):
    return 20736*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmP2Z[self.sigma](self.k_) + 576*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmPZ[self.sigma](self.k_) + 4608*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmPZ2[self.sigma](self.k_) + 6912*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmPZC[self.sigma](self.k_) + 55296*Power(self.A,7)*Power(self.HNL,3)*(self.FNL + 6*self.A*self.HNL)*OmPZCH[self.sigma](self.k_) + 6912*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmPZH[self.sigma](self.k_) + 20736*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmPZR[self.sigma](self.k_)

def NClike(self):
    return 288*Power(self.A,5)*Power(self.GNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmNC[self.sigma](self.k_) + 2304*Power(self.A,6)*Power(self.HNL,2)*Power(self.FNL + 6*self.A*self.HNL,2)*OmNC2[self.sigma](self.k_) + 6912*Power(self.A,6)*Power(self.GNL,2)*self.HNL*(self.FNL + 6*self.A*self.HNL)*OmNCH[self.sigma](self.k_) + 20736*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmNCR[self.sigma](self.k_) + 27648*Power(self.A,7)*Power(self.HNL,3)*(self.FNL + 6*self.A*self.HNL)*OmNCZH[self.sigma](self.k_)

def PNlike(self):
    return 82944*Power(self.A,8)*Power(self.HNL,4)*OmP2N[self.sigma](self.k_) + 1296*Power(self.A,6)*Power(self.GNL,4)*OmPN[self.sigma](self.k_) + 20736*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmPNC[self.sigma](self.k_) + 41472*Power(self.A,7)*Power(self.GNL,2)*Power(self.HNL,2)*OmPNH[self.sigma](self.k_) + 165888*Power(self.A,8)*Power(self.HNL,4)*OmPNR[self.sigma](self.k_)

def power_spec(self):
    value = self.A*np.power(1 + 3*self.A*self.GNL,2)*P1(self.k_,self.sigma) + 2*np.power(self.A,2)*np.power(self.FNL + 6*self.A*self.HNL,2)*P2(self.k_,self.sigma) + 6*np.power(self.A,3)*np.power(self.GNL,2)*P3(self.k_,self.sigma) + 24*np.power(self.A,4)*np.power(self.HNL,2)*P4(self.k_,self.sigma)
    value *= self.k_**3 / (2 * np.pi)
    return value


def total(self): 

        # if FNL**2 * A > 1 or GNL**2 * A > FNL**2 or:
            # print('Warning: Perturbativity Violating. ',A,FNL,GNL)
        value = self.Glike() + self.Clike() + self.Zlike() + self.Plike() + self.Nlike() + self.CZlike() + self.PZlike() + self.NClike() + self.PNlike() 
        # value = 
        return value

def tot_test(self): 

        value = (Power(self.A,3)*(Power(self.FNL,2)*super().F2() + self.GNL*super().G1()) + Power(self.A,4)*(self.FNL*self.HNL*super().F1H1() + Power(self.FNL,2)*self.GNL*super().F2G1() + Power(self.FNL,4)*super().F4() + Power(self.GNL,2)*super().G2()) + Power(self.A,7)*(self.FNL*Power(self.HNL,3)*super().F1H3() + Power(self.GNL,2)*Power(self.HNL,2)*super().G2H2()) + Power(self.A,6)*(self.FNL*Power(self.GNL,2)*self.HNL*super().F1G2H1() + Power(self.FNL,2)*Power(self.HNL,2)*super().F2H2() + self.GNL*Power(self.HNL,2)*super().G1H2() + Power(self.GNL,4)*super().G4()) + Power(self.A,2)*super().Gs() + Power(self.A,5)*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.FNL,2)*Power(self.GNL,2)*super().F2G2() + Power(self.FNL,3)*self.HNL*super().F3H1() + Power(self.GNL,3)*super().G3() + Power(self.HNL,2)*super().H2()) + Power(self.A,8)*Power(self.HNL,4)*super().H4())
        return value


def ob(self):
    return Trf * self.total()


def ng1(self):

        value = (Power(self.A,3)*(6*self.FNL*self.GNLlss*super().F2() + 4*self.HNLlsss*super().G1() + self.FNLls*(4*Power(self.FNL,2)*super().F2() + 6*self.GNL*super().G1())) + Power(self.A,7)*(3*self.GNLlss*Power(self.HNL,3)*super().F1H3() + 8*self.GNL*Power(self.HNL,2)*self.HNLlsss*super().G2H2()) + Power(self.A,4)*(3*self.GNLlss*(self.HNL*super().F1H1() + 2*self.FNL*self.GNL*super().F2G1() + 4*Power(self.FNL,3)*super().F4()) + self.HNLlsss*(4*Power(self.FNL,2)*super().F2G1() + 8*self.GNL*super().G2()) + self.FNLls*(4*self.FNL*self.HNL*super().F1H1() + 2*Power(self.FNL,2)*self.GNL*super().F2G1() + 4*Power(self.GNL,2)*super().G2())) + Power(self.A,6)*(3*self.GNLlss*self.HNL*(Power(self.GNL,2)*super().F1G2H1() + 2*self.FNL*self.HNL*super().F2H2()) + 2*self.FNLls*self.GNL*Power(self.HNL,2)*super().G1H2() + 4*self.HNLlsss*(2*self.FNL*self.GNL*self.HNL*super().F1G2H1() + Power(self.HNL,2)*super().G1H2() + 4*Power(self.GNL,3)*super().G4())) + 8*Power(self.A,2)*self.FNLls*super().Gs() + Power(self.A,5)*(self.GNLlss*(3*self.GNL*self.HNL*super().F1G1H1() + 6*self.FNL*Power(self.GNL,2)*super().F2G2() + 9*Power(self.FNL,2)*self.HNL*super().F3H1()) + 4*self.HNLlsss*(self.FNL*self.HNL*super().F1G1H1() + 2*Power(self.FNL,2)*self.GNL*super().F2G2() + 3*Power(self.GNL,2)*super().G3()) + 2*self.FNLls*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.GNL,3)*super().G3() + 2*Power(self.HNL,2)*super().H2())))
        return value


def ng2(self):

        value = (Power(self.A,3)*(9*Power(self.GNLlss,2)*super().F2() + 24*self.FNL*self.HNLllss*super().F2() + 4*Power(self.FNLls,2)*(Power(self.FNL,2)*super().F2() + 3*self.GNL*super().G1()) + 6*self.GNLlls*(2*Power(self.FNL,2)*super().F2() + 3*self.GNL*super().G1()) + self.FNLls*(24*self.FNL*self.GNLlss*super().F2() + 24*self.HNLlsss*super().G1())) + Power(self.A,7)*(12*Power(self.HNL,3)*self.HNLllss*super().F1H3() + 16*Power(self.HNL,2)*Power(self.HNLlsss,2)*super().G2H2()) + Power(self.A,4)*(24*self.FNL*self.GNLlss*self.HNLlsss*super().F2G1() + 9*Power(self.GNLlss,2)*(self.GNL*super().F2G1() + 6*Power(self.FNL,2)*super().F4()) + 12*self.HNLllss*(self.HNL*super().F1H1() + 2*self.FNL*self.GNL*super().F2G1() + 4*Power(self.FNL,3)*super().F4()) + 16*Power(self.HNLlsss,2)*super().G2() + 4*Power(self.FNLls,2)*(self.FNL*self.HNL*super().F1H1() + Power(self.GNL,2)*super().G2()) + 6*self.GNLlls*(2*self.FNL*self.HNL*super().F1H1() + Power(self.FNL,2)*self.GNL*super().F2G1() + 2*Power(self.GNL,2)*super().G2()) + self.FNLls*(12*self.GNLlss*(self.HNL*super().F1H1() + self.FNL*self.GNL*super().F2G1()) + 8*self.HNLlsss*(Power(self.FNL,2)*super().F2G1() + 4*self.GNL*super().G2()))) + Power(self.A,6)*(24*self.GNL*self.GNLlss*self.HNL*self.HNLlsss*super().F1G2H1() + 9*Power(self.GNLlss,2)*Power(self.HNL,2)*super().F2H2() + 12*self.HNL*self.HNLllss*(Power(self.GNL,2)*super().F1G2H1() + 2*self.FNL*self.HNL*super().F2H2()) + 6*self.GNL*self.GNLlls*Power(self.HNL,2)*super().G1H2() + 8*self.FNLls*Power(self.HNL,2)*self.HNLlsss*super().G1H2() + 16*Power(self.HNLlsss,2)*(self.FNL*self.HNL*super().F1G2H1() + 6*Power(self.GNL,2)*super().G4())) + Power(self.A,2)*(24*Power(self.FNLls,2)*super().Gs() + 24*self.GNLlls*super().Gs()) + Power(self.A,5)*(12*self.GNLlss*self.HNLlsss*(self.HNL*super().F1G1H1() + 4*self.FNL*self.GNL*super().F2G2()) + 9*Power(self.GNLlss,2)*(Power(self.GNL,2)*super().F2G2() + 3*self.FNL*self.HNL*super().F3H1()) + 12*self.HNLllss*(self.GNL*self.HNL*super().F1G1H1() + 2*self.FNL*Power(self.GNL,2)*super().F2G2() + 3*Power(self.FNL,2)*self.HNL*super().F3H1()) + 16*Power(self.HNLlsss,2)*(Power(self.FNL,2)*super().F2G2() + 3*self.GNL*super().G3()) + self.FNLls*(6*self.GNL*self.GNLlss*self.HNL*super().F1G1H1() + 8*self.HNLlsss*(self.FNL*self.HNL*super().F1G1H1() + 3*Power(self.GNL,2)*super().G3())) + 4*Power(self.FNLls,2)*Power(self.HNL,2)*super().H2() + 6*self.GNLlls*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.GNL,3)*super().G3() + 2*Power(self.HNL,2)*super().H2())))
        return value

    
def ng3(self):

        value = (Power(self.A,3)*(self.GNLlss*(72*self.FNL*self.GNLlls*super().F2() + 72*self.HNLllss*super().F2()) + 8*Power(self.FNLls,3)*self.GNL*super().G1() + 72*self.GNLlls*self.HNLlsss*super().G1() + self.HNLllls*(48*Power(self.FNL,2)*super().F2() + 72*self.GNL*super().G1()) + Power(self.FNLls,2)*(24*self.FNL*self.GNLlss*super().F2() + 48*self.HNLlsss*super().G1()) + self.FNLls*(36*Power(self.GNLlss,2)*super().F2() + 96*self.FNL*self.HNLllss*super().F2() + 24*self.GNLlls*(Power(self.FNL,2)*super().F2() + 3*self.GNL*super().G1()))) + Power(self.A,4)*(36*Power(self.GNLlss,2)*self.HNLlsss*super().F2G1() + 96*self.FNL*self.HNLllss*self.HNLlsss*super().F2G1() + 108*self.FNL*Power(self.GNLlss,3)*super().F4() + self.GNLlss*(36*self.GNLlls*(self.HNL*super().F1H1() + self.FNL*self.GNL*super().F2G1()) + 72*self.HNLllss*(self.GNL*super().F2G1() + 6*Power(self.FNL,2)*super().F4())) + 24*self.GNLlls*self.HNLlsss*(Power(self.FNL,2)*super().F2G1() + 4*self.GNL*super().G2()) + 24*self.HNLllls*(2*self.FNL*self.HNL*super().F1H1() + Power(self.FNL,2)*self.GNL*super().F2G1() + 2*Power(self.GNL,2)*super().G2()) + Power(self.FNLls,2)*(12*self.GNLlss*self.HNL*super().F1H1() + 32*self.GNL*self.HNLlsss*super().G2()) + self.FNLls*(18*self.GNL*Power(self.GNLlss,2)*super().F2G1() + 48*self.FNL*self.GNLlss*self.HNLlsss*super().F2G1() + 48*self.HNLllss*(self.HNL*super().F1H1() + self.FNL*self.GNL*super().F2G1()) + 64*Power(self.HNLlsss,2)*super().G2() + 24*self.GNLlls*(self.FNL*self.HNL*super().F1H1() + Power(self.GNL,2)*super().G2()))) + Power(self.A,6)*(96*self.GNL*self.HNL*self.HNLllss*self.HNLlsss*super().F1G2H1() + self.GNLlss*(48*self.HNL*Power(self.HNLlsss,2)*super().F1G2H1() + 72*Power(self.HNL,2)*self.HNLllss*super().F2H2()) + 24*self.GNL*Power(self.HNL,2)*self.HNLllls*super().G1H2() + 24*self.GNLlls*Power(self.HNL,2)*self.HNLlsss*super().G1H2() + 256*self.GNL*Power(self.HNLlsss,3)*super().G4()) + Power(self.A,2)*(32*Power(self.FNLls,3)*super().Gs() + 144*self.FNLls*self.GNLlls*super().Gs() + 96*self.HNLllls*super().Gs()) + Power(self.A,5)*(72*self.GNL*Power(self.GNLlss,2)*self.HNLlsss*super().F2G2() + 48*self.HNLllss*self.HNLlsss*(self.HNL*super().F1G1H1() + 4*self.FNL*self.GNL*super().F2G2()) + 27*Power(self.GNLlss,3)*self.HNL*super().F3H1() + self.GNLlss*(18*self.GNL*self.GNLlls*self.HNL*super().F1G1H1() + 96*self.FNL*Power(self.HNLlsss,2)*super().F2G2() + 72*self.HNLllss*(Power(self.GNL,2)*super().F2G2() + 3*self.FNL*self.HNL*super().F3H1())) + 64*Power(self.HNLlsss,3)*super().G3() + 24*self.GNLlls*self.HNLlsss*(self.FNL*self.HNL*super().F1G1H1() + 3*Power(self.GNL,2)*super().G3()) + 24*self.HNLllls*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.GNL,3)*super().G3() + 2*Power(self.HNL,2)*super().H2()) + self.FNLls*(24*self.GNL*self.HNL*self.HNLllss*super().F1G1H1() + 24*self.GNLlss*self.HNL*self.HNLlsss*super().F1G1H1() + 96*self.GNL*Power(self.HNLlsss,2)*super().G3() + 24*self.GNLlls*Power(self.HNL,2)*super().H2())))
        return value
