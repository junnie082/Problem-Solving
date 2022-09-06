#include <stdio.h>
#include <stdlib.h>

void insert(int *ht, int key, int capacity) {

	int hkey = key % capacity;
	int index;

	for (int i = 0; i < capacity; i++) {
		index = (hkey + i) % capacity;
		if (index < 0) index *= -1;
		if (ht[index] == NULL) {
			ht[index] = key;
			break;
		}
	}
}

int search(int *ht, int key, int capacity) {

	int hkey = key % capacity;
	int index;

	for (int i = 0; i < capacity; i++) {
		index = (hkey + i) % capacity;
		if (index < 0) index *= -1;
		if (ht[index] == key) return 1;
	}
	return 0;
}

int main()
{
	int N, M, key;
	scanf("%d", &N);
	int *A = (int *)malloc(sizeof(int) * N);
	for (int i = 0 ; i < N; i++) {
		scanf("%d", &key);
		insert(A, key, N);
	}

	// for (int i = 0 ; i < N; i++) {
	// 	printf("A[%d]: %d\n", i, A[i]);
	// }

	scanf("%d", &M);
	for (int i = 0 ; i < M; i++) {
		scanf("%d", &key);
		printf("%d\n", search(A, key, N));
	}

	free(A);
}