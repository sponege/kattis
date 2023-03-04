// Rainbow Road Race
#include <stdio.h>
#include <stdlib.h>

struct street {
	int length;
	char color;
	int leads_to; // leads to tent number
};

struct tent {
	int num_streets;
	struct street *streets;
};

struct tent *tents;

struct path {
	int length;
	int *tents;
};

struct path *paths;

int main() {
	int n, m;
	// n - number of tents
	// m - number of streets
	scanf("%d %d\n", &n, &m);
	printf("%d %d\n", n, m);
	tents = malloc(sizeof(struct tent) * (n+1)); // allocate memory for all tents
	// zero out all the allocated memory
	for (int i = 0; i < n; i++) {
		tents[i].num_streets = 0;
		tents[i].streets = NULL;
	}
	for (int i = 0; i < m; i++) {
		int t1, t2, d; // tent 1, tent 2, distance
		char color; // color of street
		scanf("%d %d %d %c\n", &t1, &t2, &d, &color);
		//printf("%d %d %d %c\n", t1, t2, d, color);
		tents[t1].num_streets++;
		tents[t2].num_streets++;
		tents[t1].streets = realloc(tents[t1].streets, sizeof(struct street) * tents[t1].num_streets);
		tents[t2].streets = realloc(tents[t2].streets, sizeof(struct street) * tents[t2].num_streets);
		tents[t1].streets[tents[t1].num_streets-1].length = d;
		tents[t2].streets[tents[t2].num_streets-1].length = d;
		tents[t1].streets[tents[t1].num_streets-1].color = color;
		tents[t2].streets[tents[t2].num_streets-1].color = color;
		tents[t1].streets[tents[t1].num_streets-1].leads_to = t2;
		tents[t2].streets[tents[t2].num_streets-1].leads_to = t1;

	}

	// print out all streets tent 4 is connected to
	/*int tent = 1;
	for (int i = 0; i < tents[tent].num_streets; i++) {
		printf("%d %d %c\n", tents[tent].streets[i].leads_to, tents[tent].streets[i].length, tents[tent].streets[i].color);
	}*/

	// pathfind shortest path reaching all colors ROYGBIV
	// start at tent 1
	// reach all colors
	// go back to tent 1
	// find shortest path
	//
	
	paths = malloc(sizeof(struct path) * n);
	for (int i = 0; i < n; i++) {
		paths[i].length = 0;
		paths[i].tents = NULL;
	}
	

	// free all allocated memory
	for (int i = 0; i < n; i++) {
		free(tents[i].streets);
	}
	free(tents);
}
