/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para ordenar as contas pelo código
*/
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

    // Verifica se a lista está vazia
    if (L->Primeiro == NULL) {
        return;  // Retorna sem fazer nada se a lista estiver vazia
    }

    // Verifica se há apenas um elemento
    if (L->Primeiro->proximo == NULL) {
        return;  // Retorna sem fazer nada se houver apenas um elemento
    }

    qtde = conta_elementos(L); // Conta o número de elementos na lista
    aux1 = L->Primeiro; // Começa do primeiro item da lista

    for (i = 1; i <= qtde - 1; i++) // Laço externo para percorrer a lista
    {
        aux2 = aux1->proximo; // Começa do próximo item
        for (j = i + 1; j <= qtde; j++) // Laço interno para comparar os itens
        {
            if (aux2 != NULL && aux1->conteudo.conta_bancaria.codigo_conta > aux2->conteudo.conta_bancaria.codigo_conta) // Se o código da conta for maior
            {
                reg = aux1->conteudo; // Armazena o valor de aux1
                aux1->conteudo = aux2->conteudo; // Troca os dados de aux1 com aux2
                aux2->conteudo = reg; // Troca os dados de aux2 com os de aux1
            }
            if (aux2 != NULL) {
                aux2 = aux2->proximo; // Avança para o próximo elemento
            }
        }
        aux1 = aux1->proximo; // Avança para o próximo item
        if (aux1 == NULL) {
            break;  // Sai do loop se chegou ao fim da lista
        }
    }
}
