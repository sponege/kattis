cases=int(input())
colors=[]
for case in range(cases):
    things = input().split()
    try:
        num = int(things[0])/2
        color = things[1]
    except:
        num = int(things[1])
        color = things[0]
    colors.append((num,color))
colors.sort()
print("\n".join(list(map(lambda color: color[1], colors))))
