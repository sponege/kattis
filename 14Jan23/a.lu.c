// Integer Estate Agent
#include <stdio.h>

int main() {
	int ans;
	for (int n = 1; n < 1000000; n++) {
		ans = 0;
		for (int i = 1;  i < n; i++) {
			int sum = 0;
			int j = i;
			int len = 0;
			while (sum < n) {
				sum += j + 1;
				j++;
				len++;
			}
			if (n == sum) {
				ans++;
			}
		}
		printf("%d %d\n", n, ans);
	}
}
