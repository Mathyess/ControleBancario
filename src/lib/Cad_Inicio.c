#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para cadastrar conta bancária no início da lista
void cad_inicio(TipoLista *L)
{
    int resp;
    TipoApontador p;
    TipoApontador aux1;
    reg_cliente reg_clie;
    conta_bancaria nova_conta;

    // Exibe a tela de conta bancária
    tela_conta_bancaria();
    gotoxy(20, 03);
    printf("CADASTRAR CONTA BANCARIA");

    // Laço para verificar se o código da conta já foi cadastrado
    do
    {
        gotoxy(30, 05);
        printf("           "); // Limpa o campo de entrada
        gotoxy(07, 23);
        printf("Digite o codigo da conta: ");
        scanf("%d", &nova_conta.codigo_conta);
        getchar(); // Limpa o buffer

        // Pesquisa a conta na lista
        aux1 = verificar_codigo_conta(L, nova_conta.codigo_conta);
        if (aux1 != NULL) {
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
        // Criação de um novo nó e inserção no início da lista
        p = (TipoApontador)malloc(sizeof(TipoItem));
        if (p == NULL)
        {
            gotoxy(07, 23);
            printf("Erro ao alocar memoria!");
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

        // Atualiza a lista com o novo nó
        p->conteudo = reg_clie;
        p->proximo = L->Primeiro;
        L->Primeiro = p;
        if (L->Ultimo == NULL)
        {
            L->Ultimo = L->Primeiro;
        }

        // Exibe mensagem de sucesso
        gotoxy(07, 23);
        printf("Conta bancaria cadastrada com sucesso!");
        getch();
    }
    else
    {
        // Caso o usuário não queira gravar os dados
        gotoxy(07, 23);
        printf("Cadastro cancelado.");
        getch();
    }
}
