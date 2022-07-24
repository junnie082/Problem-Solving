#include <stdio.h>
#include <stdlib.h>

int static ascend(const void *a, const void *b)
{
	int first = *(int *)a;
	int second = *(int *)b;

	if (first > second) 
		return 1;
	else if (first < second)
		return -1;

	return 0; 
}

int static descend(const void *a, const void *b)
{
	int first = *(int *)a;
	int second = *(int *)b;

	if (first > second) return -1;
	else if (first < second) return 1;

	return 0; 
}

int main()
{
	int n, sum=0;
	scanf("%d", &n);

	int *A = malloc(sizeof(int) * n);
	int *B = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) scanf("%d", &A[i]);
	for (int i = 0; i < n; i++) scanf("%d", &B[i]);

	qsort(A, n, sizeof(int), descend);
	qsort(B, n, sizeof(int), ascend);

	for (int i = 0; i < n; i++) {
		sum += A[i] * B[i];
	}

	printf("%d", sum);
	return 0;

}