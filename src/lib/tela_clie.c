/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "../include/funcoes.h"

// Tela de interação do cliente para cadastro e manipulação de contas bancárias
void tela_clie()
{
    tela();  // Chama a função de tela principal (presumivelmente define a tela inicial)
    
    gotoxy(07, 05);  // Posiciona o cursor na linha 5, coluna 7
    printf("   Codigo da Conta.: ");
    
    gotoxy(07, 07);  // Linha 7
    printf("1- Banco...: ");  // Exibe o campo para o código do banco
    
    gotoxy(07, 9);  // Linha 9
    printf("2- Agencia..........: ");  // Exibe o campo para o código da agência
    
    gotoxy(07, 11);  // Linha 11
    printf("3- Numero da Conta............: ");  // Exibe o campo para o número da conta
    
    gotoxy(07, 13);  // Linha 13
    printf("4- Tipo da Conta...............: ");  // Exibe o campo para o tipo da conta (ex. Corrente, Poupança)
    
    gotoxy(07, 15);  // Linha 15
    printf("5- Saldo..............: ");  // Exibe o campo para o saldo da conta
    
    gotoxy(07, 17);  // Linha 17
    printf("6- Limite..............: ");  // Exibe o campo para o limite de crédito da conta (se aplicável)
    
    gotoxy(07, 19);  // Linha 19
    printf("7- Status da Conta.....: ");  // Exibe o campo para o status da conta (Ativa, Inativa, Suspensa)
}
