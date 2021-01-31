// Implementação desenvolvida por Marcelo Zaguette Junior - RA: 180998	e Giovanna Hallsr - RA: 171240
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main(){
	
	double x0=0, xm=0, x1=0, fx0=0, fxm=0, fx1=0, erro=0, m1=0, m2=0, mod=0;
	int i=0, quantidade=0,coeficientes[10],expoentes[10], total=0;
	
	printf("Digite a quantidade de termos da funcao (max 10): ");
	scanf("%i",&quantidade);
	
	for(i = 0; i<quantidade; i++){
		printf("Digite o valor do %io coeficiente e do %io expoente de x: ",i+1,i+1);
		scanf("%i %i",&coeficientes[i],&expoentes[i]);
	}
	
	printf("Digite o intervalo que sera considerado (separado por espaco): ");
	scanf("%lf %lf",&x0,&x1);
	
	xm = (x0+x1)/2;
	
	printf("Digite o valor do erro: ");
	scanf("%lf",&erro);
	
	for(i = 0; i<quantidade; i++){
		fx0 += coeficientes[i]*(pow(x0,expoentes[i]));
	}
	
	for(i = 0; i<quantidade; i++){
		fx1 += coeficientes[i]*(pow(x1,expoentes[i]));
	}
	
	for(i = 0; i<quantidade; i++){
		fxm += coeficientes[i]*(pow(xm,expoentes[i]));
	}
	
	mod = fxm;
	
	printf("Indice: %i   X0 =   %lf   Xm =   %lf   X1 =   %lf   f(X0) =   %lf   f(Xm) =   %lf   f(X1) =   %lf\n",total, x0,xm,x1,fx0,fxm,fx1);
	
	while(mod > erro){
		m1 = fx0*fxm;
		m2 = fx1*fxm;
		if(m1 < 0){
			x0 = x0;
			
			x1 = xm;
			
			xm = (x0+x1)/2;
			
			fx0 = 0;
			
			fxm = 0;
			
			fx1 = 0;
			
			for(i = 0; i<quantidade; i++){
				fx0 += coeficientes[i]*(pow(x0,expoentes[i]));
			}
			
			for(i = 0; i<quantidade; i++){
				fx1 += coeficientes[i]*(pow(x1,expoentes[i]));
			}
			
			for(i = 0; i<quantidade; i++){
				fxm += coeficientes[i]*(pow(xm,expoentes[i]));
			}	
		}else if(m2 < 0){
			x0 = xm;
			
			x1 = x1;
			
			xm = (x0+x1)/2;
			
			fx0 = 0;
			
			fxm = 0;
			
			fx1 = 0;
			
			for(i = 0; i<quantidade; i++){
				fx0 += coeficientes[i]*(pow(x0,expoentes[i]));
			}
			
			for(i = 0; i<quantidade; i++){
				fx1 += coeficientes[i]*(pow(x1,expoentes[i]));
			}
			
			for(i = 0; i<quantidade; i++){
				fxm += coeficientes[i]*(pow(xm,expoentes[i]));
			}
		}
		total++;
		printf("Indice: %i   X0 =   %lf   Xm =   %lf   X1 =   %lf   f(X0) =   %lf   f(Xm) =   %lf   f(X1) =   %lf\n",total, x0,xm,x1,fx0,fxm,fx1);
		if(fxm < 0){
			mod = fxm * -1;
		}else{
			mod = fxm;
		}
	}
	printf("\nA quantidade de iteracoes foi %i e a raiz da funcao eh %lf com erro de + ou - %lf\n",total, xm,fxm);
	system("pause");
	return 0;
}
