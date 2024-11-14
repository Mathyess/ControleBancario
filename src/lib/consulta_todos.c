#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
void consulta_todos(TipoLista *L, char msg[40])
{
    TipoApontador p;
    int lin;
    tela();
    gotoxy(22, 03);
    printf("%s", msg);
    lin = 7;
    gotoxy(02, 05);
    printf("Cd Nome                       CPF            Cidade          UF Telefone   ");
    gotoxy(02, 06);
    printf("-- -------------------------- -------------- --------------- -- -------------");
    p = L->Primeiro;
    if (p == NULL)
    {
        gotoxy(07, 23);
        printf("LISTA VAZIA..");
        getch();
    }
    else
    {
        while (p != NULL)
        {
            gotoxy(02, lin);
            printf("%d", p->conteudo.cd_cliente);
            gotoxy(05, lin);
            printf("%s", p->conteudo.nm_cliente);
            gotoxy(32, lin);
            printf("%s", p->conteudo.nr_documento);
            gotoxy(47, lin);
            printf("%s", p->conteudo.ds_cidade);
            gotoxy(63, lin);
            printf("%s", p->conteudo.cd_uf);
            gotoxy(66, lin);
            printf("%s", p->conteudo.nr_telefone);
            lin++;
            if (lin > 21)
            {
                gotoxy(07, 23);
                system("pause");
                limpa_tela();
                lin = 7;
            }
            p = p->proximo;
        }
        gotoxy(07, 23);
        system("pause");
    }
}