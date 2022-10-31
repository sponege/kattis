#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define rep(i, a, b) for (int i = a; i < b; ++i)

unsigned char* encode(unsigned char* str) {
		int len = strlen(str);
		unsigned char* encoded = (unsigned char*)malloc(len*2+1); // char should be a byte in size, we are doubling to be safe.
		unsigned char* ptr = encoded;
		while (*str) {
			if (*str < 38) {
				*ptr++ = 35; // # control code
				*ptr++ = *str + 38;
			} else if (*str >= 38 + 89 + 89) {
				*ptr++ = 36; // $ control code
				*ptr++ = *str - (89 + 89);
			} else if (*str >= 38 + 89) {
				*ptr++ = 37; // % control code
				*ptr++ = *str - 89;
			} else {
				*ptr++ = *str;
			}
			++str;
		}
		*ptr = 0;
		return encoded;
}

unsigned char* decode(unsigned char* str) {
		int len = strlen(str);
		unsigned char* decoded = (unsigned char*)malloc(len+1);
		unsigned char* ptr = decoded;
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
	// printf("%s", encode("Hello World!"));
	// return 0;
	FILE *fp = fopen("ascii-nums.txt", "r");
	if (fp == NULL) {
		printf("Error opening file\n");
		return 1;
	}

	char* bytes = malloc(57); // really only need 49 bytes, this is weird.....
	
	rep(i, 0, 7*11) {
		char line[5];
		fscanf(fp, "%c%c%c%c%c\n", &line[0], &line[1], &line[2], &line[3], &line[4]);
		rep(j, 0, 5) {
			printf("%c", line[j]);
			if (line[j] != '.') {
				bytes[(i*5+j)/8] |= 1 << ((i*5+j)%8);
			}
		}
		printf("\n");

	}

	printf("\n");

	rep(i, 0, 7*5*11) {
		printf("%c", (bytes[i/8] >> (i%8)) & 1 ? 'x' : '.');
		if (i % 5 == 4) {
			printf("\n");
		}
		if (i % 35 == 34) {
			printf("\n%i\n", i/8);
		}
	}

	rep(i, 0, sizeof bytes) {
		printf("0x%hhx, ", bytes[i]);
	}

	printf("\n\n");
	printf("char a[] = \"%s\";\n", encode(bytes));
	printf("char b[] = \"%s\";\n", encode(decode(encode(bytes))));
	//encode(bytes);

}
