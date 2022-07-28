#include <stdio.h>
#include <stdlib.h>
//test(6976,0x101308580) malloc: *** error for object 0x5e40857d0070: pointer being freed was not allocated
//test(6976,0x101308580) malloc: *** set a breakpoint in malloc_error_break to debug
struct NODE {
	struct NODE *next;
	int data;
};

void insertNode(struct NODE *target, int data)
{
	struct NODE *newNode = malloc(sizeof(struct NODE));
	newNode -> next = target -> next;
	newNode -> data = data;

	target -> next = newNode;
}

void removeNode(struct NODE *target)
{
	struct NODE *target2 = target -> next;
	target -> next = target2 -> next;

	free(target2);
}

void calFunc(struct NODE *head1, struct NODE *head2, int N)
{
	struct NODE *curr1 = head1; // 분모
	struct NODE *curr2 = head2; // 분자

	//==========================================

	for (int i = 1; i <= N; i++){
		curr2 = head2 -> next;
		for (int j = 0; j < i; j++)
		{
			curr1 = head1 -> next;
			while (curr1 != NULL)
			{
				if (curr2 -> data % curr1 -> data == 0)
				{
					curr2 -> data /= curr1 -> data;
					curr1 -> data = 1;
				}
				if (curr1 -> data % curr2 -> data == 0)
				{
					curr1 -> data /= curr2 -> data;
					curr2 -> data = 1;
				}
				curr1 = curr1 -> next;
			}

			curr2 = curr2 -> next;
		}
	}
	//==========================================
}

void resultFunc()
{
	
}


int main()
{
	int T, M, N;
	unsigned int nominator, denominator;
	scanf("%d", &T);
	//int *arr = malloc(sizeof(int) * T);

	while (1)
	{
		if (!T) break;
		nominator = 1;
		denominator = 1;

		struct NODE *head1 = malloc(sizeof(struct NODE));
		struct NODE *head2 = malloc(sizeof(struct NODE));

		scanf("%d %d", &N, &M);
		// 연결 리스트에 2부터 N까지 넣기 (분모)
		for (int i = 1; i <= N; i++) insertNode(head1, i);
		// 다른 연결 리스트에 M-N+1 부터 M까지 넣기 (분자)
		for (int i = M; i > M - N ; i--) insertNode(head2, i);

		calFunc(head1, head2, N);

		//분모
		struct NODE *curr1 = head1 -> next;
		//분자
		struct NODE *curr2 = head2 -> next;

		while (head1->next != NULL)
		{
			denominator *= curr1 -> data;
			curr1 = curr1 -> next;
			removeNode(head1);
		}

	// 분자 결과 구하기 
		while (head2->next != NULL)
		{
			nominator *= curr2 -> data;
			curr2 = curr2 -> next;
			removeNode(head2);
		}

		free(head1);
		free(head2);

		printf("%d\n", nominator/ denominator);
		T--;
	}	

	return 0; 
}