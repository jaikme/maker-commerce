#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main() {
setlocale (LC_ALL, "");
int i, idade[10], soma= 0, media, qtd=0;

for (i=0 ; i<5; i++)
{
printf("Idade..: ");
scanf("%d", &idade[i] );
soma = soma + idade[i];
//calculando a média de idade do grupo

}
media = soma/i;
printf("\nMedia de idade do grupo..: %d", soma/i);

// verificando quem tem idade menor que a média de idade do grupo
for (i=0; i< 5; i++)
{
if (idade[i] < media)
{
qtd++;
}

}
printf("\n\nQuantidade de pessoas com idade abaixo da média de idade do grupo..: %d", qtd);



return 0;
}