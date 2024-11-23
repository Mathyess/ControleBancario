/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"
// Função para ler um inteiro
int ler_inteiro() {
    int valor;
    scanf("%d", &valor);
    return valor;
}

// Função de pausa (para aguardar o usuário pressionar uma tecla)
void pausa() {
    printf("Pressione qualquer tecla para continuar...");
    getch();  // Pausa a execução até o usuário apertar uma tecla
}
