import itertools

numbers = [10,20,40,60,70] 
target = 70

result = [seq for i in range(len(numbers), 0, -1)
          for seq in itertools.combinations(numbers, i)
          if sum(seq) == target]

print(result)
