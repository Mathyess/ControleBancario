/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <string.h>
#include "../include/funcoes.h"

// Função para ler dados da conta bancária
void ler_dados_conta(conta_bancaria *conta) {
    char buffer[50];

    // Lê o código da conta
    gotoxy(30, 05);
    scanf("%d", &conta->codigo_conta);
    getchar(); // Limpa o buffer

    // Lê o nome do banco
    gotoxy(30, 07);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(conta->banco, buffer, sizeof(conta->banco) - 1);
    conta->banco[sizeof(conta->banco) - 1] = '\0';

    // Lê a agência
    gotoxy(30, 9);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(conta->agencia, buffer, sizeof(conta->agencia) - 1);
    conta->agencia[sizeof(conta->agencia) - 1] = '\0';

    // Lê o número da conta
    gotoxy(30, 11);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(conta->numero_conta, buffer, sizeof(conta->numero_conta) - 1);
    conta->numero_conta[sizeof(conta->numero_conta) - 1] = '\0';

    // Lê o tipo da conta
    gotoxy(30, 13);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(conta->tipo_conta, buffer, sizeof(conta->tipo_conta) - 1);
    conta->tipo_conta[sizeof(conta->tipo_conta) - 1] = '\0';

    // Lê o saldo
    gotoxy(30, 15);
    scanf("%lf", &conta->vl_saldo);
    getchar(); // Limpa o buffer

    // Lê o limite
    gotoxy(30, 17);
    scanf("%lf", &conta->vl_limite);
    getchar(); // Limpa o buffer

    // Lê o status da conta
    gotoxy(30, 19);
    fgets(buffer, sizeof(buffer), stdin);
    buffer[strcspn(buffer, "\n")] = 0;
    strncpy(conta->status, buffer, sizeof(conta->status) - 1);
    conta->status[sizeof(conta->status) - 1] = '\0';
}

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

// Função para cadastrar conta bancária no final da lista
void cadastrar(TipoLista *L) {
    TipoApontador p;
    TipoApontador aux1;
    int resp;
    conta_bancaria nova_conta;
    
    tela_conta_bancaria();
    gotoxy(20, 03);
    printf("CADASTRAR CONTA BANCARIA NO FINAL");

    // Verifica se o código da conta já está cadastrado
    do {
        gotoxy(30, 05);
        printf("           ");
        gotoxy(07, 23);
        printf("Digite o codigo da conta bancaria: ");
        scanf("%d", &nova_conta.codigo_conta);
        getchar(); // Limpa o buffer
        
        aux1 = verificar_codigo_conta(L, nova_conta.codigo_conta);
        if (aux1 != NULL) {
            gotoxy(07, 23);
            printf("                                            ");
            gotoxy(07, 23);
            printf("Erro: O codigo %d ja esta cadastrado.", nova_conta.codigo_conta);
            getch();
            gotoxy(07, 23);
            printf("                                            ");
        }
    } while (aux1 != NULL);

    // Leitura dos dados da conta
    ler_dados_conta(&nova_conta);

    // Confirmação de gravação dos dados
    gotoxy(07, 23);
    printf("Deseja gravar os dados (1-Sim; 2-Nao).: ");
    scanf("%d", &resp);
    getchar(); // Limpa o buffer

    if (resp == 1) {
        p = (TipoApontador)malloc(sizeof(TipoItem));
        if (p == NULL) {
            gotoxy(07, 23);
            printf("Erro ao alocar memoria!");
            getch();
            return;
        }

        // Inicializa os campos do cliente com strings vazias
        p->conteudo.cd_cliente = nova_conta.codigo_conta; // Usa o mesmo código da conta
        strcpy(p->conteudo.nm_cliente, "");
        strcpy(p->conteudo.ds_endereco, "");
        p->conteudo.nr_numero = 0;
        strcpy(p->conteudo.nr_documento, "");
        strcpy(p->conteudo.ds_cidade, "");
        strcpy(p->conteudo.cd_uf, "");
        strcpy(p->conteudo.dt_cadastro, "");
        strcpy(p->conteudo.nr_telefone, "");
        
        // Atribui a conta bancária
        p->conteudo.conta_bancaria = nova_conta;
        p->proximo = NULL;

        // Se a lista estiver vazia
        if (L->Primeiro == NULL) {
            L->Primeiro = p;
            L->Ultimo = p;
        } else {
            L->Ultimo->proximo = p;
            L->Ultimo = p;
        }

        gotoxy(07, 23);
        printf("Conta bancaria cadastrada com sucesso!");
        getch();
    } else {
        gotoxy(07, 23);
        printf("Cadastro cancelado.");
        getch();
    }
}
