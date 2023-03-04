#!/bin/python3

import sys

num_inputs = int(input())

good_job = 1
a = 0
for _ in range(num_inputs):
    b = int(input())
    
    for i in range(a+2, b+1):
        good_job = 0
        print(i-1)

    a = b
if good_job:
    print("good job")
