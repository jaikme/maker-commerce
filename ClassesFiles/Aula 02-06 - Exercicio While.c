#include <stdio.h>
#include <stdlib.h>
#include <locale.h>



int main() {
setlocale (LC_ALL, "");
int idade, sexo, qtd=0, menorIdade, maiorIdade, menorIdSal, menorSexoSal, qtdMulher =0;
float sal, soma=0, menorSal = 999999.00;

printf("\nIdade..: ");
scanf("%d", &idade);
menorIdade = idade;
maiorIdade = idade;

while (idade >0)
{
printf("Sexo 1-Masculino 2-Feminino..: ");
scanf("%d", &sexo);
printf("Salario..: ");
scanf("%f", &sal);
// calculando a media salarial do grupo
soma = soma + sal; // aplicando o conceito do somatório
qtd++; // qtd = qtd+1; aplicando o conceito de contador
//verificando a menor idade do grupo
if (idade < menorIdade)
{
menorIdade = idade;
}

// verificando a maior idade do grupo
if (idade > maiorIdade)
{
maiorIdade = idade;
}

//verificando a menor salario do grupo
if (sal < menorSal)
{
menorSal = sal;
menorIdSal = idade;
menorSexoSal = sexo;
}
// calculando a quantidade de mulheres que ganham até 200.
if (sexo == 2 && sal <= 200.00)
{
qtdMulher++; // qtdMulher = qtdMulher + 1;
}

// alterando o valor da idade -- conceito de incremento da estrutura condicional
printf("\n--------------------------------");
printf("\nIdade..: ");
scanf("%d", &idade);

}// fim enquanto

printf("\n---------------- Resultado --------------------");
if (qtd == 0)
{
printf("\nNinguem participou da pesquisa.");
}
else
{
printf("\nMedia salarial do grupo..: %.2f", soma/qtd);
}
printf("\nMenor idade do grupo..: %d ano(s)", menorIdade);
printf("\nMaior idade do grupo..: %d ano(s)", maiorIdade);
printf("\nMenor salario do grupo..: %.2f", menorSal);
printf("\nIdade do funcionario com menor Salario..: %d anos", menorIdSal);
if (menorSexoSal == 1)
{
printf("\nSexo do funcionario com menor Salario é Masculino.");
}
else
{
printf("\nSexo do funcionario com menor Salario é Feminino.");
}

printf("\nQuantidade de mulheres que ganham ate R$ 200.00 ..: %d", qtdMulher);
return 0;
}