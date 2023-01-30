#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
	int map[26][26] = {0};
	int visited[26][26] = {0}; 

	queue<int> row;
	queue<int> col; 

	int N;
	cin >> N; 

	string str; 
	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < N; j++) {
			map[i][j] = (int)str[j]-'0';
		}
	}

	int count;

	vector<int> result;  
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (map[i][j] == 1) {
				row.push(i); col.push(j); 
				count = 1;

				while (!row.empty()) { 
					// 네 가지 경우로 나뉜다.
					// 상, 우, 하, 좌 ..... => 내일부터 다시 도전. 
					map[row.front()][col.front()] = 0; 
					if (row.front()-1 >= 0 &&
						map[row.front()-1][col.front()] == 1) {
						// 상
						row.push(row.front()-1);
						col.push(col.front());
						map[row.back()][col.back()] = 0; 
						count++;  
					} 
					if (col.front()+1 < N &&
						map[row.front()][col.front()+1] == 1) {
						// 우
						row.push(row.front()); 
						col.push(col.front()+1); 
						map[row.back()][col.back()] = 0;
						count++; 
					} 
					if (row.front()+1 < N &&
						map[row.front()+1][col.front()] == 1) {
						// 하
						row.push(row.front()+1); 
						col.push(col.front()); 
						map[row.back()][col.back()] = 0; 
						count++; 
					} 
					if (col.front()-1 >= 0 &&
						map[row.front()][col.front()-1] == 1) {
						// 좌
						row.push(row.front());
						col.push(col.front()-1); 
						map[row.back()][col.back()] = 0; 
						count++; 
					}

					row.pop(); 
					col.pop(); 

				}
				if (count > 0) {
					result.push_back(count); 
				} 
			}

			
		}

	}

	sort(result.begin(), result.end());

	cout << result.size() << endl; 
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl; 
	}
}