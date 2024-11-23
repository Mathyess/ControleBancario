/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para cadastrar conta bancária em uma posição específica
void cad_posicao(TipoLista *L)
{
    TipoApontador p;
    TipoApontador r;
    TipoApontador aux1;
    reg_cliente reg_clie;
    conta_bancaria nova_conta;
    int resp;
    int Posicao;
    int cont;
    int qtde;

    do
    {
        tela_conta_bancaria();
        gotoxy(20, 03);
        printf("CADASTRAR CONTA BANCARIA");
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
        // Verifica se o código da conta já está cadastrado
        do
        {
            gotoxy(30, 05);
            printf("           ");
            gotoxy(07, 23);
            printf("Digite o codigo da conta: ");
            scanf("%d", &nova_conta.codigo_conta);
            getchar(); // Limpa o buffer
            
            aux1 = verificar_codigo_conta(L, nova_conta.codigo_conta);
            if (aux1 != NULL)
            {
                gotoxy(07, 23);
                printf("                                            ");
                gotoxy(07, 23);
                printf("Erro: O codigo %d ja esta cadastrado.", nova_conta.codigo_conta);
                getch();
                gotoxy(07, 23);
                printf("                                            ");
            }
        } while (aux1 != NULL);

        // Leitura dos dados da conta
        ler_dados_conta(&nova_conta);

        // Confirmação para gravar os dados
        gotoxy(07, 23);
        printf("Deseja gravar os dados (1-Sim; 2-Nao).: ");
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

            // Inicializa os dados do cliente com valores vazios
            reg_clie.cd_cliente = nova_conta.codigo_conta;
            strcpy(reg_clie.nm_cliente, "");
            strcpy(reg_clie.ds_endereco, "");
            reg_clie.nr_numero = 0;
            strcpy(reg_clie.nr_documento, "");
            strcpy(reg_clie.ds_cidade, "");
            strcpy(reg_clie.cd_uf, "");
            strcpy(reg_clie.dt_cadastro, "");
            strcpy(reg_clie.nr_telefone, "");
            reg_clie.conta_bancaria = nova_conta;

            // Move os dados para o ponteiro r
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
            printf("Conta bancaria cadastrada com sucesso!");
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
