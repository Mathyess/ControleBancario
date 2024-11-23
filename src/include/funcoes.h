/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    
    Objetivo: Header principal do sistema bancário.
    Este arquivo define:
    - Estruturas de dados principais
    - Protótipos de todas as funções
    - Tipos de dados personalizados
    
    Estruturas principais:
    - conta_bancaria: Armazena dados da conta (código, banco, agência, etc.)
    - reg_cliente: Armazena dados do cliente e sua conta bancária
    - movimentacao_bancaria: Registra operações financeiras
    
    Tipos de Lista:
    - Lista Simplesmente Encadeada: Para contas bancárias
    - Lista Duplamente Encadeada: Para movimentações financeiras
    
    O sistema implementa operações CRUD completas para contas e
    movimentações, além de relatórios e consultas especializadas.
*/

#ifndef FUNCOES_H
#define FUNCOES_H

// Estruturas para Conta Bancária e Cliente
typedef struct {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
} conta_bancaria;

typedef struct {
    int cd_cliente;
    char nm_cliente[100];
    char ds_endereco[200];
    int nr_numero;
    char nr_documento[20];
    char ds_cidade[100];
    char cd_uf[3];
    char dt_cadastro[11];
    char nr_telefone[20];
    conta_bancaria conta_bancaria;
} reg_cliente;

// Estrutura para Movimentações Bancárias
typedef struct {
    int codigo_movimentacao;
    int codigo_conta_origem;
    int codigo_conta_destino;  // Para transferências
    char tipo_movimentacao[20];  // "DEBITO", "CREDITO", "TRANSFERENCIA"
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
    reg_cliente conteudo;
    TipoApontador proximo;
} TipoItem;

typedef struct {
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;

// Funções de interface
void tela();
void tela_clie();
void tela_conta_bancaria();
void tela_movimentacao();
void limpa_tela();
void gotoxy(int x, int y);
void SetCor(int corTexto, int corFundo);

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
void consultar_cliente(TipoLista *L);
void consulta_todos(TipoLista *L, char msg[40]);
void mostra_cliente(reg_cliente cliente);
void mostra_conta_bancaria(conta_bancaria conta);

// Funções de alteração
void altera_cliente(TipoLista *L);
void altera_conta(TipoLista *L);

// Funções de menu
void menu_inicial();
void menu_contas_bancarias();
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
void leitura(reg_cliente *reg_clie);
char *le_nm_nome();
char *le_ds_endereco();
int le_nr_numero();
char *le_nr_documento();
char *le_ds_cidade();
char *le_cd_uf();
char *le_dt_cadastro();
char *le_nr_telefone();

// Funções auxiliares
int ler_inteiro();
void pausa();
void obter_data_hora(char *data, char *hora);

// Funções de persistência
void carregar(TipoLista *L);
void Salvar(TipoLista *L);

#endif // FUNCOES_H
