/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para remover contas numa posição específica da lista
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void remove_posicao(TipoLista *L)
{
    TipoApontador p;
    TipoApontador r;
    int resp;
    int Posicao;
    int cont;
    int qtde;

    if (L == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    // Verifica se a lista está vazia
    if (L->Primeiro == NULL) {
        tela_conta_bancaria();
        gotoxy(20, 3);
        printf("REMOVER CONTA BANCARIA");
        gotoxy(8, 23);
        printf("Lista vazia!");
        getch();
        return;
    }

    do {
        tela_conta_bancaria();
        gotoxy(20, 3);
        printf("REMOVER CONTA BANCARIA");
        gotoxy(60, 3);
        qtde = conta_elementos(L);
        printf("Total Contas: %d", qtde);

        gotoxy(8, 23);
        printf("Deseja remover de qual Posicao? (0 para cancelar): ");
        scanf("%d", &Posicao);
        getchar(); // Limpa o buffer

        // Opção para cancelar
        if (Posicao == 0) {
            gotoxy(8, 23);
            printf("Operacao cancelada.");
            getch();
            return;
        }

        if (Posicao > qtde || Posicao < 0) {
            gotoxy(7, 23);
            printf("                                                    ");
            gotoxy(8, 23);
            printf("Posicao invalida. Tente novamente.");
            getch();
        }
    } while (Posicao > qtde || Posicao <= 0);

    // Encontra o Elemento a ser removido e o Elemento anterior
    if (Posicao == 1) {
        r = L->Primeiro;
        p = r;
    } else {
        r = L->Primeiro;
        p = r->proximo;
        cont = 1;
        while (cont < Posicao - 1) {
            cont++;
            p = p->proximo;
            r = r->proximo;
        }
    }

    // Mostra o Elemento a ser removido
    tela_conta_bancaria();
    gotoxy(20, 3);
    printf("REMOVER CONTA BANCARIA");

    // Mostra os detalhes do cliente e da conta
    gotoxy(7, 5);
    printf("Cliente: %s", p->conteudo.nm_cliente);
    gotoxy(7, 6);
    printf("Documento: %s", p->conteudo.nr_documento);
    
    // Exibe os dados da conta bancária
    mostra_conta_bancaria(p->conteudo.conta_bancaria);

    gotoxy(7, 23);
    printf("Deseja Remover a Conta Bancaria (1=Sim; 2=Nao): ");
    scanf("%d", &resp);
    getchar(); // Limpa o buffer

    if (resp == 1) {
        if (Posicao == 1) {
            L->Primeiro = p->proximo;
            // Se era o único elemento
            if (L->Primeiro == NULL) {
                L->Ultimo = NULL;
            }
            free(p);
        } else {
            r->proximo = p->proximo;
            // Se era o último elemento
            if (p->proximo == NULL) {
                L->Ultimo = r;
            }
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
