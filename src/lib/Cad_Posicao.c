#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para cadastrar cliente em uma posição específica
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
        printf("CADASTRAR CONTA EM UMA POSICAO");
        gotoxy(60, 03);
        qtde = conta_elementos(L);
        printf("Total Contas.: %d", qtde);

        gotoxy(8, 23);
        printf("Deseja cadastrar em qual Posicao.: ");
        scanf("%d", &Posicao);
        getchar(); // Limpa o buffer

        // Verifica se a posição informada é válida
        if (Posicao <= 0 || Posicao > qtde + 1) 
        {
            gotoxy(07, 23);
            printf("                                                    ");
            gotoxy(8, 23);
            printf("Posicao invalida. Tente novamente.");
            getch();
        }
    } while (Posicao <= 0 || Posicao > qtde + 1);

    if (Posicao > 0)
    {
        // Verifica se o código do cliente já está cadastrado
        do
        {
            gotoxy(30, 05);
            printf("           ");
            gotoxy(30, 05);
            printf("Digite o codigo do cliente: ");
            scanf("%d", &reg_clie.cd_cliente);
            getchar(); // Limpa o buffer
            
            aux1 = pesquisa(L, reg_clie.cd_cliente);
            if (aux1 != NULL)
            {
                gotoxy(07, 23);
                printf("Codigo Ja Cadastrado..");
                getch();
            }
        } while (aux1 != NULL);

        // Leitura dos dados do cliente
        leitura(&reg_clie);

        // Confirmação para gravar os dados
        gotoxy(07, 23);
        printf("Deseja gravar os dados (1-Sim; 2-Nao): ");
        scanf("%d", &resp);
        getchar(); // Limpa o buffer

        if (resp == 1)
        {
            r = (TipoApontador)malloc(sizeof(TipoItem));
            if (r == NULL) 
            {
                gotoxy(07, 23);
                printf("Erro ao alocar memoria.");
                getch();
                return;
            }

            // Move os dados lidos para o ponteiro r
            r->conteudo = reg_clie;

            // Insere o registro na lista na posição desejada
            if (Posicao == 1) // Inserir no início
            {
                r->proximo = L->Primeiro;
                L->Primeiro = r;
                if (L->Ultimo == NULL) // Se a lista estava vazia
                {
                    L->Ultimo = r;
                }
            }
            else // Inserir em qualquer outra posição
            {
                p = L->Primeiro;
                for (cont = 1; cont < Posicao - 1; cont++)
                {
                    p = p->proximo;
                }
                r->proximo = p->proximo;
                p->proximo = r;
                if (r->proximo == NULL) // Se inserido na última posição
                {
                    L->Ultimo = r;
                }
            }

            gotoxy(07, 23);
            printf("Cliente cadastrado com sucesso!");
            getch();
        }
        else
        {
            gotoxy(07, 23);
            printf("Cadastro cancelado.");
            getch();
        }
    }
}
