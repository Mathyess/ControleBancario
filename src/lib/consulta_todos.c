/*  
    Alunos: Matheus Alende Pires
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Implementa a funcionalidade de exibição de relatórios do sistema bancário.
    Este módulo é responsável por exibir diferentes tipos de relatórios:
    - Relatório geral de contas
    - Relatório de contas inativas
    - Relatório de limites de crédito
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "../include/funcoes.h"

void consulta_todos(TipoLista *L, char msg[40])
{
    TipoApontador p;
    int lin;
    int is_inactive_report = (strstr(msg, "INATIVAS") != NULL);
    int is_limit_report = (strstr(msg, "LIMITES") != NULL);

    // Limpa a tela e exibe o título da consulta
    tela();
    gotoxy(22, 03);
    printf("%s", msg);

    // Inicia a linha para exibição dos dados
    lin = 7;

    // Exibe o cabeçalho da tabela com informações da conta bancária
    gotoxy(02, 05);
if (is_limit_report) {
        printf("Codigo  Banco         Agencia    Conta         Tipo        Limite      Saldo     Disponivel");
        gotoxy(02, 06);
        printf("------ ------------ ---------- ------------ ----------- ----------- ---------- ------------");
    } else {
        printf("Codigo  1-Banco......  2-Agencia...  3-Conta.....  4-Tipo.....  5-Status...  Saldo");
        gotoxy(02, 06);
        printf("------ ------------- ------------ ------------ ----------- ----------- ------------");
    }

    // Inicia a busca pela primeira conta na lista
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
        // Enquanto houver contas na lista, exibe seus dados
        while (p != NULL)
        {
            // Se for relatório de inativas, só mostra as inativas
            if (is_inactive_report) {
                // Se é relatório de inativas e a conta não é inativa, pula
                if (strcmp(p->conteudo.status, "INATIVA") != 0) {
                    p = p->proximo;
                    continue;
                }
            } else {
                // Se é relatório normal e a conta é inativa, pula
                if (strcmp(p->conteudo.status, "INATIVA") == 0) {
                    p = p->proximo;
                    continue;
                }
            }

            if (is_limit_report) {
                // Relatório de limites de crédito
                double disponivel = p->conteudo.vl_saldo + p->conteudo.vl_limite;
                gotoxy(02, lin);
                printf("%-6d", p->conteudo.codigo_conta);
                gotoxy(9, lin);
                printf("%-12s", p->conteudo.banco);
                gotoxy(22, lin);
                printf("%-10s", p->conteudo.agencia);
                gotoxy(33, lin);
                printf("%-12s", p->conteudo.numero_conta);
                gotoxy(46, lin);
                printf("%-11s", p->conteudo.tipo_conta);
                gotoxy(58, lin);
                printf("%10.2f", p->conteudo.vl_limite);
                gotoxy(69, lin);
                printf("%10.2f", p->conteudo.vl_saldo);
                gotoxy(80, lin);
                printf("%10.2f", disponivel);
            } else {
                // Relatório padrão ou de inativas
                gotoxy(02, lin);
                printf("%-6d", p->conteudo.codigo_conta);
                gotoxy(10, lin);
                printf("%-13s", p->conteudo.banco);
                gotoxy(25, lin);
                printf("%-12s", p->conteudo.agencia);
                gotoxy(39, lin);
                printf("%-12s", p->conteudo.numero_conta);
                gotoxy(53, lin);
                printf("%-11s", p->conteudo.tipo_conta);
                gotoxy(66, lin);
                printf("%-11s", p->conteudo.status);
                gotoxy(79, lin);
                printf("%10.2f", p->conteudo.vl_saldo);
            }

            // Avança para a próxima linha
            lin++;

            // Se a quantidade de registros for muito grande, pausa e limpa a tela
            if (lin > 21)
            {
                gotoxy(07, 23);
                system("pause");
                limpa_tela();
                
                // Reimprime o cabeçalho
                gotoxy(22, 03);
                printf("%s", msg);

                gotoxy(02, 05);
                if (is_limit_report) {
                    printf("Codigo  Banco         Agencia    Conta         Tipo        Limite      Saldo     Disponivel");
                    gotoxy(02, 06);
                    printf("------ ------------ ---------- ------------ ----------- ----------- ---------- ------------");
                } else {
                    printf("Codigo  1-Banco......  2-Agencia...  3-Conta.....  4-Tipo.....  5-Status...  Saldo");
                    gotoxy(02, 06);
                    printf("------ ------------- ------------ ------------ ----------- ----------- ------------");
                }
                
                lin = 7;
            }

            // Avança para a próxima conta na lista
            p = p->proximo;
        }

        // Pausa a exibição no final
        gotoxy(07, 23);
        system("pause");
    }
}
