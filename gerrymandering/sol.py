#!/bin/python3

import sys


p, d = map(int, input().split())
ds = []
for _ in range(d):
    ds.append([0, 0]) # [a, b]

print(ds, file=sys.stderr)
for _ in range(p):
    di, votesA, votesB = map(int, input().split())
    di -= 1
    print(di, votesA, votesB, file=sys.stderr)
    # B 100 49
    # A 1 197
    # A 49 100
    # 0.1965897693
    ds[di][0] += votesA
    ds[di][1] += votesB

print(ds, file=sys.stderr)
for d in ds:
    output = []
    output.append('A' if d[0] > d[1] else 'B')
    a_wasted_votes = d[0] - d[1] if d[0] > d[1] else d[0]
    b_wasted_votes = d[1] - d[0] if d[1] > d[0] else d[1]
    output.append(str(a_wasted_votes))
    output.append(str(b_wasted_votes))

    print(' '.join(output))

