#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "../include/funcoes.h"
void mostra_cliente(reg_cliente reg_clie)
{
    gotoxy(30, 05);
    printf("%d", reg_clie.cd_cliente);
    gotoxy(30, 07);
    printf("%s", reg_clie.nm_cliente);
    gotoxy(30, 9);
    printf("%s", reg_clie.ds_endereco);
    gotoxy(30, 11);
    printf("%d", reg_clie.nr_numero);
    gotoxy(30, 13);
    printf("%s", reg_clie.nr_documento);
    gotoxy(30, 15);
    printf("%s", reg_clie.ds_cidade);
    gotoxy(30, 17);
    printf("%s", reg_clie.cd_uf);
    gotoxy(30, 19);
    printf("%s", reg_clie.dt_cadastro);
    gotoxy(30, 21);
    printf("%s", reg_clie.nr_telefone);
}
