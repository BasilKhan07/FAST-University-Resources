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
    return a, b

def f(eq, num):
    x = float(num)
    return eval(eq)
     
Iteration = 0
Func = getFunc()
a, b = getIntervals()
col_names = ["n", "a", "b", "c", "f(c)"]
arr = [[]]
root_check = false
c = (float(a)+float(b))/2
if(f(Func, a) * f(Func, b) < 0):
    arr.insert(Iteration, [Iteration, a, b, c, f(Func, c)])
    while(f(Func, c) != 0):
        c = (float(a)+float(b))/2
        if f(Func, a) * f(Func, c) < 0:
            b = c
        else:
            a = c
        Iteration += 1
        arr.insert(Iteration, [Iteration, a, b, c, f(Func, c)])
        ans = f(Func, c)
    print(tabulate(arr, headers=col_names, tablefmt="fancy_grid"))
    print("Root: ", format(c, ".5f"))
    print("Number of Iterations: ", Iteration)
    print("f(c) = ", ans)
else:
    print("Root is not availble in given Intervals. ")

    