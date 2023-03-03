#include <iostream>
using namespace std; 

int main()
{
	int N, M; 
	cin >> N >> M; 
	int arr[1001][1001];

	int num; 
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num; 
			arr[i][j] = num; 
		}
	}

	int dp[1001][1001] = {0}; 
	dp[1][1] = arr[1][1]; 

	for (int r = 1; r <= N; r++) {
		for (int c = 1; c <= M; c++) {
			if (r == 1 && c == 1) continue; 
			if (r==1) dp[1][c] = dp[1][c-1] + arr[r][c]; 
			else if (c==1) dp[r][1] = dp[r-1][1] + arr[r][c]; 
			else {
				dp[r][c] = max(dp[r-1][c-1], dp[r-1][c]);
				dp[r][c] = max(dp[r][c], dp[r][c-1]);
				dp[r][c] += arr[r][c];  
			}
		}
	}

	cout << dp[N][M]; 
}