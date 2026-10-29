#include <iostream>
#include <raylib.h>
 
using namespace std;
int main(){
    
    
    cout<<"starting the game...\n";
    const int Screen_Width= 1280;
    const int Screen_Height = 800;
    
    
    InitWindow(Screen_Width, Screen_Height, "Pong");
    SetTargetFPS(60);

    while(WindowShouldClose() == false){

        BeginDrawing();

        

        EndDrawing();



    }

    
    
    CloseWindow();
    
    
    
    return 0;
}