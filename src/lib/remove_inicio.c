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

    p = L->Primeiro;

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
        printf("REMOVER CONTA BANCARIA INICIO");

        // Mostra os detalhes da conta bancária
        mostra_conta_bancaria(p->conteudo.conta_bancaria);  // Alterado para mostrar os dados da conta bancária

        gotoxy(7, 23);
        printf("Deseja Remover a Conta Bancaria no Inicio (1=Sim; 2=Nao): ");
        scanf("%d", &resp);
        if (resp == 1)
        {
            // Verifica se existe apenas um elemento na lista
            if (p->proximo == NULL)
            {
                free(p);
                L->Primeiro = NULL;
                L->Ultimo = NULL;
            }
            else
            {
                L->Primeiro = p->proximo;
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
