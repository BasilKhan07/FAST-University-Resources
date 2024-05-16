from sympy import *
from tabulate import tabulate
from array import *
from math import e

def getFunc():
    func = input("Enter Function : ")
    return func

def getIntervls():
    print("Enter Intervals : ")
    a = input("a = ")
    b = input("b = ")
    return a,b

def f(eq, num):
    x = float(num)
    return eval(eq)

Iteration = 0
Func = getFunc()
a,b = getIntervls()
col_names = ["n", "a", "b", "c", "f(c)"]
arr = [[]]

c = float(float(a) * f(Func,b) - float(b) * f(Func,a))/(f(Func,b) - f(Func,a))

if(f(Func,a) * f(Func,b) < 0):
    while f(Func , c) != 0:
        arr.insert(Iteration, [Iteration, a, b, c, f(Func, c)])
        c = float(float(a) * f(Func,b) - float(b) * f(Func,a))/(f(Func,b) - f(Func,a))

        if(f(Func, a) * f(Func, c) < 0):
            b = c
        else:
            a = c

        Iteration += 1
        ans = f(Func, c)

    arr.insert(Iteration, [Iteration, a, b, c, f(Func, c)])
    print(tabulate(arr, headers=col_names, tablefmt="fancy_grid"))
    print("Root : ", c)
    print("Number of Iterations performed : ", Iteration)
    print("f(c) = ", ans)
else:
    print("Root is not available in given Intervals. ")
