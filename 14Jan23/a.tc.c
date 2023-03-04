// generate 50 thousand test cases
// a test case is one random number between 0 and 1000000

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
	srand(time(NULL));
	for (int i = 0; i < 50000; i++) {
		printf("%d\n", rand() % 1000000);
	}
}
