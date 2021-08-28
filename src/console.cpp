#include <console.hpp>

Console::Console(){
#ifdef __linux__
    printf("\033[6n");
    scanf("\033[%d;%dR", x, y);
#else
    ConsoleHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO bufferInfo;
    GetConsoleScreenBufferInfo(ConsoleHandle, &bufferInfo);
    x= bufferInfo.dwCursorPosition.X;
    y= bufferInfo.dwCursorPosition.Y;
#endif
}

#ifndef __linux__
HANDLE Console::GetHandle(){
    return ConsoleHandle;
}
#endif

int Console::GetX(){
    return x;
}

int Console::GetY(){
    return y;
}

void Console::SetX(int _x){
    x=_x;
}

void Console::SetY(int _y){
    y=_y;
}

void Console::Print(std::string content){
    SetCursorPos(x,y);
    printf("%s",content.c_str());
}

void Console::Print(std::string content, int _x ,int _y){
    x=_x;
    y=_y;
    SetCursorPos(x,y);
    printf("%s",content.c_str());
}

void Console::SetCursorPos(int _x, int _y){
#ifdef __linux__
    printf("\033[%d;%dH",_y+1,_x+1);
#else
    COORD coord;
    coord.X = _x; coord.Y = _y;
    SetConsoleCursorPosition(ConsoleHandle,coord);
#endif
}