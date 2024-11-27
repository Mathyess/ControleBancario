/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para salvar os dados das contas bancárias em um arquivo .dat
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para carregar os dados das contas bancárias de um arquivo
void carregar(TipoLista *L) {
    FILE *ptr = fopen("Contas.dat", "rb");  // Abre o arquivo no modo binário para leitura
    conta_bancaria reg;  // Estrutura da conta bancária
    
    // Inicializa a lista como vazia
    L->Primeiro = NULL;
    L->Ultimo = NULL;

    if (ptr == NULL) {
        // Se o arquivo não existe, cria um novo
        ptr = fopen("Contas.dat", "wb");
        if (ptr == NULL) {
            printf("Erro ao criar arquivo de dados!\n");
            getch();
            return;
        }
        fclose(ptr);
        return;
    }

    // Loop para ler os registros do arquivo
    while (fread(&reg, sizeof(conta_bancaria), 1, ptr) == 1) {
        TipoApontador novo = (TipoApontador)malloc(sizeof(TipoItem));  // Aloca um novo item para a lista
        if (novo == NULL) {
            printf("Erro de alocacao de memoria!\n");
            getch();
            fclose(ptr);
            return;
        }

        novo->conteudo = reg;  // Copia o registro da conta
        novo->proximo = NULL;

        // Se a lista estiver vazia, o novo item será o primeiro e o último
        if (L->Primeiro == NULL) {
            L->Primeiro = novo;
            L->Ultimo = novo;
        } else {
            L->Ultimo->proximo = novo;  // Conecta o novo item ao final da lista
            L->Ultimo = novo;  // Atualiza o último item
        }
    }

    fclose(ptr);  // Fecha o arquivo
}

// Função para salvar as contas bancárias em um arquivo
void Salvar(TipoLista *L) {
    if (L == NULL) {
        printf("Lista invalida!\n");
        getch();
        return;
    }

    FILE *ptr = fopen("Contas.dat", "wb");  // Abre o arquivo no modo binário para escrita
    if (ptr == NULL) {
        printf("Erro ao abrir arquivo para gravacao!\n");
        getch();
        return;
    }

    TipoApontador atual = L->Primeiro;
    size_t registros_escritos = 0;

    while (atual != NULL) {
        // Escreve o registro da conta no arquivo
        if (fwrite(&(atual->conteudo), sizeof(conta_bancaria), 1, ptr) != 1) {
            printf("Erro ao escrever no arquivo!\n");
            getch();
            fclose(ptr);
            return;
        }
        registros_escritos++;
        atual = atual->proximo;
    }

    // Força a gravação do buffer para o disco
    fflush(ptr);
    
    // Fecha o arquivo
    if (fclose(ptr) != 0) {
        printf("Erro ao fechar o arquivo!\n");
        getch();
        return;
    }

    // Verifica se o arquivo foi criado corretamente
    ptr = fopen("Contas.dat", "rb");
    if (ptr == NULL) {
        printf("Erro ao verificar arquivo salvo!\n");
        getch();
        return;
    }
    fclose(ptr);
}
