z=1
while 1:
    w,h=[int(b) for b in input().split()]
    m=[]
    if w==0:
        break
    for i in range(h):
        m.append([c for c in input()])
    x=0
    y=0
    s=0
    for l in m:
        #print(l)
        for c in l:
            if c=='*':
                s=1
                break
            x+=1
        if s:break
        x=0
        y+=1
    #print(x,y,s)
    dx=1
    dy=0
    if x!=0:
        if y==0:
            dy=1
            dx=0
        else:
            dx=-1
    if y==len(m)-1:
        dy=-1
        dx=0
    while not m[y][x]=='x':
        y+=dy
        x+=dx
        if m[y][x]=='/':
            swp=dx
            dx=-dy
            dy=-swp
        elif m[y][x]=='\\':
            swp=dx
            dx=dy
            dy=swp
    m[y][x]='&'
    print(f"HOUSE {z}")
    print('\n'.join([''.join(l)for l in m]))
    z+=1
