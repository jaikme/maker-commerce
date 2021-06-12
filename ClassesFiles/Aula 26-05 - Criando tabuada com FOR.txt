#include <stdio.h>
int main()
{
    //pra fazer somatório é necessario igualar ela a zero
    int i, nr;
    printf("Qual tabuada deseja criar?");
    scanf("%d", &nr);
    printf("-----------Tabuada de %d ------------", nr);
    for(i=0; i<=10; i++){
        printf("\n%d x %d = %d", nr,i,nr*i);
    }
    return 0;
}
