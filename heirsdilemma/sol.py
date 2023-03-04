#!/bin/python3

import sys

L, H = list(map(int, input().split()))

ans = 0

for i in range(L, H+1):
    c = str(i)
    if '0' in c: continue
    if len(set(c)) != len(c): continue
    failed = False
    for num in c:
        if i % int(num) != 0:
            failed = True
            break
    if failed: continue
    ans += 1

print(ans)
