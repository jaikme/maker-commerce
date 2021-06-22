#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <locale.h>
#include "ANSI-color-codes.h"

// Protótipos de funções
int getMenuOption();

// ──────────────────────────────────────
// Definições globais
#define HEADER_NAME "SUNLIGHT YELLOW"
#define MAX_STR_LENGTH 64
#define BOX_WIDTH 60
#define MAX_PRODUCTS 1

// ──────────────────────────────────────
// Tipos customizados do programa
typedef char string[MAX_STR_LENGTH];

// ──────────────────────────────────────
// Constantes do programa
const int IDX_REGISTER_PRODUCT = 1;
const int IDX_REMOVE_PRODUCT = 2;
const int IDX_REPORT_PRODUCT = 3;

// ──────────────────────────────────────
// Variáveis e estruturas
struct User {
  int balance;
};

struct Products {
  char name[MAX_STR_LENGTH];
  int cod;
  float amount;
};

int totalProducts = 0, renderMenuHeader = false;
struct Products products[MAX_PRODUCTS];


/*
 typedef struct {
      char nome[30];
      float matematica, fisica, media;
  } Alunos;
 */

/*
typedef struct {
  int index;
  char label;
} MenuOption;
 */

/* typedef struct {
  char nomeProd[30], categoria[20], descricao[70] ;
  int codigo, qtdEst, qtdMinEst;
  float valor;
} Produto;

struct Estoque {
  Produto produtos;
};

struct MenuItem {
  char value[30];
}; */


// ──────────────────────────────────────
// Métodos de utilidades

int calcLength(const string value) {
  int length = 0;
  // Calcula a quantidade e caracteres da string value
  while (value[length] != '\0') { ++length; }
  return length;
}

int calcPad( int width, int length) {
  return  (width - length) / 2;
}

void printError(string value) {
  printf(RED "\n⛔️ %s" reset, value);
}

void printInput(string value) {
  printf("%s%s: %s", value, HYELLOW, reset);
}

void printSuccess(string value) {
  printf("\n✅ %s%s%s\n", HGRENN, value, reset);
}

void pressAnyContinue(string value) {
  string buffer;
  sprintf(buffer, HGRENN "\n→ %s\n" reset, value);
  printInput(buffer);
}

// ──────────────────────────────────────
// Métodos do Cabeçalho

void printDoubleLine(int width) {
  unsigned i = width;
  while(i > 0) {
    i--;
    printf("═");
  }
}

void printLine(int width, bool newLine) {
  unsigned i = width;
  if(newLine) printf("\n" HYELLOW);
  while(i > 0) {
    i--;
    printf("─");
  }
  if(newLine) printf(reset "\n");
}

void displayHeading(string value) {
  /*
   * width  - largura interna da caixa(não contando as bordas)
   * length - quantidade e caracteres
   */
  int width = BOX_WIDTH, length = calcLength(value);

  // Desenha o início da caixa do cabeçalho com cor amarela
  printf("\n%s╔", HYELLOW);
  // Desenha a borda da caixa
  printDoubleLine(width);
  // Finaliza a primeira linha da caixa e inícia a próxima
  printf("╗\n║");

  // Desenha o miolo da caixa com o título
  int paddingWidth = calcPad(width, length);
  int paddingOdd = length % 2 ? paddingWidth + 1 : paddingWidth;

  printf("%s%*s%s%*s%s", IYELLOW, paddingWidth, "", value, paddingOdd, "", reset);
  printf("%s║\n╚", HYELLOW);

  // Desenha a borda da caixa
  printDoubleLine(width);

  // Finaliza a última linha da caixa e reseta a cor
  printf("╝\n%s", reset);
}

void displayChoiceHeading(string value) {
  int width = BOX_WIDTH, length = calcLength(value);
  int paddingWidth = calcPad(width, length);
  printf("\n" HYELLOW);
  printLine(paddingWidth, false);
  printf(" %s ", value);
  printLine(paddingWidth, false);
  printf(reset "\n");
}


// ──────────────────────────────────────
// Métodos do Menu

void displayText(string value) {
  printf("\n%s", value);
}

void displayMenuTitle(string value) {
  printf("\n%s☞ %s%s", IYELLOW, value, reset);
}

void displayMenuItem(int index, string label) {
  printf("\n%s%d) %s%s", HCYN, index, label, reset);
}

void renderMenu() {
  if(renderMenuHeader) {
    displayHeading("MENU");
  }
  /*
  * ╭─────────────────────────╮
  * │ OPÇÕES DE ADMINISTRAÇÃO │
  * ╰─────────────────────────╯
  */
  displayMenuTitle("Opções de administração:");

  displayMenuItem(IDX_REGISTER_PRODUCT, "Cadastrar produtos");
  displayMenuItem(IDX_REMOVE_PRODUCT, "Remover produto");
  displayMenuItem(IDX_REPORT_PRODUCT, "Relatório de produtos");
  printf("\n");

  /*
   * ╭───────────────────╮
   * │ OPÇÕES DE COMPRAS │
   * ╰───────────────────╯
   */
  displayMenuTitle("Opções de arrecadação:");

  displayMenuItem(4, "Adicionar produtos");
  displayMenuItem(5, "Remove produtos");
  displayMenuItem(6, "Produtos selecionados");
  displayMenuItem(7, "Pagar");
  printf("\n");


  displayMenuTitle("Outros");
  displayMenuItem(0, "Sair");

  renderMenuHeader = true;
}


// ──────────────────────────────────────
// Cadastro de produtos

void registerProduct() {

  // Valida a quantidade de produtos que podem ser cadastrados
  if(totalProducts >= MAX_PRODUCTS) {
    printError("Número máximo de produtos cadastrados!");
    return;
  }



  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading("Cadastrar produto");

  // Inputs
  printInput("Codigo do produto");
  scanf("%d", &products[totalProducts].cod);

  printInput("Nome do produto");
  fflush(stdin);
  fgets(products[totalProducts].name, MAX_STR_LENGTH, stdin);

  printInput("Valor do Produto");
  scanf("%f", &products[totalProducts].amount);

  totalProducts++;

  // Feedback de que o porduto foi cadastrado
  printSuccess("Produto cadastrado");
}

void removeProduct() {
  int cod;
  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading("Remover produto");

  // Inputs
  printInput("Codigo do produto");
  scanf("%d", &cod);

  for (int i = 0; i < totalProducts; ++i) {
    printf("%s", &products[i].name);
  }
}

void productsReport() {
  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading("Relatório de produtos");

  if(totalProducts > 0) {
    for (int i = 0; i < totalProducts; ++i) {
      // Posição e propriedades do item na tabela
      printf("[%d]\t", i + 1);
      printf("Código: %d\n\t", products[i].cod);
      printf("Nome: %s\t", products[i].name);
      printf("Valor: R$ %.2f\n", products[i].amount);
      printLine(MAX_STR_LENGTH, false);
    }
  } else {
    printError("Nenhum produto cadastrado no momento!\n");
  }

  pressAnyContinue("Pressione qualquer tecla para continuar...");
  fflush(stdin); // option ONE to clean stdin
  getchar(); // wait for ENTER
}

// ──────────────────────────────────────
// Ponto de entrada

int main() {
  // Aceitando Acentos
  setlocale (LC_ALL, "");

  struct User user;
  int menuCode;

  // Quanto de dinheiro o usuário tem quando abre o app
  // Esse valor pode ser uma consulta a um banco
  user.balance = 1375;

  // Começa entrada do menu e boas vindas
  displayHeading(HEADER_NAME);

  // Mostra mensagem de boas vindas
  displayText("BEM-VINDO, SELECIONE UMA OPÇÃO:\n");

  // Renderiza menu e computa ações do usuário
  do {
    renderMenu();
    menuCode = getMenuOption();
    switch (menuCode) {
      case 0: break;

      case IDX_REGISTER_PRODUCT:
        registerProduct();
        break;

      case IDX_REMOVE_PRODUCT:
        removeProduct();
        break;

      case IDX_REPORT_PRODUCT:
        productsReport();
        break;

      default:
        printError("Opção inválida");
    }

  } while (menuCode != 0);

  return 0;
}

// Pergunta ao usuário qual item do menu deseja
int getMenuOption() {
  int n;

  displayText(HMAG "\nCodigo: " reset);
  scanf("%d", &n);

  return n;
}