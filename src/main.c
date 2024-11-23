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
        SetCor(13, 0); // Texto roxo brilhante para as opções do menu
        gotoxy(10, 10);
        printf("1. Contas Bancarias");
        gotoxy(10, 12);
        printf("2. Movimentacao Bancaria");
        gotoxy(10, 14);
        printf("3. Sair do Programa");

        SetCor(5, 0); // Texto roxo normal para a entrada
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
                SetCor(13, 0); // Texto roxo brilhante para mensagem de saída
                printf("Saindo do programa...\n");
                exit(0);
                break;
            default:
                SetCor(13, 0); // Texto roxo brilhante para mensagem de erro
                printf("Opcao invalida! Tente novamente.\n");
                getch();
                break;
        }
    } while (1);
}

int main() {
    // Configura o console para usar cores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salva os atributos atuais
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    // Define a cor padrão do sistema como roxo
    system("color 05");

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

    // Restaura os atributos originais do console antes de sair
    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}
