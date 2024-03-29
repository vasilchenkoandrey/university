import math

eps = 0
k = 1
E = [0] * 100
E[1] = (math.exp(-1) + eps)
EFact = [0] * 100
EFact[1] = (math.exp(-1))
while k <= 20:
    k += 1
    E[k] = (1 - k * E[k - 1])
    EFact[k] = (E[k] + math.factorial(k-1) * eps) #k-1 because after k += 1

print("Устойчивость и неустойчивость алгоритмов")
print(" ________________________________________")
print("| {:<2} | {:<15} | {:<15} |" .format("k", "E[k]=1-k*E[k-1]", "E[k*]=E[k]+k!"))
print("|----|-----------------|-----------------|")
for count in range(1,21):
    print("| {:<2d} | {:<15e} | {:<15e} |" .format(count, E[count], EFact[count]))
print("|________________________________________|")
print("Вывод: последнее значение должно стремиться к нулю, однако этого не происходит, так как в ходе вычислений погрешность умножается на k!")

k = 30
E[k] = 0
while k > 1:
    k -= 1
    E[k] = ((1 - E[k+1]) / k)
print(" ________________________")
print("| {:<2} | {:<17} |" .format("k", "E[k-1]=(1-E[k])/k"))
print("|----|-------------------|")
k = 30
while k > 0:
    print("| {:<2d} | {:<17e} |" .format(k, E[k]))
    k -= 1
print("|________________________|")
print("Вывод: Данный алгоритм устойчив.")

    

