#include <stdio.h>

int funcOfStick(int X) {
	int sumOfStick = 0, a = 64, numOfStick = 1;
	if (X==64) return 1;

	do {
		a/=2;
		sumOfStick += a;
		if (sumOfStick < X) {
			numOfStick += 1;
		} else if (sumOfStick > X) {
			sumOfStick -= a;
		} 
	} while(X!=sumOfStick);

	return numOfStick;
}

int main()
{
	int X;
	scanf("%d", &X);
	printf("%d", funcOfStick(X));

}