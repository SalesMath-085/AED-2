#include "programa.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 1000000

void questao_1(int* vetor_de_1milhao){
    int quantidades_de_repeticoes=10;
    int chave;
    double tempo_da_busca_sequencial[quantidades_de_repeticoes], tempo_da_busca_binaria[quantidades_de_repeticoes];
    //int*vetor_de_1milhao=cria_vetor(tam);

    //TESTE BUSCA SEQUENCIAL VETOR DESORDENADO//
    for(int repeticoes_acumuladas=0;repeticoes_acumuladas<quantidades_de_repeticoes;repeticoes_acumuladas++){
        if(repeticoes_acumuladas<15){
            chave=rand()%tam;
            clock_t tempo_inicial=clock(); //incia o timer//
            busca_sequencial(vetor_de_1milhao,quantidades_de_repeticoes,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_sequencial[repeticoes_acumuladas]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//

        }else{
            chave=rand();
            
            clock_t tempo_inicial=clock(); //incia o timer//
            busca_sequencial(vetor_de_1milhao,quantidades_de_repeticoes,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_sequencial[repeticoes_acumuladas]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//
        }
    }

    ///// CRIA VETOR ORDENADO ////////////
    int*vetor_de_1milhao_ordenado=cria_vetor_ordenado(tam);


    for(int repeticoes_acumuladas=0;repeticoes_acumuladas<quantidades_de_repeticoes;repeticoes_acumuladas++){
        if(repeticoes_acumuladas<15){
            chave=rand()%tam;
            clock_t tempo_inicial=clock(); //incia o timer//
            busca_binaria(vetor_de_1milhao_ordenado,quantidades_de_repeticoes,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_binaria[repeticoes_acumuladas]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//

        }else{
            chave=rand();

            clock_t tempo_inicial=clock(); //incia o timer//
            busca_binaria(vetor_de_1milhao_ordenado,quantidades_de_repeticoes,chave);
            clock_t tempo_final=clock(); //finaliza o timer//

            tempo_da_busca_binaria[repeticoes_acumuladas]=(double)(tempo_final-tempo_inicial)/CLOCKS_PER_SEC;//calcula os segundos//
        }
    }


    //  MOSTRA OS TEMPOS DE EXECUCAO E ESTATISTICAS //
    printf("RODADAS    BUSCA BINARIA    BUSCA SEQUENCIAL\n");


    for(int i=1;i<=(quantidades_de_repeticoes/2);i++){
        printf("RODADA %i    ",i);
        printf("%.8f    ",tempo_da_busca_sequencial[i]);
        printf("%.8f\n",tempo_da_busca_binaria[i]);
    }
    calcula_estatistica(tempo_da_busca_sequencial,quantidades_de_repeticoes,"busca sequencial");
    calcula_estatistica(tempo_da_busca_binaria, quantidades_de_repeticoes,"busca binaria");


}