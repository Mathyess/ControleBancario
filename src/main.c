/*  Autor.....: Matheus Alende
    Data......: 24/10/2024
    Objetivo..: Programa princiapl
    */
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "include/menu.h"
#include "include/tela.h"
#include "include/Cadastro.h"
#include "include/EstruturaDados.h"
int main ()  {
    {
    TipoLista L;
    L.Primeiro = NULL;
    L.Ultimo = NULL;
    carregar(&L);
    int opc;
    system("color 0E");
    do
    {
        tela();
        gotoxy(20, 03);
        printf("MENU PRINCIPAL");
        gotoxy(10, 05);
        printf("1 - Cadastrar Funcionario no Final");
        gotoxy(10, 07);
        printf("2 - Cadastrar Funcionario no Inicio");
        gotoxy(10, 9);
        printf("3 - Cadastrar Funcionario na Posicao");
        gotoxy(10, 11);
        printf("4 - Remover Funcionario no Final");
        gotoxy(10, 13);
        printf("5 - Remover Funcionario no Inicio");
        gotoxy(10, 15);
        printf("6 - Remover Funcionario na Posicao");
        gotoxy(10, 17);
        printf("7 - Alteracao do Funcionario");
        gotoxy(10, 19);
        printf("8 - Listar Funcionarios");
        gotoxy(10, 21);
        printf("9 - Sair");
        gotoxy(10, 23);
        printf("Digite sua opcao: ");
        gotoxy(28, 23);
        scanf("%d", &opc);
        switch (opc)
        {
        case 1:
        {
            cadastrar(&L);
            break;
        }

        case 2:
        {
            cad_inicio(&L);
            break;
        }
        case 3:
        {
            cad_posicao(&L);
            break;
        }
        case 4:
        {
            remove_final(&L);
            break;
        }
        case 5:
        {
            remove_posicao(&L);
            break;
        }
        case 6:
        {
            remove_inicio(&L);
            break;
        }
        case 7:
        {
            menu_consultar(&L);
            break;
        }
        case 8:
        {
            altera_cliente(&L);
            break;
        }
        }
    } while (opc < 9);

    return 0;
}
}