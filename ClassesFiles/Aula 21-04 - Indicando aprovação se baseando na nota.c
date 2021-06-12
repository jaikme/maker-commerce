#include <stdio.h>
int main(){
float n1, n2, media;
printf("Digite a nota da p1: ");
scanf("%f", &n1);
printf("Digite a nota da p2: ");
scanf("%f", &n2);
media = (n1+n2)/2;
printf("\nSua média é: %.2f\n\n", media);
if(media<=2.99){
    printf("Você foi reprovado!");
}       else if (media<7){
        printf("Em exame");
}           else {
            printf("Você foi aprovado");
}
    return 0;
}