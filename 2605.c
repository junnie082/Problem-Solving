#include <stdio.h>
#include <stdlib.h>

struct Student {
	struct Student *next;
	struct Student *previous;
	int studentNum; 
	int chosenNum;
};

void insertOne(struct Student *head, int studentNum, int chosenNum)
{
	struct Student *new = malloc(sizeof(struct Student));
	new -> studentNum = studentNum;
	new -> chosenNum = chosenNum;

	if (head -> next == NULL) {
		head -> next = new;
		new -> previous = head;
		return;
	}

	new -> next = head -> next;
	head -> next = new;

	new -> next -> previous = new;
	new -> previous = head;
}

void removeOne(struct Student *head) {
	struct Student *target = head -> next;
	head -> next = target -> next; 

	free(target);
}

void swapStudents(struct Student *move1) {
	struct Student *move2 = move1 -> next;

	//방법 1.
	int studentNum = move1 -> studentNum;
	move1 -> studentNum = move2 -> studentNum;
	move2 -> studentNum = studentNum;

	int chosenNum = move1 -> chosenNum;
	move1 -> chosenNum = move2 -> chosenNum;;
	move2 -> chosenNum = chosenNum;
}

void sortStudents(struct Student *head)
{
	int a;
	struct Student *point = head;
	struct Student *move = head;

	while (move -> next != NULL) move = move -> next;
	move = move -> previous;
	while (point -> next != move) point = point -> next;

	while (1) {
		a = point -> next -> chosenNum;
		for (int i = 0; i < a; i++) {
			swapStudents(move);
			move = move -> next; 
		}
	
		point = point -> previous;
		if (point == NULL) break;
		move = point -> next;	
	}
}


int main()
{
	int N, chosenNum;
	struct Student *head = malloc(sizeof(struct Student));

	scanf("%d", &N);

	if (N == 1) {
		scanf("%d", &chosenNum);
		printf("%d", N);
		free(head);
		return 0;
	}

	for (int i = 1; i <= N; i++) {
		scanf("%d", &chosenNum);
	 	insertOne(head, i, chosenNum);
	}

	sortStudents(head);

	struct Student *curr = head;
	while (curr -> next != NULL) curr = curr -> next;

	while (curr != head) {
		printf("%d ", curr -> studentNum);
		curr = curr -> previous;
	}

	//TEST nodes
	// struct Student *curr = head -> next;
	// while (curr -> next != NULL) curr = curr -> next;

	// while (1) {
	// 	printf("curr1: %d %d\n", curr -> studentNum, curr -> chosenNum);
	// 	if (curr != head) curr = curr -> previous;
	// 	else break;
	// }

	while (head -> next != NULL) {
		removeOne(head);
	}
	free(head);

	return 0; 
}



