#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void consultar_cliente(TipoLista *L)
{
    TipoApontador p;
    int codigo;
    int qtde;

    // Verifica se a lista está vazia
    p = L->Primeiro;
    if (p == NULL)
    {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA...");
        getch();
        return;
    }

    do
    {
        tela();
        tela_clie();
        gotoxy(25, 03);
        printf("CONSULTAR CONTA ESPECIFICA");

        // Exibe o total de contas cadastradas
        qtde = conta_elementos(L);
        gotoxy(60, 03);
        printf("Total Contas.: %d", qtde);

        // Solicita o código da conta
        gotoxy(30, 05);
        printf("Digite o código da conta: ");
        scanf("%d", &codigo);
        getchar();  // Para capturar o ENTER após o código

        // Busca pela conta com o código informado
        p = pesquisa(L, codigo);

        if (p == NULL)
        {
            gotoxy(07, 23);
            printf("Conta Nao Cadastrada..");
            getch();  // Aguarda interação do usuário
        }

    } while (p == NULL);  // Continua pedindo até encontrar a conta

    // Exibe os dados da conta encontrada
    mostra_cliente(p->conteudo);

    // Pausa a execução para o usuário visualizar os dados
    gotoxy(10, 23);
    system("pause");
}
