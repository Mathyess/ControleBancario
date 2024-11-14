#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"
// Tela de interacao do cliente
void tela_clie()
{
    tela();
    gotoxy(07, 05);
    printf("   Codigo do Cliente.: ");
    gotoxy(07, 07);
    printf("1- Nome do Cliente...: ");
    gotoxy(07, 9);
    printf("2- Endereco..........: ");
    gotoxy(07, 11);
    printf("3- Numero............: ");
    gotoxy(07, 13);
    printf("4- CPF...............: ");
    gotoxy(07, 15);
    printf("5- Cidade............: ");
    gotoxy(07, 17);
    printf("6- Estado............: ");
    gotoxy(07, 19);
    printf("7- Data cadastro.....: ");
    gotoxy(07, 21);
    printf("8- Telefone..........: ");
}