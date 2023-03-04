#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	char str[101];
	scanf("%s", str);
	int len = strlen(str);
	for (int n = 1; n <= len; n++) {
		if (len % n != 0) continue;
		int success = 1;
		for (int index = 0; index < len/n; index++) {
			for (int i = 0; i < n; i++) {
				if (str[i] != str[(index*n)+((index+i)%n)]) {
					success = 0;
					break;
				}
			}
			if (!success) break;
		}
		if (success) {
			printf("%d", n);
			return 0;
		}
	}
}
