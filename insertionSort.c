#include <stdio.h>

void insert_sort(int list[], int N) {
	int i, temp;

	for (int key = 1; key < N; key++) {
		i = key - 1;
		while (1) {
			if (list[i] <= list[key] || i < 0) break;

			if (list[i] > list[key]) {
				temp = list[i];
				list[i] = list[key];
				list[key] = temp; 
			}
			i--;key--;
		}
	}
}

int main()
{
	int N;
	int list[10] = {8, 5, 6, 2, 4, 1, 9, 3, 7, 0};

	insert_sort(list, 10);

	for (int i = 0; i < 10; i++) {
		printf("%d\n", list[i]);
	}

}	