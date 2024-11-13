#ifndef GOTOXY_H
#define GOTOXY_H

// Funcao para posicionar o cursor em um determinado ponto da Tela
void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}