def gcd(a, b):
    if a == 0:
        return b
    return gcd(b % a, a)

def reduceFraction(a, b):
    return (a//gcd(a,b), b//gcd(a,b))

input() # blah
i = [int(a) for a in input().split(' ')]
numerator = i[0]
denoms = i[1:]
denoms = [reduceFraction(numerator, denom) for denom in denoms]
print('\n'.join(['/'.join([str(a) for a in denom]) for denom in denoms]))


