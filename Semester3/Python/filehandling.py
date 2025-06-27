import string

l=[]

n = int(input("Enter the number of numbers: "))

for i in range(0,n):
    x = int(input("Enter the number: "))
    l.append(x)

f = open("demo1.txt","w+")
f.write("\n")
for num in l:
    f.writelines(str(num) + "\n")
f.seek(0)
print(f.read())
l.sort()
f.close()

f1 = open("demo2.txt","w+")
f1.write("\n")
for no in l:
    f1.writelines(str(no) + "\n")
f1.seek(0)
print(f1.read())
f1.close()
