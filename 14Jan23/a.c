// Integer Estate Agent
#include <stdio.h>

int main() {
	int n, ans;
	while (1) {
		scanf("%d\n", &n);
		if (!n) return 0;
		ans = 0;
		for (int i = 1; i < n; i++) {
			int sum = 0;
			int j = i;
			while (sum < n) {
				sum += j + 1;
				j++;
			}
			if (n == sum) ans++;
		}
		printf("%d\n", ans);
	}
}
