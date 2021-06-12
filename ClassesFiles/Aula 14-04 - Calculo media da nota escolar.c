#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main() {
  float nota1, nota2, nota3, nota4, media, limite = 10;
    printf("Digite sua nota da p1..: ");
    scanf("%f", &nota1);
    printf("Digite sua nota da p2..: ");
    scanf("%f", &nota2);
    printf("Digite sua nota da p3..: ");
    scanf("%f", &nota3);
    printf("Digite sua nota da p4..: ");
    scanf("%f", &nota4);  
    media = (nota1+nota2+nota3+nota4) / 4; 
if(media > limite){
  printf("Algo está errado! Verifique se escreveu suas notas corretamente");
  return 0;
}
  
  if(media >= 7){
    printf("\nParabéns, Você foi aprovado!");
    printf("\nSua média é..: %.2f", media);
  }else{
    printf("Estude mais da próxima vez. Você foi Reprovado.");
  };      
return 0;
} 