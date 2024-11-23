/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Implementa a funcionalidade de exibição de relatórios do sistema bancário.
    Este módulo é responsável por exibir diferentes tipos de relatórios:
    - Relatório geral de contas
    - Relatório de contas inativas
    - Relatório de limites de crédito
    
    Características:
    - Formatação tabular dos dados
    - Paginação automática para grandes volumes de dados
    - Filtragem específica para cada tipo de relatório
    - Cálculo de valores disponíveis (saldo + limite)
    - Exibição colorizada para melhor legibilidade
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
    SetCor(15, 0); // Texto branco para título
    gotoxy(22, 03);
    printf("%s", msg);

    // Inicia a linha para exibição dos dados
    lin = 7;

    // Exibe o cabeçalho da tabela com informações da conta bancária
    SetCor(11, 0); // Texto azul claro para cabeçalhos
    gotoxy(02, 05);
    if (is_limit_report) {
        printf("Codigo  Banco         Agencia    Conta         Tipo        Limite      Saldo     Disponivel");
        gotoxy(02, 06);
        printf("------ ------------ ---------- ------------ ----------- ----------- ---------- ------------");
    } else {
        printf("Codigo  Nome Cliente              Banco         Agencia    Conta         Tipo        Status");
        gotoxy(02, 06);
        printf("------ ----------------------- -------------- ---------- ------------ ----------- ----------");
    }

    // Inicia a busca pelo primeiro cliente na lista
    p = L->Primeiro;
    if (p == NULL)
    {
        // Caso a lista esteja vazia, exibe uma mensagem
        SetCor(11, 0); // Texto azul claro para mensagens
        gotoxy(07, 23);
        printf("LISTA VAZIA..");
        getch();
    }
    else
    {
        SetCor(3, 0); // Texto ciano para dados
        // Enquanto houver clientes na lista, exibe seus dados
        while (p != NULL)
        {
            // Se for relatório de inativas, só mostra as inativas
            if (is_inactive_report && strcmp(p->conteudo.conta_bancaria.status, "INATIVA") != 0) {
                p = p->proximo;
                continue;
            }

            if (is_limit_report) {
                // Relatório de limites de crédito
                double disponivel = p->conteudo.conta_bancaria.vl_saldo + p->conteudo.conta_bancaria.vl_limite;
                gotoxy(02, lin);
                printf("%-6d", p->conteudo.conta_bancaria.codigo_conta);
                gotoxy(9, lin);
                printf("%-12s", p->conteudo.conta_bancaria.banco);
                gotoxy(22, lin);
                printf("%-10s", p->conteudo.conta_bancaria.agencia);
                gotoxy(33, lin);
                printf("%-12s", p->conteudo.conta_bancaria.numero_conta);
                gotoxy(46, lin);
                printf("%-11s", p->conteudo.conta_bancaria.tipo_conta);
                gotoxy(58, lin);
                printf("%10.2f", p->conteudo.conta_bancaria.vl_limite);
                gotoxy(69, lin);
                printf("%10.2f", p->conteudo.conta_bancaria.vl_saldo);
                gotoxy(80, lin);
                printf("%10.2f", disponivel);
            } else {
                // Relatório padrão ou de inativas
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
                printf("%-10s", p->conteudo.conta_bancaria.status);
            }

            // Avança para a próxima linha
            lin++;

            // Se a quantidade de registros for muito grande, pausa e limpa a tela
            if (lin > 21)
            {
                SetCor(11, 0); // Texto azul claro para mensagens
                gotoxy(07, 23);
                system("pause");
                limpa_tela();
                
                // Reimprime o cabeçalho
                SetCor(15, 0); // Texto branco para título
                gotoxy(22, 03);
                printf("%s", msg);

                SetCor(11, 0); // Texto azul claro para cabeçalhos
                gotoxy(02, 05);
                if (is_limit_report) {
                    printf("Codigo  Banco         Agencia    Conta         Tipo        Limite      Saldo     Disponivel");
                    gotoxy(02, 06);
                    printf("------ ------------ ---------- ------------ ----------- ----------- ---------- ------------");
                } else {
                    printf("Codigo  Nome Cliente              Banco         Agencia    Conta         Tipo        Status");
                    gotoxy(02, 06);
                    printf("------ ----------------------- -------------- ---------- ------------ ----------- ----------");
                }
                
                SetCor(3, 0); // Volta para ciano para os dados
                lin = 7;
            }

            // Avança para o próximo cliente na lista
            p = p->proximo;
        }

        // Pausa a exibição no final
        SetCor(11, 0); // Texto azul claro para mensagens
        gotoxy(07, 23);
        system("pause");
    }
}
