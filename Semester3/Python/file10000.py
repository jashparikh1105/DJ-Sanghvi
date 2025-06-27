import random as r
import string 

f = open("sample.txt","w+")
for i in range(10000):
     rand = r.randint(1, 10000)
     rands = str(rand) +"\n" 
     f.write(rands)
       
lis=[]
f = open("sample.txt","r")
for i in range(10000):
        rand=int(f.readline())
        lis.append(rand)
sort_lis=sorted(lis)

f1 = open("sample1.txt","a")
for i in range(10000):
        rands=str(sort_lis[i])+"\n"
        f1.write(rands)
