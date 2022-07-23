#include <stdio.h>
#include <stdlib.h>

int static compare(const void *a, const void *b)
{
	int first = *(int *) a;
	int second = *(int *) b;

	if (first > second) return 1;
	else if (first < second) return -1; 

	return 0; 
}

int main()
{
	int n, sum = 0;

	scanf("%d", &n);
	int *arr = malloc(sizeof(int) * n);

	for (int i = 0; i < n; i++) 
		scanf("%d", &arr[i]);

	int *p = arr;

	qsort(arr, n, sizeof(int), compare);

	for (int i = 0; i < n; i++) {
		arr[i] = *p;

		if (i == n-1) break;

		*(p+1) += *p;
		p++;
	}

	for (int i = 0; i < n; i++) sum += arr[i];

	printf("%d", sum);
	free(arr); 

	return 0; 
}
