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
    printf("CADASTRAR CONTA NO INICIO");

    do
    {
        gotoxy(30, 05);
        printf("           ");
        gotoxy(30, 05);
        scanf("%d", &_conta_bancaria.codigo_conta);
        getchar();
        aux1 = pesquisa(L, _conta_bancaria.codigo_conta);
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
    // Le os dados da Conta
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
