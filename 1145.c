#include <stdio.h>

int main()
{
	int num[5], N, divided = 1, result;

	for (int i = 0 ; i < 5 ; i++) {
		scanf("%d", &N);
		num[i] = N;
	}

	while(1) {
		result = 0;
		for (int i = 0; i < 5; i++) {
			if (divided % num[i] == 0) result++;
		}

		if (result >= 3) break;
		divided++;
	}

	printf("%d", divided);
}


