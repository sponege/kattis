
def find_longest_alpha_string(s):
    current = ""
    longest = ""

    for c in s:
        if len(current) == 0 or ord(c) >= ord(current[-1]):
            current += c
        else:
            if len(current) > len(longest):
                longest = current
            current = c

    if len(current) > len(longest):
        longest = current

    return longest

print(find_longest_alpha_string(input()))
