#include <iostream>
#include <queue>
using namespace std; 

int deter(int district[][101], int N) {
	queue<int> r, c;
	int current, numberOfDistrict = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (district[i][j] == 0) continue; 
			current = district[i][j]; 
			r.push(i); c.push(j);
			district[i][j] = 0; 
			numberOfDistrict++;  

			while (!r.empty()) {
				// 상, 우, 하, 좌 순서대로 검사하기. 
				if (r.front()-1 >= 1 && district[r.front()-1][c.front()] == current) {
					// 상
					district[r.front()-1][c.front()] = 0; 
					r.push(r.front()-1); c.push(c.front());
				}
				if (c.front()+1 <= N && district[r.front()][c.front()+1] == current) {
					// 우
					district[r.front()][c.front()+1] = 0; 
					r.push(r.front()); c.push(c.front()+1); 
				}
				if (r.front()+1 <= N && district[r.front()+1][c.front()] == current) {
					// 하
					district[r.front()+1][c.front()] = 0; 
					r.push(r.front()+1); c.push(c.front());
				}
				if (c.front()-1 >= 1 && district[r.front()][c.front()-1] == current) {
					// 좌
					district[r.front()][c.front()-1] = 0; 
					r.push(r.front()); c.push(c.front()-1);
				}
				r.pop(); c.pop(); 
			}
		}
	} 	

	return numberOfDistrict;
}

int main()
{
	int N; 
	int canDistrict[101][101]; 
	int cantDistrict[101][101]; 
	cin >> N; 

	string str; 
	for (int i = 1; i <= N; i++) {
		cin >> str; 
		for (int j = 0; j < N; j++) {
			if (str[j] == 'R') {
				canDistrict[i][j+1] = 1; cantDistrict[i][j+1] = 1; 
			}
			else if (str[j] == 'G') {
				canDistrict[i][j+1] = 2; cantDistrict[i][j+1] = 1; 
			}
			else {
				canDistrict[i][j+1] = 3; cantDistrict[i][j+1] = 2; 
			}
		}
	}

	
	// 적록색약 아닌 사람
	cout << deter(canDistrict, N) << " "; 
	// 적록색약인 사람
	cout << deter(cantDistrict, N); 

}