#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* ascii;

char* decode(char* str) {
		int len = strlen(str);
		char* decoded = (char*)malloc(len+1);
		char* ptr = decoded;
		while (*str) {
			if (*str == 35) { // # control code
				*ptr++ = *++str - 38;
			} else if (*str == 36) { // $ control code
				*ptr++ = *++str + (89 + 89);
			} else if (*str == 37) { // % control code
				*ptr++ = *++str + 89;
			} else {
				*ptr++ = *str;
			}
			++str;
		}
		*ptr = 0;
		return decoded;
}

int read(int i) {
	return ascii[i/8] >> (i%8) & 1;
}


void print(char* str) {
	int len = strlen(str);

	for (int y = 0; y < 7; y++) {
		for (int x = 0; x < len; x++) {
			int index = str[x] - '0';
			if (str[x] == '+') index = 10;
			if (index>=0){
				for (int c = 0; c < 6-(x>(len-3)); c++) {
					putchar((read((index*7+y)*5+c)&&c<5)?'#':'.');
				}
			}
		}
		puts("");
	}
}

int main() {
	ascii = decode("?%m#>$1%.#6B#.$/%.$>%.$>?%+#E%i#Ec$J#6%i#E%i%.$>$M#6~%3$MC#.#G%+?%m#E$1$M1~#.?#F$2#9#(");

	char* input = (char*)malloc(999);
	fgets(input, 999, stdin);

	print(input);
}

