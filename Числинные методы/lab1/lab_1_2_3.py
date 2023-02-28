import math

xCount = -50
k = res = e = 0
test = -1
print(" _____________________________________________________")
print("| {:<3} | {:<13} | {:<13} | {:<13} |".format("X","Series","Sin", "Error"))
print("|-----|---------------|---------------|---------------|")
while xCount <= 50:
    x = xCount
    if x > 2*math.pi:
        x = math.fmod(x, 2 * math.pi)
    elif x < -2 * math.pi:
        x = math.fmod(x, 2 * math.pi)
    sin = (math.pow(-1, k) * math.pow(x, 2*k+1)) / math.factorial(2*k+1)
    res = res + sin
    if (res != test):
        test = res
        k += 1
    else:
        print("| {:<3d} | {:<13e} | {:<13e} | {:<13e} |" .format(xCount, res, math.sin(x), math.sin(x)-res))
        sin = res = k = 0
        test = -1
        xCount += 5
print("|_____________________________________________________|")