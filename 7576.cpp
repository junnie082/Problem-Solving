#include <iostream>
#include <queue>
using namespace std; 

int main()
{
	int M, N; 
	cin >> M >> N; 

	int box[1001][1001] = {0}; 
	queue<int> row;
	queue<int> col; 
	queue<int> days;

	int num;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> num;
			if (num == 1) {
				row.push(i); col.push(j); days.push(0); 
			}
			box[i][j] = num;
		}
	}
	
	int day = 0; 
	while (!row.empty()) {
		// 상, 우, 하, 좌 를 확인.
		// 0이 들어 있다면, queue 에 값들을 넣은 후에 box에 0을 1로 갱신. 
		if (row.front()-1 >= 1 && box[row.front()-1][col.front()] == 0) {
			// 상
			row.push(row.front()-1); col.push(col.front()); 
			days.push(days.front()+1);
			box[row.front()-1][col.front()] = 1;  
		}
		if (col.front()+1 <= M && box[row.front()][col.front()+1] == 0) {
			// 우
			row.push(row.front()); col.push(col.front()+1); 
			days.push(days.front()+1);
			box[row.front()][col.front()+1] = 1;  
		}
		if (row.front()+1 <= N && box[row.front()+1][col.front()] == 0) {
			// 하
			row.push(row.front()+1); col.push(col.front()); 
			days.push(days.front()+1);
			box[row.front()+1][col.front()] = 1;  
		}
		if (col.front()-1 >= 1 && box[row.front()][col.front()-1] == 0) {
			// 좌
			row.push(row.front()); col.push(col.front()-1); 
			days.push(days.front()+1);
			box[row.front()][col.front()-1] = 1;  
		}
		if (days.back() > day) {
			day = days.back(); 
		}
		row.pop(); col.pop(); days.pop(); 
	}

	// 마지막에 배열 공간을 둘러보았을 때, 0이 남아 있다면 -1을 출력하고 프로그램 종료.
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			if (box[i][j] == 0) {
				cout << -1;
				return 0; 
			}
		}
	}

	cout << day; 
	return 0; 
}