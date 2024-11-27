#ifndef FUNCOES_H
#define FUNCOES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <windows.h>
#include <time.h>

// Estrutura para Conta Bancária
typedef struct {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
    char dt_cadastro[11];
} conta_bancaria;

// Estrutura para Movimentações Bancárias
typedef struct {
    int codigo_movimentacao;
    int codigo_conta_origem;
    int codigo_conta_destino;
    char tipo_movimentacao[20];
    double valor;
    char data[11];
    char hora[9];
    char descricao[100];
} movimentacao_bancaria;

typedef struct TipoItemMov *TipoApontadorMov;

typedef struct TipoItemMov {
    movimentacao_bancaria conteudo;
    TipoApontadorMov proximo;
} TipoItemMov;

typedef struct {
    TipoApontadorMov Primeiro;
    TipoApontadorMov Ultimo;
} TipoListaMov;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem {
    conta_bancaria conteudo;
    TipoApontador proximo;
} TipoItem;

typedef struct {
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

// Funções de interface
void tela();
void tela_conta_bancaria();
void tela_movimentacao();
void limpa_tela();
void gotoxy(int x, int y);
void SetCor(int corTexto, int corFundo);
void mostra_conta_form(conta_bancaria conta);

// Funções de manipulação de lista
void cadastrar(TipoLista *L);
void cad_inicio(TipoLista *L);
void cad_posicao(TipoLista *L);
void remove_final(TipoLista *L);
void remove_inicio(TipoLista *L);
void remove_posicao(TipoLista *L);
TipoApontador pesquisa(TipoLista *L, int codigo);
int conta_elementos(TipoLista *L);
TipoApontador verificar_codigo_conta(TipoLista *L, int codigo);

// Funções de ordenação
void ordena_codigo(TipoLista *L);
void ordena_nome(TipoLista *L);

// Funções de consulta
void consulta_todos(TipoLista *L, char msg[40]);
void mostra_conta_bancaria(conta_bancaria conta);
void consultar_conta(TipoLista *L);
void consultar(TipoLista *L);

// Funções de alteração
void altera_conta(TipoLista *L);

// Funções de menu
void menu_inicial(void);
void menu_contas_bancarias(TipoLista *L);
void menu_movimentacoes(TipoLista *L, TipoListaMov *M);
void menu_consultar(TipoLista *L);

// Funções de movimentação bancária
void realizar_debito(TipoLista *L, TipoListaMov *M);
void realizar_credito(TipoLista *L, TipoListaMov *M);
void realizar_transferencia(TipoLista *L, TipoListaMov *M);
void consultar_movimentacoes(TipoListaMov *M);
void consultar_extrato_conta(TipoLista *L, TipoListaMov *M, int codigo_conta);
void salvar_movimentacoes(TipoListaMov *M);
void carregar_movimentacoes(TipoListaMov *M);

// Funções de entrada de dados
void ler_dados_conta(conta_bancaria *conta);
void limpar_buffer();
void ler_string(char *destino, int tamanho);

// Funções auxiliares
int ler_inteiro();
void pausa();
void obter_data_hora(char *data, char *hora);
void obter_data_atual(char *data);

// Funções de persistência
void carregar(TipoLista *L);
void Salvar(TipoLista *L);

#endif // FUNCOES_H
