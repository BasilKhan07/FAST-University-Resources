from sympy import *

func = input("Enter Function: ")
print("\nEnter Intervals: ")
a = float(input("a = "))
b = float(input("b = "))
print("\n\tOPEN NEWTON COTES FORMULA")
print("\nn = 0 ?\nn = 1 ?\nn = 2 ?\nn = 3 ?")
n = int(input("\nEnter value of n: "))

h = float((b-a)/float(n+2))

if n == 0:
    result = 0
    x = a + h
    y0 = float(eval(func))
    result = (2 * h) * y0
    print("\nResult using n = 0: ", result)
elif n == 1:
    result = 0
    sum = 0
    x = a + h
    y = []
    y.append(eval(func))
    x = a + (2 * h)
    y.append(eval(func))
    for i in range(n+1):
       sum = sum + float(y[i])
    result = ((3 * h) / 2) * sum
    print("\nResult using n = 1: ", result)
elif n == 2:
    result = 0
    sum = 0
    x = a + h
    y = []
    y.append(eval(func))
    for i in range(0, 3):
        x = a + (i+2) * h
        y.append(eval(func))
    sum = (2 * y[0]) + (2 * y[2])
    sum = sum - y[1]
    result = ((4 * h)/ 3) * sum
    print("\nResult using n = 2: ", result)
elif n == 3:
    result = 0
    sum = 0
    x = a + h
    y = []
    y.append(eval(func))
    for i in range(0, 4):
        x = a + (i+2) * h
        y.append(eval(func))
    y[0] = 11 * y[0]
    y[3] = 11 * y[3]
    for i in range(n+1):
        sum = sum + float(y[i])
    result = ((5*h)/24) * sum
    print("\nResult using n = 3: ", result) 
else:
    print("\nChoose Valid Option !!!")