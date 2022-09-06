#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *next;
	struct Node *prev;
	int data;
};

void insert(struct Node *one, int data)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode -> data = data;

	if (one -> next == NULL) {
		one -> next = newNode;
		newNode -> prev = one;
		newNode -> next = one;
		one -> prev = newNode;
		return;
	}

	newNode -> next = one -> next; 
	one -> next -> prev = newNode;
	newNode -> prev = one;
	one -> next = newNode; 

	// printf("newNode->prev: %d\n", newNode -> prev -> data);
	// printf("newNode:  %d \n", newNode -> data); 
	// printf("newNode->next:  %d \n", newNode -> next -> data);
}

void findRemove(struct Node *one, int k)
{
	struct Node *point = one;
	struct Node *target = point;

	for (int i = 1; i < k ; i++) point = point -> next; 

	while (1)
	{
		if (point -> next == point -> prev) {
			printf("%d, ", point -> data);
			printf("%d", point -> next -> data);
			target = point -> next;
			free(point);
			free(target);
			break;
		} 
		printf("%d, ", point -> data); 
		point -> prev -> next = point -> next;
		point -> next -> prev = point -> prev; 

		target = point; 
		for (int i = 0 ; i < k; i++) point = point -> next;
		free(target); 
	}

}

int main()
{
	struct Node *one = malloc(sizeof(struct Node));
	one -> data = 1;

	int N, k; 
	scanf("%d %d", &N, &k);


	for (int i = N; i > 1; i--) {
		insert(one, i);
	}

	

	printf("<");
	if (N==1) printf("1");
	else findRemove(one, k);
	printf(">");
}