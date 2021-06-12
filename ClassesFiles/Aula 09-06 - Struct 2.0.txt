#include <stdio.h>
#include <stdlib.h>
#include <string.h>>



struct Produtos{
char nomeProd[30], categoria[20], descricao[70];
int codigo, qtdEst, qtdMinEst;
float valor;
};



//struct cliente
// struct carrinho de compras



int main() {



// declarando uma variável do tipo struct
struct Produtos cadProduto[5];
int i;
// entrada de dados
printf("\n-------------------- Cadastro de Produtos ---------------------\n");
for (i=0; i< 3; i++)
{
printf("Codigo..: ");
scanf("%d", & cadProduto[i].codigo);
printf("Quantidade em Estoque..: ");
scanf("%d", & cadProduto[i].qtdEst);
printf("Quantidade em Minima no Estoque..: ");
scanf("%d", & cadProduto[i].qtdMinEst);
printf("Valor do Produto..: ");
scanf("%f", & cadProduto[i].valor);
printf("\n-----------------------------------------------------------------\n");
}
// imprimindo os dados cadastrados
printf("\n\n-------------------- Produtos Cadastrados ---------------------\n");
for (i=0; i<3; i++)
{
printf("Codigo..: %d", cadProduto[i].codigo);
printf("\nQuantidade em Estoque..: %d", cadProduto[i].qtdEst);
printf("\nQuantidade em Minima no Estoque..: %d", cadProduto[i].qtdMinEst);
printf("\nValor do Produto..: %.2f", cadProduto[i].valor);
printf("\n-----------------------------------------------------------------\n");
}

// imprimindo os dados cadastrados
printf("\n\n-------------------- Relatorio dos Produtos Cadastrados ---------------------\n");
printf("\nCodigo\tValor\tEstoque\tEstoque Minimo\n");
for (i=0; i<3; i++)
{
printf("%d \t %.2f \t %d \t %d \n", cadProduto[i].codigo, cadProduto[i].valor, cadProduto[i].qtdEst, cadProduto[i].qtdMinEst);
}
printf("\n----------------------------------------------------------------\n");


return 0;
}