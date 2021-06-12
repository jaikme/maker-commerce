#include <stdio.h>
#include <stdlib.h>
#include <locale.h>


int main() {
	
	int n1, n2;
	printf("Saiba qual eh o menor entre dois numeros!\n\n ");
	printf(" Digite o primeiro numero: ");
	scanf("%d", &n1);
	printf("\n  Digite o segundo numero: ");
	scanf("%d", &n2);
	if(n1 < n2){
		printf("\n\nO %d eh o menor numero!", n1);
	}else{
		printf("\n\n\nO %d eh o menor numero!", n2);
	}	
	system("pause");
	return 0;
}