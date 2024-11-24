/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void altera_cliente(TipoLista *L) {
    TipoApontador p;
    int codigo, qtde, campo, resp;
    reg_cliente cliente_temp;

    if (L == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    // Verifica se a lista está vazia
    p = L->Primeiro;
    if (p == NULL) {
        tela();
        SetCor(9, 0); // Define azul claro para toda a interface
        gotoxy(8, 23);
        printf("LISTA VAZIA...");
        getch();
        return;
    }

    // Solicita o código do cliente até encontrar um válido
    do {
        tela();
        tela_clie();
        SetCor(9, 0); // Define azul claro para toda a interface
        gotoxy(25, 3);
        printf("ALTERACAO DADOS DO CLIENTE");
        gotoxy(60, 3);
        qtde = conta_elementos(L);
        printf("Total Clientes.: %d", qtde);
        gotoxy(30, 5);
        printf("Digite o codigo do cliente: ");
        codigo = ler_inteiro();
        
        p = pesquisa(L, codigo);
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Cliente Nao Cadastrado..");
            getch();
        }
    } while (p == NULL);

    // Cria uma cópia temporária dos dados do cliente
    cliente_temp = p->conteudo;

    // Mostra os dados atuais do cliente
    mostra_cliente(cliente_temp);

    // Menu de campos para alteração
    do {
        gotoxy(7, 23);
        printf("                                               ");
        gotoxy(7, 23);
        printf("Digite o Campo a ser Alterado (0=Sair): ");
        campo = ler_inteiro();

        switch (campo) {
            case 1:
                gotoxy(30, 7);
                printf("                              ");
                gotoxy(30, 7);
                printf("Novo nome: ");
                fgets(cliente_temp.nm_cliente, sizeof(cliente_temp.nm_cliente), stdin);
                cliente_temp.nm_cliente[strcspn(cliente_temp.nm_cliente, "\n")] = 0;
                break;
            case 2:
                gotoxy(30, 9);
                printf("                              ");
                gotoxy(30, 9);
                printf("Novo endereco: ");
                fgets(cliente_temp.ds_endereco, sizeof(cliente_temp.ds_endereco), stdin);
                cliente_temp.ds_endereco[strcspn(cliente_temp.ds_endereco, "\n")] = 0;
                break;
            case 3:
                gotoxy(30, 11);
                printf("                              ");
                gotoxy(30, 11);
                printf("Novo numero: ");
                cliente_temp.nr_numero = ler_inteiro();
                break;
            case 4:
                gotoxy(30, 13);
                printf("                              ");
                gotoxy(30, 13);
                printf("Novo documento: ");
                fgets(cliente_temp.nr_documento, sizeof(cliente_temp.nr_documento), stdin);
                cliente_temp.nr_documento[strcspn(cliente_temp.nr_documento, "\n")] = 0;
                break;
            case 5:
                gotoxy(30, 15);
                printf("                              ");
                gotoxy(30, 15);
                printf("Nova cidade: ");
                fgets(cliente_temp.ds_cidade, sizeof(cliente_temp.ds_cidade), stdin);
                cliente_temp.ds_cidade[strcspn(cliente_temp.ds_cidade, "\n")] = 0;
                break;
            case 6:
                gotoxy(30, 17);
                printf("                              ");
                gotoxy(30, 17);
                printf("Nova UF: ");
                fgets(cliente_temp.cd_uf, sizeof(cliente_temp.cd_uf), stdin);
                cliente_temp.cd_uf[strcspn(cliente_temp.cd_uf, "\n")] = 0;
                break;
            case 7:
                gotoxy(30, 19);
                printf("                              ");
                gotoxy(30, 19);
                printf("Novo telefone: ");
                fgets(cliente_temp.nr_telefone, sizeof(cliente_temp.nr_telefone), stdin);
                cliente_temp.nr_telefone[strcspn(cliente_temp.nr_telefone, "\n")] = 0;
                break;
            case 0:
                break;
            default:
                gotoxy(7, 23);
                printf("Campo invalido!");
                getch();
                break;
        }

        if (campo != 0) {
            // Atualiza a exibição após cada alteração
            mostra_cliente(cliente_temp);
        }
    } while (campo != 0);

    // Confirmação das alterações
    gotoxy(7, 23);
    printf("Confirma as Alteracoes (1-Sim; 2-Nao): ");
    resp = ler_inteiro();
    
    if (resp == 1) {
        // Atualiza os dados do cliente
        p->conteudo = cliente_temp;
        
        // Salva as alterações imediatamente
        Salvar(L);

        gotoxy(7, 23);
        printf("                                               ");
        gotoxy(7, 23);
        printf("Dados alterados com sucesso!");
    } else {
        gotoxy(7, 23);
        printf("                                               ");
        gotoxy(7, 23);
        printf("Alteracoes canceladas.");
    }
    getch();
}
