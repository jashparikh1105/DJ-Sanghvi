#with open("T3.txt","w") as file:
#    for i in range(10):
#        inp=input("Enter a number: ")
#        file.write(str(inp)+"\n")
#print("Execution successful")


with open("T3.txt","r") as file:
    numbers=[int(line.strip()) for line in file]
sortednum= sorted(numbers)
with open("T2.txt","w") as file:
    for i in sortednum:
        file.write(str(i)+"\n")
print("Execution successful")
