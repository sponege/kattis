#include <stdio.h>
int getWays(int n);

int main() {
	int n;

	// the plank
	// test all planks to build bigger planck with width n
	// you have plancks with width 1, 2, and 3
	// you can use each planck as many times as you want
	// you have too fill out the whole width of the plank
	// get the number of possible ways to build the plank
	
	while (1) {
		int code = scanf("%d", &n);
		if (code!=1) {
			return 0;
		}
		int ways = getWays(n);
		printf("%d\n", ways);
	}
}

int getWays(int n){
	if (n == 1) {
		return 1;
	}
	if (n == 2) {
		return 2;
	}
	if (n == 3) {
		return 4;
	}
	return getWays(n-3) + getWays(n-2) + getWays(n-1);
}
