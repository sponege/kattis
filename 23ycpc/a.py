prices = []
for i in range(int(input())):
    prices.append(int(input()))

prices.sort()

groups = []
while 1:
    try:
        for i in range(2):
            groups.append(prices.pop())
        prices.pop()
    except:
        break

print(sum(groups))


#print(sum(prices[:-(len(prices)//3)-1]))
