import sys
grid = [[int(a) for a in b.split(' ')] for b in sys.stdin.read().splitlines()]

def find(a):
    for y in range(len(grid)):
        for x in range(len(grid[y])):
            if grid[y][x]==a:
                return (x,y)

p = [find(a) for a in range(1,10)] ## positions

def dist(a,b):
    return ((a[0]-b[0])**2 + (a[1]-b[1])**2) ** (1/2)

ans = sum(dist(p[i],p[i+1]) for i in range(8))
print(ans)
