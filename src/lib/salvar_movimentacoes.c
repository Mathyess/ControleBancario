/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para salvar as movimentações em um arquivo .dat
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void salvar_movimentacoes(TipoListaMov *M) {
    FILE *arquivo;
    TipoApontadorMov p;
    long registros_salvos = 0;
    size_t tamanho;
    
    if (M == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    arquivo = fopen("Movimentacoes.dat", "wb");
    if (arquivo == NULL) {
        printf("Erro ao abrir arquivo para gravacao!\n");
        getch();
        return;
    }

    // Grava cada movimentação no arquivo
    p = M->Primeiro;
    while (p != NULL) {
        if (fwrite(&p->conteudo, sizeof(movimentacao_bancaria), 1, arquivo) != 1) {
            printf("Erro ao gravar movimentacao!\n");
            getch();
            fclose(arquivo);
            return;
        }
        registros_salvos++;
        p = p->proximo;
    }

    // Verifica se o arquivo foi gravado corretamente
    tamanho = ftell(arquivo);
    if ((size_t)tamanho != (size_t)(registros_salvos * sizeof(movimentacao_bancaria))) {
        printf("Erro: Arquivo gravado com tamanho incorreto!\n");
        getch();
        fclose(arquivo);
        return;
    }

    fclose(arquivo);
}

void carregar_movimentacoes(TipoListaMov *M) {
    FILE *arquivo;
    movimentacao_bancaria mov;
    TipoApontadorMov novo;
    long registros_lidos = 0;
    size_t tamanho;
    
    if (M == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    arquivo = fopen("Movimentacoes.dat", "rb");
    if (arquivo == NULL) {
        // Arquivo não existe ainda, não é um erro
        return;
    }

    // Obtém o tamanho do arquivo
    fseek(arquivo, 0, SEEK_END);
    tamanho = ftell(arquivo);
    fseek(arquivo, 0, SEEK_SET);

    // Lê cada movimentação do arquivo
    while (fread(&mov, sizeof(movimentacao_bancaria), 1, arquivo) == 1) {
        novo = (TipoApontadorMov)malloc(sizeof(TipoItemMov));
        if (novo == NULL) {
            printf("Erro ao alocar memoria!\n");
            getch();
            fclose(arquivo);
            return;
        }

        novo->conteudo = mov;
        novo->proximo = NULL;

        if (M->Primeiro == NULL) {
            M->Primeiro = novo;
            M->Ultimo = novo;
        } else {
            M->Ultimo->proximo = novo;
            M->Ultimo = novo;
        }

        registros_lidos++;
    }

    // Verifica se o arquivo foi lido corretamente
    if ((size_t)tamanho != (size_t)(registros_lidos * sizeof(movimentacao_bancaria))) {
        printf("Erro: Arquivo lido com tamanho incorreto!\n");
        getch();
        fclose(arquivo);
        return;
    }

    fclose(arquivo);
}
