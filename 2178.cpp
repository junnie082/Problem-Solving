#include <iostream>
#include <queue> 
using namespace std; 

int main()
{
	int N, M; 
	int maze[101][101];
	cin >> N >> M;

	string str; 
	for (int i = 1; i <= N; i++) {
		cin >> str;
		for (int j = 1; j <= M; j++) {
			maze[i][j] = (int)str[j-1]-'0';
		}
	}

	queue<int> row; 
	queue<int> col;
	queue<int> total; 

	row.push(1); col.push(1); total.push(1); 

	int largest = 100000; 
	while (!row.empty()) {
		// "하, 우, 상, 좌" 를 먼저 확인한 후에, 1 인 좌표를 큐에 넣음.
		// 방문한 좌표에는 0 으로 업데이트 해줌. 
		// -> 하지만, 좌표가 (N, M) 이라면 0으로 업데이트 하지 않음. 
		// 만약 주변이 모두 0이라면, pop()

		// "하"
		if (row.front()+1 <= N && maze[row.front()+1][col.front()] == 1) {
			row.push(row.front()+1); col.push(col.front()); 
			total.push(total.front()+1);
			maze[row.back()][col.back()] = 0; 
		} 
		// "우"
		if (col.front()+1 <= M && maze[row.front()][col.front()+1] == 1) {
			row.push(row.front()); col.push(col.front()+1);
			total.push(total.front()+1);  
			maze[row.back()][col.back()] = 0; 
		}
		// "상"
		if (row.front()-1 >= 1 && maze[row.front()-1][col.front()] == 1) {
			row.push(row.front()-1); col.push(col.front());
			total.push(total.front()+1); 
			maze[row.back()][col.back()] = 0;  
		}
		// "좌"
		if (col.front()-1 >= 1 && maze[row.front()][col.front()-1] == 1) {
			row.push(row.front()); col.push(col.front()-1); 
			total.push(total.front()+1); 
			maze[row.back()][col.back()] = 0; 
		}

		if (row.front() == N && col.front() == M) {
			maze[row.front()][col.front()] = 1; 
			if (total.front() < largest) {
				largest = total.front(); 
			}
		}

		row.pop(); col.pop(); total.pop(); 

	}

	cout << largest; 
}