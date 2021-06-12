#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

float calcAumento(float preco, int categoria);
float calcImposto(int categoria, int situacao, float preco);
void classifica(float novoP);
int main()
{
setlocale(LC_ALL, "Portuguese");
int cat, sit;
float p, valAumento, valImposto,novoPreco;
// entrada de dados
printf("----------------------------------");
printf("\nCategoria \n1- Limpeza \n2- Alimentação \n3- Vestuário");
printf("\nQual categoria deseja..: ");
scanf("%d", &cat);
printf("\nSituação \n1- Produtos que necessitam de refrigeração \n2- Produtos que não necessitam de refrigeração");
printf("\nQual Situação deseja..: ");
scanf("%d", &sit);
printf("\nPreço..: ");
scanf("%f", &p);
// chamando a função que calcula o valor do aumento
valAumento = calcAumento(p,cat);
printf("Valor do Aumento..: %.2f", valAumento);
// chamando a função que calcula o valor do imposto
valImposto = calcImposto(cat,sit,p);
printf("\nValor do Imposto..: %.2f", valImposto);
// Calculando o novo preço
novoPreco = p + valAumento - valImposto;
printf("\nValor do Novo Preço..: %.2f", novoPreco);
// Chamando a função de Classificação
classifica(novoPreco);
return 0;
}

float calcAumento(float preco, int categoria)
{
int perc;
float aumento;
if (preco <= 25.00)
{
if (categoria == 1 )
{
perc = 5;
}
else if (categoria == 2)
{
perc = 8;
}
else
{
perc = 10;
}
}
else // já sei que o preço é maior que 25.00
{
if (categoria == 1)
{
perc = 12;
}
else if (categoria == 2)
{
perc = 15;
}
else
{
perc = 18;
}
}
aumento = preco * perc /100;
return aumento;
}

float calcImposto(int categoria, int situacao, float preco)
{
if (categoria == 2 || situacao == 1)
{
return preco *5/100;
}
else
{
return preco *8/100;
}
}

void classifica(float novoP)
{
if (novoP <= 50.00 )
{
printf("\nClassificação..: Barato");
}
else if (novoP < 120.00)
{
printf("\nClassificação..: Normal");
}
else
{
printf("\nClassificação..: Caro");
}
}