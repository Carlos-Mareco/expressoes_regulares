/**
 * @file equipe_0_n_1010_n.c
 * @author Carlos Henrique Barreto Mareco
 * @date 5 Dez 2019
 * @brief Máquina de Turing de reconhecimento de 0*1010*
 */

/**
 * @brief Máquina de Turing responsável em identificar Filas com 0*1010*
 * @param char* Cadeia para ser avaliada
 */
#include "equipe_0_n_1010_n.h"

void equipe_0_n_1010_n( char *word ) {
    /** O inteiro "i" é um contador de estados e inicia em 0 */
    int i = 0;
    /** O inteiro "tam" armazena a quantidade de caracteres de "word" */
    int tam = strlen(word);
    /** O inteiro "aceita" informa se a palavra foi aceita ou não, verdairo(1) e falso(0) */
    int aceita = 0;
    /** Nessa parte o while é usado para reconhecer os 0's */
    while (word[i] == '0')
        i++;
    /** Para cada if, se verdadeiro, avança para o próximo estado */
    if (word[i] == '1'){
        i++;
        if (word[i] == '0'){
            i++;
            if (word[i] == '1'){
                /** Se os ifs anteriores forem verdadeiros, então a cadeia é aceita, logo "aceita = 1" */
                aceita = 1;
            } 
        }
    }
    /** A próxima parte do programa só executa se as condições anteriores forem satisfeitas */
    if (aceita == 1){
        /** Incrementa em "i" para avançar até o próximo estado */
        i++;
        /** Caso "i" ainda esteja na cadeia e o próximo caractere seja diferente de zero, então
         * a cadeia é recusada */
        if (word[i] != '0' && i < tam)
            aceita = 0;
        else{
            while (word[i] == '0'){
                i++;
                if (word[i] != '0' && i < tam)
                    aceita = 0;
            }
        }  
    }
    /** Caso as condições acima forem satisfeita, então a cadeia é aceita */
    if (aceita == 1)
        printf(CLR_GREEN "Cadeia aceita\n" CLR_RESET);
    else{
        /** Algoritmo usado para alterar a cor do caractere onde está o erro */
        printf(CLR_RED "Cadeia recusada\n" CLR_RESET);
        if (i == tam){
            for (int j = 0; j <= i; j++){
            if ( j < i)
                printf(CLR_BLUE "%c", word[j]);
            else
                printf(CLR_RED "[]\n");
            }
            printf("A cadeia não cumpre completamente 0*1010*\n" CLR_RESET);
        }else{
            for (int j = 0; j <= i; j++){
            if ( j != i)
                printf(CLR_BLUE "%c", word[j]);
            else
                printf(CLR_RED "%c" CLR_RESET, word[j]);
            }
            for (int j = i+1; j < tam; j++){
                printf(CLR_BLUE "%c", word[j]);
            }
            printf ("\n");
        }
    }
}