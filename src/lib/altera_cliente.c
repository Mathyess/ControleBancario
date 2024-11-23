#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void altera_cliente(TipoLista *L) {
    TipoApontador p;
    int codigo, qtde, campo, resp;

    // Verifica se a lista está vazia
    p = L->Primeiro;
    if (p == NULL) {
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA...");
        getch();
        return;
    }

    // Solicita o código do cliente até encontrar um válido
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
        getchar(); // Limpa o buffer
        
        p = pesquisa(L, codigo);
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Cliente Nao Cadastrado..");
            getch();
        }
    } while (p == NULL);

    // Mostra os dados atuais do cliente
    mostra_cliente(p->conteudo);

    // Menu de campos para alteração
    do {
        gotoxy(7, 23);
        printf("                                               ");
        gotoxy(7, 23);
        printf("Digite o Campo a ser Alterado (0=Sair): ");
        scanf("%d", &campo);
        getchar(); // Limpa o buffer

        switch (campo) {
            case 1:
                gotoxy(30, 7);
                printf("                              ");
                gotoxy(30, 7);
                printf("Novo nome: ");
                fgets(p->conteudo.nm_cliente, sizeof(p->conteudo.nm_cliente), stdin);
                p->conteudo.nm_cliente[strcspn(p->conteudo.nm_cliente, "\n")] = 0;
                break;
            case 2:
                gotoxy(30, 9);
                printf("                              ");
                gotoxy(30, 9);
                printf("Novo endereco: ");
                fgets(p->conteudo.ds_endereco, sizeof(p->conteudo.ds_endereco), stdin);
                p->conteudo.ds_endereco[strcspn(p->conteudo.ds_endereco, "\n")] = 0;
                break;
            case 3:
                gotoxy(30, 11);
                printf("                              ");
                gotoxy(30, 11);
                printf("Novo numero: ");
                scanf("%d", &p->conteudo.nr_numero);
                getchar(); // Limpa o buffer
                break;
            case 4:
                gotoxy(30, 13);
                printf("                              ");
                gotoxy(30, 13);
                printf("Novo documento: ");
                fgets(p->conteudo.nr_documento, sizeof(p->conteudo.nr_documento), stdin);
                p->conteudo.nr_documento[strcspn(p->conteudo.nr_documento, "\n")] = 0;
                break;
            case 5:
                gotoxy(30, 15);
                printf("                              ");
                gotoxy(30, 15);
                printf("Nova cidade: ");
                fgets(p->conteudo.ds_cidade, sizeof(p->conteudo.ds_cidade), stdin);
                p->conteudo.ds_cidade[strcspn(p->conteudo.ds_cidade, "\n")] = 0;
                break;
            case 6:
                gotoxy(30, 17);
                printf("                              ");
                gotoxy(30, 17);
                printf("Nova UF: ");
                fgets(p->conteudo.cd_uf, sizeof(p->conteudo.cd_uf), stdin);
                p->conteudo.cd_uf[strcspn(p->conteudo.cd_uf, "\n")] = 0;
                break;
            case 7:
                gotoxy(30, 19);
                printf("                              ");
                gotoxy(30, 19);
                printf("Novo telefone: ");
                fgets(p->conteudo.nr_telefone, sizeof(p->conteudo.nr_telefone), stdin);
                p->conteudo.nr_telefone[strcspn(p->conteudo.nr_telefone, "\n")] = 0;
                break;
            case 0:
                break;
            default:
                gotoxy(7, 23);
                printf("Campo invalido!");
                getch();
                break;
        }
    } while (campo != 0);

    // Confirmação das alterações
    gotoxy(7, 23);
    printf("Confirma as Alteracoes (1-Sim; 2-Nao): ");
    scanf("%d", &resp);
    
    if (resp == 1) {
        gotoxy(7, 23);
        printf("Dados alterados com sucesso!");
    } else {
        gotoxy(7, 23);
        printf("Alteracoes canceladas.");
    }
    getch();
}
