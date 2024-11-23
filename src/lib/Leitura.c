#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para ler os dados de um cliente
void leitura(reg_cliente *reg_clie)
{
    // Lê o nome do cliente
    strncpy(reg_clie->nm_cliente, le_nm_nome(), sizeof(reg_clie->nm_cliente) - 1);
    reg_clie->nm_cliente[sizeof(reg_clie->nm_cliente) - 1] = '\0'; // Garante a terminação correta
    
    // Lê o endereço do cliente
    strncpy(reg_clie->ds_endereco, le_ds_endereco(), sizeof(reg_clie->ds_endereco) - 1);
    reg_clie->ds_endereco[sizeof(reg_clie->ds_endereco) - 1] = '\0'; // Garante a terminação correta
    
    // Lê o número da casa (ou do imóvel)
    reg_clie->nr_numero = le_nr_numero();
    
    // Lê o número do documento (CPF ou CNPJ)
    strncpy(reg_clie->nr_documento, le_nr_documento(), sizeof(reg_clie->nr_documento) - 1);
    reg_clie->nr_documento[sizeof(reg_clie->nr_documento) - 1] = '\0'; // Garante a terminação correta
    
    // Lê o nome da cidade onde o cliente reside
    strncpy(reg_clie->ds_cidade, le_ds_cidade(), sizeof(reg_clie->ds_cidade) - 1);
    reg_clie->ds_cidade[sizeof(reg_clie->ds_cidade) - 1] = '\0'; // Garante a terminação correta
    
    // Lê o código da unidade federativa (UF)
    strncpy(reg_clie->cd_uf, le_cd_uf(), sizeof(reg_clie->cd_uf) - 1);
    reg_clie->cd_uf[sizeof(reg_clie->cd_uf) - 1] = '\0'; // Garante a terminação correta
    
    // Lê a data de cadastro
    strncpy(reg_clie->dt_cadastro, le_dt_cadastro(), sizeof(reg_clie->dt_cadastro) - 1);
    reg_clie->dt_cadastro[sizeof(reg_clie->dt_cadastro) - 1] = '\0'; // Garante a terminação correta
    
    // Lê o número de telefone do cliente
    strncpy(reg_clie->nr_telefone, le_nr_telefone(), sizeof(reg_clie->nr_telefone) - 1);
    reg_clie->nr_telefone[sizeof(reg_clie->nr_telefone) - 1] = '\0'; // Garante a terminação correta
}

char *le_nm_nome() {
    static char nome[100];
    printf("Digite o nome do cliente: ");
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha, caso exista
    return nome;
}

char *le_ds_endereco() {
    static char endereco[200];
    printf("Digite o endereço do cliente: ");
    fgets(endereco, sizeof(endereco), stdin);
    endereco[strcspn(endereco, "\n")] = '\0'; // Remove a nova linha, caso exista
    return endereco;
}

int le_nr_numero() {
    int numero;
    printf("Digite o número da casa: ");
    scanf("%d", &numero);
    getchar(); // Limpa o buffer
    return numero;
}

char *le_nr_documento() {
    static char documento[20];
    printf("Digite o número do documento (CPF ou CNPJ): ");
    fgets(documento, sizeof(documento), stdin);
    documento[strcspn(documento, "\n")] = '\0'; // Remove a nova linha, caso exista
    return documento;
}

char *le_ds_cidade() {
    static char cidade[100];
    printf("Digite a cidade do cliente: ");
    fgets(cidade, sizeof(cidade), stdin);
    cidade[strcspn(cidade, "\n")] = '\0'; // Remove a nova linha, caso exista
    return cidade;
}

char *le_cd_uf() {
    static char uf[3];
    printf("Digite o código da UF (ex: SP): ");
    fgets(uf, sizeof(uf), stdin);
    uf[strcspn(uf, "\n")] = '\0'; // Remove a nova linha, caso exista
    return uf;
}

char *le_dt_cadastro() {
    static char data[11];
    printf("Digite a data de cadastro (DD/MM/AAAA): ");
    fgets(data, sizeof(data), stdin);
    data[strcspn(data, "\n")] = '\0'; // Remove a nova linha, caso exista
    return data;
}

char *le_nr_telefone() {
    static char telefone[20];
    printf("Digite o número de telefone do cliente: ");
    fgets(telefone, sizeof(telefone), stdin);
    telefone[strcspn(telefone, "\n")] = '\0'; // Remove a nova linha, caso exista
    return telefone;
}
