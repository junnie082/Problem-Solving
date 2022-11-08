#include <stdio.h>
#include <stdlib.h>
int dfs[1001][1001] = {0};  
int bfs[1001][1001] = {0};

void matrix(int graph[][1001], int from, int to) {
	// 간선은 양방향이므로, 그래프의 graph[from][to] 와 graph[to][from] 모두 1로 설정해준다. 
	graph[from][to]++; 
	graph[to][from]++; 
}

// ========= DFS
typedef struct _Node {
	struct _Node *next; 
	int number; 
} Node; 

// 문제 없음. 
void insertStack(Node *top, int number) {
	Node *newNode = malloc(sizeof(Node)); 
	newNode -> number = number; 

	newNode -> next = top -> next; 
	top -> next = newNode; 
}


void deleteStack(Node *top) {
	Node *target = top -> next; 
	top -> next = target -> next; 
	
	free(target); 
}

void DFSandPrint(int dfs[][1001], Node *top, Node *bottom, int N, int existsDFS[]) {
	int i, flag; 

	while (top -> next != bottom) {
		flag = 1; 
		i = top -> next -> number; 

		for (int j = 1; j <= N; j++) {
			if (dfs[i][j]) {
				if (existsDFS[j] == 1) continue;  // 이 한 줄 때문에.....
				// 하루 종일 고민했다... 심지어 다른 사람의 도움을 빌려서@@@@@
				flag = 0;   
				dfs[i][j]--; 
				dfs[j][i]--; 
				// 만약 i에서 j로 가는 연결이 있다면? 
				// 이전에 방문한 노드라면????
				insertStack(top, j);
				if (existsDFS[j] == 0) {
					existsDFS[j] = 1; 
					printf("%d ", j);
				}  
				break; 
			}
		}
	
		// 만약 for 문에서 1 부터 N 까지 모두 돌아도 1 이 없다면??
		// 스택에서 노드 하나를 삭제하여야 한다. 
		if (flag) {
			deleteStack(top);
		}
	}
}

// ======== BFS
typedef struct _Queue {
	struct _Queue *next; 
	struct _Queue *prev; 
	int number; 
} Queue;

void insertQueue(Queue *end, int number) {
	Queue *newNode = malloc(sizeof(Queue));
	newNode -> number = number;	

	end -> next -> prev = newNode; 
	newNode -> next = end -> next; 
	end -> next = newNode; 
	newNode -> prev = end; 
}

void deleteQueue(Queue *front) {
	Queue *target = front -> prev; 
	front -> prev = target -> prev; 
	target -> prev -> next = front;

	free(target); 
}

void BFSandPrint(int bfs[][1001], Queue *end, Queue *front, int N, int existsBFS[]) {
	int i;

	while (end -> next != front) {
		i = front -> prev -> number; 

		for (int j = 1; j <= N; j++) {
			if (bfs[i][j]) {
				bfs[i][j]--; 
				insertQueue(end, j);
				if (existsBFS[j] == 0) {
					existsBFS[j] = 1; 
					printf("%d ", j); 
				}
			}
		}
		
		deleteQueue(front); 
	}
}

int main()
{	
	int N, M, V; 
	scanf("%d %d %d", &N, &M, &V);
	int *existsDFS = calloc(N + 1, sizeof(int));
	int *existsBFS = calloc(N + 1, sizeof(int)); 

	// 스택 만들기. 
	Node *bottom = malloc(sizeof(Node)); 
	Node *top = malloc(sizeof(Node));

	top -> next = bottom;  
	bottom -> next = NULL; 

	int from, to; 
	// 인접 행렬에 연결 표현하기. 
	for (int i = 0; i < M; i++) {
		scanf("%d %d", &from, &to); 
		matrix(dfs, from, to); 
		matrix(bfs, from, to); 
	}
	//DFS 탐색 및 출력.
	insertStack(top, V);  
	existsDFS[V] = 1; 
	printf("%d ", V); 
	DFSandPrint(dfs, top, bottom, N, existsDFS); 
	printf("\n"); 
	//top, bottom BFS에서 다시 사용하기 위해 스택 비우기
	while (top -> next != bottom) {
		deleteStack(top); 
	}
	//큐에는 *prev 또한 필요하므로, 새로운 구조체를 만들 필요가 있겠다. 
	Queue *front = malloc(sizeof(Queue)); 
	Queue *end = malloc(sizeof(Queue));

	end -> next = front; 
	end -> prev = NULL; 
	front -> next = NULL; 
	front -> prev = end;  


	//BFS 탐색 및 출력. 
	insertQueue(end, V); 
	existsBFS[V] = 1; 
	printf("%d ", V); 
	BFSandPrint(bfs, end, front, N, existsBFS);
	// 큐 비우기
	while (top -> next != bottom) {
		deleteQueue(front); 
	}

	free(existsDFS); free(existsBFS); 
	free(top); free(bottom); 
	free(front); free(end); 
}