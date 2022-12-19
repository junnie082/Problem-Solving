#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N;
	scanf("%d", &N); 

	// dp 이차원 배열 생성. 
	long long int **dp = (long long int **)calloc(11, sizeof(long long int *)); 
	for (int i = 0; i <= 10; i++) {
		dp[i] = (long long int *)calloc(N+1, sizeof(long long int)); 
	}

	// dp[10] 에는 dp[1][i] 부터 dp[9][i] 까지 합한 수를 넣을 것임. 
	long long int sum = 0; 
	// 초깃값. dp[i][1] = 1
	for (int i = 0; i <= 9; i++) {
		dp[i][1] = 1;
		sum += 1;
	}
	dp[10][1] = sum;



	for (int i = 2; i <= N; i++) {
		sum = 0; 
		for (int j = 0; j <= 9; j++) {
			if (j == 0) {
				// 이차원 배열의 첫번째 가로줄은, 
				// 이전 세로줄의 모든 값을 합한 값과 같다.
				// 그 값은, dp[0][i-1] 과 같다. 
				dp[j][i] = dp[10][i-1]%10007;
			} else {
				// 음수의 mod 는 어떻게 계산할래? ===> 이것 땜시.
				// 틀렸습니다 가 여러번 나왔다. 
				//printf("%d", (-1+3) % 3);
				dp[j][i] = (dp[j-1][i]%10007-dp[j-1][i-1]%10007 + 10007)%10007;
			}
			sum += dp[j][i];
		}
		dp[10][i] = sum%10007; 
	}

	printf("%lld\n", dp[10][N]%10007); 

	// 메모리 해제
	for (int i = 0; i <= 10; i++) {
		free(dp[i]); 
	} free(dp); 

}