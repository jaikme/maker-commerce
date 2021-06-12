/* Entrando com 5 idades e informando ao final
- Quantidade de idosos
- Somatorio de idade do grupo
- Media de idade do grupo
- media de idade dos idosos ---- somatorio da idade dos idosos e quantidade dos idosos
- Percentual de crianças com menos de 10 anos
*/



#include <stdio.h>
#include <stdlib.h>
#include<locale.h>



int main() {
setlocale (LC_ALL, "Portuguese");
int i, soma=0, qtd=0, idade, media, somaIdoso=0, mediaIdoso, qtdEsp=0;
for(i=1; i<=5; i++)
{
printf("Idade..: ");
scanf("%d", &idade);
if (idade >=60)
{
qtd++; // quantidade de idoso
somaIdoso = somaIdoso + idade; // somatorio da idade dos idosos

}
soma = soma + idade; // somatorio da idade do grupo
if (idade <10) // verificando se é criança com menos de 10 anos
{
qtdEsp++;
}
printf("\n------------------\n");

} // fim for
media = soma / 5; // media = soma / (i-1) -- o i sai com 6
mediaIdoso = somaIdoso/ qtd;

printf("\n--- Resultados ---------------\n");
printf("Quantidade de Idosos..: %d", qtd);
printf("\nSomatorio da idade do grupo..: %d anos.", soma);
printf("\nMedia de idade do grupo..: %d anos.", media);
printf("\nMedia de idade dos idosos..: %d anos.", mediaIdoso);
printf("\nPercentual de crianças com menos de 10 anos..: %d%%.",qtdEsp *100/ 5);
printf("\n------------------\n");
return 0;
}