#include <stdio.h>
#include <stdlib.h>

// chojl1125
// 계단오르기는 마지막 계단을 반드시 밟아야 하지만 포도주는 마지막 잔을 마시지 
// 않을 수도 있다는 게 차이겠네요. 
int main()
{
	int n; 
	scanf("%d", &n); 

	int *dp = malloc(sizeof(int) * n);
	int *numbers = malloc(sizeof(int) * n); 

	int num; 
	int max = 0; 
	for (int i = 0; i < n; i++) {
		scanf("%d", &num); 
		numbers[i] = num; 
		if (i == 0) dp[0] = num;
		else if (i == 1) dp[1] = num + dp[0]; 
		else if (i == 2) {
			dp[2] = numbers[i]+numbers[i-1] > num+dp[0] ? numbers[i]+numbers[i-1] : num+dp[0]; 
			dp[2] = numbers[0] + numbers[1] > dp[2] ? numbers[0] + numbers[1] : dp[2]; 
		} else if (i == 3) {
			dp[i] = dp[i] = numbers[i]+numbers[i-1]+dp[i-3] > numbers[i]+dp[i-2] ? 
		 	numbers[i]+numbers[i-1]+dp[i-3] : numbers[i]+dp[i-2]; 
		} 
		else {
		 	dp[i] = numbers[i]+numbers[i-1]+dp[i-3] > numbers[i]+dp[i-2] ? 
		 	numbers[i]+numbers[i-1]+dp[i-3] : numbers[i]+dp[i-2]; 
			// printf("prevNum: %d num: %d dp[i-3]: %d\n", prevNum, num, dp[i-3]); 
			// printf("first: %d\n", num+prevNum+dp[i-3]); 
			// printf("second: %d\n", num+dp[i-2]); 
			dp[i] = numbers[i-2]+numbers[i-1]+dp[i-4] > dp[i] ?
			numbers[i-2]+numbers[i-1]+dp[i-4] : dp[i]; 
		}

		if (dp[i] > max) max = dp[i]; 

		// printf("dp: \n"); 
		// for (int j = 0; j <= i; j++) {
		// 	printf("%d ", dp[j]); 
		// }
	}

	printf("%d", max); 

	free(dp); free(numbers);
}