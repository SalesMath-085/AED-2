#include "programa.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int questão_5(){
    double tempo_da_busca_sequencial[10], tempo_da_busca_binaria[10];
    int chave;
    int i;
    for(i=1;i<=10;i++){

        int*vetorprincipal = cria_vetor(i*100000);
        int tamanho=i*100000;
        chave=rand()%tamanho;
            clock_t tempo_inicial=clock(); //incia o timer//
            busca_sequencial(vetorprincipal,tamanho,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_sequencial[i-1]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//
       
        chave=rand();
            
            clock_t tempo_inicial=clock(); //incia o timer//
            busca_sequencial(vetorprincipal,tamanho,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_sequencial[i]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//

        int*vetorordenado = cria_vetor_ordenado(i*100000);
        chave=rand()%tam;
            clock_t tempo_inicial=clock(); //incia o timer//
            busca_binaria(vetorordenado,tamanho,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

        tempo_da_busca_binaria[repeticoes_acumuladas]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//

    }
}