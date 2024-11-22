#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"
void consultar(TipoLista *L)
{
    TipoApontador p;
    p = L->Primeiro;
    if (p == NULL)
    {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA...");
        getch();
    }
    else
    {
        tela();
        while (p != NULL)
        {
            tela_clie();
            gotoxy(35, 03);
            printf("CONSULTAR CONTA");
            // Mostra registro da Conta
            mostra_cliente(p->conteudo);

            gotoxy(10, 23);
            system("pause");
            p = p->proximo;
        }
    }
}
