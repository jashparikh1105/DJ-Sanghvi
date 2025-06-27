s = """Rohit Sharma is the captain of the Indian Cricket team.
He is one of the greatest batsmen.
He is a very kind-hearted person."""

words = s.split()
sentences = s.split('.')
lines = s.split('\n')

l1=[]

for x in words:
    if(len(x)>3 and len(x)<7):
        l1.append(x)

print("Words: ")
print(len(words))
print("Sentences: ")
print(len(sentences)-1)
print("Lines: ")
print(len(lines))
print("Words with length >3 and <7: ")
print(l1)
