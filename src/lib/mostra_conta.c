/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void mostra_conta_bancaria(conta_bancaria conta)
{
    // Exibe os dados da conta nas posições corretas da tela
    gotoxy(8, 5);
    printf("Codigo.............: ");
    gotoxy(28, 5);
    printf("%d", conta.codigo_conta);
    
    gotoxy(8, 7);
    printf("1- Banco...........: ");
    gotoxy(28, 7);
    printf("%s", conta.banco);
    
    gotoxy(8, 9);
    printf("2- Agencia.........: ");
    gotoxy(28, 9);
    printf("%s", conta.agencia);
    
    gotoxy(8, 11);
    printf("3- Numero da Conta.: ");
    gotoxy(28, 11);
    printf("%s", conta.numero_conta);
    
    gotoxy(8, 13);
    printf("4- Tipo de Conta...: ");
    gotoxy(28, 13);
    printf("%s", conta.tipo_conta);
    
    gotoxy(8, 15);
    printf("5- Saldo...........: ");
    gotoxy(28, 15);
    printf("%.2f", conta.vl_saldo);
    
    gotoxy(8, 17);
    printf("6- Limite..........: ");
    gotoxy(28, 17);
    printf("%.2f", conta.vl_limite);
    
    gotoxy(8, 19);
    printf("7- Status..........: ");
    gotoxy(28, 19);
    printf("%s", conta.status);
}
