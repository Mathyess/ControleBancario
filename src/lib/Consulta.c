/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Funçao para consultar contas em ordem
*/
#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void consultar(TipoLista *L)
{
    TipoApontador p;
    p = L->Primeiro;

    if (p == NULL)
    {
        // Caso a lista esteja vazia, exibe uma mensagem de aviso
        tela();
        gotoxy(8, 23);
        printf("LISTA VAZIA...");
        getch();
    }
    else
    {
        // Percorre a lista e exibe os dados de cada cliente
        p = L->Primeiro; // Garantir que começamos do primeiro elemento
        do
        {
            // Exibe a tela do cliente
            tela();
            tela_clie();

            // Título da seção
            gotoxy(35, 03);
            printf("CONSULTAR CONTA");

// Mostra o registro da conta atual
            mostra_conta_bancaria(p->conteudo.conta_bancaria);

            // Pausa para que o usuário veja os dados antes de avançar
            gotoxy(10, 23);
            system("pause");

            // Avança para o próximo cliente
            p = p->proximo;

        } while (p != NULL);  // Continua até que todos os clientes sejam exibidos
    }
}
