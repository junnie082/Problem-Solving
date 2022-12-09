#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N; 
	scanf("%d", &N); 

	// 메모리 할당. 
	int **dp = (int **)calloc(N+1, sizeof(int*)); 
	for (int i = 1; i <= N; i++) {
		dp[i] = (int *)calloc(10, sizeof(int)); 
	}


	// 각 dp 계산마다 1000000000 를 나눠주지 않으면
	// [틀렸습니다]가 뜬다. 
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j <= 9; j++) {
			if (i == 1) dp[i][j] = 1; 
			else if (j == 0) dp[i][0] = dp[i-1][1] % 1000000000; 
			else if (j == 9) dp[i][9] = dp[i-1][8] % 1000000000; 
			else dp[i][j] = (dp[i-1][j-1] + dp[i-1][j+1]) % 1000000000; 
		}
	}	


	// 결과값 계산. 
	int result = 0;
	for (int j = 1; j <= 9; j++) {
		result += dp[N][j]; 
		result %= 1000000000;
	}
	// 결과 출력. 
	printf("%d", result);

	// 메모리 해제. 
	for (int i = 1; i <= N; i++) {
		free(dp[i]); 
	} free(dp); 
}