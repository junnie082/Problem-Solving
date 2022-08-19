#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Stack {
	struct Stack *next;
	char c;
};

void pushStack(struct Stack *head, char pushChar){

	struct Stack *newNode = malloc(sizeof(struct Stack));
	newNode -> c = pushChar;

	if (head -> next != NULL) newNode -> next = head -> next; 
	else newNode -> next = NULL;

	head -> next = newNode;
}

void popStack(struct Stack *head) {

	if (head -> next == NULL) return;
	struct Stack *target = head -> next;

	while (target != NULL) {
		printf("%c", target -> c);
		target = target -> next; 
	}


	while (1) {
		target = head -> next; 
		if (target == NULL) break;
		else {
			head -> next = target -> next; 
			free(target);
		}
	}
	free(target);

	// while (head -> next != NULL) {
		
	// 	target = head -> next; 
	// 	printf("%c", target -> c);
	// 	if (target -> next != NULL) head -> next = target -> next; 
		
	// 	free(target);
	// }
	// if (target -> next == NULL) printf("%c", target -> c);
	// else head -> next = target -> next; 
	
	//head -> next = NULL;
}

int main()
{
	int length, Reverse = 1;
	char string[100000];

	scanf("%[^\n]s", string);
	length = strlen(string);


	struct Stack *head = malloc(sizeof(struct Stack));
	head -> next = NULL; 


	for (int i = 0 ; i <= length ; i++) {


		if (string[i] == '<') {
			Reverse = 0;
			popStack(head); 
		} else if (string[i] == '>') {
			Reverse = 1; 
			printf(">");
			continue;
		} else if (string[i] == ' ' || i == length){
			//printf(" ");
			popStack(head);
			printf(" ");
			continue;
		}

		if (Reverse) {
			pushStack(head, string[i]);
		} else {
			printf("%c", string[i]); 
		}


	}
	free(head); 

}