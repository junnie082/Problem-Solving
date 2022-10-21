#include <stdio.h>
#include <stdlib.h>

void sortx(int *x, int *y, int i)
{
	int tempx, tempy;
	for (int j=1; j<i; j++){
		for (int k=0; k<i-1; k++){
			if (x[k] > x[k+1]){
				tempx = x[k];
				x[k] = x[k+1];
				x[k+1] = tempx;	

				tempy = y[k];
				y[k] = y[k+1];
				y[k+1] = tempy;
			}
		}
	}
}

void sortyy(int *arr, int *y, int j, int flag)
{
	int temp;
	for (int i=j-flag; i<j; i++){
		//printf("arr[i]: %d arr[i+1]: %d\n", arr[i], arr[i+1]);
		if (arr[i] > arr[i+1]){
			temp = y[i];
			y[i] = y[i+1];
			y[i+1] = temp;
		}
	}

}

void sorty(int *x, int *y, int i)
{
	int temp, arr[i], flag=0;
	for (int j=0; j<i-1; j++){
		if (x[j] == x[j+1]){
			arr[j] = y[j];
			flag++;
			if (x[j+2] == '\0'){
				arr[j+1] = y[j+1];
				sortyy(arr, y, j+1, flag);
				break;
			}
			else if (x[j+1] != x[j+2]) {
				arr[j+1] = y[j+1];
				sortyy(arr, y,  j+1, flag);
			}
		} else {
			flag = 0;
		}
	}
}

int main()
{
	int n, i=0;
	scanf("%d", &n);

	int *x = calloc(n, sizeof(int));
	int *y = calloc(n, sizeof(int));

	while (n--) {
		scanf("%d %d", x+i, y+i);
		i++;
	}
	sortx(x, y, i);
	sorty(x, y, i);

	for (int q = 0; q<i; q++){
		printf("%d %d\n", x[q], y[q]);
	}

	free(x);
	free(y);
}