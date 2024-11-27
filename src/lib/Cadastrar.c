/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para cadastrar uma conta no final da lista
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include "../include/funcoes.h"

// Função para cadastrar conta bancária no final da lista
void cadastrar(TipoLista *L) {
    TipoApontador p;
    TipoApontador aux1;
    int resp;
    conta_bancaria nova_conta;
    
    tela_conta_bancaria();
    gotoxy(20, 3);
    printf("CADASTRAR CONTA BANCARIA NO FINAL");

    // Verifica se o código da conta já está cadastrado
    do {
        gotoxy(30, 5);
        printf("           ");
        gotoxy(7, 23);
        printf("Digite o codigo da conta bancaria: ");
        scanf("%d", &nova_conta.codigo_conta);
        gotoxy(30, 05);
        printf("%d", nova_conta.codigo_conta);
        getchar(); // Limpa o buffer
        
        aux1 = verificar_codigo_conta(L, nova_conta.codigo_conta);
        if (aux1 != NULL) {
            gotoxy(7, 23);
            printf("                                            ");
            gotoxy(7, 23);
            printf("Erro: O codigo %d ja esta cadastrado.", nova_conta.codigo_conta);
            getch();
            gotoxy(7, 23);
            printf("                                            ");
        }
    } while (aux1 != NULL);

    // Leitura dos dados da conta
    ler_dados_conta(&nova_conta);

    // Confirmação de gravação dos dados
    gotoxy(7, 23);
    printf("Deseja gravar os dados (1-Sim; 2-Nao).: ");
    scanf("%d", &resp);
    getchar(); // Limpa o buffer

    if (resp == 1) {
        p = (TipoApontador)malloc(sizeof(TipoItem));
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Erro ao alocar memoria!");
            getch();
            return;
        }

        // Atribui os dados da conta
        p->conteudo = nova_conta;
        p->proximo = NULL;

        // Se a lista estiver vazia
        if (L->Primeiro == NULL) {
            L->Primeiro = p;
            L->Ultimo = p;
        } else {
            L->Ultimo->proximo = p;
            L->Ultimo = p;
        }

        // Salva imediatamente após cadastrar
        Salvar(L);

        gotoxy(7, 23);
        printf("                                                       ");
        gotoxy(7, 23);
        printf("Conta bancaria cadastrada com sucesso!");
        getch();
    } else {
        gotoxy(7, 23);
        printf("                                                       ");
        gotoxy(7, 23);
        printf("Cadastro cancelado.");
        getch();
    }
}
