#include <stdio.h>
#include <stdlib.h>
#define max(a,b,c) (a>b)?(a>c)?a:c:(b>c)?b:c

int main() {
	int n;
	char*answers=malloc(100);
	scanf("%d %s", &n, answers);
	
	char friends[][7] = {"Adrian", "Bruno", "Goran"};
	char adrian[] = {'A', 'B', 'C'};
	char bruno[] = {'B', 'A', 'B', 'C'};
	char goran[] = {'C', 'C', 'A', 'A', 'B', 'B'};

	int adrian_score = 0;
	int bruno_score = 0;
	int goran_score = 0;

	for (int i = 0; i < n; i++) {
		if (answers[i] == adrian[i % 3]) {
			adrian_score++;
		}
		if (answers[i] == bruno[i % 4]) {
			bruno_score++;
		}
		if (answers[i] == goran[i % 6]) {
			goran_score++;
		}
	}
	
	int highest_score = max(adrian_score, bruno_score, goran_score);
	

	printf("%d\n", highest_score);

	if (highest_score == adrian_score) {
		printf("%s\n", friends[0]);
	}
	if (highest_score == bruno_score) {
		printf("%s\n", friends[1]);
	}
	if (highest_score == goran_score) {
		printf("%s\n", friends[2]);
	}
}
