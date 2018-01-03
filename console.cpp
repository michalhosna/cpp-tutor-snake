#include "console.h"
#include <cstdlib>

#ifdef _WIN32

#include <windows.h>
#include <iostream>

void vytiskniSymbolNaSouradnice(char symbol, int x, int y) {
    COORD p = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), p);
    std::cout << symbol;
}

void vymazObrazovku() {
    system("CLS");
}

bool jeCoCistNaVstupu(){
    return _kbhit();
}

char prectiVstup(){
    char p;
    p = _getch();
    return p;
}

void init(){
}


#else

#include <unistd.h>
#include <term.h>
#include <ncurses.h>
#include <iostream>
#include <fcntl.h>

using namespace std;

void vymazObrazovku() {
    system("clear");
}


void vytiskniSymbolNaSouradnice(char symbol, int x, int y) {
    int err;
    if (!cur_term)
        if (setupterm(NULL, STDOUT_FILENO, &err) == ERR)
            return;
    putp(tparm(tigetstr(const_cast<char *>("cup")), y, x, 0, 0, 0, 0, 0, 0, 0));
    putchar(symbol);
}


int kbhit(void) {
    struct termios oldt, newt;
    int ch;
    int oldf;

    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    ch = getchar();

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        ungetc(ch, stdin);
        return 1;
    }

    return 0;
}

bool jeCoCistNaVstupu() {
    return kbhit();
}

char prectiVstup() {
    return getchar();
}

void init() {

}


#endif