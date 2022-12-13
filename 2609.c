#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d %d", &a, &b); 

	int min, max; 
	min = a < b ? a : b;
	max = a > b ? a : b; 
	int gcd; 
	// 최대공약수 구하기.
	for (int i = 1; i <= min; i++) {
		if(min % i == 0 && max % i == 0) {
			gcd = i; 
		}
	}

	// 최소공배수 구하기.
	int oper = 1;
	int lcm;  
	while (1) {
		lcm = min * oper; 

		if (lcm % max == 0) {
			break;
		}
		oper++; 
	}

	printf("%d\n%d\n", gcd, lcm);

}