#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "../include/funcoes.h"

// Função para alterar as cores no console (opcional)
void SetCor(int corTexto, int corFundo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (corFundo << 4) | corTexto);
}

// Mostra a Tela Padrao
void tela()
{
    int t;
    system("cls");
    
    // Definir a cor do texto e fundo
    SetCor(15, 0); // Texto branco, fundo preto
    
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
    
    // Criando bordas laterais
    for (t = 5; t < 24; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(79, t);
        printf("|");
    }
    
    // Rodapé
    gotoxy(01, 22);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(02, 23);
    printf("MSG.:");
    gotoxy(01, 24);
    printf("+-----------------------------------------------------------------------------+");
    
    // Resetando para as cores padrões
    SetCor(7, 0);  // Texto cinza, fundo preto
}
