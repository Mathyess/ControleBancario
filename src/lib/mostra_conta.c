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
    gotoxy(30, 5);
    printf("Codigo: %d", conta.codigo_conta);
    
    gotoxy(30, 7);
    printf("Banco: %s", conta.banco);
    
    gotoxy(30, 9);
    printf("Agencia: %s", conta.agencia);
    
    gotoxy(30, 11);
    printf("Conta: %s", conta.numero_conta);
    
    gotoxy(30, 13);
    printf("Tipo: %s", conta.tipo_conta);
    
    gotoxy(30, 15);
    printf("Saldo: %.2f", conta.vl_saldo);
    
    gotoxy(30, 17);
    printf("Limite: %.2f", conta.vl_limite);
    
    gotoxy(30, 19);
    printf("Status: %s", conta.status);
    
    gotoxy(30, 21);
    printf("Data Cadastro: %s", conta.dt_cadastro);
}
