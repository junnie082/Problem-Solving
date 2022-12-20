#include <stdio.h>
#include <stdlib.h>

int main()
{
	// 점화식. 
	// dp[n] = dp[n-1] + 2dp[n-2]; 
	int n; 
	scanf("%d", &n);
	int *dp = (int *)calloc(n+1, sizeof(int)); 


	for (int i = 1; i <= n; i++) {
		if (i == 1) dp[i] = 1;
		else if (i == 2) dp[i] = 3;
		else {
			dp[i] = (dp[i-1]%10007 + 2*dp[i-2]%10007)%10007; 
		}
	}
	printf("%d\n", dp[n]);
	free(dp); 
}