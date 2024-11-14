#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
void ordena_nome(TipoLista *L)
{
    int i;
    int j;
    int qtde;
    int result;
    reg_cliente reg;
    TipoApontador aux1;
    TipoApontador aux2;

    qtde = conta_elementos(L);
    aux1 = L->Primeiro;
    aux2 = aux1->proximo;
    for (i = 1; i <= qtde - 1; i++)
    {
        for (j = i + 1; j <= qtde; j++)
        {
            result = strcmp(aux1->conteudo.nm_cliente, aux2->conteudo.nm_cliente);
            if (result > 0)
            {

                reg = aux1->conteudo;
                aux1->conteudo = aux2->conteudo;
                aux2->conteudo = reg;
            }

            aux2 = aux2->proximo;
        }
        aux1 = aux1->proximo;
        aux2 = aux1->proximo;
    }
}

// Le o nome do Cliente
char *le_nm_nome()
{
    char *nm_cliente;
    nm_cliente = malloc(sizeof(char) * 50);
    do
    {
        gotoxy(30, 07);
        printf("                                               ");
        gotoxy(30, 07);
        fgets(nm_cliente, 50, stdin);

        if ((strlen(nm_cliente) == 1) && (strcmp(nm_cliente, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Nome do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                              ");
        }
    } while ((strlen(nm_cliente) == 1) && (strcmp(nm_cliente, "0") == -1));
    return nm_cliente;
}

// Le o Endereco do Cliente
char *le_ds_endereco()
{
    char *ds_endereco;
    ds_endereco = malloc(sizeof(char) * 50);
    do
    {
        gotoxy(30, 9);
        printf("                                               ");
        gotoxy(30, 9);
        fgets(ds_endereco, 50, stdin);

        if ((strlen(ds_endereco) == 1) && (strcmp(ds_endereco, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Endereco do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                    ");
        }
    } while ((strlen(ds_endereco) == 1) && (strcmp(ds_endereco, "0") == -1));
    return ds_endereco;
}
// Le o Numero do Endereco do Cliente
int le_nr_numero()
{
    int nr_numero;
    do
    {
        gotoxy(30, 11);
        printf("                                               ");
        gotoxy(30, 11);
        scanf("%d", &nr_numero);
        getchar();
        if (nr_numero == 0)
        {
            gotoxy(07, 23);
            printf("Numero do Endereco do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                             ");
        }
    } while (nr_numero <= 0);
    return nr_numero;
}

// Le o CPF do Cliente
char *le_nr_documento()
{
    char *nr_documento;
    nr_documento = malloc(sizeof(char) * 20);
    do
    {
        gotoxy(30, 13);
        printf("                                               ");
        gotoxy(30, 13);
        fgets(nr_documento, 20, stdin);

        if ((strlen(nr_documento) == 1) && (strcmp(nr_documento, "0") == -1))
        {
            gotoxy(07, 23);
            printf("O CPF do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                    ");
        }
    } while ((strlen(nr_documento) == 1) && (strcmp(nr_documento, "0") == -1));
    return nr_documento;
}

// Le a Cidade do Cliente
char *le_ds_cidade()
{
    char *ds_cidade;
    ds_cidade = malloc(sizeof(char) * 50);
    do
    {
        gotoxy(30, 15);
        printf("                                               ");
        gotoxy(30, 15);
        fgets(ds_cidade, 50, stdin);

        if ((strlen(ds_cidade) == 1) && (strcmp(ds_cidade, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Cidade do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                    ");
        }
    } while ((strlen(ds_cidade) == 1) && (strcmp(ds_cidade, "0") == -1));
    return ds_cidade;
}

// Le o Estado do Cliente
char *le_cd_uf()
{
    char *cd_uf;
    cd_uf = malloc(sizeof(char) * 5);
    do
    {
        gotoxy(30, 17);
        printf("                                               ");
        gotoxy(30, 17);
        fgets(cd_uf, 5, stdin);

        if ((strlen(cd_uf) == 1) && (strcmp(cd_uf, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Estado do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                    ");
        }
    } while ((strlen(cd_uf) == 1) && (strcmp(cd_uf, "0") == -1));
    return cd_uf;
}
// Le Data do Cadastro do Cliente
char *le_dt_cadastro()
{
    char *dt_cadastro;
    dt_cadastro = malloc(sizeof(char) * 19);
    do
    {
        gotoxy(30, 19);
        printf("                                               ");
        gotoxy(30, 19);
        fgets(dt_cadastro, 19, stdin);

        if ((strlen(dt_cadastro) == 1) && (strcmp(dt_cadastro, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Data do Cadastro do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                            ");
        }
    } while ((strlen(dt_cadastro) == 1) && (strcmp(dt_cadastro, "0") == -1));
    return dt_cadastro;
}

// Le Numero do Telefone do Cliente
char *le_nr_telefone()
{
    char *nr_telefone;
    nr_telefone = malloc(sizeof(char) * 15);
    do
    {
        gotoxy(30, 21);
        printf("                                               ");
        gotoxy(30, 21);
        fgets(nr_telefone, 15, stdin);

        if ((strlen(nr_telefone) == 1) && (strcmp(nr_telefone, "0") == -1))
        {
            gotoxy(07, 23);
            printf("Numero do Telefone do cliente eh Obrigatorio");
            getch();
            gotoxy(07, 23);
            printf("                                            ");
        }
    } while ((strlen(nr_telefone) == 1) && (strcmp(nr_telefone, "0") == -1));
    return nr_telefone;
}