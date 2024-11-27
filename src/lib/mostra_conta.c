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
    // Labels à esquerda
    gotoxy(8, 5);
    printf("Codigo.........: ");
    gotoxy(23, 5);
    printf("%d", conta.codigo_conta);
    
    gotoxy(8, 7);
    printf("Banco..........: ");
    gotoxy(23, 7);
    printf("%s", conta.banco);
    
    gotoxy(8, 9);
    printf("Agencia........: ");
    gotoxy(23, 9);
    printf("%s", conta.agencia);
    
    gotoxy(8, 11);
    printf("Numero da Conta: ");
    gotoxy(23, 11);
    printf("%s", conta.numero_conta);
    
    gotoxy(8, 13);
    printf("Tipo...........: ");
    gotoxy(23, 13);
    printf("%s", conta.tipo_conta);
    
    // Status e outras informações à direita
    gotoxy(50, 6); // Moved status up
    printf("Status.........: ");
    gotoxy(65, 6);
    printf("%s", conta.status);
    
    gotoxy(50, 8);
    printf("Data Cadastro..: ");
    gotoxy(65, 8);
    printf("%s", conta.dt_cadastro);
    
    // Informações financeiras à esquerda
    gotoxy(8, 10); // Moved balance up
    printf("Saldo..........: ");
    gotoxy(23, 10);
    printf("%.2f", conta.vl_saldo);
    
    gotoxy(8, 12); 
    printf("Limite.........: ");
    gotoxy(23, 12);
    printf("%.2f", conta.vl_limite);
}
