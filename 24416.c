#include <stdio.h>

int recurCount = 0; 
int dynamicCount = 0; 

int recurFib(n) {
	if (n == 1 || n == 2) {
		recurCount++; 
		return 1; 
	} else {
		return recurFib(n-1) + recurFib(n-2); 
	}
}

void dynamicFib(n) { 
	if (n == 1 || n == 2) return; 

	for (int i = 2; i < n; i++) {
		dynamicCount++; 
	}
}

int main()
{
	int n; 
	scanf("%d", &n);
	recurFib(n); 
	dynamicFib(n); 
	printf("%d %d\n", recurCount, dynamicCount); 
}