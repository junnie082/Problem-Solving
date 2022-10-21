#include <stdio.h>
#define MAX_SIZE 200

void insert_value(int heap[], int size, int key) {
	int temp;
	int child = ++size;
	int parent = child / 2;

	while (child != 1 && heap[parent] < heap[child]) {
		temp = heap[parent];
		heap[parent] = heap[child];
		heap[child] = temp;

		parent = child; 
		child /= 2;
	}
}