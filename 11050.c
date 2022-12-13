#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, K; 
	scanf("%d %d", &N, &K); 

	int *numerator = (int *)malloc(sizeof(int) * K); 
	int *denominator = (int *)malloc(sizeof(int) * K); 

	int k = K;
	for (int i = 0; i < K; i++) {
		numerator[i] = N--;
		denominator[i] = k--; 
	}

	int n; 
	for (int i = 0; i < K; i++) {
		for (int k = 0; k < K; k++) {
			n = numerator[i] > denominator[i] ? numerator[i] : denominator[i]; 
			for (int j = 1; j <= n; j++) {
				if (numerator[i] % j == 0 && denominator[k] % j == 0) {
					numerator[i] /= j; 
					denominator[k] /= j; 
				}
			}
		}
	}

	// 분모 구하기. 
	int num = 1;
	int den = 1; 
	for (int i = 0; i < K; i++) {
		num *= numerator[i]; 
		den *= denominator[i]; 
	}


	printf("%d\n", num/den);
	free(numerator); free(denominator); 
}