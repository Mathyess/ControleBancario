#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

// Limpa a tela entre as linhas 7 a 22 e colunas 2 a 79
void limpa_tela() {
    int lin, col;
    for (lin = 7; lin < 22; lin++) {
        for (col = 2; col < 79; col++) {
            gotoxy(col, lin);
            printf(" "); // Substitui o caractere na posição com espaço
        }
    }
}

// Função que pesquisa um cliente pelo código na lista
TipoApontador pesquisa(TipoLista *L, int codigo) {
    if (L == NULL || L->Primeiro == NULL) {
        return NULL;  // Se a lista for NULL ou vazia, retorna NULL
    }

    TipoApontador p = L->Primeiro;  // Começa do início da lista
    while (p != NULL) {  // Percorre a lista
        if (p->conteudo.cd_cliente == codigo) {  // Se o código do cliente for igual
            return p;  // Retorna o ponteiro para o cliente encontrado
        }
        p = p->proximo;  // Vai para o próximo cliente
    }
    return NULL;  // Se não encontrar o cliente, retorna NULL
}

// Conta quantos Elementos tem na Lista
int conta_elementos(TipoLista *L) {
    if (L == NULL || L->Primeiro == NULL) {
        return 0;  // Retorna 0 se a lista for NULL ou vazia
    }

    int cont = 0; // Inicializa o contador
    TipoApontador aux = L->Primeiro; // Começa do primeiro elemento da lista
    while (aux != NULL) { // Enquanto houver elementos
        cont++; // Incrementa o contador
        aux = aux->proximo; // Avança para o próximo elemento
    }
    return cont; // Retorna o número total de elementos
}
