#include <stdio.h>

#include <stdlib.h>



int main(){



     float salario,somaSalario=0;



    do

    {

        //somar salário.

        somaSalario=somaSalario+salario;



        printf("Digite seu salário..: \n ");

        scanf("%f",&salario);



    } while (salario>0);

    

    printf("Total da folha de pagamento: R$ %.2f\n",somaSalario);

    system("Pause");

    

}