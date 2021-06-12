#include <stdio.h>
#include <stdlib.h>
#include<locale.h>



int main() {
setlocale (LC_ALL, "Portuguese");
int i,idade, sexo, sintomas, dias, ajuda, teste, resTeste, qtdNaoSint=0, qtdEspId25=0, qtdMSA = 0, somaMSA=0;
int qtdSintSim=0, somaDias=0, qtdNAjuda=0, qtdAssint=0;
for (i = 1 ; i<=4 ; i++)
{
// entrada de dados
printf("-------------- Entrevista - Nr: %d ----------------------\n", i);
printf("Idade..: ");
scanf("%d", &idade);
printf("\nSexo da Pessoa \n1- Masculino \n2- Feminino ");
printf("\nSexo..: ");
scanf("%d", &sexo);
printf("\nTeve sintomas do Coronavirus \n1- Sim \n2- Não ");
printf("\nSintomas..: ");
scanf("%d", &sintomas);
if (sintomas == 1) // só entra no if se teve sintomas
{
printf("\nPor quantos dias você teve sintomas..: ");
scanf("%d", &dias);
printf("\nPrecisou procurar ajuda médica? \n1- Sim \n2- Não");
printf("\nAjuda médica..: ");
scanf("%d" , &ajuda);
// calculando o somatório de dias e quantidade de pessoas que tiveram sintomas para posterior cálculo da média de dias
qtdSintSim++;
somaDias = somaDias+ dias;
// verificando se não precisou de ajuda
if (ajuda == 2)
{
qtdNAjuda++;
}
} // fim do if de quem teve sintomas
printf("\nJá realizou algum tipo de teste de covid? \n1-Sim \n2-Não ");
printf("\nTeste..: ");
scanf("%d", &teste);
if (teste == 1)
{
printf("\nQual foi o resultado? \n1-Positivo \n2-Negativo..: ");
printf("\nResultado..: ");
scanf("%d", &resTeste);

}
//A quantidade de pessoas que não tiveram sintomas.
if (sintomas == 2) // verificando se não teve sintomas
{
qtdNaoSint++; // qtd de pessoas que não tiveram sintomas

if (teste == 1) // Assintomáticos, pois já sei que não tiveram sintomas, mas teste foi positivo.
{
qtdAssint++;
}
}



//Qual o percentual de pessoas com menos de 25 anos que tiveram sintomas.
if (idade < 25 && sintomas == 1)
{
qtdEspId25++;
}
//A média de idade das mulheres que tiverem sintomas, mas não precisaram de ajuda médica.
if (sexo == 2 && sintomas == 1 && ajuda == 2)
{
somaMSA = somaMSA + idade;
qtdMSA++;

}
printf("\n-------------------------------------------------\n\n");
} // fim for

printf("\n---------------------- Resultado da Pesquisa ----------------------------");
printf("\nQuantidade de Pessoas que não tiveram sintomas..: %d", qtdNaoSint);
printf("\nPercentual de Pessoas com menos de 25 anos que tiveram sintomas.: %d%%", qtdEspId25 * 100 / (i-1)); // i é a quantidade de pessoas, mas lembre-se que ele sai do for com o valor 4
if (qtdMSA >0)
{
printf("\nMédia de idade das mulheres que tiverem sintomas, mas não precisaram de ajuda médica.: %d anos", somaMSA/qtdMSA);
}
else if (qtdMSA == 0)
{
printf("\nAs mulheres não tiveram sintomas.");
}
// media de dias com sintomas
if (qtdSintSim >0)
{
printf("\nMédia de dias com sintomas..: %d dias.", somaDias/qtdSintSim);
}
else if (qtdSintSim == 0)
{
printf("\nNo grupo ninguém teve sintomas.");
}

printf("\nQuantidade de Pessoas que tiveram sintomas, mas não precisaram de ajuda..: %d pessoa(s)", qtdNAjuda);
printf("\nQuantide de Assintomáticos..: %d pessoa(s))", qtdAssint);
printf("\n-------------------------------------------------------------------------");
return 0;
}