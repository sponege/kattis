#!/bin/python3

import sys

m,n,s=map(int,input().split())
ans=0
for _ in range(n):
    ans+=1
    a,b=map(int,input().split())
    s=(s*a+b)%m
    if s==0:break
if s==0:print(ans)
else:print(-1)
