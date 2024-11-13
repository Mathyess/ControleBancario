/*  Autor.....: Matheus Alende
    Data......: 24/10/2024
    Objetivo..: Criar a estrutura da tela
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>

// Mostra a Tela Padrao
void tela()
{
    int t;
    system("cls");
    gotoxy(01, 01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 02);
    printf("| UNICV");
    gotoxy(60, 02);
    printf("Estrutura de Dados |");
    gotoxy(01, 03);
    printf("|");
    gotoxy(24, 02);
    printf("SISTEMA BANCARIO");
    gotoxy(79, 03);
    printf("|");
    gotoxy(01, 04);
    printf("+-----------------------------------------------------------------------------+");
    for (t = 5; t < 24; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(79, t);
        printf("|");
    }
    gotoxy(01, 22);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(02, 23);
    printf("MSG.:");
    gotoxy(01, 24);
    printf("+-----------------------------------------------------------------------------+");
}
