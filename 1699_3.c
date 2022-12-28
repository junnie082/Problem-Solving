#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N; 
	scanf("%d", &N); 

	int *dp = (int *)calloc(N+1, sizeof(int)); 
	// 제곱수에다가 1을 집어 넣음. 
	for (int i = 1; i*i <= N; i++) {
		dp[i*i] = 1;  
	}

	for (int i = 2; i <= N; i++) {
		if (i == 2) dp[i] = 2;
		else if (i == 3) dp[i] = 3;
		else {
			if (dp[i] == 0) {
				dp[i] = dp[i-1] + dp[1]; 

				// 제곱수의 배수. 
				for (int j = 2; j*j < i; j++) {
					if (i % (j*j) == 0) {
						if(i / (j*j) < dp[i]) {
							dp[i] = i/(j*j); 
						} 
					}		
				}

				// 가장 가까운 제곱수 k.
				// ===> 무조건 큰 제곱수부터 빼는 것이 정답이 아닙니다.
			 
				for (int j = 1; j*j < i ; j++) {
					if (dp[j*j] + dp[i-j*j] < dp[i]) {
						dp[i] = dp[j*j] + dp[i-j*j]; 
					} 
				}

			}
		}
	}

	printf("%d\n", dp[N]);
	free(dp);  
}