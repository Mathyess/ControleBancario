/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Implementa a interface específica para contas bancárias.
    Este módulo fornece:
    - Tela de cadastro e edição de contas bancárias
    - Exibição formatada dos dados da conta
    - Layout padronizado para entrada de dados
    - Campos específicos para informações bancárias:
      * Código da conta
      * Banco
      * Agência
      * Número da conta
      * Tipo de conta
      * Saldo
      * Limite
      * Status da conta
    
Funções:
    - tela_conta_bancaria(): Exibe o formulário para entrada de dados
    - mostra_conta_form(): Exibe os dados de uma conta no formulário
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void tela_conta_bancaria()
{
    tela();  // Chama a função de tela base
    
gotoxy(7, 5);
    printf("Codigo.............: ");
    
    gotoxy(7, 7);
    printf("1- Banco...........: ");
    
    gotoxy(7, 9);
    printf("2- Agencia.........: ");
    
    gotoxy(7, 11);
    printf("3- Numero da Conta.: ");
    
    gotoxy(7, 13);
    printf("4- Tipo de Conta...: ");
    
    gotoxy(7, 17);
    printf("5- Saldo...........: ");
    
    gotoxy(7, 19);
    printf("6- Limite..........: ");
    
    gotoxy(7, 21);
    printf("7- Status..........: ");
}

// Função para mostrar os detalhes de uma conta bancária no formulário
void mostra_conta_form(conta_bancaria conta)
{
    gotoxy(25, 5);
    printf("%d", conta.codigo_conta);
    
    gotoxy(25, 7);
    printf("%s", conta.banco);
    
    gotoxy(25, 9);
    printf("%s", conta.agencia);
    
    gotoxy(25, 11);
    printf("%s", conta.numero_conta);
    
    gotoxy(25, 13);
    printf("%s", conta.tipo_conta);
    
    gotoxy(25, 17);
    printf("%.2f", conta.vl_saldo);
    
    gotoxy(25, 19);
    printf("%.2f", conta.vl_limite);
    
    gotoxy(25, 21);
    printf("%s", conta.status);
}
