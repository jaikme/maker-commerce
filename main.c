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
#define MAX_STR_LENGTH 64
#define HEADER_NAME "SUNLIGHT YELLOW"

// ──────────────────────────────────────
// Tipos customizados do programa
typedef char String[MAX_STR_LENGTH];

// ──────────────────────────────────────
// Constantes do programa
#define MAX_STR_LENGTH 64
#define HEADER_NAME "SUNLIGHT YELLOW"


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
// Métodos do Cabeçalho

void printDoubleLine(int width) {
  unsigned i = width;
  while(i > 0) {
    i--;
    printf("═");
  }
}

void displayHeading(String value) {
  /*
   * width  - largura interna da caixa(não contando as bordas)
   * length - quantidade e caracteres
   */
  int width = 60, length = 0;

  // Calcula a quantidade e caracteres da string value
  while (value[length] != '\0') { ++length; }

  // Desenha o início da caixa do cabeçalho com cor amarela
  printf("%s╔", HYELLOW);
  // Desenha a borda da caixa
  printDoubleLine(width);
  // Finaliza a primeira linha da caixa e inícia a próxima
  printf("╗\n║");

  // Desenha o miolo da caixa com o título
  int paddingWidth = (width - length) / 2;
  int paddingOdd = length % 2 ? paddingWidth + 1 : paddingWidth;

  printf("%s%*s%s%*s%s", IYELLOW, paddingWidth, "", value, paddingOdd, "", reset);
  printf("%s║\n╚", HYELLOW);

  // Desenha a borda da caixa
  printDoubleLine(width);

  // Finaliza a última linha da caixa e reseta a cor
  printf("╝\n%s", reset);
}



// ──────────────────────────────────────
// Métodos do Menu

void displayText(String value) {
  printf("\n%s", value);
}

//void displayMenuItem(MenuOption opt) {
//  printf("\n░ %d → %s", opt.index, opt.label);
//}

void displayMenuItem(int index, String label) {
  printf("\n%s%d → %s%s", HBLU, index, label, reset);
}


int main() {
  // Aceitando Acentos
  setlocale (LC_ALL, "");

  displayHeading(HEADER_NAME);

  displayText("BEM-VINDO, SELECIONE UMA OPÇÃO:\n");

  displayMenuItem(1, "Cadastrar produtos");
  displayMenuItem(2, "Remover produto");

  displayMenuItem(2, "Relatório de produtos");
  displayMenuItem(3, "Cadastrar produtos");
  displayMenuItem(4, "Cadastrar produtos");

//  displayMenuItem(1, "Cadastrar produtos");
//  displayMenuItem(2, "Listar produtos");
//  displayMenuItem(2, "Listar produtos");

  int menuCode = getMenuOption();

  printf("%d", menuCode);
  return 0;
}

// Pergunta ao usuário qual item do menu deseja
int getMenuOption() {
  int n;

  displayText("\nCodigo: ");
  scanf("%d", &n);

  return n;
}