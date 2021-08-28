#include <snake.hpp>

int main()
{
    Console console;
    int x= console.GetX();
    int y= console.GetY();
    for(int i=0;i<10;i++){
        for(int j=0; j<10;j++){
            console.SetX(x+i);
            console.SetY(y+j);
            console.Print("-");
        }
    }
    return 0;
}