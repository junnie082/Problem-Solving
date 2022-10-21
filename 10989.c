#include <stdio.h>

int main() {
	int N, num, max = 0, min = 1;
	int counted[10001] = {0};
	scanf("%d", &N); 

	for (int i = 0; i < N; i++) {
		scanf("%d", &num);
		counted[num]++;
		if (max < num) {
			max = num; 
		} 

		if (min > num) {
			min = num; 
		}
	}

	for (int i = min; i <= max; i++) {
		for (int j = 0; j < counted[i]; j++) {
			printf("%d\n", i); 
		}
	}
}