// Integer Estate Agent
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
	int n, ans;
	while (1) {
		scanf("%d\n", &n);
		if (!n) return 0;
		ans = 0;
		for (int i = 2; i <= n; i++) {
			int a = i;
			int s = n;
			double sum = (2 * s) + (a * a) - a;
			// assert if sum is not an integer
			if (sum != (int)sum) { puts("sum not integer"); exit(1); }
			double b = sqrt((4 * sum) + 1) - 1;
			// assert if b is not an integer
			if (b != (int)b) { 
				//printf("b not integer %i %i %lf %lf", a, s, sum, b); exit(1); 
				continue;
			}
			if ((int)b % 2 == 0) { 
				ans++;
				//printf("%i\n", i);
			};
		}
		//printf("%d %d\n", n, ans);
		printf("%d\n", ans);
	}
}
