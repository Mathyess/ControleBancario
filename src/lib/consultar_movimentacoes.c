#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"

void consultar_movimentacoes(TipoListaMov *M) {
    TipoApontadorMov p;
    int lin;
    
    tela();
    gotoxy(20, 3);
    printf("CONSULTA DE MOVIMENTACOES BANCARIAS");
    
    // Inicia a linha para exibição dos dados
    lin = 7;
    
    // Exibe o cabeçalho da tabela
    gotoxy(2, 5);
    printf("Cod    Data      Hora     Tipo           Origem  Destino    Valor R$  Descricao");
    gotoxy(2, 6);
    printf("------ --------- -------- -------------- ------- ---------- --------- -------------------");
    
    p = M->Primeiro;
    if (p == NULL) {
        gotoxy(8, 23);
        printf("Nenhuma movimentacao encontrada!");
        getch();
        return;
    }
    
    while (p != NULL) {
        gotoxy(2, lin);
        printf("%-6d", p->conteudo.codigo_movimentacao);
        
        gotoxy(9, lin);
        printf("%-9s", p->conteudo.data);
        
        gotoxy(19, lin);
        printf("%-8s", p->conteudo.hora);
        
        gotoxy(28, lin);
        printf("%-14s", p->conteudo.tipo_movimentacao);
        
        gotoxy(43, lin);
        printf("%-7d", p->conteudo.codigo_conta_origem);
        
        if (strcmp(p->conteudo.tipo_movimentacao, "TRANSFERENCIA") == 0) {
            gotoxy(51, lin);
            printf("%-10d", p->conteudo.codigo_conta_destino);
        } else {
            gotoxy(51, lin);
            printf("%-10s", "-");
        }
        
        gotoxy(62, lin);
        printf("%9.2f", p->conteudo.valor);
        
        gotoxy(72, lin);
        // Limita a descrição a 19 caracteres para caber na tela
        char desc_truncada[20];
        strncpy(desc_truncada, p->conteudo.descricao, 19);
        desc_truncada[19] = '\0';
        printf("%-19s", desc_truncada);
        
        lin++;
        
        // Se atingir o limite da tela, pausa e continua em uma nova página
        if (lin > 21) {
            gotoxy(8, 23);
            printf("Pressione qualquer tecla para continuar...");
            getch();
            
            // Limpa a tela e reimprime o cabeçalho
            limpa_tela();
            gotoxy(2, 5);
            printf("Cod    Data      Hora     Tipo           Origem  Destino    Valor R$  Descricao");
            gotoxy(2, 6);
            printf("------ --------- -------- -------------- ------- ---------- --------- -------------------");
            lin = 7;
        }
        
        p = p->proximo;
    }
    
    gotoxy(8, 23);
    printf("Pressione qualquer tecla para voltar ao menu...");
    getch();
}
