import pandas as pd

def Calculating_p(p, n):
    temp = p
    for i in range(1, n):
        temp = temp * (p + i)
    return float(temp)

def Factorial(n):
    Fact = 1
    for i in range(2, n + 1):
        Fact = Fact * i 
    return int(Fact)

Num_of_data = int(input("Enter number of data: "))
print("\nEnter values of X: ")
x = []
for i in range(Num_of_data):
    num1 = input("X" + str(i) + " : ")
    x.append(num1)

y = [[0 for i in range(Num_of_data)] for j in range(Num_of_data)]
print("\nEnter f(x) values: ")
for i in range(Num_of_data):
    num2 = input("Y" + str(i) + " : ")
    y[i][0] = float(num2)

for i in range(1, Num_of_data):
    for j in range(Num_of_data-1, i-1, -1):
        y[j][i] = float(y[j][i - 1]) - float(y[j - 1][i - 1])

print(pd.DataFrame(y))

value = float(input("\nEnter Value to Interpolate: "))

sum = float(y[Num_of_data-1][0])
p = (float(value) - float(x[Num_of_data-1])) / (float(x[1]) - float(x[0]))
for i in range(1,Num_of_data):
    sum = float(sum) + (Calculating_p(p, i) * float(y[Num_of_data-1][i])) / Factorial(i)

print("\nValue at ", value, "is", sum)