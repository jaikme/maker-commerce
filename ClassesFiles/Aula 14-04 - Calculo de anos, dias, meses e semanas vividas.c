#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
int main(){
float anoNasc, anoAtual, idades;
printf("Informe o ano do seu nascimento..: ");
scanf("%f", &anoNasc);
printf("Informe o ano Atual..: ");
scanf("%f", &anoAtual);
if(anoNasc > anoAtual){
  printf("Não é possivel nascer após o ano atual!");
}else{  
  idades = anoAtual - anoNasc;
printf("\n Sua idade em anos..: %.0f ", idades);
printf("\n Sua idade em meses..: %.0f ", idades * 12);
printf("\n Sua idade em dias..: %.0f ", idades * 365);
printf("\n Sua idade em semanas..: %.2f ",idades * 52.143); //Este valor é ~ a quantidade de semanas em 1 ano
} 
  system("pause");
  return 0;
}