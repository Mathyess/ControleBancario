/*  Autor.....: Matheus Alende
    Data......: 30/10/2024
    Equipe....: RA membro 1 168649-2024
                RA membro 2 179381-2024
    Objetivo..: Estrutura de dados
*/

#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"

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