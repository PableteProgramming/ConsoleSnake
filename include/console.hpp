#include <string>

#ifndef __linux__
#include <Windows.h>
#else
#include <unistd.h>
#endif

class Console{
private:
    int x;
    int y;
#ifndef __linux__
    HANDLE ConsoleHandle;
#endif
    void SetCursorPos(int,int);
public:
    Console();
#ifndef __linux__
    HANDLE GetHandle();
#endif
    int GetX();
    int GetY();
    void SetX(int);
    void SetY(int);
    void Print(std::string);
    void Print(std::string,int,int);
};