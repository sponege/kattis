a,b=[int(b) for b in input().split()]
d=0
e=0
l=[]
f=0
z=a//b
for c in range(z-9999,z+9999):
   d=b*c
   e=abs(d-a)
   l.append(e)
print(min(l))
