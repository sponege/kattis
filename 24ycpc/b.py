arrowTotal = int(input())
arrowCords = []


for i in range(arrowTotal):
    arrowCords.append([float(b) for b in input().split()])

top2arrowpos = [[0,0]]*2

def dist(xy):
    x = xy[0]
    y = xy[1]
    return (x**2+y**2)**0.5

for i in range(arrowTotal):
    if dist(arrowCords[i]) > dist(top2arrowpos[0]):
        top2arrowpos[0] = arrowCords[i]
    elif dist(arrowCords[i]) > dist(top2arrowpos[1]):
        top2arrowpos[1] = arrowCords[i]

def _two_point_dist(xy, xy2):
    x = xy[0] - xy2[0]
    y = xy[1] - xy2[1]
    return (x**2+y**2)**0.5

print(_two_point_dist(top2arrowpos[0], top2arrowpos[1]))
