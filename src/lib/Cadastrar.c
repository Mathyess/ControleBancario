#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"
void cadastrar(TipoLista *L)
{
    TipoApontador p;
    TipoApontador aux1;
    int resp;
    reg_cliente reg_clie;
    tela_clie();
    gotoxy(20, 03);
    printf("CADASTRAR CLIENTE");
    do
    {
        gotoxy(30, 05);
        printf("           ");
        gotoxy(30, 05);
        scanf("%d", &reg_clie.cd_cliente);
        getchar();
        aux1 = pesquisa(L, reg_clie.cd_cliente);
        if (aux1 != NULL)
        {
            gotoxy(07, 23);
            printf("                                            ");
            gotoxy(07, 23);
            printf("Codigo Ja Cadastrado..");
            getch();
            gotoxy(07, 23);
            printf("                                            ");
        }
    } while (aux1 != NULL);
    // Le os dados do Cliente
    leitura(&reg_clie);

    gotoxy(07, 23);
    printf("Deseja gravar os dados (1-Sim; 2-Nao).:");
    scanf("%d", &resp);
    if (resp == 1)
    {
        p = (TipoApontador)malloc(sizeof(TipoItem));
        // Move os valores lidos para o Ponteiro
        p->conteudo = reg_clie;
        if (L->Primeiro == NULL)
        {
            L->Primeiro = p;
            L->Primeiro->proximo = NULL;
            L->Ultimo = L->Primeiro;
        }
        else
        {
            L->Ultimo->proximo = p;
            L->Ultimo = L->Ultimo->proximo;
            L->Ultimo->proximo = NULL;
        }
    }
}
