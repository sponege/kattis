## Cold-puter Science
import sys
input()
y = input()
inputs = [int(x) for x in y.split()]

c = 0
for i in inputs:
    if i < 0:
        c += 1
print(c)
