//
// Created by Jaime Costa on 21/06/21.
//

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>
#include "ANSI-color-codes.h"

// Protótipos de funções
int getMenuOption();
void productsReport();
void printLine(int width, bool newLine);

// ──────────────────────────────────────
// Definições globais
#define HEADER_NAME "SUNLIGHT YELLOW"
#define MAX_STR_LENGTH 60
#define BOX_WIDTH 40
#define MAX_PRODUCTS 4

// ──────────────────────────────────────
// Tipos customizados do programa
typedef char string[MAX_STR_LENGTH];

// ──────────────────────────────────────
// Constantes do programa
const int IDX_REGISTER_PRODUCT = 1;
const int IDX_REMOVE_PRODUCT = 2;
const int IDX_REPORT_PRODUCT = 3;

const int IDX_CHOSEN_SELECT = 4;
const int IDX_CHOSEN_REMOVE = 5;
const int IDX_PRODUCTS_CHOSEN = 6;
const int IDX_PRODUCTS_PAY = 7;

// ──────────────────────────────────────
// Variáveis e estruturas
struct User {
  string name;
  float balance;
  double rechargeTime;
};

struct User user;

//// produtos
struct Products {
  string name;
  int cod;
  float price;
};

int totalProducts = 0, totalChosen = 0, renderMenuHeader = false;
struct Products products[MAX_PRODUCTS];

//// carrinho
struct ProductsChosenCart {
  struct Products products[MAX_PRODUCTS];
  float total;
};

struct ProductsChosenCart cart;

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

void displayText(string value) {
  printf("\n%s", value);
}

void pressAnyContinue() {
  string buffer;
  sprintf(buffer, HGRENN "\n→ %s\n" reset, "Pressione qualquer tecla para continuar...");
  printInput(buffer);
  fflush(stdin);
  getchar();
}

void displayProductRow(int i, int cod, string name, float price) {
  printf("[%d]\t", i);
  printf("Código: %d\n\t", cod);
  printf("Nome: %s\n\t", name);
  printf("Valor: R$ %.2f\n", price);
  printLine(BOX_WIDTH, false);
  printf("\n");
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
void displayCurrentUserInfo() {
  printf("\n" YELB BBLK "Bem vinda(o) %s " reset "\n", user.name);
  printf(BYEL "\n💰 Seu saldo é: R$ %.2f" reset, user.balance);
  printf(GRN "\n🔋 Tempo de recarga: %.2fh" reset, user.rechargeTime);
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

  displayMenuItem(IDX_CHOSEN_SELECT, "Selecionar produto para arrecadar");
  displayMenuItem(IDX_CHOSEN_REMOVE, "Remover do carrinho");
  displayMenuItem(IDX_PRODUCTS_CHOSEN, "Produtos selecionados");
  displayMenuItem(IDX_PRODUCTS_PAY, "Pagar");
  printf("\n");

  displayMenuTitle("Outros");
  displayMenuItem(0, "Sair");

  renderMenuHeader = true;
}


// ──────────────────────────────────────
// Administração de produtos

void registerProduct() {

  // Valida a quantidade de produtos que podem ser cadastrados
  if(totalProducts >= MAX_PRODUCTS) {
    printError("Número máximo de produtos cadastrados!\n");
    pressAnyContinue();
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
  scanf("%f", &products[totalProducts].price);

  totalProducts++;

  // Feedback de que o porduto foi cadastrado
  printSuccess("Produto cadastrado");
}

void removeProduct() {
  int cod, i, j, foundIndex = -1;
  string errorMsg = "Produto não encontrado ou inexistente!";
  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading("Remover produto");

  // Inputs
  printInput("Código do produto");
  scanf("%d", &cod);

  // Se for um código inválido, dispara um erro
  if(cod < 1) {
    printError(errorMsg);
    pressAnyContinue();
    return;
  }

  // Pesquisa pelo item e para quando encontrar
  for (i = 0; i < totalProducts; ++i) {
    if(products[i].cod == cod) {
      // Guarda a posição
      foundIndex = i;
      break;
    }
  }

  if(foundIndex == -1) {
    printError(errorMsg);
  } else {
    // Remove o elemento movendo suas posições pra esquerda
    for (i = foundIndex + 1; i < totalProducts; ++i) {
      int currentPos = i - 1;
      // Pega a posição atual e substitui pela seguinte
      products[currentPos] = products[i];
    }

    // Atualiza a contagem total de produtos
    totalProducts--;
    printSuccess("Produto removido");
  }

  pressAnyContinue();
}

void productsReport() {
  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading("Relatório de produtos");

  if(totalProducts > 0) {
    for (int i = 0; i < totalProducts; ++i) {
      // Posição e propriedades do item na tabela
      displayProductRow(i + 1, products[i].cod, products[i].name, products[i].price);
    }
  } else {
    printError("Nenhum produto cadastrado no momento!\n");
  }

  pressAnyContinue();
}


// ──────────────────────────────────────
// Opções de compras

void selectProduct() {
  int cod, foundIndex = -1;

  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading("Selecionar produto");

  // Inputs
  printInput("Codigo do produto");
  scanf("%d", &cod);

  // Se for um código inválido, dispara um erro
  if(cod < 1) {
    printError("Código inválido!");
    pressAnyContinue();
    return;
  }

  for (int i = 0; i < totalProducts; ++i) {
    // Posição e propriedades do item na tabela
    int prodCod = products[i].cod;
    if(prodCod == cod) {
      foundIndex = i;
      break;
    }
  }

  if(foundIndex == -1) {
    printError("Produto não encontrado!");
  } else {
    displayText(CYN "Produto selecionado:" reset "\n\n");
    struct Products chosen = products[foundIndex];

    // Exibe informações do item escolhido
    displayProductRow(foundIndex + 1, chosen.cod, chosen.name, chosen.price);
    // Adiciona no carrinho
    cart.products[foundIndex] = chosen;
    cart.total += chosen.price;
    // Atualiza a contagem total de produtos
    totalChosen++;
    printSuccess("Produto adicionado no carrinho");
  }

  pressAnyContinue();
}

void unselectProduct() {
  int cod, i, foundIndex = -1;
  string errorMsg = "Produto não encontrado!";

  if(totalChosen < 1) {
    printError("Você ainda não possui produto(s) selecionado(s)!\n");
    pressAnyContinue();
    return;
  }

  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading("Remover do carrinho");

  // Inputs
  printInput("Código do produto");
  scanf("%d", &cod);

  // Se for um código inválido, dispara um erro
  if(cod < 1) {
    printError(errorMsg);
    pressAnyContinue();
    return;
  }

  // Pesquisa pelo item e para quando encontrar
  for (int o = 0; o < totalChosen; ++o) {
    // Posição e propriedades do item na tabela
    struct Products p = cart.products[o];
    if(p.cod == cod) {
      foundIndex = o;
      break;
    }
  }

  if(foundIndex == -1) {
    printError(errorMsg);
  } else {
    // Remove o elemento movendo suas posições pra esquerda
    for (i = foundIndex + 1; i < totalChosen; ++i) {
      int currentPos = i - 1;
      // Pega a posição atual e substitui pela seguinte
      cart.products[currentPos] = cart.products[i];
    }

    // Atualiza a contagem total de produtos
    totalChosen--;
    printSuccess("Produto removido do carrinho");
  }

  pressAnyContinue();
}

void productsChosen(bool showTotal, bool askPay) {
  // Cabeçalho do que o usuário escolheu
  printf("\n");
  displayChoiceHeading(askPay ? "Pagar" : "Produtos selecionados");

  int i;

  if(totalChosen > 0) {
    for (i = 0; i < totalChosen; ++i) {
      // Posição e propriedades do item na tabela
      struct Products p = cart.products[i];
      displayProductRow(i + 1, p.cod, p.name, p.price);
    }

    if(showTotal) {
      printf(BBLK YELB " =\tTOTAL: R$ %.2f   " reset "\n", cart.total);
    }

    if(askPay) {
      string answer;
      printf("\n\n" YEL "💳\tSaldo: R$ %.2f", user.balance);
      printInput(BHWHT "\n\tDeseja realmente pagar? " reset MAG "S" reset "im / " MAG "N" reset "ão" );
      fflush(stdin);
      scanf("%s", answer);
      for(int k = 0; answer[k]; k++){
        answer[k] = tolower(answer[k]);
      }

      if(
          strcmp(answer, "sim") == 0 ||
          strcmp(answer, "s") == 0)
      {
        // Limpando carrinho
        for (i = 0; i < totalChosen; ++i) {
          // Posição e propriedades do item na tabela
          cart.products[i].cod = 0;
          strcpy(cart.products[i].name, "");
          cart.products[i].price = 0;
        }

        user.balance -= cart.total;
        cart.total = 0;
        totalChosen = 0;

        printf(BLU "\n🎉 Parabéns - Você arrecadou os produtos com sucesso!\n" reset);
        printf("\n💰 Novo saldo: " BBLK YELB " R$ %.2f " reset, user.balance);
        printf("\n");
      }
    }

  } else {
    printError("Você ainda não possui produto(s) selecionado(s)!\n");
  }

  fflush(stdin);
  pressAnyContinue();
}

// ──────────────────────────────────────6
// Ponto de entrada

int main() {
  // Aceitando Acentos
  setlocale (LC_ALL, "");
  int menuCode;


  strcpy(products[0].name, "Teste 1");
  products[0].cod = 100;
  products[0].price = 5.75;

  strcpy(products[1].name, "Teste 2");
  products[1].cod = 200;
  products[1].price = 24.10;

  strcpy(products[2].name, "Teste 3");
  products[2].cod = 300;
  products[2].price = 24.10;

  totalProducts = 3;

  cart.products[0] = products[1];
  cart.total = products[1].price;
  totalChosen = 1;

  // Informações do usuário
  strcpy(user.name, "Adriana Sicsu");
  user.rechargeTime = 6.2;
  // Quanto de dinheiro o usuário tem quando abre o app
  // Esse valor pode ser uma consulta a um banco
  user.balance = 45.75;

  // Começa entrada do menu e boas vindas
  displayHeading(HEADER_NAME);

  // Mostra mensagem de boas vindas
  displayCurrentUserInfo();

  displayText("\nO QUE DESEJA FAZER?\n");

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

      case IDX_CHOSEN_SELECT:
        selectProduct();
        break;

      case IDX_CHOSEN_REMOVE:
        unselectProduct();
        break;

      case IDX_PRODUCTS_CHOSEN:
        productsChosen(true, false);
        break;

      case IDX_PRODUCTS_PAY:
        productsChosen(true, true);
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