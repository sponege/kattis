#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define rep(i, a, b) for (int i = a; i < b; ++i)

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

int main() {
	char* bytes = decode("?%m#>$1%.#6B#.$/%.$>%.$>?%+#E%i#Ec$J#6%i#E%i%.$>$M#6~%3$MC#.#G%+?%m#E$1$M1~#.?#F$2#9#(");
	printf("\n\n");
	rep(i, 0, 7*5*11) {
		printf("%c", (bytes[i/8] >> (i%8)) & 1 ? 'x' : '.');
		if (i % 5 == 4) {
			printf("\n");
		}
		if (i % 35 == 34) {
			printf("\n\n");
		}
	}
}

