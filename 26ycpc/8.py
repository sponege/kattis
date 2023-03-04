## Encoded Message

l = int(input())
for z in range(l):
    ## decode

    s = input()
    for i in range(l):
        for j in range(l):
            print(s[j][i], end='')
    print()
