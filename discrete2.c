#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main() 
{
	char p[50];
	int a, b, c , k=0 , t=0, r=0, flag = 0, v;

	int *op = calloc(b, sizeof(int));
	int *opand = calloc(c-b, sizeof(int));
	//int *result = calloc(c, sizeof(int));
	int *result2 = calloc(sizeof(result)/sizeof(int), sizeof(int));

	scanf("%d %d %d", &a, &b, &c);
	getchar();
	scanf("%[^\n]s", p);

	printf(strlen(p));
	// if ( a == 1 ) {
	// 	//1. P == True
	// 	flag = 1;
	// 	for (int i = 0; i<strlen(p); i++ ) {
	// 		if ( p[i] == ' ' ) continue;
	// 		if ( p[i] == 'P') {
	// 			opand[k++] = flag;
	// 		} else if ( p[i] == 'n') {
	// 			opand[k++]= !flag;
	// 		} else if ( p[i] == 'i')  op[t++] = 4;
	// 		else if (p[i] == 'o')  op[t++] = 3; 
	// 		else if (p[i] == 'a')  op[t++] = 2;
			
	// 	}
	// } 

	// for (int i = 0; i<sizeof(op); i++){
	// 	printf(op[i]);
	// }
	// // opertor = 2

// 	for (int j=2; j<5; j++) {
// 		for (int i = 0; i<b; i++) {
// 			if (flag == 1) {
// 				flag = 0;
// 				continue;
// 			}

// 			if ( opand[i] == j ){
// 			switch (j) {
// 				case 2:
// 				v = opand[i] && opand[i+1];
// 				break;

// 				case 3:
// 				v = opand[i] || opand[i+1];
// 				break;

// 				case 4:
// 				if (opand == 1 && opand == 0) {
// 					v = 0;
// 				} else {
// 					v = 1;
// 				}
// 				break;
// 			} 
// 			flag = 1;
// 			result[r++] = v;
// 		} else {
// 			result[r++] = opand[i];
// 		}


// 		}
// }

	// //operator = 2
	// for (int i = 0; i<b; i++){
	// 	if (flag == 1) {
	// 		flag = 0; 
	// 		continue;
	// 	}
	// 	if ( op[i] == 2 ) {
	// 		v = opand[i] && opand[i+1];
	// 		result[r++] = v;
	// 		flag = 1;
	// 	} else {
	// 		result[r++] = opand[i];
	// 	}
	// }

	// r=0; 
	// flag = 0; 
	// //operator = 3;
	// for (int i = 0; i<sizeof(result); i++) {
	// 	if ( flag == 1 ){
	// 		flag = 0;
	// 		continue;
	// 	}
	// 	if ( result[i] == 3) {
	// 		v = opand[i] || opand[i+1];
	// 		result2[r++] = v;
	// 		flag = 1;
	// 	} else {
	// 		result2[r++] = result[i];
	// 	}
	// }

	// for (int i = 0; i<t; i++) {
	// 	printf(*(op+i));
	// }
	// for (int i = 0; i<k; i++){
	// 	printf(*(opand+i));
	// }

	//operator = 4;
	// for (int i =0; i<sizeof(result2); i++)
	// {
	// 	printf(result2[i]);
	// }

	 // free(op);
	 // free(opand);


}