/*  Autor.....: Matheus Alende, Pedro Henrique
    Data......: 30/10/2024
    Equipe....: RA membro 1 168649-2024
                RA membro 2 179381-2024

    Objetivo..: Programa principal
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "../include/funcoes.h"


// Função para a Tela Inicial
void menu_inicial() {
    int opcao;
    tela();

    gotoxy(10, 10);
    printf("1. Contas Bancarias");
    gotoxy(10, 12);
    printf("2. Movimentacao Bancaria");
    gotoxy(10, 14);
    printf("3. Sair do Programa");

    gotoxy(10, 18);
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    switch (opcao) {
        case 1:
            menu_contas_bancarias();
            break;
        case 2:
            printf("Opcao Movimentacao Bancaria selecionada.");
            getch();
            
            break;
        case 3:
            printf("Saindo do programa...");
            exit(0);
            break;
        default:
            printf("Opcao invalida! Tente novamente.");
            getch();
            break;
    }
}

int main() {
    menu_inicial();
    return 0;
     }
