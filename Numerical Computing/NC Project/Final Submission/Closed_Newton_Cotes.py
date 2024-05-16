from sympy import *

func = input("Enter Function: ")
print("\nEnter Intervals: ")
a = float(input("a = "))
b = float(input("b = "))
print("\tCLOSED NEWTON COTES FORMULA")
print("\nn = 1 : Trapezoidal Rule\nn = 2 : Simpson's 1/3th Rule\nn = 3 : Simpson's 3/8th Rule\nn = 4 : Forth Formula")
n = int(input("\nEnter value of n: "))

h = float((b-a)/float(n))

if n == 1:
    result = 0
    x = a
    y0 = float(eval(func))
    x = b
    y1 = float(eval(func))
    ans = y0  + y1
    result = (h / 2) * ans
    print("\nResult using Trapezoidal Rule: ", result)
elif n == 2:
    result = 0
    sum = 0
    x = a
    y = []
    y.append(eval(func))
    for i in range(0, 2):
        x = x + h
        y.append(eval(func))
    y[1] = 4 * y[1]
    for i in range(n+1):
       sum = sum + float(y[i])
    result = (h / 3) * sum
    print("\nResult using Simpson's 1/3rd Rule: ", result)
elif n == 3:
    result = 0
    sum = 0
    x = a
    y = []
    y.append(eval(func))
    for i in range(0, 3):
        x = x + h
        y.append(eval(func))
    y[1] = 3 * y[1]
    y[2] = 3 * y[2]
    for i in range(n+1):
        sum = sum + float(y[i])
    result = ((3 * h)/ 8) * sum
    print("\nResult using Simpson's 3/8th Rule: ", result)
elif n == 4:
    result = 0
    sum = 0
    x = a
    y = []
    y.append(eval(func))
    for i in range(0, 4):
        x = x + h
        y.append(eval(func))
    y[0] = 7 * y[0]
    y[1] = 32 * y[1]
    y[2] = 12 * y[2]
    y[3] = 32 * y[3]
    y[4] = 7 * y[4]
    for i in range(n+1):
        sum = sum + float(y[i])
    result = ((2*h)/45) * sum
    print("\nResult using Forth Formula: ", result) 
else:
    print("\nChoose Valid Option !!!")