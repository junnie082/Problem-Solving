#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// Memory Corruption 취약점
// 예상되지 않은 메모리 값 변경, 참조 등에 의해서 발생한다.
// 대부분 안전하지 않은 함수의 사용, 잘못된 함수 사용 등
// BOF 취약점.
// 버퍼란 데이터를 일시적으로 저장해두는 메모리 상의 공간을 의미한다.
// BOF는 프로세스가 데이터를 버퍼에 저장할 때 원래 크기보다 초과되는 데이터를 입력하면
// 정상적인 경우에는 사용되지 않아야 할 영역에 데이터가 덮어씌워지는 것을 의미한다.
// BOF에 취약한 대표적인 함수: strcpy, strcmp, gets, scanf, getwd, sprintf
struct Node {
	struct Node *next;
	struct Node *prev;
	char data[4];
};

// struct Stack {
// 	struct Stack *next;
// 	struct Stack *prev;
// 	char RorD;
// };

// void RDinsert(struct Stack *RDhead, char RorD) {
// 	struct Stack *stackNewNode = malloc(sizeof(struct Stack));
// 	stackNewNode -> RorD = RorD;

// 	stackNewNode -> next = RDhead -> next;
// 	RDhead -> next -> prev = stackNewNode;
// 	RDhead -> next = stackNewNode;
// 	stackNewNode -> prev = RDhead;
// 	//printf("stackNewNode -> RorD: %c\n", stackNewNode->RorD);
// }

void insert(struct Node *tail, char *data) {

	struct Node *nodeNewNode = malloc(sizeof(struct Node));
	//printf("data: %s\n", data); 
	strcpy(nodeNewNode -> data, data); 

	//printf("newNode -> data: %s \n", nodeNewNode -> data);

	tail -> prev -> next = nodeNewNode; 
	nodeNewNode -> prev = tail -> prev;
	nodeNewNode -> next = tail;
	tail -> prev = nodeNewNode; 
}

void deleteFromHead(struct Node *head, struct Node *tail) {
	struct Node *target = head -> next;
	head -> next = target -> next; 
	target -> next -> prev = head; 
	free(target); 
}

void deleteFromTail(struct Node *tail, struct Node *head) {
	struct Node *target = tail -> prev;
	tail -> prev = target -> prev; 
	target -> prev -> next = tail;
	free(target); 
}

void removeNode(struct Node *head) {
	struct Node *target = head -> next;
	head -> next = target -> next; 
	free(target); 
}

// void removeFromTail(struct Stack *RDtail, struct Stack *RDhead) {
// 	if (RDtail -> prev == RDhead) return;
// 	struct Stack *target = RDtail -> prev;

// 	target -> prev -> next = RDtail;
// 	RDtail -> prev = target -> prev;
// 	free(target); 
// }

int main()
{
	int turn = 0, T, len, fromHeadisTrue = 1, isError, n, index;
	scanf("%d", &T);
	char c;
	char **p = (char **)malloc(sizeof(char) * T);

	for (int i = 0 ; i < T; i++) {
			p[i] = (char*)malloc(sizeof(char) * 100000);
	}
	//char *p[T];

	struct Node *head = malloc(sizeof(struct Node)); 
	struct Node *tail = malloc(sizeof(struct Node)); 

	// struct Stack *RDhead = malloc(sizeof(struct Stack));
	// struct Stack *RDtail = malloc(sizeof(struct Stack));
	// RDhead -> next = RDtail; 
	// RDhead -> prev = NULL;
	// RDtail -> prev = RDhead;
	// RDtail -> next = NULL; 

	head -> prev = NULL;
	head -> next = tail;
	tail -> next = NULL;
	tail -> prev = head;  
	
	getchar();



	while (turn<T) {  	

		printf("turn: %d\n", turn); 

		isError = 0; 
		fromHeadisTrue = 1;		
		// while(1) {
		// 	scanf("%c", &c);
		// 	//printf("c: %c\n", c);
		// 	if (c != 'R' && c != 'D' && RDhead -> next != RDtail) break; 
		// 	RDinsert(RDhead,  c);  
		// 	//printf("RDhead -> next -> RorD = %c\n", RDhead -> next -> RorD);
		// } 
		scanf("%s", p[turn]);
		printf("p[turn]: %s\n", p[turn]); 


		scanf("%d", &n); 
		//getchar();
		printf("n: %d\n", n); 

		//printf("n: %d\n", n); 
		//char *str[n];
		char **str = (char **)malloc(sizeof(char *) * (n+1));
		//char *str = malloc(sizeof(char) * n);
		for (int i = 0 ; i < n; i++) {
			str[i] = (char *)malloc(sizeof(char) * 10); 
		}

		index = 0; 
		len = 0;
		

		// str= "123";
		// atoi(str); // = 정수인 123을 반환함.
		/* 문제 */
		// atoi 는 123*456qpowi 입력이 들어옴. 
		// 어떤 수를 반환할까?
		// 123   왜냐, 123 까지만 정수니까. *는 문자임.
	    // 따라서, * 이 들어오면 atoi 는 0을 반환함으로써 함수를 끝내.
	    // 그러면 0은 어떻게 처리할 것인가?
	    // 1230456qpowi 이런 문자열이 들어왔을 때, atoi가 반환하는 정수는?
	    // 123 까지만 반환합니다. 왜냐, 0은 곧 return 의미하기 때문에.
	    // c를 받건, *을 받건, 0을 받건 atoi 함수는 항상 0을 반환함으로써 함수를 끝내기 때문에
	    // 문자와 0을 구별할 수 없음.
	    // 따라서 atoi 함수로는 숫자 0을 처리할 수 없게 됨.
	    // 100 -> 1만 출력됨. 그래서 atoi 포기.

		while(1){
			scanf("%c", &c);
			//printf("c: %c", c);
			// if (n == 0) break;
			if ( c == '[') continue;
			else if (c == ',') { 
				//printf("str[index]: %s\n", str[turn]);
 				insert(tail, str[index]);
				index++;
				len = 0; 
			} else if (c == ']') {
				//printf("str[index]: %s\n", str[turn]);
				//printf("index: %d len: %d\n", index, len); 
				if (n == 0) break;
				insert(tail, str[index]);
				break;
			} 
			else {
				//strcat(str[index], &c); 
				str[index][len] = c;
				len++;
			}
			//printf("index: %d\n", index);
		}
		getchar();

		//printf("n: %d, index: %d\n", n, index); 

		// while (RDhead -> next != RDtail) {
		// 	if (RDtail -> prev -> RorD == 'R') {
		// 		//printf("R!!!\n");
		// 		fromHeadisTrue = !fromHeadisTrue;
		// 	} else if (RDtail -> prev -> RorD == 'D') {
		// 		//printf("D!!!\n");
		// 		if (head -> next == tail || n == 0) {
		// 			removeFromTail(RDtail, RDhead); 
		// 			isError = 1;
		// 			break;
		// 		} else if (fromHeadisTrue) {
		// 			deleteFromHead(head, tail);
		// 		} else {
		// 			deleteFromTail(tail, head); 
		// 		}
		// 	}
		// 	removeFromTail(RDtail, RDhead); 
		// }

		len = strlen(p[turn]); 
		//printf("len: %d\n", len); 
		for (int i = 0; i < len; i++) {
			if (p[turn][i] == 'R') fromHeadisTrue = !fromHeadisTrue;
			else if (p[turn][i] == 'D') {
				if (head -> next == tail || n == 0) {
					isError = 1;
					break;
				} else if (fromHeadisTrue) {
					deleteFromHead(head, tail); 
				} else {
					deleteFromTail(tail, head); 
				}
			}
		}


		if (isError == 1) {
			printf("error");
		} else if (head -> next == tail || n == 0) {
			printf("[]");
		} else {
			printf("[");
			if (fromHeadisTrue){
				struct Node *curr = head -> next;
				while (1) {
					printf("%s", curr->data);
					if (curr -> next == tail) break;
					printf(",");
					curr = curr -> next; 
				}
			} else {
				struct Node *curr = tail -> prev;
				while (1) {
					printf("%s", curr->data);
					if (curr -> prev == head) break;
					printf(",");
					curr = curr -> prev;
				}
			}
			printf("]");
		}

		printf("\n");

		for (int i = 0; i < n; i++) {
			free(str[i]); 
		}
		free(str);
		
		while(head->next != tail) {
			removeNode(head); 
		}
		head->next = tail;
		head->prev = NULL;
		tail->prev = head;
		tail->next = NULL;

		turn++; 
	}

	for (int i = 0 ; i < T; i++) {
		free(p[i]);
	}
	free(p);

	free(head);
	free(tail);
	// free(RDhead);
	// free(RDtail);

	return 0; 
}
