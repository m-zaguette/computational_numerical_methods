#include<stdio.h>
#include<stdlib.h>
void gauss(float *vetor, int x);
int main(){
	int v=0,i=0,j=0,tamanho=0;
	
	puts("Digite o numero de variaveis(maximo 3): ");
	scanf("%i",&v);
	
	tamanho=(v*(v+1));
	
	float vetor[tamanho];
	
	
	for(i=0;i<v+1;i++){
		for(j=0;j<v+1;j++){
			printf("Posicao[%i][%i] = ",(i*j),j);
			scanf("%f",*((vetor+(j*i)+i)));
		}
	}

	
	gauss(vetor,v);
	
	
	for(i=0;i<v+1;i++){
		for(j=0;j<v+1;j++){
			printf("%f ",*(vetor+(j*i)+i));
		}
		printf("\n");
	}
}
void gauss(float *vetor, int x){
	float pivo= *(vetor) , m1=0 , m2=0 , m3=0 ;
	int i=0;
	
	m1 = (*(vetor+x+1))/pivo;
	
	for(i=0;i<x+1;i++){
		*(vetor+x+1+i) *= m1;
	}
	
	m1 = *(vetor+x+x+1)/pivo;
	
	for(i=0;i<x+1;i++){
		*(vetor+x+x+1+i) *= m1;
	}
	
	for(i=0;i<x+1;i++){
		*(vetor+x+1+i) += *(vetor+i);
		*(vetor+x+x+1+i) += *(vetor+i);
	}
	
	if(x=3){
		pivo = *(vetor+x+2);
		m1 = *(vetor+x+x+x)/pivo;
		
		for(i=0;i<x;i++){
			*(vetor+x+x+x+i) *= m1;
		}
		
		for(i=0;i<x;i++){
			*(vetor+x+x+x+i) += *(vetor+x+2);
		}
	}
}
