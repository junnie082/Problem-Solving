#include <stdio.h>
#include <stdlib.h>

void swap(int *arr, int a, int b)
{
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bubbleUp(int *arr, int capacity)
{
	int parentNode, childNode, i;
	while (1) {
		i = (int)capacity/2;
		if (capacity == 1) break;
		childNode = arr[capacity];
		parentNode = arr[i];
		if (parentNode < childNode) { 
			swap(arr, capacity, i);
		} else {break;}
		capacity = i;
	}
}

void bubbleDown(int *arr, int capacity)
{
	arr[1] = arr[capacity];

	//arr[capacity] = 0;
	capacity--;
	int big, index = 1;

	while(1){

		/*if (index < capacity && arr[index*2] == 0) {
			big = index*2 + 1;
		}*/
		if (index*2 == capacity) {
			big = index*2;
		} else if (index * 2 > capacity) { break; }
		else {
			big = arr[index * 2] > arr[index * 2 + 1] ? index * 2 : index * 2 + 1;
		}

		if (arr[big] > arr[index]) {
			swap(arr, big, index);
		}

		//이걸 arr[big] > arr[index] 조건문 안에 넣었더니, 
		// 이 조건을 만족하지 않으면 계속 index 는 previous 값에 remain,
		// while(1) 문을 빠져나갈 수 없다. 
		index = big;

	}
}

void insertNode(int *arr, int capacity, int new)
{
	arr[capacity] = new;
	bubbleUp(arr, capacity);
}

int removePeek(int *arr, int capacity) 
{
	int element = arr[1];
	bubbleDown(arr, capacity);

	return element;
}

int main()
{
	int N, new, capacity = 0, result;
	scanf("%d", &N);
	int *queue = calloc(N+1, sizeof(int));

	for (int i = 1; i <= N; i++) {
		scanf("%d", &new);
		if (capacity == 0 && new == 0) result = 0;
		else if (new == 0){
			result = removePeek(queue, capacity);
			capacity--;
		} // print the largest 
		else {
			capacity++;
			insertNode(queue, capacity, new);
			continue;
		}
		printf("%d\n", result);
	} 

	free(queue);
}