#include <stdio.h>

int main() {
    // declaração de variaveis
float salario, vendas, salNovo, comissao, comissaoProc;
// entrada de dados
printf("Digite seu salario fixo: ");
scanf("%f",&salario);
printf("Digite o total de vendas: ");
scanf("%f",&vendas);
printf("Digite o percentual da comissao: ");
scanf("%f",&comissao);  
// processamento
comissaoProc = vendas * comissao/100;
salNovo = salario + comissaoProc;
// saida de dados
printf("\n---------------------------------------");
printf("\nPara %.2f porcento de comissao, voce tem", comissao);  
printf("\nO valor da comissão: %.2f", comissaoProc);
printf("\nSeu novo salario sera: %.2f", salNovo);
printf("\n---------------------------------------"); 
    return 0;
}