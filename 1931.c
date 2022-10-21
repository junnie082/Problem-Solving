#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *next;
	//struct Node *prev; 
	//int index;
	int diff;
	int start;
	int end;
};

void insertNode(struct Node *chain[], int start, int end, int N){
	int diff = end - start;
	int hashkey = diff % N; 

	if (diff == 0) hashkey = 0; 
	else if (hashkey == 0) {
		hashkey = N; 
	}

	struct Node *newNode = malloc(sizeof(struct Node)); 
	newNode -> diff = diff;
	newNode -> start = start;
	newNode -> end = end; 
	//만약 chain[hashkey] 가 NULL이라면/?
	if (chain[hashkey] == NULL) {
		chain[hashkey] = newNode; 
	} //만약 chain[hashkey] 가 NULL 이 아니라면? 
	else {
		struct Node *temp = chain[hashkey];
		while (temp -> next) {
			temp = temp -> next; 
		}
		temp -> next = newNode; 
	}	
}

void removeNode(struct Node *head)
{
	struct Node *target = head -> next;
	if (target == NULL) free(head); 
	else if (target -> next == NULL) {
		free(target); 
		free(head); 
	} else {
		head -> next = target -> next;
		free(target); 
	}
}

int main()

{	//malloc은 memory allocation 입니다. 
	struct Node *head = malloc(sizeof(struct Node));
	struct Node *tail = malloc(sizeof(struct Node));
	head -> next = tail;
	tail -> next = NULL; 

	int N, start, end, sizeOfSchedule = 0;
	scanf("%d", &N);

	// N 크기 구조체 Node 배열을 만들기.
	struct Node *chain[N + 1];
	//chain 배열의 모든 공간을 NULL 로 초기화. 
	for (int i = 0; i <= N; i++) chain[i] = NULL;

	int diff;
	//입력을 받고, (end-start)%N 을 hashkey 로 하여, 연결 리스트를 만듦.
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &start, &end);
		if (end > sizeOfSchedule) sizeOfSchedule = end;
		insertNode(chain, start, end, N); 
	}


	// 스케줄표 배열을 만듦. 
	int *schedule = (int *)calloc(sizeOfSchedule+1, sizeof(int)); 
	// 연결 리스트를 head 부터 tail까지 모두 돌면서, 스케줄 표에 넣을 수 있는지를 확인. 
	int result = 0, flag; 
	for (int i = 1; i <= N; i++) {
		struct Node *temp = chain[i];
		// 리스트를 모두 돌면서, 스케줄 표에 넣을 수 있는지를 확인.

		//printf("temp -> diff: %d\n", temp->diff); 
		while (temp) {
			flag = 1; 
			//printf("temp -> diff: %d\n", temp -> diff); 
			for (int j = temp -> start + 1; j < temp -> end; j++){
				if (schedule[j] == 1) {
					flag = 0;
					 break;
				}
			}
			if (flag) {
				result++; 
				//printf("curr -> diff: %d curr -> start: %d curr -> end: %d\n", temp -> diff, temp -> start, temp -> end);

				for (int j = temp -> start; j <= temp -> end; j++) {
					schedule[j] = 1;
				}
			}

			temp = temp -> next;
		}
	}

	// 모든 노드 삭제.
	struct Node *curr = NULL;
	for (int i = 0; i <= N; i++) {
		if (chain[i]) { // chain[i] 가 NULL 이 아니라면, 즉 노드가 있다면. 
			removeNode(chain[i]);
		}
	}
	
	printf("%d\n", result); 

	free(head);
	free(tail);
	free(schedule);
	
}