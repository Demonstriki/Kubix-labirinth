#include <iostream>
#include <windows.h>
#include <stdlib.h>



int game_over() {
    system("cls");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 24; j++) {
            for (int z = 0; z < 72; z++) {
                std::cout << "*";
            }
            std::cout << std::endl;
        }
        Sleep(500);
        system("cls");
        Sleep(500);
    }
    system("cls");
    std::cout << "YOU LOST. GAME OVER!!!\nDO YOU WANT TO RESTART THE GAME?\n1 - YES.\n2 - NO, I WANT TO EXIT.\n";
    Sleep(1000);
    while (true) {
        if (GetAsyncKeyState(0x31) & 0x8000) {
            return true;
        }
        else if (GetAsyncKeyState(0x32) & 0x8000) {
            return false;
        }
    }
}

int vicrory() {
    system("cls");
    char str[] = { "MY CONGRATULATIONS!!! YOU WIN!!!" };
    for (int i = 0; i < strlen(str); i++) {
        std::cout << str[i];
        Sleep(30);
    }
    Sleep(100);
    for (int i = 0; i < 3; i++) {
        system("cls");
        Sleep(300);
        std::cout << str;
        Sleep(700);
    }
    std::cout << std::endl << "DO YOU WANT TO RESTART THE GAME?\n1 - YES.\n2 - NO, I WANT TO EXIT.\n";
    Sleep(1000);
    while (true) {
        if (GetAsyncKeyState(0x31) & 0x8000) {
            return true;
        }
        else if (GetAsyncKeyState(0x32) & 0x8000) {
            return false;
        }
    }
}

template <size_t rows, size_t cols>
void drawing(int(&mas)[rows][cols]) {
    for (int i = 0; i < 24; i++)
    {
        for (int g = 0; g < 24; g++)
        {
            if (mas[i][g] == 1)
            {
                std::cout << " * ";
            }
            else if (mas[i][g] == 0)
            {
                std::cout << "   ";
            }
            else if (mas[i][g] == 2) {
                std::cout << " / ";
            }
            else if (mas[i][g] == 3) {
                std::cout << " \\ ";
            }
            else {
                std::cout << " ! ";
            }
        }
        std::cout << std::endl;
    }
}

void drawing_person(int posy, int posx) {
    COORD coord;
    coord.X = posx;
    coord.Y = posy;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << " # ";
}

template <size_t rows, size_t cols>
int verification(int(&mas)[rows][cols], int posx, int posy, int a) {
    if (mas[posy][posx] == 1)
    {
        return 1;
    }
    return 1;
}

template <size_t rows, size_t cols>
int ladder_check(int(&mas)[rows][cols], int posx, int posy) {
    if (mas[posy][posx] == 2)
    {
        return 2;
    }
    if (mas[posy][posx] == 3) {
        return 3;
    }
    if (mas[posy][posx] == 5) {
        return 5;
    }
    return 0;
}

template <size_t rows, size_t cols>
int mas(int(&mas1)[rows][cols], int(&mas2)[rows][cols], int(&mas3)[rows][cols], int(&mas4)[rows][cols], int(&mas5)[rows][cols], int stage) {
    switch (stage) {
    case 1:
        return mas1;
        break;
    case 2:
        return mas2;
        break;
    case 3:
        return mas3;
        break;
    case 4:
        return mas4;
        break;
    case 5:
        return mas5;
        break;
    }
}

int main() {
    bool main_game_check = true;
    setlocale(LC_ALL, "Russian");


    int a = 1;
    int stage = 1;


    std::cout << "ИГРА - КУБИЧЕСКИЙ ЛАБИРИНТ.\n\nPress\n'W' - to move up,\n'A' - to move left,\n'S' - to move down,\n'D' - to move right.\n\n";
    std::cout << "/ - лестница вверх, при нажатии кнопки 'E' поднимает вас на этаж выше.\n";
    std::cout << "\\ - лестница вниз, при нажатии кнопки 'Q' спускает вас на этаж ниже.\n\n";
    std::cout << "Нажмите 1, чтобы перезапустить игру.\n\n";

    system("pause");
    Sleep(500);
    system("cls");


    int posy = 1;
    int posx = 3;

    const int y1 = 24;
    int mas1[y1][y1] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
                            {1,0,1,0,0,1,0,1,0,0,0,1,1,1,1,0,0,0,1,1},
                            {1,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,0,0,1},
                            {1,0,0,0,0,0,0,1,0,1,1,1,1,0,1,0,0,1,0,1},
                            {1,1,1,1,1,1,0,1,0,1,0,0,1,0,1,1,0,1,0,1},
                            {1,0,0,1,0,0,0,0,0,1,1,0,0,0,0,0,0,1,0,1},
                            {1,0,1,1,0,1,1,1,1,1,0,0,1,0,1,1,1,1,0,1},
                            {1,0,0,0,0,0,0,0,0,1,1,1,1,0,1,0,0,0,0,1},
                            {1,1,1,1,1,1,0,1,1,1,0,0,0,0,1,0,1,1,1,1},
                            {1,1,0,0,0,1,0,0,1,1,0,1,1,1,1,0,0,0,0,1},
                            {1,0,0,1,0,0,0,0,0,1,0,0,0,0,1,1,1,1,0,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,0,1,0,0,0,0,1},
                            {1,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,1},
                            {1,0,1,1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,0,1},
                            {1,0,1,0,0,0,1,0,0,0,1,0,0,0,0,0,1,1,0,1},
                            {1,0,1,1,0,1,1,0,1,0,1,1,1,0,1,0,0,0,0,1},
                            {1,0,1,0,0,0,1,0,1,0,0,0,1,1,1,1,1,1,1,1},
                            {1,0,1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1},
                            {1,0,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,1,0,1},
                            {1,0,1,0,1,0,1,0,1,0,0,0,0,0,0,0,0,1,0,1},
                            {1,0,1,0,1,0,0,0,1,0,1,1,1,1,1,1,0,1,0,1},
                            {1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,0,1,0,1},
                            {1,0,1,0,0,0,0,0,1,1,1,0,0,0,1,0,1,1,2,1},
                            {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

    int mas2[y1][y1] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,1 },
        {1,0,0,0,0,0,0,0,0,1,0,1,1,0,0,0,0,0,1,1},
        {1,0,1,1,1,1,0,1,0,1,0,1,1,0,1,1,1,0,1,1},
        {1,0,0,0,0,0,0,1,0,1,0,1,0,0,1,1,1,0,0,1},
        {1,0,1,1,0,1,0,1,0,1,0,1,1,1,1,1,1,1,0,1},
        {1,0,1,1,0,1,1,1,0,1,0,0,0,1,1,1,1,1,0,1},
        {1,1,1,0,0,0,0,1,0,1,0,1,0,1,1,1,1,0,0,1},
        {1,1,0,0,1,1,0,1,0,1,0,1,0,0,0,0,1,0,1,1},
        {1,1,0,1,1,1,0,1,0,1,0,1,1,1,1,0,1,0,1,1},
        {1,1,0,1,0,0,0,1,0,0,0,1,1,0,0,0,0,0,1,1},
        {1,1,0,1,1,1,0,1,1,1,1,1,0,0,1,1,1,1,1,1},
        {1,1,0,0,0,1,0,0,1,1,0,1,0,1,1,0,0,0,0,1},
        {1,1,1,1,0,1,1,1,1,0,0,0,0,1,1,0,1,1,0,1},
        {1,0,1,1,0,1,1,0,0,0,1,1,0,0,1,0,1,1,1,1},
        {1,0,0,0,0,1,1,1,1,0,1,1,1,1,1,0,0,0,1,1},
        {1,1,1,1,0,1,1,0,1,0,0,0,0,0,0,0,1,0,0,1},
        {1,1,0,0,0,0,0,0,1,1,1,1,1,1,1,0,1,1,0,1},
        {1,1,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,1},
        {1,1,0,1,1,0,0,0,1,0,1,0,0,0,0,0,1,1,0,1},
        {1,1,0,0,0,0,1,0,0,0,1,1,1,1,1,1,1,1,0,1},
        {1,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,0,1,0,1},
        {1,0,0,0,0,0,1,1,1,0,0,0,0,1,1,1,2,1,3,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

    int mas3[y1][y1] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,2,1,2,1,1,1,1,1,1,1,1,0,0,0,0,0,0,1,1},
        {1,0,1,0,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,1,1,0,1,0,1,1,0,0,0,0,1},
        {1,0,0,1,1,0,0,0,0,1,0,1,0,1,1,0,1,1,0,1},
        {1,1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1,1,0,1},
        {1,0,0,1,0,1,1,1,1,1,1,1,1,1,1,1,1,1,0,1},
        {1,1,0,1,0,1,1,1,0,0,0,0,1,1,1,1,1,1,0,1},
        {1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0,0,0,1},
        {1,1,1,1,1,0,1,0,1,1,1,1,1,0,1,0,1,1,1,1},
        {1,0,1,1,1,0,1,0,0,1,0,0,1,0,1,0,1,1,1,1},
        {1,0,1,0,0,0,1,1,0,1,1,0,1,0,1,0,0,0,1,1},
        {1,0,1,0,1,1,1,1,0,1,1,0,0,0,1,1,1,0,1,1},
        {1,0,1,0,1,0,0,0,0,1,1,1,1,0,1,0,1,0,1,1},
        {1,0,1,0,1,1,0,1,1,1,1,1,0,0,0,0,1,0,1,1},
        {1,0,0,0,1,1,0,0,0,1,1,1,0,1,1,1,1,0,1,1},
        {1,1,1,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,1,1},
        {1,1,1,1,1,1,1,1,0,1,0,1,1,1,1,1,1,0,0,1},
        {1,1,0,0,0,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1},
        {1,1,0,1,1,1,1,1,1,1,0,1,1,0,0,0,0,1,0,1},
        {1,1,0,0,0,0,0,1,1,1,0,1,1,0,1,1,0,1,0,1},
        {1,1,0,1,1,1,0,1,1,1,0,1,1,0,1,1,0,1,0,1},
        {1,1,0,0,0,0,0,0,0,0,0,0,0,0,1,1,3,1,2,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

    int mas4[y1][y1] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,3,1,3,0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,1},
        {1,0,1,1,1,1,1,1,0,1,1,1,0,1,1,0,0,0,0,1},
        {1,0,1,0,1,0,0,0,0,0,0,0,0,1,1,0,1,1,0,1},
        {1,0,1,0,1,0,1,1,1,1,1,1,0,1,1,0,1,1,0,1},
        {1,0,1,0,0,0,1,0,0,0,0,0,0,1,1,0,1,1,0,1},
        {1,0,1,1,1,1,1,0,1,1,1,1,1,1,0,0,1,1,0,1},
        {1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1},
        {1,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,0,1,0,1},
        {1,0,1,1,0,1,1,1,0,1,1,1,0,1,1,1,0,0,0,1},
        {1,0,0,0,0,0,0,1,0,0,1,1,0,1,0,1,0,1,0,1},
        {1,1,1,1,1,1,0,1,1,0,1,1,0,1,0,1,0,1,0,1},
        {1,0,0,0,0,1,0,0,0,0,1,1,0,1,0,1,0,1,1,1},
        {1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,1,1,1},
        {1,0,1,1,0,1,1,1,1,1,1,1,0,1,0,1,0,0,0,1},
        {1,0,1,0,0,0,0,0,0,0,0,0,0,1,0,1,1,1,0,1},
        {1,0,1,1,1,1,0,1,0,1,1,1,1,1,0,0,0,1,0,1},
        {1,0,0,0,0,1,0,1,1,1,1,1,1,1,0,1,0,0,0,1},
        {1,1,1,1,0,1,0,1,1,0,0,0,0,0,0,1,0,1,0,1},
        {1,0,0,0,0,1,0,1,1,0,1,0,1,1,0,1,0,1,0,1},
        {1,0,1,1,1,1,0,1,1,0,1,0,1,1,1,1,0,1,0,1},
        {1,1,1,1,1,1,0,1,1,0,1,0,1,1,0,0,0,1,0,1},
        {1,2,0,0,0,0,0,1,0,0,1,0,0,0,0,1,1,1,3,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

    int mas5[y1][y1] = { {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,0,0,0,0,0,0,1,1,0,1,0,0,0,0,0,5},
        {1,0,0,1,0,1,1,1,1,0,0,1,0,1,0,1,1,1,1,1},
        {1,0,1,1,0,1,1,1,1,1,0,1,0,1,0,1,0,1,0,1},
        {1,0,1,1,0,0,0,0,0,1,0,1,0,1,0,1,0,0,0,1},
        {1,0,0,1,0,1,1,1,0,1,0,1,0,1,0,1,0,1,1,1},
        {1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1},
        {1,0,1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,1,1},
        {1,0,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {1,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1},
        {1,1,0,1,0,1,0,1,0,1,0,0,0,1,0,1,0,0,0,1},
        {1,1,0,1,0,1,0,1,0,1,1,1,1,1,0,1,1,1,0,1},
        {1,0,0,1,0,1,0,1,0,0,0,0,0,1,0,1,0,1,0,1},
        {1,1,0,1,0,1,0,1,1,1,1,1,0,0,0,1,0,1,0,1},
        {1,0,0,0,0,1,0,0,0,0,1,1,1,1,1,1,0,1,0,1},
        {1,0,1,1,1,1,1,0,1,0,1,0,1,1,1,1,0,0,0,1},
        {1,0,1,1,0,0,1,0,1,0,1,0,0,0,0,1,0,1,0,1},
        {1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1},
        {1,0,1,1,0,1,1,0,1,0,1,1,1,1,0,1,0,1,0,1},
        {1,0,1,1,0,1,1,0,1,0,0,0,0,0,0,1,0,1,1,1},
        {1,0,1,0,0,1,1,0,1,0,1,1,0,1,1,1,0,1,1,1},
        {1,0,1,0,1,1,1,0,1,0,1,1,0,0,0,0,0,1,1,1},
        {1,3,0,0,0,0,0,1,0,0,1,1,1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1} };

    drawing(mas1);
    drawing_person(posy, posx);

    while (main_game_check) {
        if ((GetAsyncKeyState(0x57) & 0x8000) || (GetAsyncKeyState(VK_UP) & 0x8000)) {
            posy--;
            system("cls");
            if (stage == 1) {
                drawing(mas1);
                drawing_person(posy, posx);
                if (!verification(mas1, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 2) {
                drawing(mas2);
                drawing_person(posy, posx);
                if (!verification(mas2, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 3) {
                drawing(mas3);
                drawing_person(posy, posx);
                if (!verification(mas3, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 4) {
                drawing(mas4);
                drawing_person(posy, posx);
                if (!verification(mas4, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 5) {
                drawing(mas5);
                drawing_person(posy, posx);
                if (!verification(mas5, (posx / 3), posy, a)) a = 0;
            }
            Sleep(200);
        }
        if ((GetAsyncKeyState(0x41) & 0x8000) || (GetAsyncKeyState(VK_LEFT) & 0x8000)) {
            posx -= 3;
            system("cls");
            if (stage == 1) {
                drawing(mas1);
                drawing_person(posy, posx);
                if (!verification(mas1, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 2) {
                drawing(mas2);
                drawing_person(posy, posx);
                if (!verification(mas2, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 3) {
                drawing(mas3);
                drawing_person(posy, posx);
                if (!verification(mas3, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 4) {
                drawing(mas4);
                drawing_person(posy, posx);
                if (!verification(mas4, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 5) {
                drawing(mas5);
                drawing_person(posy, posx);
                if (!verification(mas5, (posx / 3), posy, a)) a = 0;
            }
            Sleep(200);
        }
        if ((GetAsyncKeyState(0x53) & 0x8000) || (GetAsyncKeyState(VK_DOWN) & 0x8000)) {
            posy++;
            system("cls");
            if (stage == 1) {
                drawing(mas1);
                drawing_person(posy, posx);
                if (!verification(mas1, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 2) {
                drawing(mas2);
                drawing_person(posy, posx);
                if (!verification(mas2, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 3) {
                drawing(mas3);
                drawing_person(posy, posx);
                if (!verification(mas3, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 4) {
                drawing(mas4);
                drawing_person(posy, posx);
                if (!verification(mas4, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 5) {
                drawing(mas5);
                drawing_person(posy, posx);
                if (!verification(mas5, (posx / 3), posy, a)) a = 0;
            }
            Sleep(200);
        }
        if ((GetAsyncKeyState(0x44) & 0x8000) || (GetAsyncKeyState(VK_RIGHT) & 0x8000)) {
            posx += 3;
            system("cls");
            if (stage == 1) {
                drawing(mas1);
                drawing_person(posy, posx);
                if (!verification(mas1, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 2) {
                drawing(mas2);
                drawing_person(posy, posx);
                if (!verification(mas2, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 3) {
                drawing(mas3);
                drawing_person(posy, posx);
                if (!verification(mas3, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 4) {
                drawing(mas4);
                drawing_person(posy, posx);
                if (!verification(mas4, (posx / 3), posy, a)) a = 0;
            }
            else if (stage == 5) {
                drawing(mas5);
                drawing_person(posy, posx);
                if (!verification(mas5, (posx / 3), posy, a)) a = 0;
            }
            Sleep(200);
        }

        if (GetAsyncKeyState(0x31) & 0x8000) {
            system("cls");
            posx = 3;
            posy = 1;
            stage = 1;
            Sleep(500);
            std::cout << "RESTART.";
            Sleep(500);
            system("cls");
            std::cout << "RESTART..";
            Sleep(500);
            system("cls");
            std::cout << "RESTART...";
            Sleep(500);
            system("cls");
            drawing(mas1);
            drawing_person(posy, posx);
        }

        if (stage == 1) {
            if (ladder_check(mas1, (posx / 3), posy) == 2) {
                if (GetAsyncKeyState('E') & 0x8000) {
                    stage++;
                    system("cls");
                    Sleep(500);
                    drawing(mas2);
                    drawing_person(posy, posx);
                }
            }
        }
        else if (stage == 2) {
            if (ladder_check(mas2, (posx / 3), posy) == 2) {
                if (GetAsyncKeyState('E') & 0x8000) {
                    stage++;
                    system("cls");
                    Sleep(500);
                    drawing(mas3);
                    drawing_person(posy, posx);
                }
            }
            else if (ladder_check(mas2, (posx / 3), posy) == 3) {
                if (GetAsyncKeyState('Q') & 0x8000) {
                    stage--;
                    system("cls");
                    Sleep(500);
                    drawing(mas1);
                    drawing_person(posy, posx);
                }
            }
        }
        else if (stage == 3) {
            if (ladder_check(mas3, (posx / 3), posy) == 2) {
                if (GetAsyncKeyState('E') & 0x8000) {
                    stage++;
                    system("cls");
                    Sleep(500);
                    drawing(mas4);
                    drawing_person(posy, posx);
                }
            }
            else if (ladder_check(mas3, (posx / 3), posy) == 3) {
                if (GetAsyncKeyState('Q') & 0x8000) {
                    stage--;
                    system("cls");
                    Sleep(500);
                    drawing(mas2);
                    drawing_person(posy, posx);
                }
            }
        }
        else if (stage == 4) {
            if (ladder_check(mas4, (posx / 3), posy) == 2) {
                if (GetAsyncKeyState('E') & 0x8000) {
                    stage++;
                    system("cls");
                    Sleep(500);
                    drawing(mas5);
                    drawing_person(posy, posx);
                }
            }
            else if (ladder_check(mas4, (posx / 3), posy) == 3) {
                if (GetAsyncKeyState('Q') & 0x8000) {
                    stage--;
                    system("cls");
                    Sleep(500);
                    drawing(mas3);
                    drawing_person(posy, posx);
                }
            }
        }
        else if (stage == 5) {
            if (ladder_check(mas5, (posx / 3), posy) == 3) {
                if (GetAsyncKeyState('Q') & 0x8000) {
                    stage++;
                    system("cls");
                    Sleep(500);
                    drawing(mas4);
                    drawing_person(posy, posx);
                }
            }
        }

        if (ladder_check(mas5, (posx / 3), posy) == 5) {
            main_game_check = vicrory();
            stage = 1;
            a = 1;
            posx = 3;
            posy = 1;
        }

        if (a == 0) {
            main_game_check = game_over();
            stage = 1;
            a = 1;
            posx = 3;
            posy = 1;
        }
    }



    system("pause");

    return 0;
}
