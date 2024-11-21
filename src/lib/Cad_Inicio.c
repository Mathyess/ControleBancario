#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"
void cad_inicio(TipoLista *L)
{
    int resp;
    TipoApontador p;
    TipoApontador aux1;
    reg_cliente reg_clie;
    tela_clie();
    gotoxy(20, 03);
    printf("CADASTRAR CLIENTE NO INICIO");

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
        p->proximo = L->Primeiro;
        L->Primeiro = p;
        if (L->Ultimo == NULL)
        {
            L->Ultimo = L->Primeiro;
        }
        // Move os valores lidos para o Ponteiro
        L->Primeiro->conteudo = reg_clie;
    }
}
