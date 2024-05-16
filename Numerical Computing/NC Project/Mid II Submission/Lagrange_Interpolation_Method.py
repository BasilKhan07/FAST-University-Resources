

def EnterNumberOfData(): 
    data = input("Enter Number of Data points: ")
    return int(data)

def Enter_Value():
    val = input("Enter value x to find: ")
    print("\n")
    return float(val)

def getData(num):
    for i in range(num):
        val1 = input("Enter x" + str(i) + ": ")
        val2 = input("Enter y" + str(i) + ": ")
        X_values.append(float(val1))
        Y_values.append(float(val2))
    return

Num_Of_Data = EnterNumberOfData()

Degree = Num_Of_Data - 1

x = Enter_Value()
y = 0

X_values = []
Y_values = []

getData(Num_Of_Data)
print("\n")

for i in range(Degree+1):
    product = 1
    for j in range(Degree+1):
        if j != i:
            product = product * ((x - X_values[j])/(X_values[i]-X_values[j]))
    y = y + Y_values[i] * product

print("\nResult: ")
print("x = " + str(x))
print("P(x) = " + str(y))