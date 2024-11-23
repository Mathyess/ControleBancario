#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "include/funcoes.h"

// Função para a Tela Inicial
void menu_inicial(TipoLista *L, TipoListaMov *M) {
    int opcao;

    do {
        tela();
        gotoxy(10, 10);
        printf("1. Contas Bancarias");
        gotoxy(10, 12);
        printf("2. Movimentacao Bancaria");
        gotoxy(10, 14);
        printf("3. Sair do Programa");

        gotoxy(10, 18);
        printf("Escolha uma opcao: ");
        if(scanf("%d", &opcao) != 1) {
            printf("Entrada invalida!\n");
            while(getchar() != '\n'); // Limpa o buffer
            continue;
        }
        getchar(); // Limpa o buffer após o scanf

        switch (opcao) {
            case 1:
                menu_contas_bancarias();
                break;
            case 2:
                menu_movimentacoes(L, M);
                // Salva após cada operação no menu de movimentações
                salvar_movimentacoes(M);
                Salvar(L);
                break;
            case 3:
                // Salva os dados antes de sair
                Salvar(L);
                salvar_movimentacoes(M);
                printf("Saindo do programa...\n");
                exit(0);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                getch();
                break;
        }
    } while (1);
}

int main() {
    // Inicializa as listas
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    
    TipoListaMov M;
    M.Primeiro = NULL;
    M.Ultimo = NULL;
    
    // Carrega os dados salvos
    carregar(&L);
    carregar_movimentacoes(&M);

    // Inicia o menu passando as listas como parâmetros
    menu_inicial(&L, &M);

    return 0;
}
