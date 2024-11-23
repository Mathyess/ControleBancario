#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void obter_data_hora(char *data, char *hora) {
    time_t t = time(NULL);
    struct tm *tm = localtime(&t);
    
    sprintf(data, "%02d/%02d/%04d", tm->tm_mday, tm->tm_mon + 1, tm->tm_year + 1900);
    sprintf(hora, "%02d:%02d:%02d", tm->tm_hour, tm->tm_min, tm->tm_sec);
}

void realizar_debito(TipoLista *L, TipoListaMov *M) {
    int codigo_conta;
    double valor;
    char descricao[100];
    char data[11], hora[9];
    TipoApontador conta;
    
    tela();
    gotoxy(20, 03);
    printf("REALIZAR DEBITO");
    
    // Solicita e valida o código da conta
    gotoxy(8, 8);
    printf("Digite o codigo da conta: ");
    scanf("%d", &codigo_conta);
    getchar(); // Limpa o buffer
    
    conta = pesquisa(L, codigo_conta);
    if (conta == NULL) {
        gotoxy(8, 23);
        printf("Conta nao encontrada!");
        getch();
        return;
    }
    
    // Mostra os dados da conta
    mostra_conta_bancaria(conta->conteudo.conta_bancaria);
    
    // Solicita o valor do débito
    gotoxy(8, 15);
    printf("Digite o valor do debito: R$ ");
    scanf("%lf", &valor);
    getchar(); // Limpa o buffer
    
    // Verifica se há saldo suficiente (considerando o limite)
    double saldo_disponivel = conta->conteudo.conta_bancaria.vl_saldo + conta->conteudo.conta_bancaria.vl_limite;
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
    
    // Atualiza o saldo da conta
    conta->conteudo.conta_bancaria.vl_saldo -= valor;
    
    gotoxy(8, 23);
    printf("Debito realizado com sucesso!");
    getch();
}
