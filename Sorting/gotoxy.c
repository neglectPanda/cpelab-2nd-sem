#include <stdio.h>
#include <windows.h>

int main() {
    COORD coord;

    coord.X = 100;
    coord.Y = 50;

    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

    printf("Hello!\n");

    return 0;
}