# not my solution, but it's good to compare my golfed version with this one

from os import uname

def ascii_to_string(ascii):
	if ascii == ('xxxxx',
				'x...x',
				'x...x',
				'x...x',
				'x...x',
				'x...x',
				'xxxxx'):
		return '0'
	elif ascii == ('....x',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x'):
		return '1'
	elif ascii == ('xxxxx',
				'....x',
				'....x',
				'xxxxx',
				'x....',
				'x....',
				'xxxxx'):
		return '2'
	elif ascii == ('xxxxx',
				'....x',
				'....x',
				'xxxxx',
				'....x',
				'....x',
				'xxxxx'):
		return '3'
	elif ascii == ('x...x',
				'x...x',
				'x...x',
				'xxxxx',
				'....x',
				'....x',
				'....x'):
		return '4'
	elif ascii == ('xxxxx',
				'x....',
				'x....',
				'xxxxx',
				'....x',
				'....x',
				'xxxxx'):
		return '5'
	elif ascii == ('xxxxx',
				'x....',
				'x....',
				'xxxxx',
				'x...x',
				'x...x',
				'xxxxx'):
		return '6'
	elif ascii == ('xxxxx',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x'):
		return '7'
	elif ascii == ('xxxxx',
				'x...x',
				'x...x',
				'xxxxx',
				'x...x',
				'x...x',
				'xxxxx'):
		return '8'
	elif ascii == ('xxxxx',
				'x...x',
				'x...x',
				'xxxxx',
				'....x',
				'....x',
				'xxxxx'):
		return '9'
	elif ascii == ('.....',
				'..x..',
				'..x..',
				'xxxxx',
				'..x..',
				'..x..',
				'.....'):
		return '+'

def string_to_ascii(string):
	if string == '0':
		return ('xxxxx',
				'x...x',
				'x...x',
				'x...x',
				'x...x',
				'x...x',
				'xxxxx')
	elif string == '1':
		return ('....x',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x')
	elif string == '2':
		return ('xxxxx',
				'....x',
				'....x',
				'xxxxx',
				'x....',
				'x....',
				'xxxxx')
	elif string == '3':
		return ('xxxxx',
				'....x',
				'....x',
				'xxxxx',
				'....x',
				'....x',
				'xxxxx')
	elif string == '4':
		return ('x...x',
				'x...x',
				'x...x',
				'xxxxx',
				'....x',
				'....x',
				'....x')
	elif string == '5':
		return ('xxxxx',
				'x....',
				'x....',
				'xxxxx',
				'....x',
				'....x',
				'xxxxx')
	elif string == '6':
		return ('xxxxx',
				'x....',
				'x....',
				'xxxxx',
				'x...x',
				'x...x',
				'xxxxx')
	elif string == '7':
		return ('xxxxx',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x',
				'....x')
	elif string == '8':
		return ('xxxxx',
				'x...x',
				'x...x',
				'xxxxx',
				'x...x',
				'x...x',
				'xxxxx')
	elif string == '9':
		return ('xxxxx',
				'x...x',
				'x...x',
				'xxxxx',
				'....x',
				'....x',
				'xxxxx')
	elif string == '+':
		return ('.....',
				'..x..',
				'..x..',
				'xxxxx',
				'..x..',
				'..x..',
				'.....')

ascii = []
line = input()

for pos in range(0, len(line), 6):
	ascii.append([line[pos:pos+5]])

for i in range(6):
	line = input()
	for pos in range(0, len(line), 6):
		ascii[pos//6].append(line[pos:pos+5])

input_value = ''
for i in range(len(ascii)):
	input_value += ascii_to_string(tuple(ascii[i]))

output_value = str(eval(input_value))
output_lines = ['']*7
for line in range(7):
	for i in range(len(output_value) - 1):
		output_lines[line] += string_to_ascii(output_value[i])[line] + '.'
	output_lines[line] += string_to_ascii(output_value[len(output_value) - 1])[line]
