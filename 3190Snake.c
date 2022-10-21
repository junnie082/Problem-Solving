#include <stdio.h>
#include <stdlib.h>

struct Snake
{
	struct snake *next;
	int row;
	int col; 
};

void addBody(struct Snake *head, struct Snake *tail, int headRow, int headCol)
{
	struct Snake *newBody = malloc(sizeof(struct Snake));
	newBody -> row = headRow;
	newBody -> col = headCol;
	
	if (tail -> next == head) {
		tail -> next = newBody;
		newBody -> next = head;
	}
}

int findTheBody(struct Snake *head, struct Snake *tail){
	struct Snake *find = head -> next;

	while (find != tail) {
		if (find -> row == head -> row && find -> col == head -> col) return 1; 
	}

	return 0; 
}

// void apples(int *applesRow, int *applesCol, int K)
// {
// 	int row, col;
// 	for (int i = 0; i < K; i++) {
// 		scanf("%d %d", &row, &col);
// 		applesRow[i] = row;
// 		applesCol[i] = col;
// 	}
// }

void direction(int *directionX, char *directionC, int L) 
{	
	int time;
	char DorL;
	
	for (int i = 0; i < L; i++) {
		scanf("%d %c", &time, &DorL); 
		directionX[i] = time;
		directionC[i] = DorL; 
	}
}


int gameStart(struct Snake *head, struct *tail, int N){
	int time = 0, lenOfSnake = 1; 
 	int apples[101][101] = {0};
  	// 사과 배열에 두기 생성.
  	int K; 
	scanf("%d", &K); 

	int row, col; 
	for (int i = 0; i < K; i++) {
		scanf("%d %d", &row, &col);
		apples[row][col] = 2;
	}

	// // 사과의 좌표를 저장해 놓는 배열 두 개. 
	// int *applesRow = (int *)malloc(sizeof(int) * K);
	// int *applesCol = (int *)malloc(sizeof(int) * K);
	// apples(applesRow, applesCol, K); 

	// 방향에 대한 배열 생성. 
	int L; 
	scanf("%d", &L);
	int *directionX = (int *)malloc(sizeof(int) * L); 
	int *directionC = (char *)malloc(sizeof(char) * L);
	direction(directionX, directionC, L);



	while (1){
		time++;
		// 뱀의 머리가 벽에 닿았을 때. 즉, 배열의 범위를 넘었을 때. 
		if (head -> row > N || head -> col > N || head -> row < 1 || head -> col < 1) break;

		// 뱀의 머리와 뱀의 꼬리의 row나 col이 같으며 뱀의 길이가 4이상일 때.  
		if ( (head -> row == tail -> row || head -> col == tail -> col) && lenOfSnake > 3) {
			// 
			if (findTheBody(head, tail)) {
				return time; 
			}
		}

		(head -> row)++;
		(head -> col)++;
		// 사과를 먹었을 때 뱀의 길이가 길어짐. 즉, snake 연결 리스트에 노드 하나 추가. 
		if (apples[head -> row][head -> col] == 2) {
			addBody(head, tail, head -> row, head -> col);
		} 

		// // 뱀의 머리와 뱀의 꼬리의 col 이 같을 때.
		// else if (head -> col == tail -> col) {

		// }
	}

	return time; 
}

int main()
{
	struct Snake *head = (struct Snake *)malloc(sizeof(struct Snake));
	struct Snake *tail = (struct Snake *)malloc(sizeof(struct Snake));
	tail -> next = head; 

	// 처음 head 와 tail 의 좌표는 모두 (1,1), (1,1)
	head -> row = 1;
	head -> col = 1;
	tail -> row = 1;
	tail -> col = 1; 

	int N, K, L, X;
	char C;

	scanf("%d", &N);


	// 게임 시작.
	gameStart(head, tail, N);

}