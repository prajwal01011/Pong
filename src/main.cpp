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

        //Drawing
        DrawLine(Screen_Width/2, 0, Screen_Width/2, Screen_Height, WHITE);
        DrawCircle(Screen_Width/2, Screen_Height/2, 20, WHITE);
        DrawRectangle(10, (Screen_Height/2)-60, 25, 120, WHITE);
        DrawRectangle(Screen_Width-35, (Screen_Height/2)-60, 25, 120, WHITE);

        EndDrawing();



    }

    
    
    CloseWindow();
    
    
    
    return 0;
}