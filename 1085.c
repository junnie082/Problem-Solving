#include <stdio.h>

int main()
{
	int x, y, w, h, arr[5], min;
	scanf("%d %d %d %d", &x, &y, &w, &h);

	arr[0] = x;
	arr[1] = y;
	arr[2] = w - x;
	arr[3] = h - y;
	min = arr[0];

	for (int i = 0 ; i < 4; i++) {
		if (arr[i] < min) min = arr[i];
	}

	printf("%d\n", min);
 	
}