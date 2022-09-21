#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	struct Node *next;
	char data;
};

void insert(struct Node *head, char data)
{
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode -> data = data;

	if (head -> next == NULL) {
		head -> next = newNode;
		newNode -> next = NULL;
		return; 
	}

	newNode -> next = head -> next;
	head -> next = newNode;
}

void removeNode(struct Node *head)
{
	struct Node *target = head -> next;

	if (head -> next == NULL) return;

	if (target -> next == NULL) {
		free(target);
		head -> next = NULL;
	} else {
		head -> next = target -> next;
		free(target); 
	}
}


int main()
{
	//char /*string[101]*/ c;
	char c;
	int len = 0, no = 0;

	struct Node *head = malloc(sizeof(struct Node));
	struct Node *curr = head -> next; 
	head -> next = NULL; 


	while (1) {
		scanf("%c", &c);
		if (c=='\n') continue;

		if(len == 0 && c == '.') break; 
		else if (c == '.') {  // 계산을 마쳐야 함. 

			len = 0; // len 값 초기화
			if (head -> next == NULL && !no) printf("yes\n"); 
			else printf("no\n"); // (나 가 )나 ]수보다 많은 경우. 

			no = 0; // no 값 초기화

			while (head->next != NULL) {
				removeNode(head);
			}
	
		} else if (no == 1) {   // )나 ]의 수가 (나 [의 수를 넘은 경우. 
			len++; 
		} else {  // 계산을 계속 진행. 
			len++;
			if (c == '(' || c == '['){
				insert(head, c);
			} else if ( c == ')' || c == ']') {
				if (head -> next == NULL) no = 1;
				else if (c == ')' && head -> next -> data == '(') {
					removeNode(head);
				} else if (c == ']' && head -> next -> data == '[') {
					removeNode(head); 
				} else {
					no = 1; 
				}
			}
		}
	}


	free(head); 
}