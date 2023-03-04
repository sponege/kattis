## Quadrant Selection
x_positive=input()[0]!='-'
y_positive=input()[0]!='-'
if x_positive:
    if y_positive:
        print(1)
    else:
        print(4)
else:
    if y_positive:
        print(2)
    else:
        print(3)
