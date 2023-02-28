import numpy as np

def lagranz(x,y,t):
    L=0
    for j in range(len(y)):
        p=1
        for i in range(len(x)):
            if i==j:p=p*1   
            else:p=p*(t-x[i])/(x[j]-x[i])
        px.append(y[j]*p)
        L=L+y[j]*p
    return L

def calc(x, i):
    return np.cos(((2*x[i]+1)*np.pi) / (2*np.max(x)+2))


d=6
n=4
nls=17 # 17, 41
N=2*(2*n+1)
vector=np.array([0,1,2,3,4])
#vector=np.array([0,1,2,3,4,5,6,7,8,9,10])
x=[(calc(vector, i)) for i in range(len(vector))]
y=[(1/(1+d*pow(x[i],2))) for i in range(len(x))]
px=[]
xnew=np.linspace(np.min(x),np.max(x),nls)
ynew=[lagranz(x,y,i) for i in xnew]

print(" -------------------------------------")
print("| n =", n,"|","| d =", d,"|", "| f(x)=1/(1+dx^2) |",)
print(" -------------------------------------")

print(" _________________")
print("| {:<6} | {:<6} |" .format("x", "f(x)"))
print("|--------|--------|")
for i in range(len(x)):
    print("| {:<6.3f} | {:<6.3f} |" .format(x[i], y[i]))
print("|_________________|")


print(" ________________________________________________________________________________________")
print("| {:<6} | {:<15} | {:<8} | {:<8} | {:<8} | {:<8} | {:<15} |" .format("X[i]", "1", "2", "3", "4", "5", "T(x)"))
print("|--------|-----------------|----------|----------|----------|----------|-----------------|")
for i in range(len(ynew)):
    print("| {:<6.3f} | {:<15.12f} | {:<8.5f} | {:<8.5f} | {:<8.5f} | {:<8.5f} | {:<15.12f} |" .format(xnew[i], px[i], px[i+1], px[i+2], px[i+3], px[i+4], ynew[i]))
print("|________________________________________________________________________________________|")
