#include <stdio.h>
#include <stdlib.h>
#define SWAP(x, y, temp) ( (temp) = (x), (x) = (y), (y) = (temp) )

int partition(int list[], int left, int right) {
	int pivot, temp;
	int low, high; 

	low = left; 
	high = right + 1; 
	pivot = list[left];

	do {

		do {
			low++;
		} while (low <= right && list[left] < pivot);

		do {
			high--;
		} while (high >= left && list[high] > pivot);

		if (low < high) {
			SWAP(list, left, right); 
		}
	}
}

void quick_sort(int list[], int left, int right) {

}

int main()
{

}