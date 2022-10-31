#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define c char
#define w while
#define f if
#define l else if
#define e else
#define n "\n\n"
#define p printf

// not up to date with cmin, idc

c* d(c* a) {
		c* z = malloc(strlen(a)+1);
		c* b = z;
		w (*a) {
			f (*a == 35) {
				*b++ = *++a - 38;
			} l (*a == 36) {
				*b++ = *++a + 178;
			} l (*a == 37) {
				*b++ = *++a + 89;
			} e {
				*b++ = *a;
			}
			++a;
		}
		*b = 0;
		return z;
}

main() {
	c* a = d("?%m#>$1%.#6B#.$/%.$>%.$>?%+#E%i#Ec$J#6%i#E%i%.$>$M#6~%3$MC#.#G%+?%m#E$1$M1~#.?#F$2#9#(");
	p(n);
	for(int i=0;i<385;++i) {
		p("%c", a[i/8] >> (i%8) & 1 ? 'x' : 46);
		f (i % 5 == 4) {
			p("\n");
		}
		f (i % 35 == 34) {
			p(n);
		}
	}
}

