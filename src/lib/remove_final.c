/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para remover contas no final da lista
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void remove_final(TipoLista *L)
{
    TipoApontador p;
    TipoApontador r;
    int resp;

    if (L == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    p = L->Ultimo;

    if (p == NULL) {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA..");
        getch();
        return;
    }

tela();  // Usa a tela base para limpar
    gotoxy(20, 3);
    printf("REMOVER CONTA BANCARIA FINAL");
    
    // Exibe os dados da conta bancária
    mostra_conta_bancaria(p->conteudo);

    gotoxy(7, 23);
    printf("Confirma remocao da conta? (1=Sim; 2=Nao): ");
    scanf("%d", &resp);
    getchar(); // Limpa o buffer

    if (resp == 1) {
        if (L->Primeiro->proximo == NULL) {
            // Se há apenas um elemento na lista
            free(p);
            L->Primeiro = NULL;
            L->Ultimo = NULL;
        } else {
            // Localiza o penúltimo elemento
            r = L->Primeiro;
            p = r->proximo;
            while (p->proximo != NULL) {
                r = r->proximo;
                p = p->proximo;
            }
            r->proximo = NULL;
            L->Ultimo = r;
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
