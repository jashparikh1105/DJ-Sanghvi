l=[13,12,11,13,14,13,7,7,13,14,12]
dict={}
for x in l:
    if x in dict:
        dict[x]+=1
    else:
        dict[x]=1
l1=[]
for k,v in dict.items():
    a=(k,v)
    l1.append(a)
l1=sorted(l1)
l2=[(y,x) for x,y in l1]
l2=sorted(l2)
l2=[(y,x) for x,y in l2]
print(l2)
