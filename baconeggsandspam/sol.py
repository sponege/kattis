#!/bin/python3

import sys

lines = sys.stdin.readlines()

while len(lines)>0:
    n=int(lines.pop(0))
    menu={}
    for _ in range(n):
        line=lines.pop(0).split()
        item=line[0]
        names=line[1:]
        for name in names:
            if name in menu:
                menu[name].append(item)
            else:
                menu[name]=[item]
    menu={k:sorted(v) for k,v in menu.items()}
    menu=[(k,menu[k]) for k in sorted(menu.keys())]
    if len(menu)==0:continue
    print('\n'.join([f'{k} {" ".join(v)}' for k,v in menu]))
    print()
