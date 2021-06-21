#include <stdio.h>
#include <stdlib.h>
#include <string.h>



struct Produtos{
  char nomeProd[30], categoria[20], descricao[70] ;
  int codigo, qtdEst, qtdMinEst;
  float valor;
};



//struct cliente
// struct carrinho de compras



int main() {

  // declarando uma variável do tipo struct
  struct Produtos cadProduto[5];
  int i, pesqProd,achei=0, posicao, compra;
  // entrada de dados
  printf("\n-------------------- Cadastro de Produtos ---------------------\n");

  for (i=0; i< 3; i++) {
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
  printf("\n\n-------------------- Pesquisando um Produto ---------------------\n");
  printf("\n Produtos em Estoque ----------------------------------------------\n");
  printf("\nCodigo\n");

  for (i=0; i<3; i++) {
    printf("%d \n", cadProduto[i].codigo);
  }

  printf("\n----------------------------------------------------------------\n");
  printf("\nQual o codigo do produto deseja pesquisar..: ");
  scanf("%d", &pesqProd);

  for (i=0; i<3;i++) {
    if (cadProduto[i].codigo == pesqProd) {
      posicao = i;
      achei = 1;
      break;
    }
  }

  if (achei == 0) {
    printf("\nProduto não encontado.");
  } else {
    printf("\nDados do Produto ---------------------\n");
    printf("Codigo..: %d", cadProduto[posicao].codigo);
    printf("\nQuantidade em Estoque..: %d", cadProduto[posicao].qtdEst);
    printf("\nQuantidade em Minima no Estoque..: %d", cadProduto[posicao].qtdMinEst);
    printf("\nValor do Produto..: %.2f", cadProduto[posicao].valor);
    printf("\n-----------------------------------------------------------------\n");
  }

  //Listar Produtos que estão abaixo da quantidade mínima de estoque
  printf("\n\n--------- Relatorio de Produtos abaixo do Estoque Mininimo -----------\n");
  printf("Codigo\t Estoque \t QtdComprar\n");

  for(i=0; i< 3; i++) {
    if(cadProduto[i].qtdEst < cadProduto[i].qtdMinEst) {
      compra = cadProduto[i].qtdMinEst - cadProduto[i].qtdEst;
      printf("\n%d \t %d \t\t %d",cadProduto[i].codigo, cadProduto[i].qtdEst, compra);
    }
  }

  printf("\n-----------------------------------------------------------------\n");

  return 0;
}