positions=[int(a) for a in input().split()]
jumps = 0

for i in range(10):
    i=0
    for i in range(len(positions)-2):
        if positions[i] == positions[i+1] - 1 and positions[i] == positions[i+2]-2:
            positions.pop(i)
            i -= 1
    if len(positions) < 3: break
    dist = positions[-1] - positions[1] - len(positions) + 3
    dist2 = positions[-2] - positions[0] - len(positions) + 3
    if dist > dist2:
        positions[0] = positions[1] + 1
    else:
        positions[-1] = positions[-2] - 1
    positions.sort()
    jumps += 1
print(jumps)
