#include <stdio.h>
#include <stdlib.h>

struct Node {
	int start;
	int end;
};

int compare(const void *a, const void *b) {
	int num1 = ((struct Node *)a) -> end;
	int num2 = ((struct Node *)b) -> end;

	if (num1 < num2) return -1; 
	if (num2 > num1) return 1;

	return 0; 
}

int main()
{
	int N, start, end;
	scanf("%d", &N); 

	struct Node *table[N];

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end); 
		table[i] -> start = start;
		table[i] -> end = end;
	}

	qsort(table, N, sizeof(struct Node), compare);
	
	for (int i = 0; i < N; i++) {
		printf("%d\n", table[i] -> end);
	}
}