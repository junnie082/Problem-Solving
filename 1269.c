#include <stdio.h>
#include <stdlib.h>

int main()
{
	int nA, nB, n, a, b;

	scanf("%d %d", &nA, &nB);

	int sum = nA + nB;
	int *A = calloc(nA, sizeof(int));
	int *B = calloc(nB, sizeof(int));

	for (int i = 0; i < nA; i++) {
		scanf("%d", &a);
		A[i] = a;
	}

	for (int i = 0; i < nB; i++) {
		scanf("%d", &b);
		B[i] = b;
	}

	for (int i = 0; i < nA; i++) {
		for (int j = 0; j < nB; j++) {
			if (A[i] == B[j]) {
				sum -=2;
				break; 
			}
		}
	}

	
	printf("%d", sum); 
	free(A);
	free(B);

}