#include <stdio.h>
#include <stdlib.h>

struct Node {
	struct Node *next;
	struct Node *prev;
	int data;
};

void init(struct Node *chain[], int N)
{
	for (int i = 0 ; i < N; i++) {
		chain[i] = NULL;
	}
}

void insert(struct Node *chain[], int data, int N)
{
	int hkey = data % N;
	if (hkey < 0) hkey *= -1;

	struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
	newNode -> data = data;

	if (chain[hkey] == NULL) {
		chain[hkey] = newNode;
		newNode -> next = NULL; 
		newNode -> prev = NULL; 
	} else if (chain[hkey] -> next == NULL) {
		chain[hkey] -> next = newNode;
		newNode -> prev = chain[hkey];
		newNode -> next = NULL;
	} else {
		newNode -> next = chain[hkey] -> next;
		chain[hkey] -> next -> prev = newNode; 
		chain[hkey] -> next = newNode;
		newNode -> prev = chain[hkey]; 
	}
}

void findRemove(struct Node *chain[], int data, int N)
{
	int hkey = data % N;
	if (hkey < 0) hkey *= -1;
	struct Node *find = chain[hkey];

	while (find != NULL) {
		if (find -> data == data) {
			printf("1\n");
			return;
		}
		find = find -> next;
	}

	printf("0\n");
}

void deleteNode(struct Node *chain)
{
	struct Node *temp = chain;
	struct Node *curr = temp;
	while (temp != NULL) {
		curr = temp -> next; 
		free(temp);
		temp = curr;
	}
}

int main()
{
	int N, M, num;
	scanf("%d", &N);
	struct Node *chain[N];
	init(chain, N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &num); 
		insert(chain, num, N);
	}

	scanf("%d", &M);
	for (int i = 0; i < M; i++) {
		scanf("%d", &num);
		findRemove(chain, num, N);
	}

	for (int i = 0; i < N; i++) {
		deleteNode(chain[i]);
	}
}