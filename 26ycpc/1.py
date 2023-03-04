## Provinces and Gold
import sys
inputs = [[int(x) for x in y.split()] for y in sys.stdin.read().splitlines()]
#print(inputs)

for input in inputs:
    g, s, c = input
    #print("Gold: {}, Silver: {}, Copper: {}".format(g, s, c))
    money = g * 3 + s * 2 + c
    #print("Money: {}".format(money))

    if money >= 8:
        print("Province or Gold")
    elif money >= 6:
        print("Duchy or Gold")
    elif money >= 5:
        print("Duchy or Silver")
    elif money >= 3:
        print("Estate or Silver")
    elif money >= 2:
        print("Estate or Copper")
    else:
        print("Copper")
