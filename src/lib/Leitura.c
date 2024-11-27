/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para ler os dados previamente registrados de uma conta
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para verificar se o código da conta já existe
TipoApontador verificar_codigo_conta(TipoLista *L, int codigo) {
    TipoApontador aux = L->Primeiro;
    while (aux != NULL) {
        if (aux->conteudo.codigo_conta == codigo) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

// Função para limpar o buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler uma string com segurança
void ler_string(char *destino, int tamanho) {
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = 0;
}

// Função para ler os dados da conta bancária
void ler_dados_conta(conta_bancaria *conta) {
    // Tela da conta bancária
    tela_conta_bancaria();
    
    // Lê o nome do banco
    gotoxy(30, 7);
    ler_string(conta->banco, sizeof(conta->banco));

    // Lê a agência
    gotoxy(30, 9);
    ler_string(conta->agencia, sizeof(conta->agencia));

    // Lê o número da conta
    gotoxy(30, 11);
    ler_string(conta->numero_conta, sizeof(conta->numero_conta));

// Mostra as opções de tipo de conta
    gotoxy(30, 13);
    printf("Opcoes de Tipo de Conta:");
    gotoxy(35, 14);
    printf("(1 - Poupanca, 2 - Corrente, 3 - Credito)");
    gotoxy(35, 15);
    printf("Escolha o tipo (1-3): ");
    
int opcao;
    do {
        gotoxy(54, 15);
        printf("      "); // Limpa entrada anterior
        gotoxy(54, 15);
        scanf("%d", &opcao);
        limpar_buffer();
    } while (opcao < 1 || opcao > 3);

    // Atribui o tipo de conta baseado na escolha
    switch(opcao) {
        case 1:
            strcpy(conta->tipo_conta, "Poupanca");
            break;
        case 2:
            strcpy(conta->tipo_conta, "Corrente");
            break;
        case 3:
            strcpy(conta->tipo_conta, "Credito");
            break;
    }

    // Lê o saldo
    double saldo;
    do {
        gotoxy(30, 17);
        printf("                    "); // Limpa entrada anterior
        gotoxy(30, 17);
        if (scanf("%lf", &saldo) != 1 || saldo < 0) {
            limpar_buffer();
            gotoxy(40, 17);
            printf("Valor invalido! Digite um numero positivo.");
            Sleep(1500); // Espera 1.5 segundos
            gotoxy(40, 17);
            printf("                                          "); // Limpa mensagem de erro
            continue;
        }
        break;
    } while (1);
    conta->vl_saldo = saldo;
    limpar_buffer();

    // Lê o limite
    double limite;
    do {
        gotoxy(30, 19);
        printf("                    "); // Limpa entrada anterior
        gotoxy(30, 19);
        if (scanf("%lf", &limite) != 1 || limite < 0) {
            limpar_buffer();
            gotoxy(40, 19);
            printf("Valor invalido! Digite um numero positivo.");
            Sleep(1500); // Espera 1.5 segundos
            gotoxy(40, 19);
            printf("                                          "); // Limpa mensagem de erro
            continue;
        }
        break;
    } while (1);
    conta->vl_limite = limite;
    limpar_buffer();

    // Lê o status da conta
    gotoxy(30, 21);
    printf("Opcoes de Status:");
    gotoxy(35, 22);
    printf("(1 - Ativa, 2 - Inativa)");
    gotoxy(35, 23);
    printf("Escolha o status (1-2): ");
    
int status_opcao;
    do {
        gotoxy(54, 23);
        printf("      "); // Limpa entrada anterior
        gotoxy(54, 23);
        scanf("%d", &status_opcao);
        limpar_buffer();
        
        if (status_opcao < 1 || status_opcao > 2) {
            gotoxy(40, 23);
            printf("Opcao invalida! Digite 1 ou 2.");
            Sleep(1500);
            gotoxy(40, 23);
            printf("                              "); // Limpa mensagem de erro
        }
    } while (status_opcao < 1 || status_opcao > 2);

    // Atribui o status baseado na escolha
    strcpy(conta->status, (status_opcao == 1) ? "Ativa" : "Inativa");

    // Obtém a data atual para o cadastro da conta
    obter_data_atual(conta->dt_cadastro);
}
