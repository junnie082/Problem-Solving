#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, K; 
	scanf("%d %d", &N, &K); 

	int *greedy = (int *)malloc(sizeof(int) * N); 

	int val; 
	for (int i = N-1; i >= 0; i--) {
		scanf("%d", &val);
		greedy[i] = val; 
	}

	int count = 0, remain = K; 

	for (int i = 0; i < N; i++) {
		count += remain / greedy[i]; 
		remain = remain % greedy[i]; 
		// printf("greedy: %d ", greedy[i]); 
		// printf("count: %d, remain: %d\n", count, remain); 
	}

	printf("%d\n", count);
	free(greedy); 
}