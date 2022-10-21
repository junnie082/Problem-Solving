#include <stdio.h>

void bubbleSort(int arr[], int N) {

	int temp;

	for (int i = 1; i < N; i++) {
		for (int j = 0; j < N - i; j++) {
			if (arr[j+1] < arr[j]) {
				temp = arr[j+1];
				arr[j+1] = arr[j];
				arr[j] = temp; 
			}
		}
	}
}

int main()
{
	int arr[10] = {4,7,2,3,1,9,0,5,8,6};

	bubbleSort(arr, 10); 

	for (int i = 0; i < 10; i++) {
		printf("%d\n", arr[i]);
	}
}