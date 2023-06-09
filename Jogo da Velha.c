#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
#include <string.h>

int menu(), jogodaVelha(), grafico();
void creditos(), comojogar();

int main() {
  setlocale(LC_ALL, "portuguese");

	system("title Jogo da Velha - v1.4");
	system("mode con: cols=100 lines=24");
	system("chcp 65001");
	system("cls");

  menu();

  return 0;
}

int menu() {
	int op;

  do {
    
  printf("##################################");
  printf("\n    -> Jogo da Velha - Menu <-      ");
  printf("\n##################################");


  printf("\t\t\t\t\t\t\tVers�o: 1.4");
  printf("\n\nAviso: Jogo ainda em desevolvimento v1.4!");
	printf("\nAviso: Recomendamos ver 'Como Jogar' antes de iniciar o Jogo!");

  printf("\n\n1 - Inicia Jogo");
  printf("\n2 - Como Jogar");
  printf("\n3 - Creditos");
  printf("\n4 - Update(Novo)");
  printf("\n0 - Sair");

  printf("\n\nEscolha uma das op��es: ");
  scanf("%d", &op);

  system("cls");

  switch(op) {
    case 1:
      jogodaVelha();
      break;
    case 2:
      comojogar();
      break;
    case 3:
	  creditos();
      break;
    case 4:
      //update();
      break;
    default:
      printf("Informa��o inserida esta invalida");
      break;
  }
        
  system("cls");

  getch();

  system("cls");

  } while (op != 0);
}

int jogodaVelha() {
	int linha, coluna, l, c, contador, ganhou, repetiu, rodada, jogador, sair = 's';
	char velha[3][3]; 
    
  for(l = 0; l < 3; l++) {
    for(c = 0; c < 3; c++) {
    	velha[l][c] = ' ';
		}
	}
	printf("\n");

	grafico(velha);
	 	
	ganhou = 0;
    
  for(rodada = 1; rodada <= 9 && ganhou == 0; rodada++) {
 
    if(jogador%2 == 1) {
    	jogador = 'X';
		}else{
			jogador = 'O';
		}	
    	
    do{

			printf("\n#Digite sua jogadar#");
			printf("\nRodadas feitas %d", rodada);
			printf("\nDigite as coordenadas (de 1 a 3 Ex: 1 2). Em quer local que colocar o '%c' Jogador %c: ", jogador, jogador);
			scanf("%d %d", &linha, &coluna);

	    fflush(stdin);
    	
    }while(linha < 1 || linha > 3 || coluna < 1 || coluna > 3 || velha[linha-1][coluna-1] != ' ');
    	
 		velha[linha-1][coluna-1] = jogador;
 		
 		grafico(velha);
 		
 		if(velha[linha-1][0] == velha[linha-1][1] && velha[linha-1][1] == velha[linha-1][2]){
 			ganhou = 1;
		} else if(velha[0][coluna-1] == velha[1][coluna-1] && velha[1][coluna-1] == velha[2][coluna-1]) {
			ganhou = 1;
		} else if(linha == coluna && velha[0][0] == velha[1][1] && velha [1][1] == velha[2][2]) {
			ganhou = 1;
		} else if(linha + coluna == 4 && velha[0][2] == velha[1][1] && velha[1][1] == velha[2][0]){
			ganhou = 1;
		}
	}

	/*if(velha[linha-1][coluna-1] == linha && coluna) {
		printf("Esse comando ja foi escolhido tente novamente");
	}*/
 
	if(ganhou == 0) {
	  printf("\nDeu velha!\n");
	  system("pause");
	}
	else {
	  printf("\nO jogador '%c' ganhou!\n", jogador);
	  
	  system("pause");
	}
}

int grafico(char velha[3][3]) {
	
	system("cls");
	
  printf("####################################");
  printf("\n    -> Jogo da Velha - Jogo <-      ");
  printf("\n####################################\n\n"); 

	printf("      1        2        3   \n");	
  printf("                            \n");
  printf("           |        |        \n");
  printf("1     %c    |   %c    |   %c   \n", velha[0][0], velha[0][1], velha[0][2]);
  printf("   ________|________|________\n");
  printf("           |        |        \n");
  printf("2     %c    |   %c    |   %c   \n", velha[1][0], velha[1][1], velha[1][2]);
  printf("   ________|________|________\n");
  printf("           |        |        \n");
  printf("3     %c    |   %c    |   %c   \n", velha[2][0], velha[2][1], velha[2][2]);
  printf("           |        |        \n");

}

void comojogar() {
	
	printf ( " #### #################################### " );
  printf ( " \n     -> Jogo da Velha - Como Jogar <-       " );
  printf ( " \n #################################### #### \n\n " );

	printf ( " Teste " );
	printf ( " \n 1 - Escolhas as cordenadas de acordo quer � mostrado como exemplo (1 a 3)! " );
	printf ( " \n 2 - No Inicio do jogo sempre come�a com o jogador um! " );
	//printf ( " \n 3 - Jogador Um 'X', Jogador Dois 'O'! " );

	printf ( " \n\n Aperte 'enter' para voltar. " );
	
	getch();
}

void creditos() {
	
  printf("######################################");
  printf("\n    -> Jogo da Velha - Cr�ditos <-      ");
  printf("\n######################################\n\n"); 

	printf("Autor: Danilo Dias");
	printf("\nGithub: TDaniloJ");
	printf("\nDireitos: Todos os direitos reservado �");
	
	
	printf("\n\nAperte 'enter' para voltar.");
	getch();
}
