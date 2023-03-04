a,b=[int(b) for b in input().split()]
c=a
d=a
m=0
while 1:
    if c%b==0 or d%b==0:
        break
    c+=1
    d-=1
    m+=1
print(m)
