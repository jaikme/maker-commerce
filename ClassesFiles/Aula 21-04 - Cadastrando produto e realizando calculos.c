#include <stdio.h>
int main(){
float precoProduto, produto, total, desconto;
int quantidade, valorDesconto;
printf("Codigo do produto..:");
scanf("%f", &produto);
printf("Quantidade comprada..:");
scanf("%d", &quantidade);
if(produto<=10){
    precoProduto = 10; //reais
}       else if(produto == 11 || produto <= 20){
            precoProduto = 15; //reais
}        else if(produto == 21 || produto <=30){
                    precoProduto = 20; //reais
}               else if( produto == 31 || produto <=40){
                            precoProduto = 30;
}
total = precoProduto * quantidade;
if(total < 250){
	desconto = total - (total * 0.05);
	valorDesconto = 5;
}		else if(total > 250 && total <= 500){
			desconto = total - (total * 0.10);
			valorDesconto = 10;
}				else if(total > 500){
					desconto = total - (total * 0.15);
					valorDesconto = 15;
}
printf("\n\nSeu produto custa: R$%.2f", precoProduto);
printf("\nVoce comprou %d unidades.", quantidade);
printf("\nTotal sem desconto: R$%.2f", total);
printf("\n\nVoce ganhou %d por cento de desconto", valorDesconto);
printf("\nTotal com desconto: R$%.2f", desconto);
system("pause");    
return 0;
}