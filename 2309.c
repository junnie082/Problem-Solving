#include <stdio.h>

void insertion_sort(int result[]) {
	int val;

	for (int i = 1; i < 7; i++) {
		val = result[i]; 
		for (int j = i - 1; j >= 0; j--) {
			if (result[j] > val) {
				result[j+1] = result[j]; 
				result[j] = val; 
			} else {
				break; 
			}
		}
	}
}

void print_result(int result[]) {

	for (int i = 0 ; i < 7; i++) {
		printf("%d\n", result[i]); 
	}
}

int main()
{
	int dwarves[9], result[7], height, sum, t; 

	for (int i = 0; i < 9; i++) {
		scanf("%d", &height); 
		dwarves[i] = height; 
	}

	for (int i = 0; i < 9; i++) {
		for (int j = i + 1; j < 9; j++) {
			// sum 과 result 의 인덱스인 t 를 
			// k 가 한 바퀴씩 돌 때마다 초기화 시켜주어야 한다. 
			sum = 0; 
			t = 0; 
			for (int k = 0; k < 9; k++) {
				if (k == i || k == j) continue;
				sum += dwarves[k];
				result[t++] = dwarves[k]; 
			}

			if (sum == 100) {
				insertion_sort(result); 
				print_result(result); 
				// sum이 100일 때를 한 번 출력했으면
				// 프로그램을 종료하는 것을 잊으면 안된다. 
				return 0;
			}
		}
	}
}