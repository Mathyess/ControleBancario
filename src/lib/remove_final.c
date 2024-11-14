#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"
void remove_final(TipoLista *L)
{
    TipoApontador p;
    TipoApontador r;
    p = L->Ultimo;
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
        printf("REMOVER CLIENTE FINAL");

        // Mostra registro do Cliente
        mostra_cliente(p->conteudo);

        gotoxy(07, 23);
        printf("Deseja Remover o Cliente no Inicio (1=Sim; 2-Nao).:");
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
                // Localiza o Penultimo Elemento
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
            gotoxy(07, 23);
            printf("                                                       ");
            gotoxy(07, 23);
            printf("Registro Removido com Sucesso.");
            getch();
        }
    }
}
