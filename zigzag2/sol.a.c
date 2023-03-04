#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/**
 * Problem J
Zigzag

A sequence of integers is said to Zigzag if adjacent elements alternate between strictly increasing and strictly decreasing. Note that the sequence may start by either increasing or decreasing. Given a sequence of integers, determine the length of the longest subsequence that Zigzags. For example, consider this sequence:

1 2 3 4 2

There are several Zigzagging subsequences of length

:

1 3 2        1 4 2        2 3 2        2 4 2        3 4 2

But there are none of length greater than
, so the answer is

.
Input

Each input will consist of a single test case. Note that your program may be run multiple times on different inputs. The first line of input contains an integer
() which is the number of integers in the list. Each of the following lines will have an integer (

).
Output

Output a single integer, which is the length of the longest Zigzagging subsequence of the input list.*/
int main() {
	// solve
	int n;
	scanf("%d", &n);
	int *a = (int *)malloc(sizeof(int) * n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int *dp = (int *)malloc(sizeof(int) * n);
	int *dp2 = (int *)malloc(sizeof(int) * n);
	int max = 0;
	
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		dp2[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) {
				if (dp[j] + 1 > dp[i]) {
					dp[i] = dp[j] + 1;
				}
			}
			if (a[i] < a[j]) {
				if (dp2[j] + 1 > dp2[i]) {
					dp2[i] = dp2[j] + 1;
				}
			}
		}
		if (dp[i] > max) {
			max = dp[i];
		}
		if (dp2[i] > max) {
			max = dp2[i];
		}
	}
	printf("%d", max);

}

