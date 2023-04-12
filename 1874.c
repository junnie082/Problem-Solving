#include <stdio.h>
#include <stdlib.h>

int result[100001] = {0};

typedef struct _stack {
	struct _stack *next;
	int node;
} stack;

void push(stack *top, int num) {
	stack *newNode = malloc(sizeof(stack)); 

	newNode -> node = num; 
	newNode -> next = top -> next; 
	top -> next = newNode; 
}

void pop(stack *top) {
	if (top -> next == NULL) top -> next = NULL;
	else if (top -> next -> next == NULL) {
		free(top -> next); 
		top -> next = NULL; 
	} else if (top -> next -> next != NULL) {
		stack *curr = top -> next; 
		top -> next = curr -> next; 
		free(curr); 
	} 
}

int main()
{
	int n; 	
	scanf("%d", &n); 

	int *stackList = malloc(sizeof(int) * (n+1)); 
	
	stack *top = malloc(sizeof(stack)); 
	top -> next = NULL; 

	push(top, 1); 
	result[0] = 1;
	int num; 

	for (int i = 1; i <= n; i++) {
		scanf("%d", &num); 
		stackList[i] = num;
	}

	int index = 1;
	int i = 2;

	int resultIndex = 1;
	while (index <= n) {
		if (top -> next != NULL && stackList[index] == top -> next -> node) {
			result[resultIndex++] = 0;
			pop(top); 
			index++; 
		} else if (top -> next == NULL 
			|| stackList[index] > top -> next -> node) {
			result[resultIndex++] = 1; 
			push(top, i);
			i++; 
		} else {
			printf("NO\n");
			return 0; 
		}
	}

	for (int i = 0; i < resultIndex; i++) {
		if (result[i] == 0) printf("-\n"); 
		else if (result[i] == 1) printf("+\n"); 
	}


	while (top -> next != NULL) {
		stack *curr = top -> next; 
		if (curr -> next != NULL) {
			top -> next = curr -> next; 
			free(curr); 	
		} else if (curr -> next == NULL) {
			free(top -> next); 
		}
	}
	free(top); 
	free(stackList);
}