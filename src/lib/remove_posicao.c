#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

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
        tela_conta_bancaria();  // Alterado para tela de conta bancária
        gotoxy(20, 03);
        printf("REMOVER CONTA BANCARIA EM UMA POSICAO");
        gotoxy(60, 03);
        qtde = conta_elementos(L);  // Conta o número de contas bancárias
        printf("Total Contas: %d", qtde);

        gotoxy(8, 23);
        printf("Deseja remover de qual Posicao?: ");
        scanf("%d", &Posicao);
        if (Posicao > qtde)
        {
            gotoxy(07, 23);
            printf("                                                    ");
            gotoxy(8, 23);
            printf("Posição maior que a quantidade de contas.");
            getch();
        }
    } while (Posicao > qtde || Posicao <= 0);

    if (Posicao > 0)
    {
        // Encontra o Elemento a ser removido e o Elemento anterior
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
                cont++;
                p = p->proximo;
                r = r->proximo;
            }
        }

        // Mostra o Elemento a ser removido
        tela_conta_bancaria();
        gotoxy(20, 03);
        printf("REMOVER CONTA BANCARIA");

        // Exibe os dados da conta bancária
        mostra_conta_bancaria(p->conteudo.conta_bancaria);  // Alterado para mostrar a conta bancária

        gotoxy(07, 23);
        printf("Deseja Remover a Conta Bancaria (1=Sim; 2=Nao): ");
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
            gotoxy(07, 23);
            printf("                                                       ");
            gotoxy(07, 23);
            printf("Conta Bancária Removida com Sucesso.");
            getch();
        }
    }
}
