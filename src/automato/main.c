/**
 * @file main.c
 * @author Claudio Rogerio claudiorogerio<at>unifap.br
 * @date 5 Dez 2019
 * @brief Atividade complementar para a Disciplina Autômatos e Linguagens Formais 2019 \n
 * Ciência da Computação \n
 * Universidade Federal do Amapá
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "include/colors.h" 				/*! Colors.h - Arquivo responsável por mudança de cores em modo texto. */
//#include "include/equipe_01_n.h"			/*! (01)*.h - Arquivo para reconhecer a máquina de turing de (00-1)'s. */
//#include "include/equipe_1000_n.h" 		/*! 1000*.h - Arquivo para reconhecer a máquina de turing de 0's 1's. */
//#include "include/equipe_12_n120_n.h" 	/*! (12)*(120)*.h - Arquivo para reconhecer a máquina de turing de (012)'s. */
//#include "include/equipe_ab_abc_n.h" 		/*! ab(abc)*.h - Arquivo para reconhecer a máquina de turing de 2's(01)'s. */
//#include "include/equipe_0n_01_n_1_n.h" 	/*! 0*(01)*1*.h - Arquivo para reconhecer a máquina de turing de 1(00)'s. */
//#include "include/equipe_011_n_01.h"  	/*! (011)*01.h - Arquivo para reconhecer a máquina de turing de (101)'s. */
#include "include/equipe_0_n_1010_n.h"  	/*! 0*1010*.h - Arquivo para reconhecer a máquina de turing de (10)'s(01)'s. */
//#include "include/equipe_10n0-1n.h"  		/*! 10n0-1n.h - Arquivo para reconhecer a máquina de turing de (10)'s0(1)'s. */
//#include "include/equipe_soma.h" 			/*! Soma.h Arquivo para reconhecer a máquina de turing da soma de dois números. */
//#include "include/equipe_palindroma.h" 	/*! Palindroma.h - Arquivo para reconhecer a máquina de turing de palavras palíndromas. */
//#include "include/equipe_potencia2.h" 	/*! Potencia2.h - Arquivo para reconhecer a máquina de turing de potencia de 2. */



/**
 * @brief Programa principal de execução dos exemplos de Máquina de Turing
 * @param argc Quantidade de cadeias de entradas recebidas
 * @param argv Cadeias de entradas
 */
int main( int argc, char** argv ) {

	/**< Verifica se o usuário digitou alguma cadeia. */	
	if ( argc <= 1 ) {
			/**<< Informa que o usuário não digitou nenhuma Cadeia e finaliza. */
		  printf( CLR_RED "\n \t Necessario digitar uma cadeia de teste \n" );
		  exit(0);
	}
	else
		/**<< Imprime a Cadeia de entrada recebida. */
		printf( CLR_BLUE "\n \t Teste da Máquina de Turing: %s \n", argv[1] );

    printf( CLR_RESET );

	/**< Execução da função da máquina de turing MODELO. */
	equipe_0_n_1010_n( argv[1] );
	
	/**< Finaliza o programa. */
	printf( CLR_RESET );
	return 0;
}