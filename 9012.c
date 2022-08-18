#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
	struct Stack *next;
	char c;
};

void push(struct Stack *head)
{
	struct Stack *newNODE = malloc(sizeof(struct Stack));
	newNODE -> c = '(';
	newNODE -> next = NULL; // 이 코드를 추가 했더니 백준 컴파일러에서도 작동됨.

	// 추가
	if (head -> next == NULL) {
		head -> next = newNODE;
	} else if (head -> next != NULL) {
		newNODE -> next = head -> next;
		head -> next = newNODE;
	}
}

void pop(struct Stack *head)
{
	// 이미 head -> next == NULL 인 경우는 이미 main 함수에서 처리하였다. 
	struct Stack *target = head -> next;
	// 수정
	if (target -> next != NULL) head -> next = target -> next;
	else head -> next = NULL; // 이 코드 한 줄 추가 했더니 됐다...
	free(target);
}

int main()
{
	int N, len, isYes; 
	char string[51];
	scanf("%d", &N);

	while (N--) {

		isYes = 1;
		scanf("%s", string);
		len = strlen(string);

		struct Stack *head = malloc(sizeof(struct Stack));
        
        // 이 코드를 추가하지 않으면 안됨.
		head -> next = NULL;

		for (int i = 0; i < len; i++) {

			if (string[i] == '(') {
				push(head);
			} else if (string[i] == ')') {
				if (head -> next == NULL) {
					isYes = 0;
					break;
				}
				pop(head);
			}

		}

		// 연결리스트가 비어 있지 않을 때 ('('가 여전히 남아 있을 때)
		if (head -> next != NULL) isYes = 0;

		if (isYes) printf("YES\n");
		else printf("NO\n");
		
		while (head -> next != NULL) {
			pop(head);
		}
		free(head);

	}
}
