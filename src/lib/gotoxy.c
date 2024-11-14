#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include "include/funcoes.h"
#include "include/gotoxy.h"

void gotoxy(int x, int y)
{
    COORD coord;
    coord.X = (short)x;
    coord.Y = (short)y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
