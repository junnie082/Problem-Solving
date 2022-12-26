#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, K;
	scanf("%d %d", &N, &K); 
	// 동적 이차원 배열 메모리 할당. 
	int **dp = (int **)calloc(N+1, sizeof(int *)); 

	for (int i = 0; i <= N; i++) {
		dp[i] = (int *)calloc(K+1, sizeof(int)); 
	}

	// 답을 1,000,000,000 으로 나눈 나머지를 출력 -> mod 연산.
	for (int j = 1; j <= K; j++) {
		for (int i = 0; i <= N; i++) {
			if (j == 1 || i == 0) {
				dp[i][j] = 1;
			} else {
				for (int t = 0; t <= i; t++) {
					dp[i][j] = (dp[i][j]%1000000000+dp[t][j-1]%1000000000) % 1000000000; 
				}
			}
			//printf("dp[%d][%d]: %d\n", i, j, dp[i][j]); 
		}
	}

	printf("%d\n", dp[N][K]%1000000000); 

	// 동적 이차원 배열 해제. 
	for (int i = 0; i <= N; i++) {
		free(dp[i]); 
	} free(dp); 

}