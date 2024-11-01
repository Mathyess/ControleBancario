#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>

void carregar(TipoLista *L) {
    FILE *ptr = fopen("Clientes.dat", "rb");
    reg_cliente reg_clie;
    if (ptr == NULL) {
        return; 
    }

    while (fread(&reg_clie, sizeof(reg_clie), 1, ptr)) { 
        TipoApontador novo = (TipoApontador)malloc(sizeof(TipoItem));
        if (novo == NULL) {
            fclose(ptr);
            return; 
        }
        novo->conteudo = reg_clie;
        novo->proximo = NULL;

        if (L->Primeiro == NULL) {
            L->Primeiro = novo;
            L->Ultimo = novo;
        } else {
            L->Ultimo->proximo = novo;
            L->Ultimo = novo;
        }
    }

    fclose(ptr);
}

// Grava informações da lista simplesmente encadeada em um arquivo em disco
void Salvar(TipoLista *L) {
    FILE *ptr = fopen("Clientes.dat", "wb");

    if (ptr == NULL) {
        return;
    }
    
    TipoApontador atual = L->Primeiro;
    while (atual != NULL) {
        fwrite(&(atual->conteudo), sizeof(reg_cliente), 1, ptr);
        atual = atual->proximo;
    }
    
    fclose(ptr);
}