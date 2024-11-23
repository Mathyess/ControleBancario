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

    p = L->Ultimo;

    if (p == NULL)
    {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA..");
        getch();
    }
    else
    {
        tela_conta_bancaria();  // Alterado para mostrar a tela de contas bancárias
        gotoxy(20, 03);
        printf("REMOVER CONTA BANCARIA FINAL");

        // Mostra os detalhes da conta bancária
        mostra_conta_bancaria(p->conteudo.conta_bancaria); // Alterado para mostrar os dados da conta bancária

        gotoxy(7, 23);
        printf("Deseja Remover a Conta Bancaria no Final (1=Sim; 2=Nao): ");
        scanf("%d", &resp);
        if (resp == 1)
        {
            if (L->Primeiro->proximo == NULL)
            {
                free(p);
                L->Primeiro = NULL;
                L->Ultimo = NULL;
            }
            else
            {
                // Localiza o penúltimo elemento
                r = L->Primeiro;
                p = r->proximo;
                while (p->proximo != NULL)
                {
                    r = r->proximo;
                    p = p->proximo;
                }
                r->proximo = NULL;
                L->Ultimo = r;
                free(p);
            }
            gotoxy(7, 23);
            printf("                                                       ");
            gotoxy(7, 23);
            printf("Conta Bancária Removida com Sucesso.");
            getch();
        }
    }
}
