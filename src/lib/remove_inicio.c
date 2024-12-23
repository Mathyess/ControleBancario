/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para remover contas no início da lista
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void remove_inicio(TipoLista *L)
{
    TipoApontador p;
    int resp;

    if (L == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    p = L->Primeiro;

    if (p == NULL) {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA..");
        getch();
        return;
    }

tela();  // Usa a tela base para limpar
    gotoxy(20, 3);
    printf("REMOVER CONTA BANCARIA NO INICIO");
    
    // Exibe os dados da conta bancária
    mostra_conta_bancaria(p->conteudo);

    gotoxy(7, 23);
    printf("Confirma remocao da conta? (1=Sim; 2=Nao): ");
    scanf("%d", &resp);
    getchar(); // Limpa o buffer

    if (resp == 1) {
        // Verifica se existe apenas um elemento na lista
        if (p->proximo == NULL) {
            free(p);
            L->Primeiro = NULL;
            L->Ultimo = NULL;
        } else {
            L->Primeiro = p->proximo;
            free(p);
        }

        // Salva as alterações imediatamente
        Salvar(L);

        gotoxy(7, 23);
        printf("                                                       ");
        gotoxy(7, 23);
        printf("Conta Bancaria Removida com Sucesso.");
        getch();
    } else {
        gotoxy(7, 23);
        printf("                                                       ");
        gotoxy(7, 23);
        printf("Operacao cancelada.");
        getch();
    }
}
