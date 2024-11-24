/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024

    Objetivo: Função para alterar uma conta previamente cadastrada.
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para alterar os dados de uma conta
void altera_conta(TipoLista *L) {
    TipoApontador p;
    conta_bancaria reg_conta;
    int codigo, qtde, campo, resp;
    char buffer[100];

    if (L == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

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
        tela_conta_bancaria();

        gotoxy(25, 3);
        printf("ALTERACAO DADOS DA CONTA");
        gotoxy(60, 3);
        qtde = conta_elementos(L);
        printf("Total Contas.: %d", qtde);
        gotoxy(30, 5);
        printf("Digite o codigo da conta: ");
        codigo = ler_inteiro();
        p = pesquisa(L, codigo);
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Conta Nao Cadastrada..");
            getch();
        }
    } while (p == NULL);

    // Mostra os dados do cliente e da conta
    gotoxy(7, 5);
    printf("Cliente: %s", p->conteudo.nm_cliente);
    gotoxy(7, 6);
    printf("Documento: %s", p->conteudo.nr_documento);
    
// Mostra os dados da conta bancária no formulário
    mostra_conta_form(p->conteudo.conta_bancaria);
    reg_conta = p->conteudo.conta_bancaria;

    // Permite a alteração dos dados da conta
    do {
        gotoxy(7, 23);
        printf("                                                                ");
        gotoxy(7, 23);
        printf("Digite o Campo da Conta a ser Alterado (0=Sair): ");
        campo = ler_inteiro();

        if (campo < 0 || campo > 7) {
            gotoxy(7, 23);
            printf("Campo invalido..");
            getch();
            continue;
        }

        if (campo != 0) {
            gotoxy(7, 23);
            printf("                                                                ");
            gotoxy(7, 23);
            printf("Digite o novo valor: ");
        }

        switch (campo) {
            case 1:
                fgets(buffer, sizeof(buffer), stdin);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strncpy(reg_conta.banco, buffer, sizeof(reg_conta.banco) - 1);
                reg_conta.banco[sizeof(reg_conta.banco) - 1] = '\0';
                break;
            case 2:
                fgets(buffer, sizeof(buffer), stdin);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strncpy(reg_conta.agencia, buffer, sizeof(reg_conta.agencia) - 1);
                reg_conta.agencia[sizeof(reg_conta.agencia) - 1] = '\0';
                break;
            case 3:
                fgets(buffer, sizeof(buffer), stdin);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strncpy(reg_conta.numero_conta, buffer, sizeof(reg_conta.numero_conta) - 1);
                reg_conta.numero_conta[sizeof(reg_conta.numero_conta) - 1] = '\0';
                break;
            case 4:
                fgets(buffer, sizeof(buffer), stdin);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strncpy(reg_conta.tipo_conta, buffer, sizeof(reg_conta.tipo_conta) - 1);
                reg_conta.tipo_conta[sizeof(reg_conta.tipo_conta) - 1] = '\0';
                break;
            case 5:
                reg_conta.vl_saldo = ler_inteiro();
                break;
            case 6:
                reg_conta.vl_limite = ler_inteiro();
                break;
            case 7:
                fgets(buffer, sizeof(buffer), stdin);
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strncpy(reg_conta.status, buffer, sizeof(reg_conta.status) - 1);
                reg_conta.status[sizeof(reg_conta.status) - 1] = '\0';
                break;
            default:
                break;
        }

        if (campo != 0) {
// Atualiza a exibição após cada alteração
            mostra_conta_form(reg_conta);
        }
    } while (campo != 0);

    // Confirmação da alteração
    gotoxy(7, 23);
    printf("                                                                ");
    gotoxy(7, 23);
    printf("Confirma a Alteracao dos Dados (1-Sim; 2-Nao): ");
    resp = ler_inteiro();

    if (resp == 1) {
        p->conteudo.conta_bancaria = reg_conta;
        
        // Salva as alterações imediatamente
        Salvar(L);

        gotoxy(7, 23);
        printf("                                                                ");
        gotoxy(7, 23);
        printf("Dados alterados com sucesso!");
        getch();
    } else {
        gotoxy(7, 23);
        printf("                                                                ");
        gotoxy(7, 23);
        printf("Alteracao cancelada.");
        getch();
    }
}
