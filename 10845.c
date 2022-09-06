#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	struct Node *next;
	struct Node *prev;
	int X;
};

void push(struct Node *tail, int X)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode -> X = X;

	struct Node *backNode = tail -> prev;

	backNode -> next = newNode;
	newNode -> next = tail;
	tail -> prev = newNode;
	newNode -> prev = NULL;  
	
}

void pop(struct Node *head, struct Node *tail)
{
	struct Node *target = head -> next; 

	if (target == tail){
		printf("-1\n");
		return;
	} 

	printf("%d\n", target -> X);
	head -> next = target -> next;
	if (target -> next == tail) {
		tail -> prev = head;
	}

	free(target);
}

void empty(struct Node *head, struct Node *tail)
{
	if (head -> next == tail) printf("1\n");
	else printf("0\n");
}

void front(struct Node *head, struct Node *tail) 
{
	if (head -> next == tail) {
		printf("-1\n");
		return;
	}
	printf("%d\n", head -> next -> X);
}

void back(struct Node *head, struct Node *tail)
{
	if (tail -> prev == head) {
		printf("-1\n");
		return; 
	}
	printf("%d\n", tail->prev->X);
}


int main()
{
	char string[6];
	int N, X, size = 0;
	scanf("%d", &N);

	struct Node *head = malloc(sizeof(struct Node));
	struct Node *tail = malloc(sizeof(struct Node));

	head -> next = tail;
	head -> prev = NULL; 
	tail -> next = NULL;
	tail -> prev = head;

	for (int i = 0 ; i < N; i++) {
		scanf("%s", string);
		if (!strcmp(string, "push")) {
			scanf("%d", &X);
			push(tail, X);
			size++;
		} else if (!strcmp(string, "pop")) {
			pop(head, tail);
			size--;
			if (size<0) size++;
		} else if (!strcmp(string, "size")) {
			printf("%d\n", size); 
		} else if (!strcmp(string, "empty")) {
			empty(head, tail);
		} else if (!strcmp(string, "front")) {
			front(head, tail);
		} else if (!strcmp(string, "back")) {
			back(head, tail);
		}
		
	}

	free(head);
	free(tail);
}