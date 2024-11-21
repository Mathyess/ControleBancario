#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"
void remove_inicio(TipoLista *L)
{
    TipoApontador p;
    p = L->Primeiro;
    int resp;

    if (p == NULL)
    {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA..");
        getch();
    }
    else
    {
        tela_clie();
        gotoxy(20, 03);
        printf("REMOVER CLIENTE INICIO");

        // Mostra registro do Cliente
        mostra_cliente(p->conteudo);

        gotoxy(07, 23);
        printf("Deseja Remover o Cliente no Inicio (1=Sim; 2-Nao).:");
        scanf("%d", &resp);
        if (resp == 1)
        {
            // Verifica se tem um segundo elemento. Se nao tiver o p->proximo sera NULL
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
            gotoxy(07, 23);
            printf("                                                       ");
            gotoxy(07, 23);
            printf("Registro Removido com Sucesso.");
            getch();
        }
    }
}