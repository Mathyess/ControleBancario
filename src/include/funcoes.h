#ifndef FUNCOES_H
#define FUNCOES_H

typedef struct _conta_bancaria {
    int codigo_conta;
    char banco[50];
    char agencia[10];
    char numero_conta[20];
    char tipo_conta[20];
    double vl_saldo;
    double vl_limite;
    char status[10];
} conta_bancaria;

typedef struct _conta_trans {
    int sequencial;
    int codigo_conta;
    char data_movimento[11];
    char tp_movimentacao[15];
    double vl_movimento;
    double vl_saldo;
} conta_trans;

typedef struct
{
    int cd_cliente;
    char nm_cliente[50];
    char ds_endereco[50];
    int nr_numero;
    char nr_documento[20];
    char ds_cidade[50];
    char cd_uf[05];
    char dt_cadastro[19];
    char nr_telefone[15];
} reg_cliente;

typedef struct TipoItem *TipoApontador;

typedef struct TipoItem
{
    reg_cliente conteudo;
    TipoApontador proximo;
} TipoItem;

typedef struct
{
    TipoApontador Primeiro;
    TipoApontador Ultimo;
} TipoLista;


void tela_clie();
void limpa_tela();
void ordena_codigo();
void ordena_nome();
void leitura();
void mostra_cliente();
void cadastrar();
void consultar_cliente();
void consultar();
void cad_inicio();
void cad_posicao();
void remove_final();
void remove_posicao();
void remove_inicio();
void consulta_todos();
void altera_cliente();
void menu_consultar();
void tela();
void gotoxy();
void carregar();
void Salvar();
void menu_contas_bancarias();
TipoApontador pesquisa();
int conta_elementos();
char *le_nm_nome();
char *le_ds_endereco();
char* le_nr_documento();
int le_nr_numero();
char *le_ds_cidade();
char *le_cd_uf();
char *le_dt_cadastro();
char *le_nr_telefone();
void menu_inicial();

#endif // FUNCOES_H
