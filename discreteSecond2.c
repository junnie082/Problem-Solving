#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, m, v, a, b, i, j=0, k=1, t=1;
	scanf("%d %d %d", &n, &m, &v);
	int *arr = calloc(2*m, sizeof(int));
	int *result = calloc(2*m, sizeof(int));
    
	i = m;

	while(i--) {
		scanf("%d %d", &a, &b);
		arr[j++] = a;
		arr[j++] = b;
	}

	
}