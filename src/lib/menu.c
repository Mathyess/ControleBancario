/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função que contém o código de Contas Bancárias
void menu_contas_bancarias(TipoLista *L) {  // Recebe a lista como parâmetro
    int opc;
    system("color 09");  // Muda a cor da tela para azul claro

    do {
        tela();  // Exibe a tela inicial
        SetCor(9, 0); // Define azul claro para todo o texto
        gotoxy(20, 3);  // Move o cursor para a posição X=20, Y=03
        printf("MENU PRINCIPAL - CONTAS BANCARIAS");
        
        // Exibe as opções do menu
        gotoxy(10, 5); printf("1 - Cadastrar Conta no Final");
        gotoxy(10, 7); printf("2 - Cadastrar Conta no Inicio");
        gotoxy(10, 9); printf("3 - Cadastrar Conta na Posicao");
        gotoxy(10, 11); printf("4 - Remover Conta no Final");
        gotoxy(10, 13); printf("5 - Remover Conta no Inicio");
        gotoxy(10, 15); printf("6 - Remover Conta na Posicao");
        gotoxy(10, 17); printf("7 - Alterar Dados da Conta Bancaria");
        gotoxy(10, 19); printf("8 - Listar Contas");
        gotoxy(10, 21); printf("9 - Sair");
        
        gotoxy(10, 23);
        printf("Digite sua opcao: ");
        gotoxy(28, 23);
        
        // Validação da opção
        while (scanf("%d", &opc) != 1 || opc < 1 || opc > 9) {
            gotoxy(10, 23);
            printf("Opcao invalida! Tente novamente: ");
            while(getchar() != '\n');  // Limpa o buffer
        }
        getchar(); // Limpa o buffer após a leitura válida

        // Switch para executar a ação conforme a opção do usuário
        switch (opc) {
case 1:
                cadastrar(L);  // Chama a função de cadastrar no final
                break;
            case 2:
                cad_inicio(L);  // Chama a função de cadastrar no início
                break;
            case 3:
                cad_posicao(L);  // Chama a função de cadastrar em uma posição
                break;
            case 4:
                remove_final(L);  // Chama a função de remover no final
                Salvar(L);        // Salva as alterações
                break;
            case 5:
                remove_inicio(L);  // Chama a função de remover no início
                Salvar(L);         // Salva as alterações
                break;
            case 6:
                remove_posicao(L);  // Chama a função de remover em uma posição
                Salvar(L);          // Salva as alterações
                break;
            case 7:
                altera_conta(L);  // Chama a função de alterar uma conta
                Salvar(L);        // Salva as alterações
                break;
            case 8:
                menu_consultar(L);  // Chama o menu de consulta
                break;
            case 9:
                SetCor(9, 0);
                printf("Voltando ao menu inicial...\n");
                Salvar(L);  // Salva antes de sair
                getch();
                return;     // Retorna ao invés de chamar menu_inicial recursivamente
            default:
                SetCor(9, 0);
                printf("Opcao invalida! Tente novamente.\n");
                getch();
                break;
        }
    } while (opc != 9);  // O menu repete até que o usuário escolha a opção 9
}

// Função para o Menu Inicial
void menu_inicial() {
    // Inicializa a lista uma única vez
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    carregar(&L);  // Carrega os dados do arquivo

    int opcao;
    do {
        tela();
        SetCor(9, 0); // Define azul claro para todo o texto
        gotoxy(10, 10);
        printf("1. Contas Bancarias");
        gotoxy(10, 12);
        printf("2. Movimentacao Bancaria");
        gotoxy(10, 14);
        printf("3. Sair do Programa");

        gotoxy(10, 18);
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        getchar(); // Limpa o buffer

        switch (opcao) {
            case 1:
                menu_contas_bancarias(&L);  // Passa a lista como parâmetro
                break;
            case 2:
                menu_movimentacoes(&L, NULL);  // Passa a lista como parâmetro
                Salvar(&L);  // Salva após operações de movimentação
                break;
            case 3:
                Salvar(&L);  // Salva antes de sair
                SetCor(9, 0);
                printf("\nSaindo do programa...\n");
                exit(0);
                break;
            default:
                SetCor(9, 0);
                printf("\nOpcao invalida! Tente novamente.\n");
                getch();
                break;
        }
    } while (1);
}
