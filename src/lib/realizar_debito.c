/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para a realização de débito de uma conta
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void realizar_debito(TipoLista *L, TipoListaMov *M) {
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
    printf("REALIZAR DEBITO");
    
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
    
    // Solicita o valor do débito
    gotoxy(8, 15);
    printf("Digite o valor do debito: R$ ");
    scanf("%lf", &valor);
    getchar(); // Limpa o buffer
    
    // Verifica se o valor é válido
    if (valor <= 0) {
        gotoxy(8, 23);
        printf("Valor invalido!");
        getch();
        return;
    }

    // Verifica se há saldo suficiente (considerando o limite)
    double saldo_disponivel = conta->conteudo.vl_saldo + conta->conteudo.vl_limite;
    if (valor > saldo_disponivel) {
        gotoxy(8, 23);
        printf("Saldo e limite insuficientes!");
        getch();
        return;
    }

    // Calcula quanto será debitado do saldo e quanto do limite
    double valor_do_saldo = 0;
    double valor_do_limite = 0;

    if (valor <= conta->conteudo.vl_saldo) {
        // Se tem saldo suficiente, debita apenas do saldo
        valor_do_saldo = valor;
    } else {
        // Se não tem saldo suficiente, usa todo o saldo disponível e o restante do limite
        valor_do_saldo = conta->conteudo.vl_saldo;
        valor_do_limite = valor - valor_do_saldo;
    }
    
    // Solicita a descrição da operação
    gotoxy(8, 17);
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
    strcpy(novo->conteudo.tipo_movimentacao, "DEBITO");
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
    
// Atualiza o saldo e limite da conta
    conta->conteudo.vl_saldo -= valor_do_saldo;
    conta->conteudo.vl_limite -= valor_do_limite;
    
    // Atualiza o status da conta para ativa
    strcpy(conta->conteudo.status, "ATIVA");
    
    // Salva as alterações imediatamente
    Salvar(L);
    salvar_movimentacoes(M);

    gotoxy(8, 23);
    printf("Debito realizado com sucesso!");
    getch();
}
