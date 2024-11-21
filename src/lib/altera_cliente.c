#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void altera_cliente(TipoLista *L) {
    TipoApontador p;
    reg_cliente reg_clie;
    int codigo, qtde, campo, resp;

    p = L->Primeiro;
    if (p == NULL) {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA...");
        getch();
        return;
    }

    do {
        tela();
        tela_clie();
        gotoxy(25, 3);
        printf("ALTERACAO DADOS DO CLIENTE");
        gotoxy(60, 3);
        qtde = conta_elementos(L);
        printf("Total Clientes.: %d", qtde);
        gotoxy(30, 5);
        printf("Digite o código do cliente: ");
        scanf("%d", &codigo);
        getchar();
        p = pesquisa(L, codigo);
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Cliente Nao Cadastrado..");
            getch();
        }
    } while (p == NULL);

    // Mostra registro do Cliente
    mostra_cliente(p->conteudo);
    reg_clie = p->conteudo;

    do {
        gotoxy(7, 23);
        printf("                                               ");
        gotoxy(7, 23);
        printf("Digite o Campo a ser Alterado (0=Sair).: ");
        scanf("%d", &campo);
        getchar();

        if (campo < 0 || campo > 8) {
            gotoxy(7, 23);
            printf("Campo inválido..");
            getch();
            continue;
        }

        switch (campo) {
            case 1:
                strcpy(reg_clie.nm_cliente, le_nm_nome());
                break;
            case 2:
                strcpy(reg_clie.ds_endereco, le_ds_endereco());
                break;
            case 3:
                reg_clie.nr_numero = le_nr_numero();
                break;
            case 4:
                strcpy(reg_clie.nr_documento, le_nr_documento());
                break;
            case 5:
                strcpy(reg_clie.ds_cidade, le_ds_cidade());
                break;
            case 6:
                strcpy(reg_clie.cd_uf, le_cd_uf());
                break;
            case 7:
                strcpy(reg_clie.dt_cadastro, le_dt_cadastro());
                break;
            case 8:
                strcpy(reg_clie.nr_telefone, le_nr_telefone());
                break;
            default:
                break;
        }
    } while (campo != 0);

    gotoxy(7, 23);
    printf("Confirma a Alteração dos Dados (1-Sim;2-Não): ");
    scanf("%d", &resp);
    getchar();

    if (resp == 1) {
        p->conteudo = reg_clie;
        gotoxy(7, 23);
        printf("Dados alterados com sucesso!");
        getch();
    }
}
