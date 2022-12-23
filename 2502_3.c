#include <stdio.h>
#include <stdlib.h>

typedef struct _formula {
	// 상수
	int constant; 
	// 계수
	int coefficient; 
} formula;

int main()
{
	int D, K; 
	scanf("%d %d", &D, &K); 

	formula *dp = (formula *)malloc(sizeof(formula) * (D+1)); 

	// dp[1] 
	dp[1].constant = K; dp[1].coefficient = 0; 
	// dp[2]
	dp[2].constant = 0; dp[2].coefficient = 1; 
	// dp[3] 부터.
	for (int i = 3; i <= D; i++) {
		dp[i].constant = dp[i-2].constant - dp[i-1].constant;
		dp[i].coefficient = dp[i-2].coefficient - dp[i-1].coefficient; 
		//printf("dp[D].constant: %d dp[D].coefficient: %d\n", 
		//dp[i].constant, dp[i].coefficient);
	}

	int a = 1; 
	int dpD, dpDminOne;


	while (1) {
		// dp[D] 의 값.
		dpD = dp[D].constant+dp[D].coefficient*a;
		// dp[D-1] 의 값.
		dpDminOne = dp[D-1].constant+dp[D-1].coefficient*a;
		if (dpD >= 1 && dpDminOne >= 1 && dpDminOne >= dpD) {
			printf("%d\n%d", dpD, dpDminOne);
			break;
		}
		a++;
	}

	free(dp); 

}