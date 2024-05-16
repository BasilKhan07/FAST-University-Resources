from sympy import *

func = input("Enter Function: ")
print("\nEnter Intervals: ")
a = float(input("a = "))
b = float(input("b = "))

print("\n\tUsing Midpoint Composite Formula")
print("\nDo you want to enter value of \n (1) n \n (2) h")
choice = int(input("Enter 1 or 2 : "))
if choice == 1:
    n = int(input("Enter value of n : "))
    h = float((b-a)/float(n+2))
elif choice == 2:
    h = float(input("Enter value of h : "))
    n = int(((b-a)/float(h))-2)
else :
    print("Wrong choice")
    exit(0)

sum = 0
result = 0
x = a + h
y = []
t = int((n/2) + 1)

for i in range(t):
    y.append(eval(func))
    sum = sum + float(y[i])
    x = x + 2*h

result = 2*h*float(sum)
print("\nResult using Midpoint Formula with value of n =",n, "is :" , result)
