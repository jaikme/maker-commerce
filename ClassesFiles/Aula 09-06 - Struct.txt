#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Produtos{
char nomeProd[30], categoria[20], descricao[70];
int codigo, qtdEst, qtdMinEst;
float valor;
};



//struct cliente
// struct carrinho de compras



int main() {



// declarando uma variável do tipo struct
struct Produtos cadProduto;

// entrada de dados
printf("\n-------------------- Cadastro de Produtos ---------------------\n");
printf("Codigo..: ");
scanf("%d", & cadProduto.codigo);
printf("Quantidade em Estoque..: ");
scanf("%d", & cadProduto.qtdEst);
printf("Quantidade em Minima no Estoque..: ");
scanf("%d", & cadProduto.qtdMinEst);
printf("Valor do Produto..: ");
scanf("%f", & cadProduto.valor);

// imprimindo os dados cadastrados
printf("\n\n-------------------- Produtos Cadastrados ---------------------\n");
printf("Codigo..: %d", cadProduto.codigo);
printf("\nQuantidade em Estoque..: %d", cadProduto.qtdEst);
printf("\nQuantidade em Minima no Estoque..: %d", cadProduto.qtdMinEst);
printf("\nValor do Produto..: %.2f", cadProduto.valor);
printf("\n----------------------------------------------------------------\n");


return 0;
}