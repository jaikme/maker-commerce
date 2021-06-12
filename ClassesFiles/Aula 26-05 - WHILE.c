#include <stdio.h>
#include <stdlib.h>

int main() {
int matricula, tempo, qtd=0;
float sal, soma=0;

printf("Matricula..: ");
scanf("%d", &matricula);

while(matricula >0)
{
printf("Salario..: ");
scanf("%f", &sal);
printf("Tempo de Serviço..:");
scanf("%d", &tempo);
// calculando o total da folha de pagamento
soma = soma + sal;
// calculando o total de funcionários da empresa3
qtd++;

printf("\n----------------------------\n");
printf("Matricula..: ");
scanf("%d", &matricula);
}
printf("\n-------------------- Resultados ------------------");
printf("\nTotal da folha de pagamento..: %.2f", soma);
printf("\nTotal de funcionarios da empresa..: %d", qtd);
return 0;
}