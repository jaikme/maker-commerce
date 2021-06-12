ALGORITMO!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

//variaveis
peso, engordar, emagrecer

//entrada
escreva("Digite seu peso: ")
leia()
//processamento
engordar = peso x 1,15
emagrecer = peso x 0,80
//saida
escreva("Engordando 15 por cento, seu peso sera: ", engordar)
escreva("Emagrecendo 20 por cento, seu peso sera: ", emagrecer)

EM C !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

#include <stdio.h>

int main() {
    // declaração de variaveis
float peso, engordar, emagrecer;
  //entrada
  printf("Digite seu peso: ");
  scanf("%f", &peso);
  //processamento
  engordar = peso * 1.15;
  emagrecer = peso * 0.8;
  //saida
  printf("\nEngordando 15 por cento, seu peso sera: %.2f Kg", engordar);
  printf("\nEmagrecendo 20 por cento, seu peso sera: %.2f Kg", emagrecer );  
    return 0;
}
