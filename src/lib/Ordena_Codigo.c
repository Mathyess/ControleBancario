#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void ordena_codigo(TipoLista *L)
{
    int i;
    int j;
    int qtde;
    reg_cliente reg;
    TipoApontador aux1;
    TipoApontador aux2;

    qtde = conta_elementos(L); // Conta o número de elementos na lista
    aux1 = L->Primeiro; // Começa do primeiro item da lista
    aux2 = aux1->proximo; // Começa do segundo item

    for (i = 1; i <= qtde - 1; i++) // Laço externo para percorrer a lista
    {
        for (j = i + 1; j <= qtde; j++) // Laço interno para comparar os itens
        {
            if (aux1->conteudo.conta_bancaria.codigo_conta > aux2->conteudo.conta_bancaria.codigo_conta) // Se o código da conta for maior
            {
                reg = aux1->conteudo; // Armazena o valor de aux1
                aux1->conteudo = aux2->conteudo; // Troca os dados de aux1 com aux2
                aux2->conteudo = reg; // Troca os dados de aux2 com os de aux1
            }
            aux2 = aux2->proximo; // Avança para o próximo elemento
        }
        aux1 = aux1->proximo; // Avança para o próximo item
        if (aux1->proximo != NULL) {
            aux2 = aux1->proximo; // Ajusta aux2 para o próximo do novo aux1
        }
    }
}
