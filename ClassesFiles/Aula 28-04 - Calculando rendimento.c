#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
int main() {
setlocale(LC_ALL, "Portuguese");
int tipoRenda; float valorInv;
printf("Digite: \n 1: Poupança\n 2: Fundos de renda fixa\n");
scanf("%d", &tipoRenda);
if(tipoRenda > 2 || tipoRenda < 1){
printf("\n ERRO: Digite um tipo de fundo válido\n\n");
system("pause");
return 0;
}
printf("Digite o valor do seu investimento: ");
scanf("%f", &valorInv);
if(tipoRenda == 1){
printf("\n\n Na Poupança seu investimento terá rendido R$%.2f em um mês\n" , valorInv * 1.03);
}else if(tipoRenda == 2){
printf("\n\n No Fundo de renda fixa seu investimento terá rendido R$%.2f em um mês\n", valorInv * 1.04);
}
system("pause");
return 0;
}