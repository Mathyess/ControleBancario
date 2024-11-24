/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para ler os dados previamente registrados de uma conta
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para verificar se o código da conta já existe
TipoApontador verificar_codigo_conta(TipoLista *L, int codigo) {
    TipoApontador aux = L->Primeiro;
    while (aux != NULL) {
        if (aux->conteudo.conta_bancaria.codigo_conta == codigo) {
            return aux;
        }
        aux = aux->proximo;
    }
    return NULL;
}

// Função para limpar o buffer do teclado
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para ler uma string com segurança
void ler_string(char *destino, int tamanho) {
    fgets(destino, tamanho, stdin);
    destino[strcspn(destino, "\n")] = 0;
}

// Função para ler os dados da conta bancária
void ler_dados_conta(conta_bancaria *conta) {
    // Lê o nome do banco
    gotoxy(30, 7);
    ler_string(conta->banco, sizeof(conta->banco));

    // Lê a agência
    gotoxy(30, 9);
    ler_string(conta->agencia, sizeof(conta->agencia));

    // Lê o número da conta
    gotoxy(30, 11);
    ler_string(conta->numero_conta, sizeof(conta->numero_conta));

    // Lê o tipo da conta
    gotoxy(30, 13);
    ler_string(conta->tipo_conta, sizeof(conta->tipo_conta));

    // Lê o saldo
    gotoxy(30, 15);
    scanf("%lf", &conta->vl_saldo);
    limpar_buffer();

    // Lê o limite
    gotoxy(30, 17);
    scanf("%lf", &conta->vl_limite);
    limpar_buffer();

    // Lê o status da conta
    gotoxy(30, 19);
    ler_string(conta->status, sizeof(conta->status));
}

// Função para ler todos os dados (conta e cliente)
void ler_dados_completos(conta_bancaria *conta, reg_cliente *cliente) {
    // Tela da conta bancária
    tela_conta_bancaria();

    // Lê os dados da conta bancária
    ler_dados_conta(conta);

    // Lê os dados do cliente
    system("cls");
    tela_clie();
    gotoxy(20, 3);
    printf("CADASTRO DE CLIENTE");

    // Lê o nome do cliente
    gotoxy(30, 7);
    ler_string(cliente->nm_cliente, sizeof(cliente->nm_cliente));

    // Lê o endereço
    gotoxy(30, 9);
    ler_string(cliente->ds_endereco, sizeof(cliente->ds_endereco));

    // Lê o número
    gotoxy(30, 11);
    scanf("%d", &cliente->nr_numero);
    limpar_buffer();

    // Lê o documento
    gotoxy(30, 13);
    ler_string(cliente->nr_documento, sizeof(cliente->nr_documento));

    // Lê a cidade
    gotoxy(30, 15);
    ler_string(cliente->ds_cidade, sizeof(cliente->ds_cidade));

    // Lê a UF
    gotoxy(30, 17);
    ler_string(cliente->cd_uf, sizeof(cliente->cd_uf));

    // Lê o telefone
    gotoxy(30, 19);
    ler_string(cliente->nr_telefone, sizeof(cliente->nr_telefone));

// Obtém a data atual para o cadastro da conta
    obter_data_atual(conta->dt_cadastro);
}
