#!/bin/python3

while 1:
    try:
        eq = input()
        res = eval(eq)
        if type(res) is int:
            print(f'{res}.00')
        else:
            res = round(res, 2)
            print(f"{res}{'0'*(2-len(str(res).split('.')[1]))}")
    except EOFError as e:
        break

