#!/bin/python3

import sys

num_inputs = int(input())
get_input = lambda i: i == 'T'
inputs = [get_input(i) for i in input().split()]
get_input_pos = lambda c: ord(c) - ord('A')

postfix_instructions = input().split()

print(inputs, file=sys.stderr)
print(postfix_instructions, file=sys.stderr)
instr = postfix_instructions
stack = []

# + is or
# * is and
# - is not
while len(instr) > 0:
    i = instr.pop(0)
    if i in '+*-':
        if i == '+':
            a = stack.pop()
            b = stack.pop()
            stack.append(a or b)
            # print to stderr
            print('OR', file=sys.stderr)
        elif i == '*':
            a = stack.pop()
            b = stack.pop()
            stack.append(a and b)
            print('AND', file=sys.stderr)
        elif i == '-':
            stack.append(not stack.pop())
            print('NOT', file=sys.stderr)
    else:
        print(f'INPUT {i}', file=sys.stderr)
        stack.append(inputs[get_input_pos(i)])
    print(stack, file=sys.stderr)
print('T' if stack.pop() else 'F')
