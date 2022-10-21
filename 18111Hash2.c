#include <stdio.h>
#include <stdlib.h>

int main()
{
	int N, M, B, num, time, minTime, resultOfHeight = 0, testB, index;
	scanf("%d %d %d", &N, &M, &B);

	int *height = (int *)malloc(sizeof(int) * (N * M));

	for (int i = 0; i < N * M; i++) {
		scanf("%d", &num);
		height[i] = num; 
	}

	minTime = N * M * 513;

	for (int h = 0; h <= 256; h++) {
		testB = B;
		time = 0;
		for (int i = 0; i < N*M; i++) {
			if (height[i] == h) time+=0;
			// area에 블록을 추가. 인벤토리에서 블록을 제거. 
			else if (h > height[i]) {
				time += (h - height[i]);
				testB--;
			}
			else { // area에서 블록을 제거. 인벤토리에 블록을 추가. 
				time += (height[i] - h) * 2; 
				testB++;
			}
		}

		if (testB < 0) continue;

		if (time < minTime) {
			minTime = time; 
			resultOfHeight = h;
		}

	}
	printf("%d %d\n", minTime, resultOfHeight);

}