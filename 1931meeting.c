#include <stdio.h>
#include <stdlib.h>

struct meeting {
	struct meeting *next; 
	struct meeting *prev; 
	struct meeting *start;
	int data;
};

// int compare(const void *a, const void *b) {
// 	struct meeting *tmpa = (struct meeting*)a;
// 	struct meeting *tmpb = (struct meeting*)b;

// 	if (tmpa -> data < tmpb -> data) return -1; 
// 	else if (tmpa -> data > tmpb -> data) return 1; 
// 	else return 0; 
// }

void insertNode(struct meeting *tail, int start, int end) {
	struct meeting *newNode = malloc(sizeof(struct meeting)); 
	struct meeting *startNode = malloc(sizeof(struct meeting));


	// 연결 리스트에 달려 있는 회의 끝 시간.
	newNode -> next = tail;
	newNode -> prev = tail -> prev;
	newNode -> start = startNode; 
	newNode -> data = end;  

	// 회의 끝 시간 노드에 달려 있는 회의 시작 시간. 
	startNode -> next = NULL; 
	startNode -> prev = NULL; 
	startNode -> start = NULL;
	startNode -> data = start;

	tail -> prev -> next = newNode;
	tail -> prev = newNode;  
	//printf("isnert!!\n");
}

void removeNode(struct meeting *target) {
	struct meeting *delete = target -> next;

	target -> next = delete -> next;
	delete -> next -> prev = target;

	free(delete -> start);
	free(delete);  
}

void finishNodes(struct meeting *head) {
	struct meeting *target = head -> next; 

	head -> next = target -> next; 
	free(target -> start);
	free(target); 
}


int main()
{
	int N, start, end, result = 1;
	scanf("%d", &N); 
	//struct meeting *table[N];
	struct meeting *head = malloc(sizeof(struct meeting));
	struct meeting *tail = malloc(sizeof(struct meeting)); 

	head -> next = tail;
	head -> prev = NULL;  
	head -> start = NULL; 

	tail -> next = NULL; 
	tail -> prev = head;  
	tail -> start = NULL; 


	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end); 
		insertNode(tail, start, end); 
	}

	// end 를 기준으로 오름차순으로 정렬하기. mergeSort 를 구현해 보고 싶지만...
	// 시간이 촉박한 관계로 C언어 내장함수 qsort() 를 쓰겠습니다.
	//qsort(table, N, sizeof(struct meeting), compare); 

	struct meeting *target = head -> next -> next;
	while (target != tail) {
		//printf("target -> start: %d target -> end: %d\n", target -> start -> data, target -> data); 
		// prev 노드의 start ~ end 에 target 노드의 start 가 겹치면 target 노드 삭제.
		if (target -> start -> data < target -> prev -> data) {
			//printf(" target -> prev -> data: %d target -> start -> data: %d\n", target -> prev -> data, target -> start -> data); 
			// point = target -> next;
			target = target -> prev;
			removeNode(target);

			// target = point; 
		} else {
			result++; 
		}
	
		target = target -> next; 
	}

	while (head -> next != tail) {
		finishNodes(head); 
	}


	printf("%d\n", result); 

	free(head);
	free(tail); 


}