#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main() {
setlocale (LC_ALL, "");
float sal, folha=0;

printf("\nSalário..: ");
scanf("%f", &sal);
do
{
folha = folha+ sal;

// alterando o valor da idade -- conceito de incremento da estrutura condicional
printf("\n--------------------------------");
printf("\nSalário..: ");
scanf("%f", &sal);

} while (sal >0); // fim enquanto

printf("\n---------------- Resultado --------------------");
printf("\nTotal da folha de pagamento.. R$ %.2f", folha);

return 0;
}