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

// Função que contém o código de Contas Bancárias (exibe apenas quando a opção 1 é escolhida)
void menu_contas_bancarias() {
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    carregar(&L);  // Carregar dados da lista (possivelmente de um arquivo)
    int opc;
    system("color 0E");  // Muda a cor da tela para amarelo

    do {
        tela();  // Exibe a tela inicial
        gotoxy(20, 03);  // Move o cursor para a posição X=20, Y=03
        printf("MENU PRINCIPAL - CONTAS BANCARIAS");
        
        // Exibe as opções do menu
        gotoxy(10, 05); printf("1 - Cadastrar Conta no Final");
        gotoxy(10, 07); printf("2 - Cadastrar Conta no Inicio");
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

        // Switch para executar a ação conforme a opção do usuário
        switch (opc) {
            case 1:
                cadastrar(&L);  // Chama a função de cadastrar no final
                break;
            case 2:
                cad_inicio(&L);  // Chama a função de cadastrar no início
                break;
            case 3:
                cad_posicao(&L);  // Chama a função de cadastrar em uma posição
                break;
            case 4:
                remove_final(&L);  // Chama a função de remover no final
                break;
            case 5:
                remove_inicio(&L);  // Chama a função de remover no início
                break;
            case 6:
                remove_posicao(&L);  // Chama a função de remover em uma posição
                break;
            case 7:
                altera_conta(&L);  // Chama a função de alterar uma conta
                break;
            case 8:
                menu_consultar(&L);  // Chama o menu de consulta
                break;
            case 9:
                printf("Voltando ao menu inicial...\n");
                getch();
                menu_inicial();  // Retorna ao menu inicial
                return;
            default:
                printf("Opcao invalida! Tente novamente.\n");
                getch();
                break;
        }
    } while (opc != 9);  // O menu repete até que o usuário escolha a opção 9
}
