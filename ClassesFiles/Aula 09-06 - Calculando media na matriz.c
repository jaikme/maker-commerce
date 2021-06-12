#include <stdio.h>
#include <stdlib.h>



int main() {

float matNotas[5][3], soma=0;
int l, c;

for(l=0; l< 5; l++)
{ soma =0; // eu preciso zerar pois estou indo para a próxima linha que corresp
printf("\n-----------------------------------");
printf("\nNotas do Aluno Nr..: %d \n", l+1);
for (c=0; c< 2; c++)
{
printf("Nota.: ");
scanf("%f", &matNotas[l][c]);
soma = soma + matNotas[l][c];
}
matNotas[l][2] = soma/2;



}

// apresentando os dados armazenados na matriz
printf("\n---------------------------------------");
printf("\n\nNotas dos Alunos");
printf("\n---------------------------------------");
for(l=0; l< 5; l++)
{
printf("\nAluno Nr..: %d\n", l+1);
for (c=0; c< 3; c++)
{
printf("|%.1f\t", matNotas[l][c]);
}
printf("\n----------------------------------");
}
return 0;
}