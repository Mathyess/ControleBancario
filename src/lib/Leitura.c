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

// Função para ler os dados de uma conta bancária
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

// Função para ler os dados de um cliente
void ler_dados_cliente(reg_cliente *cliente) {
    tela_clie();
    SetCor(9, 0);
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

    // Obtém a data atual para o cadastro
    obter_data_atual(cliente->dt_cadastro);
}

// Funções auxiliares de leitura
void leitura(reg_cliente *reg_clie) {
    strncpy(reg_clie->nm_cliente, le_nm_nome(), sizeof(reg_clie->nm_cliente) - 1);
    reg_clie->nm_cliente[sizeof(reg_clie->nm_cliente) - 1] = '\0';
    
    strncpy(reg_clie->ds_endereco, le_ds_endereco(), sizeof(reg_clie->ds_endereco) - 1);
    reg_clie->ds_endereco[sizeof(reg_clie->ds_endereco) - 1] = '\0';
    
    reg_clie->nr_numero = le_nr_numero();
    
    strncpy(reg_clie->nr_documento, le_nr_documento(), sizeof(reg_clie->nr_documento) - 1);
    reg_clie->nr_documento[sizeof(reg_clie->nr_documento) - 1] = '\0';
    
    strncpy(reg_clie->ds_cidade, le_ds_cidade(), sizeof(reg_clie->ds_cidade) - 1);
    reg_clie->ds_cidade[sizeof(reg_clie->ds_cidade) - 1] = '\0';
    
    strncpy(reg_clie->cd_uf, le_cd_uf(), sizeof(reg_clie->cd_uf) - 1);
    reg_clie->cd_uf[sizeof(reg_clie->cd_uf) - 1] = '\0';
    
    strncpy(reg_clie->dt_cadastro, le_dt_cadastro(), sizeof(reg_clie->dt_cadastro) - 1);
    reg_clie->dt_cadastro[sizeof(reg_clie->dt_cadastro) - 1] = '\0';
    
    strncpy(reg_clie->nr_telefone, le_nr_telefone(), sizeof(reg_clie->nr_telefone) - 1);
    reg_clie->nr_telefone[sizeof(reg_clie->nr_telefone) - 1] = '\0';
}

char *le_nm_nome() {
    static char nome[100];
    printf("Digite o nome do cliente: ");
    ler_string(nome, sizeof(nome));
    return nome;
}

char *le_ds_endereco() {
    static char endereco[200];
    printf("Digite o endereço do cliente: ");
    ler_string(endereco, sizeof(endereco));
    return endereco;
}

int le_nr_numero() {
    int numero;
    printf("Digite o número da casa: ");
    scanf("%d", &numero);
    limpar_buffer();
    return numero;
}

char *le_nr_documento() {
    static char documento[20];
    printf("Digite o número do documento (CPF ou CNPJ): ");
    ler_string(documento, sizeof(documento));
    return documento;
}

char *le_ds_cidade() {
    static char cidade[100];
    printf("Digite a cidade do cliente: ");
    ler_string(cidade, sizeof(cidade));
    return cidade;
}

char *le_cd_uf() {
    static char uf[3];
    printf("Digite o código da UF (ex: SP): ");
    ler_string(uf, sizeof(uf));
    return uf;
}

char *le_dt_cadastro() {
    static char data[11];
    printf("Digite a data de cadastro (DD/MM/AAAA): ");
    ler_string(data, sizeof(data));
    return data;
}

char *le_nr_telefone() {
    static char telefone[20];
    printf("Digite o número de telefone do cliente: ");
    ler_string(telefone, sizeof(telefone));
    return telefone;
}
