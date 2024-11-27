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
    double valor_do_saldo = 0;
    double valor_do_limite = 0;
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
    
    // Mostra os dados da conta de origem
    mostra_conta_bancaria(conta_origem->conteudo);
    
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
    
    // Mostra os dados da conta de destino
    gotoxy(50, 12);
    printf("Banco: %s", conta_destino->conteudo.banco);
    gotoxy(50, 13);
    printf("Agencia: %s", conta_destino->conteudo.agencia);
    gotoxy(50, 14);
    printf("Conta: %s", conta_destino->conteudo.numero_conta);
    
// Pergunta se quer usar crédito ou débito
    gotoxy(8, 16);
    printf("Usar credito ou debito? (C/D): ");
    char opcao;
    scanf(" %c", &opcao);
    getchar(); // Limpa o buffer

    // Solicita o valor da transferência
    gotoxy(8, 19);
    printf("Digite o valor da transferencia: R$ ");
    scanf("%lf", &valor);
    getchar(); // Limpa o buffer
    
    if (valor <= 0) {
        gotoxy(8, 23);
        printf("Valor invalido!");
        getch();
        return;
    }

// Verifica disponibilidade baseado na opção escolhida
    if (opcao == 'C' || opcao == 'c') {
        // Verifica se tem limite de crédito
        if (conta_origem->conteudo.vl_limite <= 0) {
            gotoxy(8, 23);
            printf("Conta sem limite de credito disponivel!");
            getch();
            return;
        }

        // Verifica se tem limite suficiente
        if (valor > conta_origem->conteudo.vl_limite) {
            gotoxy(8, 23);
            printf("Limite de credito insuficiente!");
            getch();
            return;
        }

        // Usa apenas o limite
        valor_do_saldo = 0;
        valor_do_limite = valor;
    } else {
        // Verifica se tem saldo suficiente
        if (valor > conta_origem->conteudo.vl_saldo) {
            gotoxy(8, 23);
            printf("Saldo insuficiente para debito!");
            getch();
            return;
        }

        // Usa apenas o saldo
        valor_do_saldo = valor;
        valor_do_limite = 0;
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
    
    // Atualiza o saldo e limite da conta origem
    conta_origem->conteudo.vl_saldo -= valor_do_saldo;
    conta_origem->conteudo.vl_limite -= valor_do_limite;

    // Verifica se há limite de crédito a ser restaurado na conta destino
    double limite_usado = conta_destino->conteudo.vl_limite;
    if (limite_usado < 0) {  // Se há limite usado (valor negativo)
        double valor_para_limite = valor;
        if (-limite_usado < valor) {  // Se o valor é maior que o limite usado
            valor_para_limite = -limite_usado;  // Restaura apenas o necessário
            // O restante vai para o saldo
            conta_destino->conteudo.vl_saldo += (valor - valor_para_limite);
        }
        // Restaura o limite
        conta_destino->conteudo.vl_limite += valor_para_limite;
    } else {
        // Se não há limite usado, todo o valor vai para o saldo
        conta_destino->conteudo.vl_saldo += valor;
    }
    
    // Atualiza o status das contas para ativa
    strcpy(conta_origem->conteudo.status, "ATIVA");
    strcpy(conta_destino->conteudo.status, "ATIVA");
    
    // Salva as alterações imediatamente
    Salvar(L);
    salvar_movimentacoes(M);

    gotoxy(8, 23);
    printf("Transferencia realizada com sucesso!");
    getch();
}
