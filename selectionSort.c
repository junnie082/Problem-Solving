#include <stdio.h>
#define SWAP(x, y, temp) ( (temp) = (x), (x) = (y), (y) = (temp) )

// 선택 정렬
void selection_sort(int list[], int N) {
	int least, temp; 

	// 마지막 숫자는 자동으로 정렬되기 때문에 (숫자 개수 - 1) 만큼 반복한다. 
	for (int i = 0; i < N-1; i++) {
		least = i; 

		// 최솟값을 탐색한다. 
		for (int j = i + 1; j < N; j++) {
			if (list[j] < list[least] ){
				least = j; 
			}
		}

		// 최솟값이 자기 자신이면 자료 이동을 하지 않는다. 
		if (i != least) {
			SWAP(list[i], list[least], temp);
		} 
	}
}


int main() {
	int list[10] = {4,2,8,1,3,9,7,6,5,10};

	selection_sort(list, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", list[i]); 
	}
}