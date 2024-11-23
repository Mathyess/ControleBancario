/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Arquivo principal do sistema de controle bancário.
    Este arquivo contém a função main e o menu inicial do sistema,
    responsável por inicializar as estruturas de dados, carregar
    os dados salvos e gerenciar o fluxo principal do programa.
*/

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
        SetCor(11, 0); // Texto azul claro para as opções do menu
        gotoxy(10, 10);
        printf("1. Contas Bancarias");
        gotoxy(10, 12);
        printf("2. Movimentacao Bancaria");
        gotoxy(10, 14);
        printf("3. Sair do Programa");

        SetCor(3, 0); // Texto ciano para a entrada
        gotoxy(10, 18);
        printf("Escolha uma opcao: ");
        if(scanf("%d", &opcao) != 1) {
            SetCor(15, 0); // Texto branco para mensagens de erro
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
                SetCor(15, 0); // Texto branco para mensagem de saída
                printf("Saindo do programa...\n");
                exit(0);
                break;
            default:
                SetCor(15, 0); // Texto branco para mensagem de erro
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

    // Define a cor padrão do sistema como azul claro
    system("color 0B");

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
