import itertools

n = int(input())
r = 0
for i in range(2,n+1):
    r += len(list(itertools.combinations([f for f in range(n)],i)))
print(r)
