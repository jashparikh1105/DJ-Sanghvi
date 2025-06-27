#a=int(input("Number 1 "))
#b=int(input("Number 2 "))
#result= lambda a,b: a if a>b else b
#print(result(a,b))

l1=[11,12,13,14]
l2=[10,25,30,45]
l3=list(map(lambda l1,l2: l1+l2,l1,l2))
print(l3)

l4=list(map(lambda x: x**2,filter(lambda x: x%2==0,l2)))
print(l4)
