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

// Função para cadastrar conta bancária no início da lista
void cad_inicio(TipoLista *L) {
    int resp;
    TipoApontador p;
    TipoApontador aux1;
    reg_cliente novo_cliente;
    conta_bancaria nova_conta;

    if (L == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    // Exibe a tela de conta bancária
    tela_conta_bancaria();
    SetCor(9, 0); // Define azul claro para toda a interface
    gotoxy(20, 3);
    printf("CADASTRAR CONTA BANCARIA NO INICIO");

    // Laço para verificar se o código da conta já foi cadastrado
    do {
        gotoxy(30, 5);
        printf("           "); // Limpa o campo de entrada
        gotoxy(7, 23);
        printf("Digite o codigo da conta: ");
        scanf("%d", &nova_conta.codigo_conta);
        getchar(); // Limpa o buffer

        // Pesquisa a conta na lista
        aux1 = verificar_codigo_conta(L, nova_conta.codigo_conta);
        if (aux1 != NULL) {
            gotoxy(7, 23);
            printf("                                            ");
            gotoxy(7, 23);
            printf("Erro: O codigo %d ja esta cadastrado.", nova_conta.codigo_conta);
            getch();
            gotoxy(7, 23);
            printf("                                            ");
        }
    } while (aux1 != NULL);

    // Leitura dos dados da conta
    ler_dados_conta(&nova_conta);

    // Leitura dos dados do cliente
    system("cls");
    ler_dados_cliente(&novo_cliente);

    // Confirmação para gravar os dados
    gotoxy(7, 23);
    printf("Deseja gravar os dados (1-Sim; 2-Nao).: ");
    scanf("%d", &resp);
    getchar(); // Limpa o buffer

    if (resp == 1) {
        // Criação de um novo nó e inserção no início da lista
        p = (TipoApontador)malloc(sizeof(TipoItem));
        if (p == NULL) {
            gotoxy(7, 23);
            printf("Erro ao alocar memoria!");
            getch();
            return;
        }
        
        // Atribui os dados do cliente
        novo_cliente.cd_cliente = nova_conta.codigo_conta;
        novo_cliente.conta_bancaria = nova_conta;
        obter_data_atual(novo_cliente.dt_cadastro);

        // Atualiza a lista com o novo nó
        p->conteudo = novo_cliente;
        p->proximo = L->Primeiro;
        L->Primeiro = p;
        if (L->Ultimo == NULL) {
            L->Ultimo = L->Primeiro;
        }

        // Salva imediatamente após cadastrar
        Salvar(L);

        // Exibe mensagem de sucesso
        gotoxy(7, 23);
        printf("Conta bancaria e cliente cadastrados com sucesso!");
        getch();
    } else {
        // Caso o usuário não queira gravar os dados
        gotoxy(7, 23);
        printf("Cadastro cancelado.");
        getch();
    }
}
