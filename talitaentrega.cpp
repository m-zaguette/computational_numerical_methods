#include<stdio.h>
#include<stdlib.h>
void gabarito(int *lin, int *col);
int main(){
	//gabarito
	int gab_lin=0,gab_col=0;
	gabarito(&gab_lin,&gab_col);
	
	
	return 0
}

void gabarito(int *lin, int *col){
	printf("Digite o numero de linhas: ");
	scanf("%i",lin);
	printf("\nDigite o numero de colunas: ");
	scanf("%i",col);
}
