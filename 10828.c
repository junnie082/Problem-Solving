#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
	int value;
	struct Stack *next;
};

void push(struct Stack *head, int X)
{
	struct Stack *newNode = malloc(sizeof(struct Stack));
	newNode -> value = X;

	if (head -> next == NULL) {
		head -> next = newNode;
		newNode -> next = NULL;
	} else {
		newNode -> next = head -> next;
		head -> next = newNode;
	}
}

int pop(struct Stack *head) 
{
	int X; 
	struct Stack *target = head -> next;
	if (head -> next == NULL) return -1;

	X = target -> value;

	if (target -> next == NULL) {
		free(target);
		head -> next = NULL;
	} else {
		head -> next = target -> next;
		free(target);
	}
	return X;
}

int empty(struct Stack *head) {
	if (head -> next == NULL) return 1;
	else return 0;
}

int top(struct Stack *head) {
	if (head -> next == NULL) return -1;
	else return head -> next -> value; 
}

int main()
{
	char string[6];
	int X, N, size = 0;
	struct Stack *head = malloc(sizeof(struct Stack));
	head -> next = NULL;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%s", string);

		if (!strcmp("push", string)) {
			scanf("%d", &X);
			push(head, X);
			size++;
		} else if (!strcmp("pop", string)) {
			printf("%d\n",pop(head));
			size--;
			if (size < 0) size++;
		} else if (!strcmp("size", string)) {
			printf("%d\n", size);
		} else if (!strcmp("empty", string)) {
			printf("%d\n", empty(head));
		} else {
			printf("%d\n", top(head));
		}
	}

	while (head -> next != NULL) {
		pop(head);
	} 
	free(head); 

}