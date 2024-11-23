#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para cadastrar conta no início da lista
void cad_inicio(TipoLista *L)
{
    int resp;
    TipoApontador p;
    TipoApontador aux1;
    reg_cliente reg_clie;
    conta_bancaria nova_conta;

    // Exibe a tela inicial
    tela_clie();
    gotoxy(20, 03);
    printf("CADASTRAR CONTA NO INICIO");

    // Laço para verificar se o código da conta já foi cadastrado
    do
    {
        gotoxy(30, 05);
        printf("           "); // Limpa o campo de entrada
        gotoxy(30, 05);
        printf("Digite o codigo da conta: ");
        scanf("%d", &nova_conta.codigo_conta);
        getchar(); // Limpa o buffer

        // Pesquisa a conta na lista
        aux1 = verificar_codigo_conta(L, nova_conta.codigo_conta);
        if (aux1 != NULL) {
            gotoxy(07, 23);
            printf("Erro: O código %d já está cadastrado.\n", nova_conta.codigo_conta);
            getch();
        }
    } while (aux1 != NULL); // Continua até um código único ser fornecido

    // Leitura dos dados do cliente
    leitura(&reg_clie);

    // Confirmação para gravar os dados
    gotoxy(07, 23);
    printf("Deseja gravar os dados (1-Sim; 2-Nao): ");
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
        
        // Atualiza a lista com o novo nó
        p->proximo = L->Primeiro;
        L->Primeiro = p;
        if (L->Ultimo == NULL)
        {
            L->Ultimo = L->Primeiro;
        }

        // Atribui os dados do cliente e conta bancária ao nó recém-criado
        p->conteudo = reg_clie;
        p->conteudo.conta_bancaria = nova_conta;

        // Exibe mensagem de sucesso
        gotoxy(07, 23);
        printf("Conta cadastrada com sucesso!");
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
