#include <stdio.h>
#include <stdlib.h>



int main() {

int nr[15], i, maior, menor, posicaoMaior, posicaoMenor;

for (i=0; i< 15 ; i++)
{

printf("Numero..: ");
scanf("%d", &nr[i]);
}

maior = nr[0];
posicaoMaior = 0;
menor = nr[0];
posicaoMenor = 0;

for (i=0; i< 15; i++)
{
if (nr[i] > maior)
{
maior = nr[i];
posicaoMaior = i;
}
if (nr[i] < menor)
{
menor = nr[i];
posicaoMenor = i;
}

}
printf("\nMaior Numero..: %d Posicao..: %d", maior, posicaoMaior);
printf("\nMenor Numero..: %d Posicao..: %d", menor, posicaoMenor);

/* números armazenados no vetor
for (i=0;i< 5; i++)
{
printf("\nPosicao..: %d\tValor..: %d", i , nr[i] );
}
*/

return 0;
}