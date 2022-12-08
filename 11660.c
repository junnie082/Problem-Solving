#include <stdio.h>
#include <stdlib.h>

// N * N 개의 배열은... 아마도 만들지 못할 것이다.
// 1000 * 1000 = 100만 이다.

int sumAll(int **arr, int *coor, int N) {
	int dp[2] = {0}; 
	// x1: coor[i][0] 
	// y1: coor[i][1]
	// x2: coor[i][2]
	// y2: coor[i][3]
	dp[0] = arr[coor[0] - 1][coor[1] - 1]; 

	int k = 1; 

	for (int x = coor[0] - 1; x < coor[2]; x++) {  // 행
		for (int y = coor[1] - 1; y < coor[3]; y++) { // 열
			if (x == coor[0] - 1 && y == coor[1] - 1) continue; 
			
			dp[1] = arr[x][y] + dp[0];
			// 이게 결국 sum += arr[x][y] + prevSum 랑 뭐가 달라...
			dp[0] = dp[1];
		}
	}

	return dp[1]; 

}

int main()
{
	int N, M;
	scanf("%d %d", &N, &M);
	int **arr = (int **)malloc(sizeof(int *) * N);  
	//int **coor = (int **)malloc(sizeof(int *) * M); 
	int *resultArr = (int *)malloc(sizeof(int) * M); 

	for (int i = 0; i < N; i++) {
		arr[i] = (int *)malloc(sizeof(int) * N);  
	}
	// for (int i = 0; i < M; i++) {
	// 	coor[i] = (int *)malloc(sizeof(int) * 4); 
	// }

	int num;  
	// N X N 배열 공간에 숫자를 대입하여 넣는다. 
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &num); 
			arr[i][j] = num; 
		}
	}
	// 좌표를 입력해서 저장하는 데에 쓰임. 
	// for (int i = 0; i < M; i++) {
	// 	// x1은 coor[][0], y1은 coor[][1], x2은 coor[][2], y2는 coor[][2]에.
	// 	for (int j = 0; j < 4; j++) {
	// 		scanf("%d", &num); 
	// 		coor[i][j] = num; 
	// 	}
	// }

	int result; 

	// 결과값 계산. 
	for (int i = 0; i < M; i++) {
		int *coor = (int *)malloc(sizeof(int) * 4); 
		for (int j = 0; j < 4; j++) {
			scanf("%d", &num); 
			coor[j] = num; 
		}
		if (coor[0] == coor[2] && coor[1] == coor[3]) {
			result = arr[coor[0] - 1][coor[1] - 1];
		}else result = sumAll(arr, coor, N); 
		//printf("%d\n", result);
		resultArr[i] = result; 
		free(coor); 
	}

	for (int i = 0; i < M; i++) {
		printf("%d\n", resultArr[i]);
	}


	for (int i = 0; i < N; i++) {
		free(arr[i]); //free(coor[i]); 
	}
	free(arr); //free(coor); 
	free(resultArr); 
}