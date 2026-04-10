#include <math.h>
#include <stdio.h>
#include "programa.h"

void calcula_estatistica(double tempo[],int tam){
    double media=0,desvio_padrao=0,soma;

    for(int i=0;i<tam;i++){
        soma=tempo[i]+soma;
    }
    media=soma/tam;

    soma=0;

    for(int i=0;i<tam;i++){
        soma = pow(tempo[i]-media,2);
    }
    desvio_padrao=sqrt(soma/tam);
    
    printf("-------------------------------\n");
    printf("Media do tempo de execucao do algoritmo: %.8f segundos\n",media);
    printf("Desvio padrao do tempo de execucao do algoritmo: %.8f segundos\n",desvio_padrao);
}