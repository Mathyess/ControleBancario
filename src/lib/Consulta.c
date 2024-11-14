#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"
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
            printf("CONSULTAR CLIENTE");
            // Mostra registro do Cliente
            mostra_cliente(p->conteudo);

            gotoxy(10, 23);
            system("pause");
            p = p->proximo;
        }
    }
}
