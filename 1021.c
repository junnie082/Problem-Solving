#include <stdio.h>
#include <stdlib.h>

int count = 0; 

typedef struct _Node {
	struct _Node *next; 
	struct _Node *prev; 
	int number; 
} Node; 

void insertNode(Node *tail, int num) {
	Node *newNode = malloc(sizeof(Node)); 
	newNode -> number = num; 

	newNode -> next = tail -> next; 
	tail -> next -> prev = newNode; 
	newNode -> prev = tail; 
	tail -> next = newNode; 
}

void deleteNode(Node *head) {
	if (head -> next -> next == head) return; 

	Node *target = head -> prev; 

	head -> prev = target -> prev; 
	target -> prev -> next = head; 

	free(target); 
}

void findNum(Node *head, Node *tail, int num) {
	// head 와 tail 중에 더 가까운 노드를 찾아야 함. 
	Node *pointHead = head; 
	Node *pointTail = tail; 

	while (pointHead->number != num && pointTail->number != num) {
		pointHead = pointHead -> prev; 
		pointTail = pointTail -> next; 
	}

	Node *target = NULL; 

	if (pointHead -> number == num) {  // head 와 더 가까웠다면!!
		// head 뒤에 있는 노드들을 tail 앞으로 보냄.
		while (head -> prev != pointHead) {
			count++; 
			target = head -> prev;  

			target -> prev -> next = head;  
			head -> prev = target -> prev; 

			tail -> next -> prev = target; 
			target -> next = tail -> next; 
			target -> prev = tail; 
			tail -> next = target; 
		} 
		
	} else {		// tail과 더 가까웠다면! head 뒤쪽으로 노드 보내기. 
		while (pointTail -> next != head) {
			count++; 
			target = tail -> next;

			target -> next -> prev = tail; 
			tail -> next = target -> next; 

			target -> prev = head -> prev; 
			head -> prev -> next = target; 
			head -> prev = target; 
			target -> next = head; 
		}
		// 타겟 노드가 tail 바로 앞쪽에 위치하고 있으므로,
		// 해당 노드를 head 앞으로 보내주고
		// count에 1을 더해 준 후에, 노드를 삭제한다. 
	}

	// 해당 원소 뽑아 내기. 
	deleteNode(head);

}

int main()
{
	int M, N; 
	scanf("%d %d", &N, &M); 
	Node *head = malloc(sizeof(Node)); 
	head -> number = -1; 
	Node *tail = malloc(sizeof(Node)); 
	tail -> number = -1; 
	head -> next = tail; 
	head -> prev = tail;
	tail -> next = head; 
	tail -> prev = head; 

	for (int i = 1; i <= N; i++) {
		insertNode(tail, i); 
	}

	int num; 

	for (int i = 0; i < M; i++) {
		scanf("%d", &num); 
		findNum(head, tail, num); 
	}

	printf("%d\n", count); 

	while (head -> next != tail) {
		deleteNode(head); 
	}

	free(head); free(tail); 
}