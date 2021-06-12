#include <stdio.h>
int main()
{
    //pra fazer somatório é necessario igualar ela a zero
    int i, idade, qtdF1=0, qtdF2=0, qtdF3=0, qtdF4=0, qtdF5=0;
    for(i=1; i<=8; i++)
    {
        printf("-----------------Idade Nr %d----------------\n", i);
        printf("Idade..:");
        scanf("%d", &idade);
        //calc qtd de pessoas por faixa
        if(idade <=15){
            qtdF1++; //somatório
        }else if(idade<=30){
            qtdF2++; 
        }else if(idade<=45){
            qtdF3++;
        }else if(idade<=60){
            qtdF4++;
        }else{
            qtdF5++;
        }
    }
        printf("\n-----------Resultado----------------");
        printf("\nQuantidade de pessoas na Faixa 1..: %d pessoa(s)", qtdF1);
        printf("\nQuantidade de pessoas na Faixa 2..: %d pessoa(s)", qtdF2);
        printf("\nQuantidade de pessoas na Faixa 3..: %d pessoa(s)", qtdF3);
        printf("\nQuantidade de pessoas na Faixa 4..: %d pessoa(s)", qtdF4);
        printf("\nQuantidade de pessoas na Faixa 5..: %d pessoa(s)", qtdF5);
        printf("\nPorcentagem de pessoas na Faixa 1..: %d%%", qtdF1 * 100/(i-1));
        printf("\nPorcentagem de pessoas na Faixa 5..: %d%%", qtdF5 * 100/(i-1));
    return 0;
}
