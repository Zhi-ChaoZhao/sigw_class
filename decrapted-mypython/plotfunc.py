import numpy as np
import pickle

Power = np.power

g0 = 3.363
ge = 106.75
Or0h2 = 4.2e-5
# Trf = Or0h2 * (g0 / ge)**(1/3)
Trf = Or0h2 
h = 0.6736
m_c = Trf**2 / h**4
PL = 2.1e-9
FNLl = -0.9 * 0.6
GNLl = -58000 * 0.36

Glike_list = ['Omega_G','Omega_H','Omega_H2','Omega_H3','Omega_R','Omega_RH','Omega_RH2','Omega_R2','Omega_R2H','Omega_R3',]
Clike_list = ['Omega_C','Omega_CH','Omega_CH2','Omega_CR','Omega_CRH','Omega_CR2','Omega_C2','Omega_C2H','Omega_C2R','Omega_C3',]
Zlike_list = ['Omega_Z','Omega_ZH','Omega_ZH2','Omega_ZR','Omega_ZRH','Omega_ZR2','Omega_Z2','Omega_Z2H','Omega_Z2R','Omega_Z3',]
Plike_list = ['Omega_P','Omega_PH','Omega_PH2','Omega_PR','Omega_PRH','Omega_PR2','Omega_PC','Omega_PCH','Omega_PCR','Omega_P2','Omega_P2H','Omega_P2R','Omega_PC2','Omega_P2C','Omega_P3',]
Nlike_list = ['Omega_N','Omega_NH','Omega_NH2','Omega_NR','Omega_NRH','Omega_NR2','Omega_NZH','Omega_NZR','Omega_N2R',]
CZlike_list = ['Omega_CZ','Omega_CZH','Omega_CZH2','Omega_CZHp','Omega_CZR','Omega_CZRH','Omega_C2Z','Omega_C2ZH','Omega_CZ2','Omega_CZ2H',]
PZlike_list = ['Omega_PZ','Omega_PZH','Omega_PZR','Omega_PZC','Omega_PZCH','Omega_P2Z','Omega_PZ2',]
NClike_list = ['Omega_NC','Omega_NCH','Omega_NCR','Omega_NCZH','Omega_NC2',]
PNlike_list = ['Omega_PN','Omega_PNH','Omega_PNR','Omega_PNC','Omega_P2N',]

func_list = Glike_list + Clike_list + Zlike_list + Plike_list + Nlike_list + CZlike_list + PZlike_list + NClike_list + PNlike_list
all_functions = func_list 

sigma_str = {1/5:'1o5',2/5:'2o5',3/5:'3o5',4/5:'4o5',1:'1',6/5:'6o5',7/5:'7o5',8/5:'8o5',9/5:'9o5',2:'2',11/5:'11o5',12/5:'12o5',13/5:'13o5',14/5:'14o5',3:'3'}

    

def P1(k_,sigma):
    if sigma == 0:
        value = []
        for q in k_:
            if np.abs(q - 1) < 5e-3:
                value.append(1e3)
            else:
                value.append(0)
        return np.array(value)
    else:
        return (np.sqrt(2)*Power(np.pi,1.5)*Power(np.e,-Power(np.log(k_),2)/(2.*Power(sigma,2))))/(Power(k_,3)*sigma)

def P2(k_,sigma):
    if sigma == 0:
        value = []
        for q in k_:
            if 0 < q <= 2:
                value.append(np.pi**2 / q)
            else:
                value.append(0)
        value = np.array(value)
    else:
        with open ('/home/jp/New_Methods/tauNL-SIGW/Pi_interp/lgP2_sigma={0}.pkl'.format(sigma_str[sigma]), 'rb') as f2:
            lg_P2 = pickle.load(f2)
        value = 10**lg_P2(np.log10(k_))
    return value

def P3(k_,sigma):
    if sigma == 0:
        value = []
        for q in k_:
            if 0 < q <= 1:
                value.append(np.pi**2)
            elif 1 < q <= 3:
                value.append(np.pi**2 * (q - 3) / (2 * q))
            else:
                value.append(0)
        value = np.array(value)
    else:
        with open ('/home/jp/New_Methods/tauNL-SIGW/Pi_interp/lgP3_sigma={0}.pkl'.format(sigma_str[sigma]), 'rb') as f3:
            lg_P3 = pickle.load(f3)
        # lg_P3 = P3_function_dict[sigma]
        value = 10**lg_P3(np.log10(k_))
    return value

def P4(k_,sigma):
    if sigma == 0:
        value = []
        for q in k_:
            if 0 < q <= 2:
                value.append(np.pi**2 * (1 - 3 * q / 8))
            else:
                value.append(0)
        value = np.array(value)
    else:
        with open ('/home/jp/New_Methods/tauNL-SIGW/Pi_interp/lgP4_sigma={0}.pkl'.format(sigma_str[sigma]), 'rb') as f4:
            lg_P4 = pickle.load(f4)
        value = 10**lg_P4(np.log10(k_))
    return value

for key in func_list:
    FD_name = key.split('_')[-1]
    new_name = 'Om'+FD_name
    globals()[new_name] = {}

    
def readdata(sigma):
    data_of_pkl = 'hNL-SIGW-{0}.pkl'.format(sigma_str[sigma])
    with open('./'+data_of_pkl,'rb') as f:
        data_ = pickle.load(f)
    # data_ = np.load('./'+data_of_pkl,allow_pickle=True).tolist()
    lg_result = {}
    lg_result = dict(data_)
    result = {}
    #from functools import partial
    for key in lg_result:
        #result[key] = partial(lambda k_, func: 10**func(np.log10(k_)), func=lg_result[key])
        result[key] = lambda k_, func=lg_result[key]: 10**func(np.log10(k_))

    if set(func_list) != set(result.keys()):
        print('Warning: result error!')
    else:
        for key in result.keys():
            FD_name = key.split('_')[-1]
            new_name = 'Om'+FD_name
            # global globals()[new_name]
            globals()[new_name][sigma] = result[key]
    
        for key in result.keys():
            FD_name = key.split('_')[-1]
            k_test = [1e-3,1e-2,1e-1,1.,10.,100.]
            new_name = 'Om'+FD_name
            diff = eval(new_name)[sigma](k_test) - result[key](k_test)
            if not np.allclose(diff, np.array([0.,]*6)):
                print(new_name+' error: '+key+': '+diff)
                break

class Unscaled_Omega:
    def __init__(self,k_,sigma): 
        self.k_ = k_
        self.sigma = sigma
    
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

    
class Omega(Unscaled_Omega):
    def __init__(self,k_,sigma,**params): 
        super().__init__(k_, sigma)
        self.A = params.get('A', 1)
        self.nu_s = params.get('nu_s', 1)
        self.FNL = params.get('FNL', 3*params.get('fNL', 0)/5)
        self.FNLls = params.get('FNLls', self.FNL)
        self.GNL = params.get('GNL', 9*params.get('gNL', 0.)/25)
        self.GNLlss = params.get('GNLlss', self.GNL)
        self.GNLlls = params.get('GNLlls', self.GNL)
        self.HNL = params.get('HNL', 27*params.get('hNL', 0.)/125)
        self.HNLlsss = params.get('HNLlsss', self.HNL)
        self.HNLllss = params.get('HNLllss', self.HNL)
        self.HNLllls = params.get('HNLllls', self.HNL)
        self.Fa = np.sqrt(self.FNL**2 * self.A)
        self.Ga = np.abs(self.GNL) * self.A
        # self.FHA2 = self.FNL * self.HNL * self.A**2
        self.Ha = np.sqrt(self.HNL**2 * self.A**3)
        
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
    
    def power_spec_new(self):
        y1 = self.A * self.k_**3 * P1(self.k_,self.sigma) / (2*np.pi)
        max_y1 = np.max(y1)
        thres = 0.001 * max_y1
        top_A = 2 * self.A
        bottom_A = 0.
        new_A = self.A
        for i in range(1000):
            # self.update_A(new_A)
            self.A = new_A
            y2 = self.power_spec()
            max_y2 = np.max(y2)
            diff = max_y2 - max_y1
            if np.abs(diff) < thres:
                break
            else:
                if diff > 0:
                    top_A = new_A
                    new_A -= (top_A - bottom_A) / 2
                else:
                    bottom_A = new_A
                    new_A += (top_A - bottom_A) / 2
        max_index = np.argmax(y2)
        x2_max = self.k_[max_index]
        self.nu_s = x2_max
        min_newk_ = self.k_[0] * x2_max
        max_newk_ = self.k_[-1] * x2_max
        self.nu_s = max_index
        num_point = len(self.k_)
        lg_min_newk_ = np.log10(min_newk_)
        lg_max_newk_ = np.log10(max_newk_)
        newk_ = np.logspace(lg_min_newk_,lg_max_newk_,num_point)
        self.k_ = newk_
        y2 = self.power_spec()
        return y2
    
    def total(self): 
        if self.A < 0:
            raise ValueError('The amplitude should be positive.')
        else:
            # if FNL**2 * A > 1 or GNL**2 * A > FNL**2 or:
                # print('Warning: Perturbativity Violating. ',A,FNL,GNL)
            value = self.Glike() + self.Clike() + self.Zlike() + self.Plike() + self.Nlike() + self.CZlike() + self.PZlike() + self.NClike() + self.PNlike() 
            # value = 
            return value
    
    def tot_test(self): 
        if self.A < 0:
            raise ValueError('The amplitude should be positive.')
        else:
            value = (Power(self.A,3)*(Power(self.FNL,2)*super().F2() + self.GNL*super().G1()) + Power(self.A,4)*(self.FNL*self.HNL*super().F1H1() + Power(self.FNL,2)*self.GNL*super().F2G1() + Power(self.FNL,4)*super().F4() + Power(self.GNL,2)*super().G2()) + Power(self.A,7)*(self.FNL*Power(self.HNL,3)*super().F1H3() + Power(self.GNL,2)*Power(self.HNL,2)*super().G2H2()) + Power(self.A,6)*(self.FNL*Power(self.GNL,2)*self.HNL*super().F1G2H1() + Power(self.FNL,2)*Power(self.HNL,2)*super().F2H2() + self.GNL*Power(self.HNL,2)*super().G1H2() + Power(self.GNL,4)*super().G4()) + Power(self.A,2)*super().Gs() + Power(self.A,5)*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.FNL,2)*Power(self.GNL,2)*super().F2G2() + Power(self.FNL,3)*self.HNL*super().F3H1() + Power(self.GNL,3)*super().G3() + Power(self.HNL,2)*super().H2()) + Power(self.A,8)*Power(self.HNL,4)*super().H4())
            return value
    

    def ob(self):
        return Trf * self.total()
    
    def ngw(self):
        OmegaT = self.total()
        nT = (np.log(OmegaT[1:])-np.log(OmegaT[:-1])) / (np.log(self.k_[1:])-np.log(self.k_[:-1]))
        nT = np.append(nT,nT[-1])
        return nT

    def ng1(self):
        if self.A <= 0:
            raise ValueError('The amplitude should be positive.')
        # elif self.FNL == 0:
        #     return np.array(len(self.k_)*[0,])
        else:
            value = (Power(self.A,3)*(6*self.FNL*self.GNLlss*super().F2() + 4*self.HNLlsss*super().G1() + self.FNLls*(4*Power(self.FNL,2)*super().F2() + 6*self.GNL*super().G1())) + Power(self.A,7)*(3*self.GNLlss*Power(self.HNL,3)*super().F1H3() + 8*self.GNL*Power(self.HNL,2)*self.HNLlsss*super().G2H2()) + Power(self.A,4)*(3*self.GNLlss*(self.HNL*super().F1H1() + 2*self.FNL*self.GNL*super().F2G1() + 4*Power(self.FNL,3)*super().F4()) + self.HNLlsss*(4*Power(self.FNL,2)*super().F2G1() + 8*self.GNL*super().G2()) + self.FNLls*(4*self.FNL*self.HNL*super().F1H1() + 2*Power(self.FNL,2)*self.GNL*super().F2G1() + 4*Power(self.GNL,2)*super().G2())) + Power(self.A,6)*(3*self.GNLlss*self.HNL*(Power(self.GNL,2)*super().F1G2H1() + 2*self.FNL*self.HNL*super().F2H2()) + 2*self.FNLls*self.GNL*Power(self.HNL,2)*super().G1H2() + 4*self.HNLlsss*(2*self.FNL*self.GNL*self.HNL*super().F1G2H1() + Power(self.HNL,2)*super().G1H2() + 4*Power(self.GNL,3)*super().G4())) + 8*Power(self.A,2)*self.FNLls*super().Gs() + Power(self.A,5)*(self.GNLlss*(3*self.GNL*self.HNL*super().F1G1H1() + 6*self.FNL*Power(self.GNL,2)*super().F2G2() + 9*Power(self.FNL,2)*self.HNL*super().F3H1()) + 4*self.HNLlsss*(self.FNL*self.HNL*super().F1G1H1() + 2*Power(self.FNL,2)*self.GNL*super().F2G2() + 3*Power(self.GNL,2)*super().G3()) + 2*self.FNLls*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.GNL,3)*super().G3() + 2*Power(self.HNL,2)*super().H2())))
            return value
    

    def ng2(self):
        if self.A <= 0:
            raise ValueError('The amplitude should be positive.')
        else:
            value = (Power(self.A,3)*(9*Power(self.GNLlss,2)*super().F2() + 24*self.FNL*self.HNLllss*super().F2() + 4*Power(self.FNLls,2)*(Power(self.FNL,2)*super().F2() + 3*self.GNL*super().G1()) + 6*self.GNLlls*(2*Power(self.FNL,2)*super().F2() + 3*self.GNL*super().G1()) + self.FNLls*(24*self.FNL*self.GNLlss*super().F2() + 24*self.HNLlsss*super().G1())) + Power(self.A,7)*(12*Power(self.HNL,3)*self.HNLllss*super().F1H3() + 16*Power(self.HNL,2)*Power(self.HNLlsss,2)*super().G2H2()) + Power(self.A,4)*(24*self.FNL*self.GNLlss*self.HNLlsss*super().F2G1() + 9*Power(self.GNLlss,2)*(self.GNL*super().F2G1() + 6*Power(self.FNL,2)*super().F4()) + 12*self.HNLllss*(self.HNL*super().F1H1() + 2*self.FNL*self.GNL*super().F2G1() + 4*Power(self.FNL,3)*super().F4()) + 16*Power(self.HNLlsss,2)*super().G2() + 4*Power(self.FNLls,2)*(self.FNL*self.HNL*super().F1H1() + Power(self.GNL,2)*super().G2()) + 6*self.GNLlls*(2*self.FNL*self.HNL*super().F1H1() + Power(self.FNL,2)*self.GNL*super().F2G1() + 2*Power(self.GNL,2)*super().G2()) + self.FNLls*(12*self.GNLlss*(self.HNL*super().F1H1() + self.FNL*self.GNL*super().F2G1()) + 8*self.HNLlsss*(Power(self.FNL,2)*super().F2G1() + 4*self.GNL*super().G2()))) + Power(self.A,6)*(24*self.GNL*self.GNLlss*self.HNL*self.HNLlsss*super().F1G2H1() + 9*Power(self.GNLlss,2)*Power(self.HNL,2)*super().F2H2() + 12*self.HNL*self.HNLllss*(Power(self.GNL,2)*super().F1G2H1() + 2*self.FNL*self.HNL*super().F2H2()) + 6*self.GNL*self.GNLlls*Power(self.HNL,2)*super().G1H2() + 8*self.FNLls*Power(self.HNL,2)*self.HNLlsss*super().G1H2() + 16*Power(self.HNLlsss,2)*(self.FNL*self.HNL*super().F1G2H1() + 6*Power(self.GNL,2)*super().G4())) + Power(self.A,2)*(24*Power(self.FNLls,2)*super().Gs() + 24*self.GNLlls*super().Gs()) + Power(self.A,5)*(12*self.GNLlss*self.HNLlsss*(self.HNL*super().F1G1H1() + 4*self.FNL*self.GNL*super().F2G2()) + 9*Power(self.GNLlss,2)*(Power(self.GNL,2)*super().F2G2() + 3*self.FNL*self.HNL*super().F3H1()) + 12*self.HNLllss*(self.GNL*self.HNL*super().F1G1H1() + 2*self.FNL*Power(self.GNL,2)*super().F2G2() + 3*Power(self.FNL,2)*self.HNL*super().F3H1()) + 16*Power(self.HNLlsss,2)*(Power(self.FNL,2)*super().F2G2() + 3*self.GNL*super().G3()) + self.FNLls*(6*self.GNL*self.GNLlss*self.HNL*super().F1G1H1() + 8*self.HNLlsss*(self.FNL*self.HNL*super().F1G1H1() + 3*Power(self.GNL,2)*super().G3())) + 4*Power(self.FNLls,2)*Power(self.HNL,2)*super().H2() + 6*self.GNLlls*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.GNL,3)*super().G3() + 2*Power(self.HNL,2)*super().H2())))
            return value
    
        
    def ng3(self):
        if self.A <= 0:
            raise ValueError('The amplitude should be positive.')
        else:
            value = (Power(self.A,3)*(self.GNLlss*(72*self.FNL*self.GNLlls*super().F2() + 72*self.HNLllss*super().F2()) + 8*Power(self.FNLls,3)*self.GNL*super().G1() + 72*self.GNLlls*self.HNLlsss*super().G1() + self.HNLllls*(48*Power(self.FNL,2)*super().F2() + 72*self.GNL*super().G1()) + Power(self.FNLls,2)*(24*self.FNL*self.GNLlss*super().F2() + 48*self.HNLlsss*super().G1()) + self.FNLls*(36*Power(self.GNLlss,2)*super().F2() + 96*self.FNL*self.HNLllss*super().F2() + 24*self.GNLlls*(Power(self.FNL,2)*super().F2() + 3*self.GNL*super().G1()))) + Power(self.A,4)*(36*Power(self.GNLlss,2)*self.HNLlsss*super().F2G1() + 96*self.FNL*self.HNLllss*self.HNLlsss*super().F2G1() + 108*self.FNL*Power(self.GNLlss,3)*super().F4() + self.GNLlss*(36*self.GNLlls*(self.HNL*super().F1H1() + self.FNL*self.GNL*super().F2G1()) + 72*self.HNLllss*(self.GNL*super().F2G1() + 6*Power(self.FNL,2)*super().F4())) + 24*self.GNLlls*self.HNLlsss*(Power(self.FNL,2)*super().F2G1() + 4*self.GNL*super().G2()) + 24*self.HNLllls*(2*self.FNL*self.HNL*super().F1H1() + Power(self.FNL,2)*self.GNL*super().F2G1() + 2*Power(self.GNL,2)*super().G2()) + Power(self.FNLls,2)*(12*self.GNLlss*self.HNL*super().F1H1() + 32*self.GNL*self.HNLlsss*super().G2()) + self.FNLls*(18*self.GNL*Power(self.GNLlss,2)*super().F2G1() + 48*self.FNL*self.GNLlss*self.HNLlsss*super().F2G1() + 48*self.HNLllss*(self.HNL*super().F1H1() + self.FNL*self.GNL*super().F2G1()) + 64*Power(self.HNLlsss,2)*super().G2() + 24*self.GNLlls*(self.FNL*self.HNL*super().F1H1() + Power(self.GNL,2)*super().G2()))) + Power(self.A,6)*(96*self.GNL*self.HNL*self.HNLllss*self.HNLlsss*super().F1G2H1() + self.GNLlss*(48*self.HNL*Power(self.HNLlsss,2)*super().F1G2H1() + 72*Power(self.HNL,2)*self.HNLllss*super().F2H2()) + 24*self.GNL*Power(self.HNL,2)*self.HNLllls*super().G1H2() + 24*self.GNLlls*Power(self.HNL,2)*self.HNLlsss*super().G1H2() + 256*self.GNL*Power(self.HNLlsss,3)*super().G4()) + Power(self.A,2)*(32*Power(self.FNLls,3)*super().Gs() + 144*self.FNLls*self.GNLlls*super().Gs() + 96*self.HNLllls*super().Gs()) + Power(self.A,5)*(72*self.GNL*Power(self.GNLlss,2)*self.HNLlsss*super().F2G2() + 48*self.HNLllss*self.HNLlsss*(self.HNL*super().F1G1H1() + 4*self.FNL*self.GNL*super().F2G2()) + 27*Power(self.GNLlss,3)*self.HNL*super().F3H1() + self.GNLlss*(18*self.GNL*self.GNLlls*self.HNL*super().F1G1H1() + 96*self.FNL*Power(self.HNLlsss,2)*super().F2G2() + 72*self.HNLllss*(Power(self.GNL,2)*super().F2G2() + 3*self.FNL*self.HNL*super().F3H1())) + 64*Power(self.HNLlsss,3)*super().G3() + 24*self.GNLlls*self.HNLlsss*(self.FNL*self.HNL*super().F1G1H1() + 3*Power(self.GNL,2)*super().G3()) + 24*self.HNLllls*(self.FNL*self.GNL*self.HNL*super().F1G1H1() + Power(self.GNL,3)*super().G3() + 2*Power(self.HNL,2)*super().H2()) + self.FNLls*(24*self.GNL*self.HNL*self.HNLllss*super().F1G1H1() + 24*self.GNLlss*self.HNL*self.HNLlsss*super().F1G1H1() + 96*self.GNL*Power(self.HNLlsss,2)*super().G3() + 24*self.GNLlls*Power(self.HNL,2)*super().H2())))
            return value
    
    
        
    def llp1Cl_tilde(self):
        Clt = (2 * np.pi * PL) * (self.ng1() / self.total() + 3 * (4 - self.ngw()) / 5)**2  ##!!!!!!!!!!!!!!!!!!!!多乘了3/5，已修正  9.17.
        return Clt
    
    def llp1Cl(self):
        Cl = self.llp1Cl_tilde() * self.ob()**2 / (4 * np.pi * h**4)
        return Cl
    
    def b_tilde(self):
        delta1 = self.ng1() / self.total() + 3 * (4 - self.ngw()) / 5
        delta2 = self.ng2() / self.total() + 3 * self.FNL * (4 - self.ngw()) / 5
        # delta2 = self.ng2() / self.total() + 3 * FNLl * (4 - self.ngw()) / 5
        bt = 8 * np.pi**2 * PL**2 * delta1**2 * delta2
        return bt
    
    def t1_tilde(self):
        delta1 = self.ng1() / self.total() + 3 * (4 - self.ngw()) / 5
        delta2 = self.ng2() / self.total() + 3 * self.FNL * (4 - self.ngw()) / 5
        # delta2 = self.ng2() / self.total() + 3 * FNLl * (4 - self.ngw()) / 5
        tt1 = 4 * (2 * np.pi * PL)**3 * delta1**2 * delta2**2
        return tt1
    
    def t2_tilde(self):
        delta1 = self.ng1() / self.total() + 3 * (4 - self.ngw()) / 5
        delta3 = self.ng3() / self.total() + 3 * self.GNL * (4 - self.ngw()) / 5
        # delta3 = self.ng3() / self.total() + 3 * GNLl * (4 - self.ngw()) / 5
        tt2 = (2 * np.pi * PL)**3 / 4 * delta1**3 * delta3
        return tt2
    

    def update_A(self, new_A):
        self.A = new_A
                

def find_closest_index(k_,r):
    min_difference = float('inf')  # 初始化最小差值为正无穷大
    closest_index = 0
    for i in range(len(k_)):
        difference = abs(r - k_[i])  # 计算目标值与数组中每个值的差的绝对值
        if difference < min_difference:  # 如果差值小于当前最小差值
            min_difference = difference  # 更新最小差值
            closest_index = i  # 更新最接近的值的索引
    return closest_index
    
def CPlotNG(func,XY,num,sigma,k_,r,A,FNL,GNL=0,HNL=0,Ateq=False):
    k_ind = find_closest_index(k_,r)
    results_temp = []
    if XY == 'F-G':
        HNL = 0
        maxF = 1/np.sqrt(A)
        X_range = np.linspace(-maxF,maxF,num)
        maxG = 1/A
        Y_range = np.linspace(-maxG,maxG,num)
        X,Y = np.meshgrid(X_range,Y_range)
    elif XY == 'G-H':
        maxG = np.abs(FNL)/np.sqrt(A)
        X_range = np.linspace(-maxG,maxG,num)
        maxH = np.abs(FNL)/A
        Y_range = np.linspace(-maxH,maxH,num)
        X,Y = np.meshgrid(X_range,Y_range)
    else:
        raise ValueError('Undefined functions.')
        
    for new_y in Y_range:
        temp = []
        for new_x in X_range:
            if XY == 'F-G':
                Om = Omega(k_=k_,sigma=sigma,A=A,FNL=new_x,GNL=new_y,HNL=0)
            elif XY == 'G-H':
                Om = Omega(k_=k_,sigma=sigma,A=A,FNL=FNL,GNL=new_x,HNL=new_y)
            if Ateq:
                Pnew = Om.power_spec_new()
                Pnew = None
            method = getattr(Om, func)
            temp.append(method()[k_ind])
        results_temp.append(temp)
    Z = np.array(results_temp)
    return (X,Y,Z)



def CPlot_nuNG(func,yaxis,num,k_,sigma,A,FNL,GNL,HNL,Ateq=False):
    if yaxis == 'F':
        maxF = 1/np.sqrt(A)
        para_range = np.linspace(-maxF,maxF,num)
    elif yaxis == 'G':
        maxG = np.abs(FNL)/np.sqrt(A)
        para_range = np.linspace(-maxG,maxG,num)
    elif yaxis == 'H':
        maxH = GNL/np.sqrt(A)
        para_range = np.linspace(-maxH,maxH,num)
    else:
        raise ValueError('Undefined functions.')
        
    X,Y = np.meshgrid(k_,para_range)
    temp = []
    for new_para in para_range:
        if yaxis == 'F':
            Om = Omega(k_=k_,sigma=sigma,A=A,FNL=new_para,GNL=GNL,HNL=HNL)
        elif yaxis == 'G':
            Om = Omega(k_=k_,sigma=sigma,A=A,FNL=FNL,GNL=new_para,HNL=HNL)
        elif yaxis == 'H':
            Om = Omega(k_=k_,sigma=sigma,A=A,FNL=FNL,GNL=GNL,HNL=new_para)
        if Ateq:#若要固定功率谱峰值，要在这一步之前调用power_spec_new，或许可行
            Pnew = Om.power_spec_new()
            Pnew = None
        method = getattr(Om, func)
        temp.append(method())
    
    Z = np.array(temp)
    return (X,Y,Z)
