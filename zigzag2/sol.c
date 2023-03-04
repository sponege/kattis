#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
	int ans = 0;
	int dir = -1; // -1 = unknown, 0 = down, 1 = up
	int prev = -1, cur = -1;
	
	// keep reading until we hit the end of the file
	while (scanf("%d", &cur) != EOF) {
		if (prev == -1 || cur == -1) {
			prev = cur;
			continue; // if we do not have both previous and current, keep reading!
		}
		// we need to figure out if we have changed directions yet
		if (prev < cur) {
			if (dir == 0) ans++; // if we zig, we increment the length
			dir = 1; // going up!
		}
		if (prev > cur) {
			if (dir == 1) ans++; // if we zag, we also increment the length
			dir = 0; // going down!
		}
		prev = cur; // update prev
	}
	printf("%d", ans);
}
