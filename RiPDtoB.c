#include <stdio.h>

int DecimalToBinary(int num)
{
	if (num < 2) return num; 

	DecimalToBinary(num/2);
	return num%2;
}

int main()
{
	int num = 293;
	printf("%d\n", DecimalToBinary(num)); 

	return 0;
}