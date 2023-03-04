## Cryptographer's Conundrum
# https://open.kattis.com/problems/conundrum

a = input().lower()
c = 0
for i in range(len(a)):
    if a[i] != 'per'[i % 3]:
        c += 1

print(c)
