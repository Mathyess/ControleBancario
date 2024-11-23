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

void mostra_cliente(reg_cliente cliente)
{
    // Exibe os dados do cliente nas posições corretas da tela
    gotoxy(30, 05);
    printf("Codigo: %d", cliente.cd_cliente);

    gotoxy(30, 07);
    printf("Nome: %s", cliente.nm_cliente);

    gotoxy(30, 9);
    printf("Endereco: %s", cliente.ds_endereco);

    gotoxy(30, 11);
    printf("Numero: %d", cliente.nr_numero);

    gotoxy(30, 13);
    printf("Documento: %s", cliente.nr_documento);

    gotoxy(30, 15);
    printf("Cidade: %s", cliente.ds_cidade);

    gotoxy(30, 17);
    printf("UF: %s", cliente.cd_uf);

    gotoxy(30, 19);
    printf("Telefone: %s", cliente.nr_telefone);

    // Se houver uma conta bancária associada, mostra seus dados também
    if (cliente.conta_bancaria.codigo_conta != 0)
    {
        gotoxy(50, 07);
        printf("Dados da Conta Bancaria:");
        
        gotoxy(50, 9);
        printf("Codigo: %d", cliente.conta_bancaria.codigo_conta);
        
        gotoxy(50, 11);
        printf("Banco: %s", cliente.conta_bancaria.banco);
        
        gotoxy(50, 13);
        printf("Agencia: %s", cliente.conta_bancaria.agencia);
        
        gotoxy(50, 15);
        printf("Conta: %s", cliente.conta_bancaria.numero_conta);
        
        gotoxy(50, 17);
        printf("Tipo: %s", cliente.conta_bancaria.tipo_conta);
        
        gotoxy(50, 19);
        printf("Saldo: %.2f", cliente.conta_bancaria.vl_saldo);
    }
}
