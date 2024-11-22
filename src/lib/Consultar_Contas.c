#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"
void consultar_cliente(TipoLista *L)
{
    TipoApontador p;
    int codigo;
    int qtde;
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
        do
        {
            tela();
            tela_clie();
            gotoxy(25, 03);
            printf("CONSULTAR CONTA ESPECIFICA");
            gotoxy(60, 03);
            qtde = conta_elementos(L);
            printf("Total Contas.: %d", qtde);
            gotoxy(30, 05);
            scanf("%d", &codigo);
            p = pesquisa(L, codigo);
            if (p == NULL)
            {
                gotoxy(07, 23);
                printf("Conta Nao Cadastrada..");
                getch();
            }
        } while (p == NULL);

        // Mostra registro da conta
        mostra_cliente(p->conteudo);

        gotoxy(10, 23);
        system("pause");
    }
}
