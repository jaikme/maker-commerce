#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main() {
setlocale (LC_ALL, "");
int i, vetCodigo[10], vetEstoque[10];
float vetPreco[10];

// Cadastrando o Produto
for (i=0; i<10; i++)
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
for (i=0; i<10; i++)
{
printf("\n----------------------------------------");
printf("\nCodigo do Produto..: %d", vetCodigo[i]);
printf("\nQtd em Estoque.....: %d", vetEstoque[i]);
printf("\nPreço unitário.....: %.2f", vetPreco[i]);
printf("\n----------------------------------------");
}

return 0;
}