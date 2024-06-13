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








void drawing_person(int posy, int posx) {
    COORD coord;
    coord.X = posx;
    coord.Y = posy;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    std::cout << " # ";
}



