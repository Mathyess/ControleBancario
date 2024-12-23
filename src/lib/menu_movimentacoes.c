/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função de menu de todas as opções de movimentação
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void menu_movimentacoes(TipoLista *L, TipoListaMov *M) {
    int opc;
    
    // Verifica se as listas são válidas
    if (L == NULL) {
        printf("Erro: Lista de contas invalida!\n");
        getch();
        return;
    }

    // Inicializa a lista de movimentações se necessário
    if (M == NULL) {
        M = (TipoListaMov*)malloc(sizeof(TipoListaMov));
        if (M == NULL) {
            printf("Erro: Falha ao alocar memoria!\n");
            getch();
            return;
        }
        M->Primeiro = NULL;
        M->Ultimo = NULL;
        carregar_movimentacoes(M);
    }
    
    do {
        tela();
        
        gotoxy(20, 3);
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
        
        // Validação da entrada
        while (scanf("%d", &opc) != 1 || opc < 1 || opc > 5) {
            gotoxy(8, 23);
            printf("Opcao invalida! Digite novamente: ");
            while(getchar() != '\n'); // Limpa o buffer
        }
        getchar(); // Limpa o buffer após leitura válida
        
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
                gotoxy(8, 23);
                printf("Retornando ao menu principal...");
                getch();
                break;
            default:
                gotoxy(8, 23);
                printf("Opcao invalida! Pressione qualquer tecla para continuar...");
                getch();
                break;
        }
    } while(opc != 5);
}
