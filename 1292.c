#include <stdio.h>
//#include <stdlib.h>

int main()
{
	int A, B, k = 0, sum = 0, i = 1;
	scanf("%d %d", &A, &B);
	int arr[1000] = {0};
	while (k != B) {
		for (int j = 0; j < i; j++) {
			if (k==B) break;
			arr[k++] = i;
		}
		i++;
	}

	// for (int i = 0; i < B; i++) {
	// 	if (k == B) break;
	// 	for (int j = 0; j <= i; j++) {
	// 		if (k == B) break;
	// 		arr[k++] = i + 1;
	// 	}
	// }

	for (int i = A-1; i < B; i++) {
		sum += arr[i];
	}

	printf("%d", sum);
	//free(arr);
}