#include <stdio.h>
#include <stdlib.h>

int max;

struct Node {
	struct Node *next;
	int data;
	int real; 
};

struct Tail {
	struct Node *next;
	struct Node *prev;
	int data;
}; 

int compare(const void *a, const void *b)
{
	int num1 = *(int *)a;
	int num2 = *(int *)b; 

	if (num1 < num2) return 1;
	if (num1 > num2) return -1; 

	return 0;
}

void insert(struct Node *head, struct Tail *tail, int data, int real)
{
	struct Node *newNode = malloc(sizeof(struct Node)); 
	newNode -> data = data; 
	newNode -> real = real; 

	if (head -> next == tail)
	{
		head -> next = newNode;
		newNode -> next = tail;
		tail -> prev = newNode;
		return;
	}

	newNode -> next = tail;
 	tail -> prev -> next = newNode;
 	tail -> prev = newNode;  
}

void toRear(struct Node *head, struct Tail *tail)
{
	struct Node *target = head -> next; 
	head -> next = target -> next;
	target -> next = tail;
	tail -> prev -> next = target;
	tail -> prev = target;
	//printf("head -> next: %d\n", head->next->data);

}

void removeNode(struct Node *head, struct Tail *tail)
{
	struct Node *target = head -> next;
	head -> next = target -> next; 
	free(target); 
}
// void maxHeap(int *heap, int capacity, int data)
// {
// 	int index = capacity, temp;
// 	heap[capacity] = data;

// 	while (1)
// 	{
// 		if (index == 1) break;

// 		if (heap[index] > heap[index/2])
// 		{
// 			temp = heap[index];
// 			heap[index] = heap[index/2];
// 			heap[index/2] = temp;
// 		}
// 		index /= 2;
// 	}
// }

int Count(int heap[], struct Node *head, struct Tail *tail)
{
	int count = 0;
	struct Node *cmp = NULL;
	struct Node *target = head -> next;

	while (1) { 
		cmp = head -> next;
		//printf("cmp: %d\n", cmp->data);
		if (heap[max] == cmp -> data)
		{
			if (cmp -> real == 1) {
				return count + 1;
			}
			removeNode(head, tail);
			max++;
			count++;
		} else {
			toRear(head, tail);
			//return 0;
		}
	}
}

int main()
{
	int T, N, M, data;
	struct Node *head = malloc(sizeof(struct Node));
	struct Tail *tail = malloc(sizeof(struct Node));
	head -> next = tail;
	tail -> prev = head; 
	tail -> next = NULL;
	scanf("%d", &T);


	for (int i = 0 ; i < T; i++) {

		max = 0;
		scanf("%d %d", &N, &M); 
		int *heap = (int *)malloc(sizeof(int) * N);
		for (int j = 0 ; j < N ; j++) {
			scanf("%d", &data); 
			if (j == M) {
				insert(head, tail, data, 1);
			} else {
				insert(head, tail, data, 0); 
			}
			//maxHeap(heap, capacity, data);
			heap[j] = data;
			//capacity++; 
		}

		qsort(heap, N, sizeof(int), compare);
		printf("%d\n", Count(heap, head, tail));

		free(heap);

		struct Node *curr = head -> next;
		while (head -> next != tail) {
			//printf("%d\n", head -> next -> data);
			head -> next = curr -> next;
			free(curr);  
			curr = head -> next; 
		}
	}

	free(tail);
	free(head);
}
