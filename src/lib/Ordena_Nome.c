/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void ordena_nome(TipoLista *L)
{
    int i, j, qtde, result;
    TipoApontador aux1, aux2;
    reg_cliente temp;  // Corrigido para usar a estrutura reg_cliente

    qtde = conta_elementos(L);  // Conta o número de elementos na lista
    aux1 = L->Primeiro;

    // Ordenação por nome do cliente (nm_cliente)
    for (i = 0; i < qtde - 1; i++) // Alterei o i para começar de 0
    {
        aux2 = aux1->proximo;  // Inicia a comparação com o próximo item
        for (j = i + 1; j < qtde; j++)  // Corrigido o loop interno
        {
            result = strcmp(aux1->conteudo.nm_cliente, aux2->conteudo.nm_cliente); // Compara os nomes
            if (result > 0)  // Se o nome de aux1 for maior que aux2, troca
            {
                temp = aux1->conteudo; // Armazena dados de aux1
                aux1->conteudo = aux2->conteudo; // Troca aux1 com aux2
                aux2->conteudo = temp; // Troca aux2 com aux1
            }
            aux2 = aux2->proximo;  // Avança para o próximo nó
        }
        aux1 = aux1->proximo;  // Avança para o próximo nó
    }
}
