#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

int main()
{
	int visited[101];

	int n; 
	cin >> n; 

	vector<int> relations[101]; 

	for (int i = 1; i <= n; i++) {
		visited[i] = -1; 
	}

	int start, end; 
	cin >> start >> end;

	int num; 
	cin >> num; 
	int x, y; 

	for (int i = 0; i < num; i++) {
		cin >> x >> y; 
		relations[x].push_back(y); 
		relations[y].push_back(x); 
	}

	queue<int> que; 
	que.push(start); 

	int count = 1;
	visited[start] = 0; 

	int flag;
	while (!que.empty()) {	

		// cout << "que: " << que.front() << endl;
		// if (relations[que.front()].size() == 0) {
		// 	break; 
		// }
		// flag = 0; 
		while (relations[que.front()].size() > 0) {
		
			que.push(relations[que.front()].back());
			if (visited[que.back()] == -1) {
				visited[que.back()] = visited[que.front()] + 1; 
				// flag = 1; 
			} 

			relations[que.front()].pop_back(); 
		}

		// cout << "quefront: " << que.front() << "count: " << count << endl; 
		// if (flag == 1) count++; 
		que.pop(); 
	}


	cout << visited[end];
}