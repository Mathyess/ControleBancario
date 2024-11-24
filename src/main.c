/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Arquivo principal do sistema de controle bancário.
    Este arquivo contém a função main e inicializa o sistema,
    responsável por configurar o ambiente, carregar os dados salvos
    e iniciar o fluxo do programa.
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include "include/funcoes.h"

int main() {
    // Configura o console para usar cores
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
    WORD saved_attributes;

    // Salva os atributos atuais
    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
    saved_attributes = consoleInfo.wAttributes;

    // Define a cor padrão do sistema como azul claro
    system("color 09");

    // Inicia o menu que irá gerenciar as listas internamente
    menu_inicial();

    // Restaura os atributos originais do console antes de sair
    SetConsoleTextAttribute(hConsole, saved_attributes);

    return 0;
}
