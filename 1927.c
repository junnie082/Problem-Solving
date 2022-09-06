#include<stdio.h>
#include<stdlib.h>

void swap(int *arr, int a, int b){
	int temp = arr[a];
	arr[a] = arr[b];
	arr[b] = temp;
}

void bubbleUp(int *arr,  int k) {

	int i = k-1;
	while (i != 0) {
		if (i % 2 == 0 && i >= 2 && arr[(i-2)/2] > arr[i]) {
		  	swap(arr, (i-2)/2, i);
		  	i = (i-2)/2;
		} else if ( i % 2 == 1 && i>=1 && arr[(i-1)/2] > arr[i]) {
		  	swap(arr, (i-1)/2, i);
		  	i = (i-1)/2;	
		} else break;
	}

	// 왼쪽 노드에 더 작은 값이 오도록.
	// if (k >= 2 && k%2 == 1) {
	// 	if (arr[k-2] > arr[k-1]) {
	// 		int temp = arr[k-2];
	// 		arr[k-2] = arr[k-1];
	// 		arr[k-1] = temp;
	// 	}
	// }
	// for (int i = 0; i < k; i++) {
	// 	printf("bubbleUP %d  \n", arr[i]);
	// }

}

void bubbleDown(int *arr, int k){
	arr[0] = arr[k-1];
    int i = 0, comp, t; 
    while (k>1) { 
    	

    	if (arr[2*i+1] == 0) break;

    	if (arr[2*i + 2] != 0 && arr[2*i + 2] < arr[2*i + 1]) {
    		swap(arr, 2*i+2, 2*i+1);
    	}

    	if (arr[i] >= arr[2*i + 1]) {
    		swap(arr, i, 2*i + 1);
    		i = 2*i + 1;
    	}
    	else if (arr[2*i + 2] != 0 && arr[i] >= arr[2*i + 2]) {
    		swap(arr, i, 2*i + 2);
    		i = 2*i + 2; 
    	} else break;

    }

    arr[k-1] = 0; 
    t = k-1;

    for (int i = k-1; i>0; i--) bubbleUp(arr, i);
    for (int t = 0; t < k; t++) {
    	printf("bubbleDown: %d \n", arr[t]);
    }

}

void insertElement(int *arr, int new, int k)
{
	arr[k-1] = new;
	bubbleUp(arr, k);
}

int removeElement(int *arr, int k) {
	int element = arr[0];
	bubbleDown(arr, k);

	return element;
}

int main()
{
	int num, N, k=0;
	scanf("%d", &N);
	int *arr = calloc(N, sizeof(int));

	for (int i = 0; i < N; i++){
		scanf("%d", &num);
		if (k == 0 && num == 0) printf("%d\n", 0);
		else if (num == 0) {
			printf("%d\n", removeElement(arr,k));
			k--;
		} else {
			k++;
			insertElement(arr, num, k);
		}
	}


	free(arr);
}