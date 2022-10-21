#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char aisOne(int *op, int *opand, char *p,int b, int P, int Q, int R)
{
	int v, flag = 0, k=0, t=0, result;

	for (int i = 0; i < strlen(p); i++){
		if (p[i] == ' ') continue;

		if (flag == 1){
			flag = 0;
			continue;
		}   

		if ( p[i] == 'P'){
			//*(opand+ k++) = P;
			opand[k++] = P;
		} else if (p[i] == 'Q') {
			//*(opand + k++) == Q;
			opand[k++] = Q;
			//printf("Q: %d, k: %d", *(opand+k), k);
		} else if (p[i] == 'R') {
			//*(opand + k++) == R;
			opand[k++] = R;
		}else if ( p[i] == 'n') {
			b--;
			flag = 1; 
			if (p[i+2] == 'P') *(opand + k++) = !P;
			else if (p[i+2] == 'Q') {
				//*(opand + k++) = !Q;
				opand[k++] = !Q;
			    //printf("Q: %d", opand[k]);

			}
			else if (p[i+2] == 'R') opand[k++] = !R;//*(opand + k++) = !R; 

		} else if ( p[i] == 'a') {
			//*(op + t++) = 2;
			op[t++] = 2;
		} else if ( p[i] == 'o') {
			//*(op+ t++) = 3; 
			op[t++] = 3;
		} else if ( p[i] == 'i') {
			//*(op+ t++) = 4;
			op[t++] = 4;
		}
	}
	// for (int i = 0; i<3; i++){
	// 	printf("%d", opand[i]);
	// 	printf("\n");
	// }
	

	result = opand[0];

	for (int i = 0; i < b; i++){
		//printf("op[i]: %d,opand[i]: %d, opand[i+1]: %d, i: %d\n", op[i],opand[i], opand[i+1], i );

		switch (op[i]) {
			case 2:
			v = result && opand[i+1];
			//printf("case: 2");
			break;

			case 3:
			v= result || opand[i+1];
			//printf("case: 3");
			break;

			case 4:
			if(result == 1 && opand[i+1] == 0) v=0;
			else v=1;
			//printf("case: 4" );
			break;
		}
		result = v;
		//printf("result:  %d\n", result);
	}

	if (v) return 'T';
	else return 'F';
}

int main()
{
	int a, b, c;
	char p[50];
	scanf("%d %d %d", &a, &b, &c);
	getchar();
	scanf("%[^\n]s", p);

	int *op = calloc(b, sizeof(int));
	int *opand = calloc( c-b, sizeof(int));

	if ( b == 0 ) { 
		printf("%c RESULT\n\n", p[0]);
		printf("T T\n\n");
		printf("F F"); }
	else if ( a == 1) {
		printf("P RESULT\n\n");
		printf("T %c\n\n",aisOne(op, opand, p, b,1, 0, 0));
		printf("F %c", aisOne(op, opand, p, b,0, 0, 0));
		
	} else if ( a == 2 ) {

		printf("P Q RESULT\n\n");
		printf("T T %c\n\n", aisOne(op, opand, p, b, 1, 1, 0));
		printf("T F %c\n\n", aisOne(op, opand, p, b, 1, 0, 0));
		printf("F T %c\n\n", aisOne(op, opand, p, b, 0, 1, 0));
		printf("F F %c", aisOne(op, opand, p, b, 0, 0, 0));

	} else {
		printf("P Q R RESULT\n\n");
		printf("T T T %c\n\n", aisOne(op, opand, p, b, 1, 1, 1));
		printf("T T F %c\n\n", aisOne(op, opand, p, b, 1, 1, 0));
		printf("T F T %c\n\n", aisOne(op, opand, p, b, 1, 0, 1));
		printf("T F F %c\n\n", aisOne(op, opand, p, b, 1, 0, 0));
		printf("F T T %c\n\n", aisOne(op, opand, p, b, 0, 1, 1));
		printf("F T F %c\n\n", aisOne(op, opand, p, b, 0, 1, 0));
		printf("F F T %c\n\n", aisOne(op, opand, p, b, 0, 0, 1));
		printf("F F F %c", aisOne(op, opand, p, b, 0, 0, 0));



	}

	free(op);
	free(opand);
}