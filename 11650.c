#include <stdio.h>
#include <stdlib.h>
//#define SWAP(x, y, temp) ( (temp) = (x), (x) = (y), (y) = (temp) )

struct Coordinate{
	int x;
	int y;
};

// void SWAP(struct Coordinate *list, int low, int high) {
// 	//printf("low: %d high: %d\n", low, high); 
// 	struct Coordinate temp = list[low];
// 	list[low] = list[high];
// 	list[high] = temp; 

// 	//printf("list[%d]: %d, list[%d]: %d\n", low, list[low].y, high, list[high].y); 
// }

// int partition(struct Coordinate *list, int left, int right) {
// 	int pivot;
// 	int low, high; 

// 	low = left;
// 	high = right + 1; 
// 	pivot = list[left].y;

// 	do {
// 		do {
// 			low++; 
// 		} while (low <= right && list[low].y < pivot); 

// 		do {
// 			high--;
// 		} while (left <= high && list[high].y > pivot);

		 
// 		if (low < high) {
// 			//printf("low: %d high: %d\n", low, high);
// 			SWAP(list, low, high); 
// 		}

// 	} while (low < high); 

// 	SWAP(list, left, high); 

// 	return high;
// }

// void quick_sort(struct Coordinate *list, int left, int right) {
// 	//printf("left: %d right: %d\n", left, right); 
// 	// for (int i = 0; i < 5; i++) {
// 	// 	printf("!!!!list[%d].x: %d, list[%d].y: %d\n", i, list[i].x, i, list[i].y); 
// 	// }

// 	if (left < right){ // quick sort (y 좌표를 오름차순으로 정렬)
// 		int p = partition(list, left, right);

// 		quick_sort(list, left, p - 1);
// 		quick_sort(list, p + 1, right); 
// 	} 
// }

void merge(char XorY, struct Coordinate *sorted, struct Coordinate *list, int start, int mid, int end) {
	int i, j, k;
	i = start;
	j = mid + 1; 
	k = start; 

	if (XorY == 'x') {
		while (i <= mid && j <= end) {
			if (list[i].x <= list[j].x) {
				sorted[k++] = list[i++];
			} else {
				sorted[k++] = list[j++];
			}
		}
	} else if (XorY == 'y') {
		while (i <= mid && j <= end) {
			if (list[i].y <= list[j].y) {
				sorted[k++] = list[i++];
			} else {
				sorted[k++] = list[j++];
			}
		}
	}

	while (i <= mid) {
		sorted[k++] = list[i++];
	} 
	while (j <= end) {
		sorted[k++] = list[j++];
	}

	for (i = start; i <= end; i++) {
		list[i] = sorted[i]; 
	}
}

void merge_sort(char XorY, struct Coordinate *sorted, struct Coordinate *list, int left, int right) {
	int mid;

	if (left < right) {
		mid = (left + right) / 2; 
		merge_sort(XorY, sorted, list, left, mid);
		merge_sort(XorY, sorted, list, mid + 1, right); 
		merge(XorY, sorted, list, left, mid, right);
	}
}

int main()
{
	int N, x, y;
	scanf("%d", &N);

	struct Coordinate *list = malloc(sizeof(struct Coordinate) * N);
	struct Coordinate *sorted = malloc(sizeof(struct Coordinate) * N); 

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &x, &y); 
		list[i].x = x;
		list[i].y = y; 
	}

	//quick_sort(list, 0, N-1);
	merge_sort('y', sorted, list, 0, N-1); 
	merge_sort('x', sorted, list, 0, N-1); 


	// for (int i = 0; i < N; i++) {
	// 	printf("x: %d y: %d\n", list[i].x, list[i].y);
	// }
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", list[i].x, list[i].y);
	}
	free(list); 
	free(sorted); 
}