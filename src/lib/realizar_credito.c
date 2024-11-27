/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para a realização de crédito de uma conta
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void realizar_credito(TipoLista *L, TipoListaMov *M) {
    int codigo_conta;
    double valor;
    char descricao[100];
    char data[11], hora[9];
    TipoApontador conta;
    
    if (L == NULL || M == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    tela();  
    gotoxy(20, 3);
    printf("      REALIZAR CREDITO");  
    
    // Solicita e valida o código da conta
    gotoxy(8, 8);
    printf("Digite o codigo da conta: ");
    codigo_conta = ler_inteiro();
    
    conta = pesquisa(L, codigo_conta);
    if (conta == NULL) {
        gotoxy(8, 23);
        printf("Conta nao encontrada!");
        getch();
        return;
    }
    
    // Mostra os dados da conta
    mostra_conta_bancaria(conta->conteudo);
    
    // Solicita o valor do crédito
    gotoxy(8, 19);
    printf("Digite o valor do credito: R$ ");
    scanf("%lf", &valor);
    getchar(); // Limpa o buffer
    
    if (valor <= 0) {
        gotoxy(8, 23);
        printf("Valor invalido!");
        getch();
        return;
    }
    
    // Solicita a descrição da operação
    gotoxy(8, 21);
    printf("Digite a descricao: ");
    fgets(descricao, sizeof(descricao), stdin);
    descricao[strcspn(descricao, "\n")] = 0;
    
    // Obtém a data e hora atual
    obter_data_hora(data, hora);
    
    // Cria o registro da movimentação
    TipoApontadorMov novo = (TipoApontadorMov)malloc(sizeof(TipoItemMov));
    if (novo == NULL) {
        gotoxy(8, 23);
        printf("Erro ao alocar memoria!");
        getch();
        return;
    }
    
    // Preenche os dados da movimentação
    novo->conteudo.codigo_movimentacao = M->Ultimo ? M->Ultimo->conteudo.codigo_movimentacao + 1 : 1;
    novo->conteudo.codigo_conta_origem = codigo_conta;
    novo->conteudo.codigo_conta_destino = 0;
    strcpy(novo->conteudo.tipo_movimentacao, "CREDITO");
    novo->conteudo.valor = valor;
    strcpy(novo->conteudo.data, data);
    strcpy(novo->conteudo.hora, hora);
    strcpy(novo->conteudo.descricao, descricao);
    novo->proximo = NULL;
    
    // Insere a movimentação na lista
    if (M->Primeiro == NULL) {
        M->Primeiro = novo;
        M->Ultimo = novo;
    } else {
        M->Ultimo->proximo = novo;
        M->Ultimo = novo;
    }
    
    // Verifica se a conta tem limite de crédito
    if (conta->conteudo.vl_limite <= 0) {
        gotoxy(8, 23);
        printf("Conta sem limite de credito disponivel!");
        getch();
        return;
    }

    // Verifica se tem limite suficiente
    if (valor > conta->conteudo.vl_limite) {
        gotoxy(8, 23);
        printf("Limite de credito insuficiente!");
        getch();
        return;
    }

    // Usa apenas o limite de crédito
    conta->conteudo.vl_limite -= valor;
    
    // Atualiza o status da conta para ativa
    strcpy(conta->conteudo.status, "ATIVA");
    
    // Salva as alterações imediatamente
    Salvar(L);
    salvar_movimentacoes(M);

    gotoxy(8, 23);
    printf("Credito realizado com sucesso!");
    getch();
}
