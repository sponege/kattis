#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <bits/stdc++.h>

#define dev 0 

struct path {
	char cur;
	int currentrun; 
	//int distance;
	char path[100];
};

int main() {
	int hit[100];
	char str[100];
	for (int i = 0; i < 100; i++) {
		hit[i] = 0;
		str[i] = 0;
	}

	scanf("%s", str);
	
	int longestrun = 1;
	char longestrunpath[100];

	for (int i = 0; i < strlen(str); i++) {
		// make paths
		struct path* paths = malloc(100000000);
		int num_paths = 1;
		paths[0].cur = str[i];
		paths[0].currentrun = 1;
		//paths[0].distance = 0;
		paths[0].path[0] = str[i];
		// loop through the rest of the string

		for (int j = i; j < strlen(str); j++) {
			//if (hit[j])continue;
			if (dev) fprintf(stderr, "number of paths: %d, current: %c\n", num_paths, str[j]);
			for (int p = 0; p < num_paths; p++) {
				//paths[p].distance++;
				// if current path is in series
				if (str[j] > paths[p].cur) {
					//hit[j] = 1;
				int currun;
					if (paths[p].cur+1!=str[j]){
						// if path is not like ab or fg or uv
						num_paths++;
						paths[num_paths - 1].cur = str[j];
						paths[num_paths - 1].currentrun = paths[p].currentrun+1;
						strcpy(paths[num_paths - 1].path, paths[p].path);
						paths[num_paths - 1].path[paths[p].currentrun] = str[j];
						if (dev) fprintf(stderr, "path: %s\n", paths[num_paths - 1].path);
						//paths[num_paths - 1].distance = 0;
						currun=paths[num_paths - 1].currentrun;
						if (currun > longestrun) {
							longestrun = currun;
							strcpy(longestrunpath, paths[num_paths - 1].path);
						}
					} else {
						// if path is like ab or fg or uv
						paths[p].currentrun++;
						paths[p].path[paths[p].currentrun-1] = str[j];
						paths[p].cur = str[j];
						if (dev) fprintf(stderr, "path: %s\n", paths[p].path);
						//paths[p].distance = 0;
						currun = paths[p].currentrun;
						if (currun > longestrun) {
							longestrun = currun;
							strcpy(longestrunpath, paths[p].path);
						}
					}
				} else {
					if (dev) fprintf(stderr, "path rejected: %c\n", str[j]);
				}
				//fprintf(stderr, "start: %c, cur: %c, index: %c, run: %d\n", str[i], cur, str[j], currentrun);
			}
		}
	}
	fprintf(stderr, "longest run: %s\n", longestrunpath);
/*	if (strlen(str) == 1) {
		longestrun = 1;
	}*/
	printf("%d", 26-longestrun);
}
