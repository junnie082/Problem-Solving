#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _member{
	int age;
	char name[101];
} member;

typedef struct _heap {
	member mem[100001];
	int heap_size;
} HeapType; 

void SWAP(HeapType *heap, int parent, int child) {
	member temp = heap->mem[parent]; 
	heap->mem[parent] = heap->mem[child];
	heap->mem[child] = temp;  
}

void insert_struct(HeapType *heap, int index) {
	heap -> heap_size++;
	member temp = heap->mem[index];
	int child = index; 
	int parent = child / 2; 

	//이거 왜 안돼지???
	while (child != 1 && heap->mem[parent].age > temp.age) {
		heap->mem[child] = heap->mem[parent]; 
		child = parent; 
		parent /= 2; 
	}	
	heap->mem[child] = temp;

	// while (child != 1) {

	// 	if (heap->mem[parent].age > temp.age) {
	// 		SWAP(heap, parent, child); 
	// 	} else {
	// 		break; 
	// 	}
	// 	child = parent; 
	// 	parent /= 2; 
	// }
}

member delete_struct(HeapType *heap) {
	member result = heap->mem[1]; 
	//printf("heap->mem[heap_size]의 인ㅔㄷㄱ스:  %d\n",  heap->mem[heap->heap_size].age); 
	//printf("heap_size: %d\n", heap->heap_size);
	//printf("mem[1]: %d\n", heap->mem[1].age); 

	heap -> mem[1] = heap -> mem[heap->heap_size];
	heap -> heap_size--;

	int parent = 1; 
	int child = 2; 

	while (1) {
		if (child > heap->heap_size) break;

		if ( (child + 1 <= heap->heap_size) && (heap->mem[child].age > heap->mem[child+1].age)) {
			child++;
		}

		if (heap->mem[parent].age > heap->mem[child].age) SWAP(heap, parent, child); 

		parent = child; 
		child *= 2; 
	} 

	return result; 
}

int main()
{
	int N, age;
	char name[101];
	scanf("%d", &N);
	HeapType *heap = malloc(sizeof(HeapType)); 

	heap -> heap_size = 0; 

	for (int i = 1; i <= N; i++) {
		scanf("%d %s", &age, name); 
		heap-> mem[i].age = age;
		strcpy(heap-> mem[i].name, name); 
		insert_struct(heap, i);
	}

	for (int i = 1; i <= N; i++) {
		member result = delete_struct(heap); 
		printf("%d %s\n", result.age, result.name);
	}


	// for (int i = 1; i <= N; i++) {
	// 	printf("%d %s\n", heap-> mem[i].age, heap-> mem[i].name); 
	// }

	free(heap); 

}