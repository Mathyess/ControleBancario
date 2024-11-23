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

// Função para alterar os dados de uma conta
void altera_conta(TipoLista *L) {
    TipoApontador p;
    conta_bancaria reg_conta;
    int codigo, qtde, campo, resp;
    char buffer[100];

    // Verifica se a lista está vazia
    p = L->Primeiro;
    if (p == NULL) {
        tela(); // Limpa a tela
        gotoxy(8, 23);
        printf("LISTA VAZIA...");
        getch();
        return;
    }

    // Solicita o código do cliente até encontrar um válido
    do {
        tela(); // Limpa a tela
        tela_conta_bancaria(); // Exibe o cabeçalho da tela de conta bancária
        gotoxy(25, 3);
        printf("ALTERACAO DADOS DA CONTA");
        gotoxy(60, 3);
        qtde = conta_elementos(L); // Obtém a quantidade de clientes
        printf("Total Contas.: %d", qtde);
        gotoxy(30, 5);
        printf("Digite o código da conta: ");
        codigo = ler_inteiro(); // Usa a função para ler de forma segura
        p = pesquisa(L, codigo); // Pesquisa o cliente pela chave
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Conta Nao Cadastrada..");
            getch();
        }
    } while (p == NULL); // Continua até encontrar o cliente

    // Mostra os dados da conta bancária
    mostra_conta_bancaria(p->conteudo.conta_bancaria);
    reg_conta = p->conteudo.conta_bancaria; // Salva a conta bancária em uma variável temporária

    // Permite a alteração dos dados da conta
    do {
        gotoxy(7, 23);
        printf("                                                                ");
        gotoxy(7, 23);
        printf("Digite o Campo da Conta a ser Alterado (0=Sair): ");
        campo = ler_inteiro();

        // Valida o campo selecionado
        if (campo < 0 || campo > 7) {
            gotoxy(7, 23);
            printf("Campo inválido..");
            getch();
            continue;
        }

        if (campo != 0) {
            gotoxy(7, 23);
            printf("                                                                ");
            gotoxy(7, 23);
            printf("Digite o novo valor: ");
        }

        // Processa as alterações de acordo com o campo selecionado
        switch (campo) {
            case 1:
                fgets(buffer, sizeof(buffer), stdin); // Limpa o buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(reg_conta.banco, buffer);
                break;
            case 2:
                fgets(buffer, sizeof(buffer), stdin); // Limpa o buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(reg_conta.agencia, buffer);
                break;
            case 3:
                fgets(buffer, sizeof(buffer), stdin); // Limpa o buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(reg_conta.numero_conta, buffer);
                break;
            case 4:
                fgets(buffer, sizeof(buffer), stdin); // Limpa o buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(reg_conta.tipo_conta, buffer);
                break;
            case 5:
                reg_conta.vl_saldo = ler_inteiro();
                break;
            case 6:
                reg_conta.vl_limite = ler_inteiro();
                break;
            case 7:
                fgets(buffer, sizeof(buffer), stdin); // Limpa o buffer
                fgets(buffer, sizeof(buffer), stdin);
                buffer[strcspn(buffer, "\n")] = 0;
                strcpy(reg_conta.status, buffer);
                break;
            default:
                break;
        }

        if (campo != 0) {
            // Atualiza a exibição após cada alteração
            mostra_conta_bancaria(reg_conta);
        }
    } while (campo != 0); // Continua até o campo 0 ser selecionado

    // Confirmação da alteração
    gotoxy(7, 23);
    printf("                                                                ");
    gotoxy(7, 23);
    printf("Confirma a Alteração dos Dados (1-Sim; 2-Nao): ");
    resp = ler_inteiro();

    if (resp == 1) {
        p->conteudo.conta_bancaria = reg_conta; // Atualiza os dados da conta bancária na lista
        gotoxy(7, 23);
        printf("                                                                ");
        gotoxy(7, 23);
        printf("Dados alterados com sucesso!");
        getch();
    } else {
        gotoxy(7, 23);
        printf("                                                                ");
        gotoxy(7, 23);
        printf("Alteração cancelada.");
        getch();
    }
}
