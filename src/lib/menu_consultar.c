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
        printf("5 - Retornar Menu Principal");
        gotoxy(8, 23);
        printf("Digite sua opcao.: ");
        gotoxy(28, 23);
        
        // Validação de entrada
        while (scanf("%d", &opc) != 1 || opc < 1 || opc > 5) {
            gotoxy(8, 23);
            printf("Opcao invalida. Tente novamente: ");
            while(getchar() != '\n'); // Limpa o buffer
        }
        
        switch (opc)
        {
        case 1:
            consultar_cliente(L);  // Alterado para a função correta
            break;
        case 2:
            ordena_codigo(L);
            consulta_todos(L, "CONSULTA LISTA CLIENTES - ORDEM DE CODIGO"); // Verifique a declaração dessa função
            break;
        case 3:
            ordena_nome(L);
            consulta_todos(L, "CONSULTA LISTA CLIENTES - ORDEM ALFABETICA"); // Verifique a declaração dessa função
            break;
        case 4:
            consultar_cliente(L);  // Função para consultar um cliente específico
            break;
        default:
            break;
        }

    } while (opc != 5);
}
