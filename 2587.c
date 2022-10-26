#include <stdio.h>

void SWAP(int arr[], int i, int j) {
	int temp = arr[i]; 
	arr[i] = arr[j]; 
	arr[j] = temp;
}

void selection_sort(int arr[]) {
	int min; 

	for (int i = 0; i < 5; i++) {
		min = i; 
		for (int j = i + 1; j < 5; j++) {
			if (arr[min] > arr[j]) min = j;
		}
		SWAP(arr, i, min); 
	}
}

void insertion_sort(int arr[]) {
	int val; 

	for (int i = 1; i < 5; i++) {
		val = arr[i]; 
		for (int j = i - 1; j >= 0; j--) {
			if (arr[j] > val) {
				arr[j+1] = arr[j];
				arr[j] = val; 
			} else {
				break; 
			}
		}
	}
}

void bubble_sort(int arr[]) {

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 - i; j++) {
			if(arr[j] > arr[j+1]) SWAP(arr, j, j+1); 
		}
	}
}

int main()
{
	int arr[5], num, average = 0; 

	for (int i = 0 ; i < 5; i++) {
		scanf("%d", &num);
		arr[i] = num;  
	}

	selection_sort(arr);
	//insertion_sort(arr);
	//bubble_sort(arr);

	for (int i = 0; i < 5; i++) {
		average += arr[i]; 
	}

	average /= 5; 
	printf("%d\n%d\n", average, arr[2]);

}