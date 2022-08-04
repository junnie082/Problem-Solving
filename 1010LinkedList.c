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

void calFunc(struct NODE *head1, int *head2, int N)
{	
	
	struct NODE *curr1 = head1 -> next;
	struct NODE *sup1 = head1;

	for (int i = 0; i < N; i++) {
		curr1 = head1 -> next;
		sup1 = head1;

		while (curr1 != NULL){
			if (head2[i] % curr1 -> data == 0) {
				head2[i] /= curr1 -> data;
				curr1 = curr1 -> next;
				removeNode(sup1);
				continue;
			}

			if (curr1 == NULL) break;

			if (head2[i] == 1) {
				break;
			}
			if (curr1 -> data % head2[i] == 0) {
				curr1 -> data /= head2[i];
				head2[i]= 1;
			}
			//printf("%d ", curr1 -> data);
			curr1 = curr1 -> next;
			sup1 = sup1 -> next;
		}
	}
	
		
}
			
int resultFunc(int *head2, int q)
{
	int result = 1;

	for (int i = 0; i < q; i++) {
		result *= head2[i];
	}

	return result;
}



void circularNode(struct NODE *head){
	struct NODE *curr = head-> next;
//각 연결 리스트의 마지막 원소를 다시 head 로 연결하기 (원형 리스트 만들기)
	while (1) {
		if (curr -> next == NULL) {
			curr -> next = head;
			curr = curr -> next; 
			break;
		}
		curr = curr -> next;
	}
}


int main()
{
	int T, M, N, k = 0, q;
	scanf("%d", &T);
	int *result = malloc(sizeof(int) * T);

	for (int y = 0; y < T; y++) {
		struct NODE *head1 = malloc(sizeof(struct NODE));
		//struct NODE *head2 = malloc(sizeof(struct NODE));

		scanf("%d %d", &N, &M);
		int *head2 = malloc(sizeof(int) * N);

		//int *arr = (int *)malloc(sizeof(int) * N);
		// 연결 리스트에 2부터 N까지 넣기 (분모)
		for (int i = 1; i <= N; i++) insertNode(head1, i);
		//flag = 0;
		// 배열에 M부터 M-N+1 까지 넣기 (분자)
		q = 0;
		for (int i = M-N+1; i <= M; i++) head2[q++] = i;

		//circularNode(head2);
		//circularNode(head1);
		calFunc(head1, head2, N);
		result[k++] = resultFunc(head2, q);

		// // ==== test
		// head2 = NULL;
		// head1 = NULL;

		free(head2);
		free(head1);
	}	

	for (int i = 0; i < k; i++) {
		printf("%d\n", result[i]);
	}

	free(result);

	return 0; 
}