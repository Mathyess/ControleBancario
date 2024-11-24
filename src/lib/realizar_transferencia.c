/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para realizar transferências entre contas
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void realizar_transferencia(TipoLista *L, TipoListaMov *M) {
    int codigo_origem, codigo_destino;
    double valor;
    char descricao[100];
    char data[11], hora[9];
    TipoApontador conta_origem, conta_destino;
    
    if (L == NULL || M == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    tela();
    gotoxy(20, 3);
    printf("REALIZAR TRANSFERENCIA");
    
    // Solicita e valida a conta de origem
    gotoxy(8, 8);
    printf("Digite o codigo da conta de origem: ");
    codigo_origem = ler_inteiro();
    
    conta_origem = pesquisa(L, codigo_origem);
    if (conta_origem == NULL) {
        gotoxy(8, 23);
        printf("Conta de origem nao encontrada!");
        getch();
        return;
    }
    
    // Mostra os dados do cliente e conta de origem
    gotoxy(8, 10);
    printf("Cliente Origem: %s", conta_origem->conteudo.nm_cliente);
    gotoxy(8, 11);
    printf("Documento: %s", conta_origem->conteudo.nr_documento);
    mostra_conta_bancaria(conta_origem->conteudo.conta_bancaria);
    
    // Solicita e valida a conta de destino
    gotoxy(8, 12);
    printf("Digite o codigo da conta de destino: ");
    codigo_destino = ler_inteiro();
    
    if (codigo_destino == codigo_origem) {
        gotoxy(8, 23);
        printf("Conta de destino nao pode ser igual a de origem!");
        getch();
        return;
    }
    
    conta_destino = pesquisa(L, codigo_destino);
    if (conta_destino == NULL) {
        gotoxy(8, 23);
        printf("Conta de destino nao encontrada!");
        getch();
        return;
    }
    
    // Mostra os dados do cliente e conta de destino
    gotoxy(50, 10);
    printf("Cliente Destino: %s", conta_destino->conteudo.nm_cliente);
    gotoxy(50, 11);
    printf("Documento: %s", conta_destino->conteudo.nr_documento);
    gotoxy(50, 12);
    printf("Banco: %s", conta_destino->conteudo.conta_bancaria.banco);
    gotoxy(50, 13);
    printf("Agencia: %s", conta_destino->conteudo.conta_bancaria.agencia);
    gotoxy(50, 14);
    printf("Conta: %s", conta_destino->conteudo.conta_bancaria.numero_conta);
    
    // Solicita o valor da transferência
    gotoxy(8, 15);
    printf("Digite o valor da transferencia: R$ ");
    scanf("%lf", &valor);
    getchar(); // Limpa o buffer
    
    if (valor <= 0) {
        gotoxy(8, 23);
        printf("Valor invalido!");
        getch();
        return;
    }
    
    // Verifica se há saldo suficiente (considerando o limite)
    double saldo_disponivel = conta_origem->conteudo.conta_bancaria.vl_saldo + conta_origem->conteudo.conta_bancaria.vl_limite;
    if (valor > saldo_disponivel) {
        gotoxy(8, 23);
        printf("Saldo e limite insuficientes!");
        getch();
        return;
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
    novo->conteudo.codigo_conta_origem = codigo_origem;
    novo->conteudo.codigo_conta_destino = codigo_destino;
    strcpy(novo->conteudo.tipo_movimentacao, "TRANSFERENCIA");
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
    
    // Atualiza os saldos das contas
    conta_origem->conteudo.conta_bancaria.vl_saldo -= valor;
    conta_destino->conteudo.conta_bancaria.vl_saldo += valor;
    
    // Salva as alterações imediatamente
    Salvar(L);
    salvar_movimentacoes(M);

    gotoxy(8, 23);
    printf("Transferencia realizada com sucesso!");
    getch();
}
