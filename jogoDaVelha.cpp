#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

int **matriz;
int l, c;
int jogadas, sair, rodando;



	//Situacoes de Vitoria
void VerificaVitoria(void){
	//Horizontais
	for(l=0;l<3;l++){
		if((matriz[l][0] == 'X' && matriz[l][1] == 'X' && matriz[l][2] == 'X') || (matriz[l][0] == 'O' && matriz[l][1] == 'O' && matriz[l][2] == 'O')){
			if(jogadas %2 == 1){
				printf("Jogador 1 (X), Venceu!");
				rodando=0;
			} else if (jogadas %2 == 0){
				printf("Jogador 2 (O), Venceu!");
				rodando=0;
			}
		}
	}
	//Verticais
	for(c=0;c<3;c++){
		if((matriz[0][c] == 'X' && matriz[1][c] == 'X' && matriz[2][c] == 'X') || (matriz[0][c] == 'O' && matriz[1][c] == 'O' && matriz[2][c] == 'O')){
			if(jogadas %2 == 1){
				printf("Jogador 1 (X), Venceu!");
				rodando=0;
			} else if (jogadas %2 == 0){
				printf("Jogador 2 (O), Venceu!");
				rodando=0;
			}
		}
	}	
	//Diagonais
	if((matriz[0][0] == 'X' && matriz[1][1] == 'X' && matriz[2][2] == 'X') || (matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O')){
		if(jogadas %2 == 1){
			printf("Jogador 1 (X), Venceu!");
			rodando=0;
		} else if (jogadas %2 == 0){
			printf("Jogador 2 (O), Venceu!");
			rodando=0;
		}
	}else if((matriz[2][0] == 'X' && matriz[1][1] == 'X' && matriz[0][2] == 'X') || (matriz[0][0] == 'O' && matriz[1][1] == 'O' && matriz[2][2] == 'O')){
		if(jogadas %2 == 1){
				printf("Jogador 1 (X), Venceu!");
				rodando=0;
			} else if (jogadas %2 == 0){
				printf("Jogador 2 (O), Venceu!");
				rodando=0;
			}
	}
	
	//Empate
	if(jogadas == 9){
		printf("\nEmpate");
		rodando=0;
	}
}


//Matriz Dinamica
int main(){
	rodando = 1;

	matriz = (int **) malloc(sizeof(int*)*3);
		
	for(l=0;l<3;l++){
		matriz[l] = (int *) malloc(sizeof(int*)*3);
		for(c=0;c<3;c++)
			matriz[l][c] = ' ';
	}



//Jogo da Velha - Rodando
	while(rodando == 1){
		sair = 0;
		
		printf("\tJogo da velha\n\n");
		for(l=0;l<3;l++){
		  	for(c=0;c<2;c++)
			  	printf(" %c |", matriz[l][c]);
				printf(" %c ", matriz[l][c]);
				printf("\n");
				printf(" ---------\n");
		}
		
		VerificaVitoria();
		if(rodando == 0){
			jogadas--;
			break;
		}
		
		while(sair == 0){
			printf("Coloque a linha e a coluna: ");
			scanf("%d %d", &l, &c);
				
			if((matriz[l][c] == 'O') || (matriz[l][c] == 'X')){
				printf("\nPosicao Ocupada");
				Sleep(2000);
				jogadas--;
				break;
			} else if(jogadas %2 == 0){
				matriz[l][c] = 'X';
				sair = 1;
			} else if(jogadas %2 == 1){
				matriz[l][c] = 'O';
				sair = 1;
			} 	
			jogadas++;
		}
		system("cls");
	}
	
	//Libera memoria
	if (matriz!=NULL){
		for (l=0 ; l<3 ; l++){
			if (matriz[l] != NULL)
				free(matriz[l]);
		}
				free(matriz);
	}

}
