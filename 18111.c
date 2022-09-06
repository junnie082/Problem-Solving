#include <stdio.h>
#include <stdlib.h>

void swap(int *heap, int i1, int i2)
{
	int temp = heap[i1];
	heap[i1] = heap[i2];
	heap[i2] = temp;
}

void bubbleUp(int *timeInArea, int* height, int index)
{
	while (1) {
		if (index == 1) break;

		if (timeInArea[(int)index/2] > timeInArea[index]) {
			swap(timeInArea, (int)index/2, index);
			swap(height, (int)index/2, index);
			index = (int)index/2;
		} else break;
	}
}



// void insertTime(int *minHeap, int *height, int time, int index)
// {
// 	minTime[index] = time;
// 	bubbleUp(minHeap, height, index);
// }

int main()
{
	int N, M, B, num,  time, testB;
	scanf("%d %d %d", &N, &M, &B);

	// // 2차원 배열에 높이를 저장.
	// int **area = (int **)malloc(sizeof(int *)*N);

	// for (int i = 0; i < N; i++) {
	// 	area[i] = (int *)malloc(sizeof(int) * M);
	// }
	int *height = (int *)malloc(sizeof(int) * (N*M+1));

	for (int i = 1 ; i <= N*M; i++) {
		scanf("%d", &num);
		height[i] = num;
	}

	int *timeInArea = (int *)malloc(sizeof(int) * (N*M+1));
	int *hashtableOfHeight = (int *)malloc(sizeof(int) *513);

	// 모든 height 를 돌아가며 각각 걸리는 시간을 계산, 배열에 저장.
	for (int i = 1; i <= N*M; i++) {
		//heightVar = height[i];
		testB = B;
		time = 0; 
		for (int j = 1; j <= N*M; j++) {
			//cmp = timeInArea[j];
			//if (testB < 0) break;
			if (height[i] == timeInArea[j]) time+=0;
			// area에 블록을 추가. 인벤토리에서 블록을 제거. 
			else if (height[i] > timeInArea[j]) {
				time += (height[i] - timeInArea[j]);
				testB--;
			}
			else { // area에서 블록을 제거. 인벤토리에 블록을 추가. 
				time += (timeInArea[j] - height[i]) * 2; 
				testB++;
			}
		}
		if (testB < 0) {
			// time 은 절대 513이 될 수 없다. 땅의 높이는 256을 초과할 수 없기 때문에.
		}		}
		timeInArea[i] = time; 
		//insertTime(timeInArea, height, time, i);
		bubbleUp(timeInArea, height, i);
	}

	int minTime = timeInArea[1];

	ifHeightTheSame(timeInArea, height)

	//minTime = 100;

	// for (int i = 1; i <= M*N; i++) {	
	// 	if (timeInArea[i] != -1) time = timeInArea[i];
	// 	if (time < minTime) {
	// 		minTime = time;
	// 		index = i; 
	// 	}
	// }


	//printf("%d %d", timeInArea[1],  height[index]);

	// for (int i = 0 ; i < N; i++) free(arr[i]);
	// free(arr);
	free(height);
	free(timeInArea);

	return 0;
}
