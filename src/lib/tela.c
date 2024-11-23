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
    system("color 05"); // Define o fundo preto (0) e texto roxo (5) como padrão do sistema
    
    // Definir a cor do texto e fundo
    SetCor(13, 0); // Texto roxo brilhante, fundo preto
    
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
    SetCor(5, 0); // Texto roxo normal para as bordas
    for (t = 5; t < 24; t++)
    {
        gotoxy(01, t);
        printf("|");
        gotoxy(79, t);
        printf("|");
    }
    
    // Rodapé
    SetCor(13, 0); // Volta para roxo brilhante para o rodapé
    gotoxy(01, 22);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(02, 23);
    printf("MSG.:");
    gotoxy(01, 24);
    printf("+-----------------------------------------------------------------------------+");
    
    // Mantém o texto roxo normal para o conteúdo
    SetCor(5, 0);  // Texto roxo normal, fundo preto
}
