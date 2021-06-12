#include <stdio.h>
#include <stdlib.h>
int main() {

int matNota[3][3], l, c;

for(l=0; l<3; l++){
	for(c=0; c<3; c++){
		printf("Numero..:");
		scanf("%d", &matNota[l][c]);
	}
}

for(l=0; l<3; l++){
	for(c=0; c<3; c++){
		printf("|%d\t", matNota[l][c]);
	}
	printf("\n");
}
return 0;
}