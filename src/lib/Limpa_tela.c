#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"
void limpa_tela()
{
    int lin;
    int col;
    for (lin = 7; lin < 22; lin++)
    {
        for (col = 2; col < 79; col++)
        {
            gotoxy(col, lin);
            printf(" ");
        }
    }
}

// Pesquisa se existe o Elementos na Lista
TipoApontador pesquisa(TipoLista *L, int codigo)
{
    TipoApontador aux;
    aux = L->Primeiro;
    while (aux != NULL)
    {
        if (aux->conteudo.cd_cliente == codigo)
        {
            break;
        }
        aux = aux->proximo;
    }
    return aux;
}

// Conta quantos Elementos tem na Lista
int conta_elementos(TipoLista *L)
{
    int cont;
    TipoApontador aux;
    aux = L->Primeiro;
    cont = 0;
    while (aux != NULL)
    {
        cont = cont + 1;
        aux = aux->proximo;
    }
    return cont;
}