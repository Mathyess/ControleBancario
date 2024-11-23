#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void consulta_todos(TipoLista *L, char msg[40])
{
    TipoApontador p;
    int lin;

    // Limpa a tela e exibe o título da consulta
    tela();
    gotoxy(22, 03);
    printf("%s", msg);

    // Inicia a linha para exibição dos dados
    lin = 7;

    // Exibe o cabeçalho da tabela com informações da conta bancária
    gotoxy(02, 05);
    printf("Codigo  Nome Cliente              Banco         Agencia    Conta         Tipo        Saldo");
    gotoxy(02, 06);
    printf("------ ----------------------- -------------- ---------- ------------ ----------- ----------");

    // Inicia a busca pelo primeiro cliente na lista
    p = L->Primeiro;
    if (p == NULL)
    {
        // Caso a lista esteja vazia, exibe uma mensagem
        gotoxy(07, 23);
        printf("LISTA VAZIA..");
        getch();
    }
    else
    {
        // Enquanto houver clientes na lista, exibe seus dados
        while (p != NULL)
        {
            // Exibe os dados da conta bancária em formato de tabela
            gotoxy(02, lin);
            printf("%-6d", p->conteudo.conta_bancaria.codigo_conta);
            
            gotoxy(9, lin);
            printf("%-21s", p->conteudo.nm_cliente);
            
            gotoxy(31, lin);
            printf("%-14s", p->conteudo.conta_bancaria.banco);
            
            gotoxy(46, lin);
            printf("%-10s", p->conteudo.conta_bancaria.agencia);
            
            gotoxy(57, lin);
            printf("%-12s", p->conteudo.conta_bancaria.numero_conta);
            
            gotoxy(70, lin);
            printf("%-11s", p->conteudo.conta_bancaria.tipo_conta);
            
            gotoxy(82, lin);
            printf("%10.2f", p->conteudo.conta_bancaria.vl_saldo);

            // Avança para a próxima linha
            lin++;

            // Se a quantidade de registros for muito grande, pausa e limpa a tela
            if (lin > 21)
            {
                gotoxy(07, 23);
                system("pause");
                limpa_tela();
                
                // Reimprime o cabeçalho
                gotoxy(02, 05);
                printf("Codigo  Nome Cliente              Banco         Agencia    Conta         Tipo        Saldo");
                gotoxy(02, 06);
                printf("------ ----------------------- -------------- ---------- ------------ ----------- ----------");
                
                lin = 7;
            }

            // Avança para o próximo cliente na lista
            p = p->proximo;
        }

        // Pausa a exibição no final
        gotoxy(07, 23);
        system("pause");
    }
}
