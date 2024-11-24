/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para cadastrar uma conta numa posição específica da lista
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
    conta_bancaria nova_conta;
    int resp;
    int Posicao;
    int cont;
    int qtde;

    if (L == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    do {
        tela_conta_bancaria();
        gotoxy(20, 3);
        printf("CADASTRAR CONTA BANCARIA");
        gotoxy(60, 3);
        qtde = conta_elementos(L);
        printf("Total Contas.: %d", qtde);

        gotoxy(8, 23);
        printf("Deseja cadastrar em qual Posicao.: ");
        scanf("%d", &Posicao);
        getchar(); // Limpa o buffer

        // Verifica se a posição informada é válida
        if (Posicao <= 0 || Posicao > qtde + 1) {
            gotoxy(7, 23);
            printf("                                                    ");
            gotoxy(8, 23);
            printf("Posicao invalida. Tente novamente.");
            getch();
        }
    } while (Posicao <= 0 || Posicao > qtde + 1);

    if (Posicao > 0) {
        // Verifica se o código da conta já está cadastrado
        do {
            gotoxy(30, 5);
            printf("           ");
            gotoxy(7, 23);
            printf("Digite o codigo da conta: ");
            scanf("%d", &nova_conta.codigo_conta);
            gotoxy(30, 05);
            printf("%d", nova_conta.codigo_conta);
            getchar(); // Limpa o buffer
            
            aux1 = verificar_codigo_conta(L, nova_conta.codigo_conta);
            if (aux1 != NULL) {
                gotoxy(7, 23);
                printf("                                            ");
                gotoxy(7, 23);
                printf("Erro: O codigo %d ja esta cadastrado.", nova_conta.codigo_conta);
                getch();
                gotoxy(7, 23);
                printf("                                            ");
            }
        } while (aux1 != NULL);

// Leitura dos dados da conta
        ler_dados_conta(&nova_conta);
        obter_data_atual(nova_conta.dt_cadastro);

        // Confirmação para gravar os dados
        gotoxy(7, 23);
        printf("Deseja gravar os dados (1-Sim; 2-Nao).: ");
        scanf("%d", &resp);
        getchar(); // Limpa o buffer

        if (resp == 1) {
            r = (TipoApontador)malloc(sizeof(TipoItem));
            if (r == NULL) {
                gotoxy(7, 23);
                printf("Erro ao alocar memoria.");
                getch();
                return;
            }

// Move os dados para o ponteiro r
            r->conteudo.conta_bancaria = nova_conta;
            // Inicializa outros campos do reg_cliente
            strcpy(r->conteudo.nm_cliente, "");
            strcpy(r->conteudo.ds_endereco, "");
            r->conteudo.nr_numero = 0;
            strcpy(r->conteudo.nr_documento, "");
            strcpy(r->conteudo.ds_cidade, "");
            strcpy(r->conteudo.cd_uf, "");
            strcpy(r->conteudo.nr_telefone, "");

            // Insere o registro na lista na posição desejada
            if (Posicao == 1) { // Inserir no início
                r->proximo = L->Primeiro;
                L->Primeiro = r;
                if (L->Ultimo == NULL) { // Se a lista estava vazia
                    L->Ultimo = r;
                }
            } else { // Inserir em qualquer outra posição
                p = L->Primeiro;
                for (cont = 1; cont < Posicao - 1; cont++) {
                    p = p->proximo;
                }
                r->proximo = p->proximo;
                p->proximo = r;
                if (r->proximo == NULL) { // Se inserido na última posição
                    L->Ultimo = r;
                }
            }

            // Salva imediatamente após cadastrar
            Salvar(L);

            gotoxy(7, 23);
printf("Conta bancaria cadastrada com sucesso!");
            getch();
        } else {
            gotoxy(7, 23);
            printf("Cadastro cancelado.");
            getch();
        }
    }
}
