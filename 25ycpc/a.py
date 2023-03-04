n,dm = [int(i) for i in input().split()]
d = [int(i) for i in input().split()]

i = 0
earliest = True
while i < len(d):
    if d[i] <= dm:
        earliest = False
        break
    i+=1

print("It hadn't snowed this early in {} years!".format(i) 
      if not earliest
      else "It had never snowed this early!")
