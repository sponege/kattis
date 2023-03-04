#!/bin/python3

import sys

word = input()
alphabet = input()
lives = 10

for letter in alphabet:
    if letter in word:
        word=word.replace(letter, '')
    else:
        lives-=1
    if lives == 0:
        print('LOSE')
        sys.exit()
    if word == '':
        print('WIN')
        sys.exit(
                )
