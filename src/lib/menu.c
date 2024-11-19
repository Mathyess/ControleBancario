#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"

// Função que contém o código de Contas Bancárias (exibe apenas quando a opção 1 é escolhida)
void menu_contas_bancarias() {
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    carregar(&L);
    int opc;
    system("color 0E");

    do {
        tela();
        gotoxy(20, 03);
        printf("MENU PRINCIPAL");
        gotoxy(10, 05);
        printf("1 - Cadastrar Conta no Final");
        gotoxy(10, 07);
        printf("2 - Cadastrar Conta no Inicio");
        gotoxy(10, 9);
        printf("3 - Cadastrar Conta na Posicao");
        gotoxy(10, 11);
        printf("4 - Remover Conta no Final");
        gotoxy(10, 13);
        printf("5 - Remover Conta no Inicio");
        gotoxy(10, 15);
        printf("6 - Remover Conta na Posicao");
        gotoxy(10, 17);
        printf("7 - Alteracao do Conta");
        gotoxy(10, 19);
        printf("8 - Listar Contas");
        gotoxy(10, 21);
        printf("9 - Sair");
        gotoxy(10, 23);
        printf("Digite sua opcao: ");
        gotoxy(28, 23);
        scanf("%d", &opc);

        switch (opc) {
            case 1:
                cadastrar(&L);
                break;
            case 2:
                cad_inicio(&L);
                break;
            case 3:
                cad_posicao(&L);
                break;
            case 4:
                remove_final(&L);
                break;
            case 5:
                remove_inicio(&L);
                break;
            case 6:
                remove_posicao(&L);
                break;
            case 7:
                altera_cliente(&L);
                break;
            case 8:
                menu_consultar(&L);
                break;
            case 9:
                printf("Voltando ao menu inicial...");
                getch();
                menu_inicial();
                return;
            default:
                printf("Opcao invalida! Tente novamente.");
                getch();
                break;
        }
    } while (opc != 9);
}