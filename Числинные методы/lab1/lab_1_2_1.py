import math

x = -50
k = res = e = 0
test = -1
print(" _____________________________________________________")
print("| {:<3} | {:<13} | {:<13} | {:<13} |".format("X","Series","Exp", "Error"))
print("|-----|---------------|---------------|---------------|")
while x <= 50:
    e = math.pow(abs(x), k) / math.factorial(k)
    res = res + e
    if (res != test):
        test = res
        k += 1
    else:
        if (x < 0):
            res = 1/res
        print("| {:<3d} | {:<13e} | {:<13e} | {:<13e} |" .format(x, res, math.exp(x), math.exp(x)-res))
        e = res = k = 0
        test = -1
        x += 10
print("|_____________________________________________________|")