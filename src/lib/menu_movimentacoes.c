#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void menu_movimentacoes(TipoLista *L, TipoListaMov *M) {
    int opc;
    
    do {
        tela();
        gotoxy(20, 03);
        printf("MENU DE MOVIMENTACOES BANCARIAS");
        
        // Opções do menu
        gotoxy(25, 8);
        printf("1 - Realizar Debito");
        gotoxy(25, 10);
        printf("2 - Realizar Credito");
        gotoxy(25, 12);
        printf("3 - Realizar Transferencia");
        gotoxy(25, 14);
        printf("4 - Consultar Movimentacoes");
        gotoxy(25, 16);
        printf("5 - Retornar ao Menu Principal");
        
        gotoxy(8, 23);
        printf("Digite sua opcao.: ");
        scanf("%d", &opc);
        getchar(); // Limpa o buffer
        
        switch(opc) {
            case 1:
                realizar_debito(L, M);
                // Salva após cada operação
                salvar_movimentacoes(M);
                Salvar(L);
                break;
            case 2:
                realizar_credito(L, M);
                // Salva após cada operação
                salvar_movimentacoes(M);
                Salvar(L);
                break;
            case 3:
                realizar_transferencia(L, M);
                // Salva após cada operação
                salvar_movimentacoes(M);
                Salvar(L);
                break;
            case 4:
                consultar_movimentacoes(M);
                break;
            case 5:
                // Salva antes de retornar ao menu principal
                salvar_movimentacoes(M);
                Salvar(L);
                break;
            default:
                gotoxy(8, 23);
                printf("Opcao invalida! Pressione qualquer tecla para continuar...");
                getch();
                break;
        }
    } while(opc != 5);
}
