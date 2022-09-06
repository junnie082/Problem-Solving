#include <stdio.h>
#include <stdlib.h>

struct Card {
	struct Card *next;
	struct Card *prev;
	int value;
};

void insertNode(struct Card *head, int value)
{
	struct Card *newNode = (struct Card *)malloc(sizeof(struct Card));

	newNode -> value = value;

	if (head -> next == NULL) {
		head -> next = newNode;
		newNode -> next = head;
		head -> prev = newNode; 
	} else  {
		newNode -> next = head -> next;
		head -> next -> prev = newNode; 
		head -> next = newNode; 
	}
	newNode -> prev = head;
}

int removeNode(struct Card *head)
{
	struct Card *target = head -> next;

	if (head -> next -> next == head) return 1; 

	head -> next = target -> next; 
	target -> next -> prev = head;

	free(target);

	return 0;
}

int toTheBottom(struct Card *head) 
{
	struct Card *target1 = head -> next;
	struct Card *target2 = head -> prev;

	if (head -> next -> next == head) return 1;

	head -> next = target1 -> next;
	target1 -> next -> prev = head; 
	target2 -> next = target1;
	target1 -> prev = target2;
	target1 -> next = head;
	head -> prev = target1;

	return 0; 
}

int main()
{
	int N, index = 1, result = 0; 
	scanf("%d", &N);

	struct Card *head = (struct Card*)malloc(sizeof(struct Card));

	for (int i = N; i > 0; i--) {
		insertNode(head, i);
	}

	while(1) {

		if (result) {
			break;
		}
		if (index % 2 == 1) {
			result = removeNode(head);
		} else if (index % 2 == 0) {
			result = toTheBottom(head); 
		}
		index++;
	}

	printf("%d\n", head->next->value);
	free(head->next);
	free(head);
}
