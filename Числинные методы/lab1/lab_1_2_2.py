import math

xCount = -50
k = res = e = 0
test = -1
print(" ______________________________________________________")
print("| {:<3} | {:<13} | {:<13} | {:<13} |".format("X","Series","Cos", "Error"))
print("|-----|---------------|---------------|---------------|")
while xCount <= 50:
    x = xCount
    if x > 2*math.pi:
        x = math.fmod(x, 2 * math.pi)
    elif x < -2 * math.pi:
        x = math.fmod(x, 2 * math.pi)
    cos = (math.pow(-1, k) * math.pow(x, 2*k)) / math.factorial(2*k)
    res = res + cos
    if (res != test):
        test = res
        k += 1
    else:
        print("| {:<3d} | {:<13e} | {:<13e} | {:<13e} |" .format(xCount, res, math.cos(x), math.cos(x)-res))
        cos = res = k = 0
        test = -1
        xCount += 5
print("|_____________________________________________________|")