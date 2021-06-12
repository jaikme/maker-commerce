#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main() {

// exemplo de vetor de string
char vetProduto[5][15]; // 5 produtos com no máximo 21 caracteres em cada.
int i;
// entrando com o nome de 5 produtos
printf("\n -------------- Cadastro de Produtos ---------------\n");
for (i=0; i< 5; i++)
{
printf("Nome do Produto..: ");
gets(vetProduto[i]);
}

printf("\n\n-------------- Produtos Cadastrados ---------------");
for (i=0; i< 5; i++)
{
printf("\n %d - Produto..: %s", i+1, strupr(vetProduto[i]));

}

return 0;
}