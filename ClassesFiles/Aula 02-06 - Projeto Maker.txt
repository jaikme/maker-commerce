#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main() {
setlocale (LC_ALL, "");
int i, vetCodigo[10], vetEstoque[10], produto, posicao, achou=0, qtdvenda;
float vetPreco[10];

// Cadastrando o Produto
for (i=0; i<3; i++)
{
printf("\n --------------- Produto Nr..: %d ------------------", i+1);
printf("\nCodigo do Produto..: ");
scanf("%d", &vetCodigo[i]);
printf("Quantidade em Estoque..: ");
scanf("%d", &vetEstoque[i]);
printf("Preço Unitário..: ");
scanf("%f", &vetPreco[i]);
printf("\n----------------------------------------------------");
}

// imprimindo os produtos cadastrados
printf("\n------------- Lista de Produtos Cadastrados -------------------");
for (i=0; i<3; i++)
{
printf("\nCodigo do Produto..: %d", vetCodigo[i]);
}

// trabalhando com o conceito de venda
printf ("\n\n------------------ Realizando uma Venda --------------------");
printf("\nDigite o código do produto desejado..:");
scanf("%d", &produto);
for (i=0 ;i<3; i++)
{
if (produto == vetCodigo[i] )
{
posicao = i;
achou = 1;
}
}
if( achou == 1)
{
printf("\nQual a quantidade que deseja..: ");
scanf ("%d", &qtdvenda);

printf("\nValor total a pagar..: %.2f ", vetPreco[posicao]* qtdvenda);
}
else
{
printf("\nInfelizmente não temos o produto desejado.");
}


return 0;
}