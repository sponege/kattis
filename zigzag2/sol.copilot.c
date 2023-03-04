#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int ans = 0;
	int dir = -1; // -1 = unknown, 0 = down, 1 = up
	int prev = -1, cur = -1;
	
	// keep reading until we hit the end of the file
	while (scanf("%d", &cur) != EOF) {
		// if we don't know the direction yet
		if (dir == -1) {
			// if the current number is greater than the previous number
			if (cur > prev) {
				// we're going up
				dir = 1;
			}
			// if the current number is less than the previous number
			else if (cur < prev) {
				// we're going down
				dir = 0;
			}
		}
		// if we know the direction
		else {
			// if we're going up
			if (dir == 1) {
				// if the current number is less than the previous number
				if (cur < prev) {
					// we've found a zig
					ans++;
					// we're now going down
					dir = 0;
				}
			}
			// if we're going down
			else if (dir == 0) {
				// if the current number is greater than the previous number
				if (cur > prev) {
					// we've found a zag
					ans++;
					// we're now going up
					dir = 1;
				}
			}
		}
		// the current number is now the previous number
		prev = cur;
	}
	printf("%d", ans);
}
