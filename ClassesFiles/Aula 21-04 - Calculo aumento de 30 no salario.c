#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]) {
	float salario;
	printf("Digite seu salário: ");
	scanf("%f", &salario);
	if(salario < 500){
		salario = salario * 1.30;
		printf("Seu salario com aumento..: R$%.2f \n\n", salario);
	}else{
		printf("\n\nVocê recebe 500 ou mais que 500 reais e não tem direito ao aumento.");
	}
	//system("pause");
	return 0;
}