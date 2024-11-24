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
#include <time.h>
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

// Função para obter a data e hora atual
void obter_data_hora(char *data, char *hora) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    // Formata a data como DD/MM/AAAA
    sprintf(data, "%02d/%02d/%04d", 
            tm->tm_mday, 
            tm->tm_mon + 1, 
            tm->tm_year + 1900);
    
    // Formata a hora como HH:MM:SS
    sprintf(hora, "%02d:%02d:%02d", 
            tm->tm_hour, 
            tm->tm_min, 
            tm->tm_sec);
}

// Função para obter apenas a data atual
void obter_data_atual(char *data) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    sprintf(data, "%02d/%02d/%04d", 
            tm->tm_mday, 
            tm->tm_mon + 1, 
            tm->tm_year + 1900);
}
