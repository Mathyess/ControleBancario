#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"
void remove_posicao(TipoLista *L)
{
    TipoApontador p;
    TipoApontador r;
    int resp;
    int Posicao;
    int cont;
    int qtde;
    do
    {
        tela_clie();
        gotoxy(20, 03);
        printf("CADASTRAR CLIENTE EM UMA POSICAO");
        gotoxy(60, 03);
        qtde = conta_elementos(L);
        printf("Total Clientes.: %d", qtde);

        gotoxy(8, 23);
        printf("Deseja cadastrar em qual Posicao.: ");
        scanf("%d", &Posicao);
        if (Posicao > qtde)
        {
            gotoxy(07, 23);
            printf("                                                    ");
            gotoxy(8, 23);
            printf("Posicão Maior que Qtde Elementos..");
            getch();
        }
    } while (Posicao != 0 && Posicao > qtde);

    if (Posicao > 0)
    {
        // Encontra o Elemento a ser removido e o Anterior a Ele
        if (Posicao == 1)
        {
            r = L->Primeiro;
            p = r;
        }
        else
        {
            r = L->Primeiro;
            p = r->proximo;
            cont = 1;
            while (cont < Posicao - 1)
            {
                cont = cont + 1;
                p = p->proximo;
                r = r->proximo;
            }
        }
        // mostra o Elemento a ser removido na Tela
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
            if (Posicao == 1)
            {
                L->Primeiro = p->proximo;
                free(p);
            }
            else
            {
                r->proximo = p->proximo;
                free(p);
            }
        }
    }
}
