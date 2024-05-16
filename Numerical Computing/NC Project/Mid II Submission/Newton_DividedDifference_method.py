
def EnterNumberOfData(): 
    data = input("Enter Number of Data points: ")
    return int(data)

def Enter_Value():
    val = input("Enter value x to find: ")
    return float(val)

def getData(num):
    for i in range(num):
        val1 = input("Enter x" + str(i) + ": ")
        val2 = input("Enter y" + str(i) + ": ")
        x.append(float(val1))
        y[i][0] = (float(val2))
    return

def product_x(i, value, x): 
    prod = 1; 
    for j in range(i): 
        prod = prod * (value - x[j]); 
    return prod; 
  
def dividedDiffTable(x, y, n):
  
    for i in range(1, n): 
        for j in range(n - i): 
            y[j][i] = ((y[j][i - 1] - y[j + 1][i - 1]) /
                                     (x[j] - x[i + j]))
    return y
  
def applyFormula(value, x, y, n): 
    sum = y[0][0]; 
    for i in range(1, n):
        sum = sum + (product_x(i, value, x) * y[0][i]); 
      
    return sum; 
  
def printDiffTable(y, n): 
    print("\t DIVIDED DIFFERENCE TABLE")
    print("f(x) \t\t", end="")
    for z in range(1,n):
        print(str(z)+"DD  \t\t\t",end="")

    print("\n")
    for i in range(n): 
        for j in range(n - i): 
            print(round(y[i][j], 7), "\t\t", 
                               end = " "); 
  
        print(" "); 
  
n = EnterNumberOfData(); 
y = [[0 for i in range(10)] 
        for j in range(10)]; 
x = []; 

getData(n)
value = Enter_Value()
y=dividedDiffTable(x, y, n); 
  
printDiffTable(y, n); 

print("\nValue at", value, "is",
        round(applyFormula(value, x, y, n), 7))
  
