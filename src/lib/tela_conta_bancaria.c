#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void tela_conta_bancaria()
{
    tela();  // Chama a função de tela base
    
    gotoxy(07, 05);
    printf("Codigo da Conta.: ");
    
    gotoxy(07, 07);
    printf("1- Banco.............: ");
    
    gotoxy(07, 9);
    printf("2- Agencia...........: ");
    
    gotoxy(07, 11);
    printf("3- Numero da Conta...: ");
    
    gotoxy(07, 13);
    printf("4- Tipo de Conta.....: ");
    
    gotoxy(07, 15);
    printf("5- Saldo.............: ");
    
    gotoxy(07, 17);
    printf("6- Limite............: ");
    
    gotoxy(07, 19);
    printf("7- Status da Conta...: ");
}

// Função para mostrar os detalhes de uma conta bancária
void mostra_conta_bancaria(conta_bancaria conta)
{
    gotoxy(30, 05);
    printf("%d", conta.codigo_conta);
    
    gotoxy(30, 07);
    printf("%s", conta.banco);
    
    gotoxy(30, 9);
    printf("%s", conta.agencia);
    
    gotoxy(30, 11);
    printf("%s", conta.numero_conta);
    
    gotoxy(30, 13);
    printf("%s", conta.tipo_conta);
    
    gotoxy(30, 15);
    printf("%.2f", conta.vl_saldo);
    
    gotoxy(30, 17);
    printf("%.2f", conta.vl_limite);
    
    gotoxy(30, 19);
    printf("%s", conta.status);
}
