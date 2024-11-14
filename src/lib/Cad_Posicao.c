#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"
void cad_posicao(TipoLista *L)
{
    TipoApontador p;
    TipoApontador r;
    TipoApontador aux1;
    reg_cliente reg_clie;
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
            printf("Posicao Maior que Qtde Elementos..");
            getch();
        }
    } while (Posicao != 0 && Posicao > qtde);

    if (Posicao > 0)
    {
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
            r = (TipoApontador)malloc(sizeof(TipoItem));

            // Move os valores lidos para o Ponteiro
            r->conteudo = reg_clie;

            // Insere o Registro na Lista
            p = L->Primeiro;
            for (cont = 1; cont <= Posicao - 2; cont++)
            {
                p = p->proximo;
            }
            if (Posicao == 1)
            {
                r->proximo = L->Primeiro;
                L->Primeiro = r;
            }
            else
            {
                r->proximo = p->proximo;
                p->proximo = r;
            }
        }
    }
}