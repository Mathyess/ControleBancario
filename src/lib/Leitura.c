#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include "include/funcoes.h"
void leitura(reg_cliente *reg_clie)
{
    strcpy(reg_clie->nm_cliente, le_nm_nome());
    strcpy(reg_clie->ds_endereco, le_ds_endereco());
    reg_clie->nr_numero = le_nr_numero();
    strcpy(reg_clie->nr_documento, le_nr_documento());
    strcpy(reg_clie->ds_cidade, le_ds_cidade());
    strcpy(reg_clie->cd_uf, le_cd_uf());
    strcpy(reg_clie->dt_cadastro, le_dt_cadastro());
    strcpy(reg_clie->nr_telefone, le_nr_telefone());
}
