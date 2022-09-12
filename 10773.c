#include <stdio.h>
#include <stdlib.h>

struct Stack {
	struct Stack *next;
	int data;
};

void insert(struct Stack *head, int data)
{
	struct Stack *newNode = malloc(sizeof(struct Stack));
	newNode -> data = data;

	if (head -> next == NULL) {
		head -> next = newNode;
		newNode -> next = NULL;
		return; 
	} 

	newNode -> next = head -> next;
	head -> next = newNode;
}

void deleteNode(struct Stack *head)
{
	struct Stack *target = head -> next;

	if (target == NULL) return;
	else if (target -> next == NULL) {
		free(target);
		head -> next = NULL;
	} else {
		head -> next = target -> next;
		free(target); 
	}
}

int sumRemove(struct Stack *head)
{
	int sum = 0;

	while(1){
		if (head -> next == NULL) return sum;
	
		sum += head -> next -> data;
		deleteNode(head); 
	}
}

int main()
{
	int k, num;
	struct Stack *head = malloc(sizeof(struct Stack));
	head -> next = NULL; 

	scanf("%d", &k); 
	for(int i = 0 ; i < k ; i++) {
		scanf("%d", &num);

		if (num == 0) {
			deleteNode(head);
			continue;
		}
		insert(head, num); 
	}

	printf("%d", sumRemove(head));
	free(head); 
}