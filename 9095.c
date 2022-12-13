#include <stdio.h>

void oneTwoThree(int *dp, int n) {
	dp[0] = 1; 
	dp[1] = 2; 
	dp[2] = 4; 
	for (int i = 3; i < n; i++) {
		dp[i] = dp[i-3] + dp[i-2] + dp[i-1]; 
	}
}

int main()
{	
	int T; 
	scanf("%d", &T); 

	int dp[12];

	oneTwoThree(dp, 12); 

	int n;
	while (T--) {
		scanf("%d", &n); 
		printf("%d\n", dp[n-1]);
	} 
}