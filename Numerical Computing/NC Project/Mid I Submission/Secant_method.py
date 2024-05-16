from sympy import *
from tabulate import tabulate
from array import *

def getFunc():
    func = input("Enter Function: ")
    return func

def getIntervals():
    print("Enter Intervals: ")
    a = input("a = ")
    b = input("b = ")
    return float(a), float(b)

def f(eq, num):
    x = float(num)
    return eval(eq)
flag = 0
Iteration = 0
Func = getFunc()
a, b = getIntervals()
col_names = ["n", "a", "b", "c", "f(c)"]
arr = [[]]
c = (a*f(Func, b) - b*f(Func, a)) / (f(Func, b) - f(Func, a))
arr.insert(Iteration, [Iteration, a, b, c, f(Func, c)])
while f(Func, c) != 0:
    a = b
    b = c
    if (f(Func, b) - f(Func, a)) == 0:
        flag = 1
        break
    c = (a*f(Func, b) - b*f(Func, a)) / (f(Func, b) - f(Func, a))
    Iteration +=1
    arr.insert(Iteration, [Iteration, a,b, c, f(Func, c)])
print(tabulate(arr, headers=col_names, tablefmt="fancy_grid"))
if(flag == 1):
    print("Loop break because denominator is zero.")
    flag = 0
print("Root: ", c)
print("Number of Iterations: ", Iteration)