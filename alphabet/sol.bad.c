#include <stdio.h>

int main() {
	char str[50];

	scanf("%s", str);

	char lastChar = str[0];
	int lettersRequired = 26, currentRequired = 0;

	for (int i = 0; i < strlen(str); i++) {

		if (str[i] >= lastChar) {
			// if in series
			// ex: abc or afiz if ordered
			currentRequired += str[i] - lastChar; // find the distance between the two letters
		} else {
			// if not in series
			// ex: zyx or zyxwvuts
			currentRequired = 0; // restart for a new series
			if (currentRequired < lettersRequired) { // if the series has ended
				lettersRequired = 'z'-str[i]+currentRequired; // calculate the distance from the last letter to z
			}
			
		}

		lastChar = str[i];


		fprintf(stderr, "%c %d %d\n", str[i], currentRequired, lettersRequired);


	}
	if (currentRequired < lettersRequired) { // if the series has ended
		lettersRequired = 'z'-str[strlen(str)]+currentRequired; // do this one last time
	}
	printf("%d",lettersRequired);
}
