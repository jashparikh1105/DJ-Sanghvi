import re
with open("regEx.txt","r") as file:
    data=file.read()
print()
name = re.compile(r"\b\. ([a-zA-Z]+)\b")
names=name.findall(data)
for x in names:
    print(x)
    
website=re.compile(r"\b([wwwplus].[a-zA-Z\.]+[comin].)\b")
websites=website.findall(data)
for w in websites:
    print(w)

email=re.compile(r"\b([a-zA-Z\.\d\d_]+@[a-zA-Z\.]+)\b")
emails=email.findall(data)
for e in emails:
    print(e)

number=re.compile(r"\d{8}|\d{3}\*\d{3}\*\d{2}|\d{3}-\d{2}-\d{3}|\d{3}-\d{3}-\d{5}|\d{5}\*\d{3}\*\d{3}")
numbers=number.findall(data)
for n in numbers:
    print(n)
