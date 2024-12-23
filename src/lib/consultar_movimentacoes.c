/*  
    Alunos: Matheus Alende Pires, Pedro Henrique Pinheiro
    Data: 28/09/2022
    Turma: Engenharia de Software 2A
    RA Matheus Alende Pires     168649-2024
    RA Pedro Henrique Pinheiro  179381-2024
    Objetivo: Função para consultar as movimentações de uma conta
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void consultar_movimentacoes(TipoListaMov *M) {
    TipoApontadorMov p;
    int lin;
    
    if (M == NULL) {
        printf("Erro: Lista invalida!\n");
        getch();
        return;
    }

    tela();
    gotoxy(20, 3);
    printf("CONSULTA DE MOVIMENTACOES BANCARIAS");
    
    // Inicia a linha para exibição dos dados
    lin = 7;
    
    // Exibe o cabeçalho da tabela
    gotoxy(2, 5);
    printf("Cod    Data      Hora     Tipo         Origem  Destino    Valor R$  Descricao");
    gotoxy(2, 6);
    printf("------ --------- -------- ------------ ------- ---------- --------- ---------");
    
    p = M->Primeiro;
    if (p == NULL) {
        gotoxy(8, 23);
        printf("Nenhuma movimentacao encontrada!");
        getch();
        return;
    }
    
    double total_creditos = 0;
    double total_debitos = 0;
    int total_movimentacoes = 0;
    
    while (p != NULL) {
        gotoxy(2, lin);
        printf("%-6d", p->conteudo.codigo_movimentacao);


        gotoxy(9, lin);
        printf("%-9s", p->conteudo.data);
        
        gotoxy(19, lin);
        printf("%-8s", p->conteudo.hora);
        
        gotoxy(28, lin);
        printf("%-14s", p->conteudo.tipo_movimentacao);
        
        gotoxy(41, lin);
        printf("%-7d", p->conteudo.codigo_conta_origem);
        
        if (strcmp(p->conteudo.tipo_movimentacao, "TRANSFERENCIA") == 0) {
            gotoxy(49, lin);
            printf("%-10d", p->conteudo.codigo_conta_destino);
        } else {
            gotoxy(49, lin);
            printf("%-10s", "-");
        }
        
        gotoxy(59, lin);
        printf("%9.2f", p->conteudo.valor);
        
        gotoxy(72, lin);
        // Limita a descrição a 19 caracteres para caber na tela
        char desc_truncada[20];
        strncpy(desc_truncada, p->conteudo.descricao, 19);
        desc_truncada[19] = '\0';
        printf("%-19s", desc_truncada);
        
        // Atualiza totais
        if (strcmp(p->conteudo.tipo_movimentacao, "CREDITO") == 0) {
            total_creditos += p->conteudo.valor;
        } else if (strcmp(p->conteudo.tipo_movimentacao, "DEBITO") == 0) {
            total_debitos += p->conteudo.valor;
        }
        total_movimentacoes++;
        
        lin++;
        
        // Se atingir o limite da tela, pausa e continua em uma nova página
        if (lin > 19) {
            gotoxy(8, 21);
            printf("Total de movimentacoes: %d", total_movimentacoes);
            gotoxy(8, 22);
            printf("Total de creditos: R$ %.2f", total_creditos);
            gotoxy(8, 23);
            printf("Total de debitos: R$ %.2f", total_debitos);
            gotoxy(8, 24);
            printf("Pressione qualquer tecla para continuar...");
            getch();
            
            // Limpa a tela e reimprime o cabeçalho
            limpa_tela();
            gotoxy(20, 3);
            printf("CONSULTA DE MOVIMENTACOES BANCARIAS");
            gotoxy(2, 5);
            printf("Cod    Data      Hora     Tipo         Origem  Destino    Valor R$  Descricao");
            gotoxy(2, 6);
            printf("------ --------- -------- ------------ ------- ---------- --------- ---------");
            lin = 7;
        }
            gotoxy(79, 07);
            printf("|");

            gotoxy(79, 8);
            printf("|");


        p = p->proximo;
    }

    
    // Exibe totais na última página
    if (lin <= 19) {
        gotoxy(8, 19);
        printf("Total de movimentacoes: %d", total_movimentacoes);
        gotoxy(8, 20);
        printf("Total de creditos: R$ %.2f", total_creditos);
        gotoxy(8, 21);
        printf("Total de debitos: R$ %.2f", total_debitos);
    }
    
    gotoxy(8, 23);
    printf("Pressione qualquer tecla para voltar ao menu...");
    getch();
}
