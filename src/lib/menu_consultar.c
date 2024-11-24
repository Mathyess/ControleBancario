/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Implementa o submenu de consultas do sistema bancário.
    Este módulo é responsável por gerenciar todas as operações de consulta,
    incluindo:
    - Consulta geral de clientes
    - Consulta ordenada por código
    - Consulta ordenada por nome
    - Consulta por código específico
    - Consulta de contas inativas
    - Consulta de limites de crédito
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h" 

void menu_consultar(TipoLista *L)
{
    int opc;
    do
    {
        tela();
        SetCor(9, 0); // Texto azul claro para toda a interface
        gotoxy(20, 03);
        printf("SUBMENU CONSULTA");
        
        gotoxy(25, 8);
        printf("1 - Consultar Fichario do Cliente Geral");
        gotoxy(25, 10);
        printf("2 - Consultar em Ordem de Codigo");
        gotoxy(25, 12);
        printf("3 - Consultar em Ordem Alfabetica");
        gotoxy(25, 14);
        printf("4 - Consultar o Codigo Especifico");
        gotoxy(25, 16);
        printf("5 - Consultar Contas Inativas");
        gotoxy(25, 18);
        printf("6 - Consultar Limites de Credito");
        gotoxy(25, 20);
        printf("7 - Retornar Menu Principal");

        gotoxy(8, 23);
        printf("Digite sua opcao.: ");
        gotoxy(28, 23);
        
        // Validação de entrada
        while (scanf("%d", &opc) != 1 || opc < 1 || opc > 7) {
            gotoxy(8, 23);
            printf("Opcao invalida. Tente novamente: ");
            while(getchar() != '\n'); // Limpa o buffer
        }
        getchar(); // Limpa o buffer após a leitura válida
        
        switch (opc)
        {
        case 1:
            consultar_cliente(L);
            break;
        case 2:
            if (L->Primeiro == NULL) {
                tela();
                gotoxy(20, 03);
                printf("CONSULTA LISTA CLIENTES - ORDEM DE CODIGO");
                gotoxy(07, 23);
                printf("LISTA VAZIA..");
                getch();
            } else {
                ordena_codigo(L);
                consulta_todos(L, "CONSULTA LISTA CLIENTES - ORDEM DE CODIGO");
            }
            break;
        case 3:
            if (L->Primeiro == NULL) {
                tela();
                gotoxy(20, 03);
                printf("CONSULTA LISTA CLIENTES - ORDEM ALFABETICA");
                gotoxy(07, 23);
                printf("LISTA VAZIA..");
                getch();
            } else {
                ordena_nome(L);
                consulta_todos(L, "CONSULTA LISTA CLIENTES - ORDEM ALFABETICA");
            }
            break;
        case 4:
            consultar_cliente(L);
            break;
        case 5:
            if (L->Primeiro == NULL) {
                tela();
                gotoxy(20, 03);
                printf("CONSULTA DE CONTAS INATIVAS");
                gotoxy(07, 23);
                printf("LISTA VAZIA..");
                getch();
            } else {
                consulta_todos(L, "CONSULTA DE CONTAS INATIVAS - APENAS INATIVAS");
            }
            break;
        case 6:
            if (L->Primeiro == NULL) {
                tela();
                gotoxy(20, 03);
                printf("CONSULTA DE LIMITES DE CREDITO");
                gotoxy(07, 23);
                printf("LISTA VAZIA..");
                getch();
            } else {
                consulta_todos(L, "CONSULTA DE LIMITES DE CREDITO POR CONTA");
            }
            break;
        case 7:
            break;
        }

    } while (opc != 7);
}
