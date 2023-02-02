#include <iostream>
#include <queue>
using namespace std; 

int main()
{
	int box[101][101][101] = {0}; 
	int M, N, H; 

	cin >> M >> N >> H; 

	int num; 
	queue<int> r, c, h, total;

	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				cin >> num; 
				if (num == 1) {
					h.push(i); 
					r.push(j);
					c.push(k);
					total.push(0);  
				}
				box[i][j][k] = num; 
			}
		}
	}

	// total.push(0); 
	int day = 0; 
	while (!total.empty()) {
		// 위, 아래, 앞, 우, 뒤, 좌
		if (h.front()-1 >= 1 && box[h.front()-1][r.front()][c.front()] == 0) {
			// 위
			h.push(h.front()-1); 
			r.push(r.front());
			c.push(c.front()); 
			total.push(total.front()+1); 
			box[h.front()-1][r.front()][c.front()] = 1;
		}
		if (h.front()+1 <= H && box[h.front()+1][r.front()][c.front()] == 0) {
			// 아래
			h.push(h.front()+1); 
			r.push(r.front());
			c.push(c.front()); 
			total.push(total.front()+1);
			box[h.front()+1][r.front()][c.front()] = 1;
		}
		if (r.front()-1 >= 1 && box[h.front()][r.front()-1][c.front()] == 0) {
			// 앞
			h.push(h.front()); 
			r.push(r.front()-1);
			c.push(c.front()); 
			total.push(total.front()+1);
			box[h.front()][r.front()-1][c.front()] = 1;
		}
		if (c.front()+1 <= M && box[h.front()][r.front()][c.front()+1] == 0) {
			// 우
			h.push(h.front()); 
			r.push(r.front());
			c.push(c.front()+1);
			total.push(total.front()+1); 
			box[h.front()][r.front()][c.front()+1] = 1;
		}
		if (r.front()+1 <= N && box[h.front()][r.front()+1][c.front()] == 0) {
			// 뒤
			h.push(h.front()); 
			r.push(r.front()+1);
			c.push(c.front()); 
			total.push(total.front()+1);
			box[h.front()][r.front()+1][c.front()] = 1;
		}
		if (c.front()-1 >= 1 && box[h.front()][r.front()][c.front()-1] == 0) {
			// 좌
			h.push(h.front()); 
			r.push(r.front());
			c.push(c.front()-1); 
			total.push(total.front()+1);
			box[h.front()][r.front()][c.front()-1] = 1;
		}
		if (total.front() > day) {
			day = total.front(); 
		}
		h.pop(); r.pop(); c.pop(); total.pop(); 
	}

	// 만약 상자에 익지 않은 토마토가 남아 있다면 -1 출력 후 프로그램 종료.
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			for (int k = 1; k <= M; k++) {
				if (box[i][j][k] == 0) {
					cout << -1;
					return 0;  
				}
			}
		}
	}
	cout << day; 
	return 0; 
}