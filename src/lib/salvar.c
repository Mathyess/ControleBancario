#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Função para carregar os dados das contas bancárias de um arquivo
void carregar(TipoLista *L) {
    FILE *ptr = fopen("Contas.dat", "rb");  // Abre o arquivo no modo binário para leitura
    conta_bancaria reg_conta;  // Usando a estrutura correta para contas bancárias
    if (ptr == NULL) {
        return;  // Se o arquivo não existe, retorna
    }

    // Loop para ler as contas bancárias do arquivo
    while (fread(&reg_conta, sizeof(reg_conta), 1, ptr)) {
        TipoApontador novo = (TipoApontador)malloc(sizeof(TipoItem));  // Aloca um novo item para a lista
        if (novo == NULL) {
            fclose(ptr);
            return;  // Se não conseguir alocar memória, encerra
        }

        novo->conteudo.conta_bancaria = reg_conta;  // Copia o conteúdo da conta bancária para o novo item
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
    FILE *ptr = fopen("Contas.dat", "wb");  // Abre o arquivo no modo binário para escrita

    if (ptr == NULL) {
        return;  // Se o arquivo não foi aberto corretamente, retorna
    }

    TipoApontador atual = L->Primeiro;
    while (atual != NULL) {
        // Escreve os dados da conta bancária no arquivo
        fwrite(&(atual->conteudo.conta_bancaria), sizeof(conta_bancaria), 1, ptr);
        atual = atual->proximo;  // Vai para o próximo item na lista
    }

    fclose(ptr);  // Fecha o arquivo
}
