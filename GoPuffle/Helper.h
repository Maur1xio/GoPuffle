#pragma once
#include <iostream>
#include <windows.h>

using namespace System;
using namespace std;

class Helper {
private:
    HANDLE consoleHandle;

public:
    Helper() {
        consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
    }

    void changeWindowColor(int r, int g, int b) {
        CONSOLE_SCREEN_BUFFER_INFOEX consoleInfo;
        consoleInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
        GetConsoleScreenBufferInfoEx(consoleHandle, &consoleInfo);
        consoleInfo.ColorTable[0] = RGB(r, g, b);
        SetConsoleScreenBufferInfoEx(consoleHandle, &consoleInfo);
    }

    void changeWindowSize(int WIDTH, int HEIGHT) {
        CONSOLE_SCREEN_BUFFER_INFOEX consoleInfo;
        consoleInfo.cbSize = sizeof(CONSOLE_SCREEN_BUFFER_INFOEX);
        GetConsoleScreenBufferInfoEx(consoleHandle, &consoleInfo);

        COORD bufferSize = { static_cast<SHORT>(WIDTH), static_cast<SHORT>(HEIGHT) };
        SetConsoleScreenBufferSize(consoleHandle, bufferSize);

        SMALL_RECT windowSize = {
            0, 0,
            static_cast<SHORT>(WIDTH - 1),
            static_cast<SHORT>(HEIGHT - 1)
        };
        SetConsoleWindowInfo(consoleHandle, TRUE, &windowSize);
    }

    void changeTextColor(int r, int g, int b) {
        cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "0m";
    }

    void goToXY(float x, float y) {
        Console::SetCursorPosition(x, y);
    }

    void setBackgroundColor(int r, int g, int b) {
        std::cout << "\033[48;2;" << r << ";" << g << ";" << b << "m";
    }
};


Helper* helper = new Helper();
