/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/funcoes.h"

void salvar_movimentacoes(TipoListaMov *M) {
    if (M == NULL) {
        return;
    }

    FILE *arquivo = fopen("Movimentacoes.dat", "wb");
    if (arquivo == NULL) {
        gotoxy(8, 23);
        printf("Erro ao abrir arquivo para salvar movimentacoes!");
        getch();
        return;
    }

    TipoApontadorMov atual = M->Primeiro;
    int registros_salvos = 0;

    while (atual != NULL) {
        // Escreve a movimentação no arquivo
        if (fwrite(&(atual->conteudo), sizeof(movimentacao_bancaria), 1, arquivo) != 1) {
            gotoxy(8, 23);
            printf("Erro ao salvar movimentacao!");
            getch();
            fclose(arquivo);
            return;
        }
        registros_salvos++;
        atual = atual->proximo;
    }

    fclose(arquivo);

    // Verifica se o arquivo foi criado corretamente
    arquivo = fopen("Movimentacoes.dat", "rb");
    if (arquivo != NULL) {
        fseek(arquivo, 0, SEEK_END);
        long tamanho = ftell(arquivo);
        fclose(arquivo);
        
        if (tamanho != (registros_salvos * sizeof(movimentacao_bancaria))) {
            gotoxy(8, 23);
            printf("Erro: Tamanho do arquivo inconsistente!");
            getch();
        }
    }
}

void carregar_movimentacoes(TipoListaMov *M) {
    if (M == NULL) {
        return;
    }

    // Limpa a lista atual
    while (M->Primeiro != NULL) {
        TipoApontadorMov temp = M->Primeiro;
        M->Primeiro = M->Primeiro->proximo;
        free(temp);
    }
    M->Primeiro = NULL;
    M->Ultimo = NULL;

    FILE *arquivo = fopen("Movimentacoes.dat", "rb");
    if (arquivo == NULL) {
        return; // Arquivo não existe ainda, lista permanece vazia
    }

    movimentacao_bancaria mov;
    int registros_lidos = 0;

    // Lê cada movimentação do arquivo
    while (fread(&mov, sizeof(movimentacao_bancaria), 1, arquivo) == 1) {
        TipoApontadorMov novo = (TipoApontadorMov)malloc(sizeof(TipoItemMov));
        if (novo == NULL) {
            gotoxy(8, 23);
            printf("Erro de alocacao de memoria!");
            getch();
            fclose(arquivo);
            return;
        }

        // Copia os dados lidos para o novo nó
        novo->conteudo = mov;
        novo->proximo = NULL;

        // Insere o novo nó na lista
        if (M->Primeiro == NULL) {
            M->Primeiro = novo;
            M->Ultimo = novo;
        } else {
            M->Ultimo->proximo = novo;
            M->Ultimo = novo;
        }
        registros_lidos++;
    }

    fclose(arquivo);

    // Verifica se todos os registros foram lidos corretamente
    FILE *verificacao = fopen("Movimentacoes.dat", "rb");
    if (verificacao != NULL) {
        fseek(verificacao, 0, SEEK_END);
        long tamanho = ftell(verificacao);
        fclose(verificacao);
        
        if (tamanho != (registros_lidos * sizeof(movimentacao_bancaria))) {
            gotoxy(8, 23);
            printf("Aviso: Possivel erro na leitura dos dados!");
            getch();
        }
    }
}
