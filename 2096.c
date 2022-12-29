#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
	int max;
	int min;  
} Node; 

Node dp[100001][3];

int main()
{
	int N; 
	scanf("%d", &N); 
	// Node **dp = (Node **)malloc(sizeof(Node *) * (N+1));
	// for (int i = 1; i <= N; i++) {
	// 	dp[i] = (Node *)malloc(sizeof(Node) * 3); 
	// }

	int val0, val1, val2; 
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d", &val0, &val1, &val2);
		if (i == 1) {
			dp[i][0].max = val0; dp[i][0].min = val0;
			dp[i][1].max = val1; dp[i][1].min = val1; 
			dp[i][2].max = val2; dp[i][2].min = val2; 
		} else {
			dp[i][0].max = val0 + (dp[i-1][0].max > dp[i-1][1].max ? dp[i-1][0].max : dp[i-1][1].max);
			dp[i][0].min = val0 + (dp[i-1][0].min < dp[i-1][1].min ? dp[i-1][0].min : dp[i-1][1].min);

			dp[i][1].max = dp[i-1][0].max > dp[i-1][1].max ? dp[i-1][0].max : dp[i-1][1].max;
			dp[i][1].min = dp[i-1][0].min < dp[i-1][1].min ? dp[i-1][0].min : dp[i-1][1].min;
			dp[i][1].max = val1 + (dp[i][1].max > dp[i-1][2].max ? dp[i][1].max : dp[i-1][2].max);
			dp[i][1].min= val1 + (dp[i][1].min < dp[i-1][2].min ? dp[i][1].min : dp[i-1][2].min);
			
			dp[i][2].max = val2 + (dp[i-1][1].max > dp[i-1][2].max ? dp[i-1][1].max : dp[i-1][2].max);
			dp[i][2].min = val2 + (dp[i-1][1].min < dp[i-1][2].min ? dp[i-1][1].min : dp[i-1][2].min);
		}

	}

	int max = dp[N][0].max > dp[N][1].max ? dp[N][0].max : dp[N][1].max;
	max = max > dp[N][2].max ? max : dp[N][2].max; 

	int min = dp[N][0].min < dp[N][1].min ? dp[N][0].min : dp[N][1].min;
	min = min < dp[N][2].min ? min : dp[N][2].min; 

	printf("%d %d\n", max, min);

	// for (int i = 1; i <= N; i++) {
	// 	free(dp[i]); 
	// }
	// free(dp); 
}