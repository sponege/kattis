import itertools
cases=int(input())
for case in range(cases):
    input()
    a=list(map(int,input().split()))
    a.sort(reverse=True)
    b=list(map(int,input().split()))
    b.sort()
    ans = 0
    for i in range(len(a)):
        ans += a[i]*b[i]
    print(f"Case #{case+1}: {ans}")

