#include <stdio.h>
#include <stdlib.h>

int static compare(const void* first, const void* second){

	if ( *(int *)first > *(int *)second) return 1; 
	else if ( *(int *)first < *(int *)second) return -1; 
	else return 0; 
}

int main()
{
	int N, num; 
	scanf("%d", &N);

	int *list = malloc(sizeof(int) * 10000000); 
	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		list[i] = num; 
	}

	qsort(list, N, sizeof(int), compare); 

	for (int i = 0; i < N; i++) {
		printf("%d\n", list[i]);
	}
}