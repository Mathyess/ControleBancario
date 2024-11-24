/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Implementa a interface visual base do sistema bancário.
    Este módulo é responsável por:
    - Definir o layout padrão das telas
    - Gerenciar as cores do sistema
    - Criar bordas e elementos visuais
    - Manter consistência visual em toda a aplicação
    
    O sistema utiliza uma única cor:
    - Azul claro (9): Todos os elementos da interface
    
    Layout padrão:
    - Cabeçalho com título do sistema
    - Bordas laterais para delimitação
    - Área de mensagens na parte inferior
    - Área central para conteúdo específico
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "../include/funcoes.h"

// Função para alterar as cores no console
void SetCor(int corTexto, int corFundo) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (corFundo << 4) | corTexto);
}

// Mostra a Tela Padrao
void tela()
{
    int t;
    system("cls");
    system("color 09"); // Define o fundo preto (0) e texto azul claro (9) como padrão do sistema
    
    // Definir a cor do texto e fundo
    SetCor(9, 0); // Texto azul claro, fundo preto
    
    gotoxy(01, 01);
    printf("+-----------------------------------------------------------------------------+");
    gotoxy(01, 02);
    printf("| UNICV");
    gotoxy(60, 02);
    printf("Estrutura de Dados |");
    gotoxy(01, 03);
    printf("|");

    // Título principal também em azul claro
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
}
