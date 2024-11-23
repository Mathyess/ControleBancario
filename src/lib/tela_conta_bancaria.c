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
    - mostra_conta_bancaria(): Exibe os dados de uma conta existente
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void tela_conta_bancaria()
{
    tela();  // Chama a função de tela base
    
    SetCor(11, 0); // Texto azul claro para os rótulos
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
    
    SetCor(3, 0); // Volta para ciano para o conteúdo
}

// Função para mostrar os detalhes de uma conta bancária
void mostra_conta_bancaria(conta_bancaria conta)
{
    SetCor(3, 0); // Texto ciano para os dados
    
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
