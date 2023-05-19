#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

int menu();
int jogodavelha();
void creditos();
void regras();
void grafico();

int main() {
    setlocale(LC_ALL, "portuguese");

    menu();

    return 0;
}

int menu() {
    int op;

    do {
    
        printf("#############################");
        printf("\n#####-> Jogo da Velha <-#####");
        printf("\n#############################");

        printf("\n\nAviso: Jogo ainda em desevolvimento v1.0 demo");

        printf("\n\n1 - Inicia Jogo");
        printf("\n2 - Creditos");
        printf("\n3 - Regras");
        printf("\n0 - Sair");

        printf("\n\nEscolha uma das opções: ");
        scanf("%d", &op);

        system("cls");

        switch(op) {
        case 1:
            //jogodavelha();
            break;
        case 2:
            //creditos();
            break;
        case 3:
            //regras();
            break;
        default:
            printf("Informação inserida esta invalida");
            break;
        }
        
        system("cls");

        getch();

        system("cls");

    } while (op != 0);
}

int jogodavelha() {
    int velha[3][3], contador, contador2;

    for (contador = 0; contador < 3; contador++) {
        for (contador2 = 0; contador2 < 3; contador2++) {
            velha[contador][contador2] = 0;
        }    
    }
    
}


void grafico() {
    
}
