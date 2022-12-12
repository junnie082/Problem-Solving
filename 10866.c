#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 0; 

typedef struct _Dequeue {
	struct _Dequeue *next; 
	struct _Dequeue *prev; 
	int num; 
} Dequeue;

void push_front(Dequeue *front, int x) {
	Dequeue *newNode = (Dequeue *)malloc(sizeof(Dequeue)); 
	newNode -> num = x; 

	newNode -> next = front -> next; 
	front -> next -> prev = newNode; 
	front -> next = newNode; 
	newNode -> prev = front; 

	size++; 
} 

void push_back(Dequeue *back, int x) {
	Dequeue *newNode = (Dequeue *)malloc(sizeof(Dequeue));
	newNode -> num = x; 

	back -> prev -> next = newNode; 
	newNode -> prev = back -> prev;
	newNode -> next = back; 
	back -> prev = newNode;

	size++; 
}

void pop_front(Dequeue *front, Dequeue *back) {
	if (front -> next == back) {
		printf("-1\n");
		return; 
	}

	Dequeue *target = front -> next; 
	printf("%d\n", target -> num); 
	front -> next = target -> next; 
	target -> next -> prev = front; 

	free(target); 

	size--; 
}

void pop_back(Dequeue *front, Dequeue *back) {
	if (back -> prev == front) {
		printf("-1\n"); 
		return; 
	}

	Dequeue *target = back -> prev; 
	printf("%d\n", target -> num); 
	back -> prev = target -> prev; 
	target -> prev -> next = back; 

	free(target); 

	size--; 
}

void sizeF() {
	printf("%d\n", size);
}

void empty() {
	if (size == 0) printf("1\n"); 
	else printf("0\n"); 
}

void frontF(Dequeue *front, Dequeue *back) {
	if (front -> next == back) printf("-1\n"); 
	else {
		printf("%d\n", front -> next -> num); 
	}
}

void backF(Dequeue *front, Dequeue *back) {
	if (back -> prev == front) printf("-1\n"); 
	else {
		printf("%d\n", back -> prev -> num); 
	}
}

int main()
{
	char oper[10001][10];
	int N; 
	scanf("%d", &N); 

	// dequeue 만들기.
	Dequeue *front = (Dequeue *)malloc(sizeof(Dequeue)); 
	Dequeue *back = (Dequeue *)malloc(sizeof(Dequeue)); 

	front -> next = back; 
	front -> prev = NULL; 
	back -> prev = front; 
	back -> next = NULL; 


	int x; 
	for (int i = 0; i < N; i++) {
		scanf("%s", oper[i]); 

		if (strcmp(oper[i],"push_front") == 0) {
			scanf("%d", &x);
			push_front(front, x);  
		} else if (strcmp(oper[i],"push_back") == 0) {
			scanf("%d", &x);
			push_back(back, x); 
		} else if (strcmp(oper[i],"pop_front") == 0) {
			pop_front(front, back); 
		} else if (strcmp(oper[i],"pop_back") == 0) {
			pop_back(front, back); 
		} else if (strcmp(oper[i],"size") == 0) {
			sizeF(); 
		} else if (strcmp(oper[i],"empty") == 0) {
			empty(); 
		} else if (strcmp(oper[i],"front") == 0) {
			frontF(front, back); 
		} else if (strcmp(oper[i],"back") == 0) {
			backF(front, back); 
		}
	} 

	Dequeue *target;
	while (front -> next != back) {
		target = front -> next; 
		front -> next = target -> next; 
		free(target); 
	}

	free(front); free(back); 

}