#include <stdio.h>
#include <math.h>

int main() {
	int num_data_sets;
	scanf("%d", &num_data_sets);

	for (int i = 0; i < num_data_sets; i++) {
		int data_set, p, q;
		scanf("%d %d/%d", &data_set, &p, &q);

		int num_terms = 0;
		// breadth-first traversal of the tree
		// label of root is p/q
		// label of left child is p/(p+q)
		// label of right child is (p+q)/q
		// calculate which child you are on, given p and q and which data set you are on
		
		int row_num = log((p + q) - 1) / log(2);

		printf("%d %d %d %d\n", data_set, p, q, row_num);
		

	}
}
