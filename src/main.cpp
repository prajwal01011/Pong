#include <iostream>
#include <raylib.h>
 
using namespace std;

class Ball{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw(){

        DrawCircle(x, y, radius, WHITE);

    }
    void Update(){
        x +=speed_x;
        y +=speed_y;


    }


};
Ball ball;

int main(){
    
    
    cout<<"starting the game...\n";

    const int Screen_Width= 1280;
    const int Screen_Height = 800;
    
    
    
    InitWindow(Screen_Width, Screen_Height, "Pong");

    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = Screen_Width/2;
    ball.y = Screen_Height/2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    while(WindowShouldClose() == false){

        BeginDrawing();
        //updating
        ball.Update();

        //Drawing
        ClearBackground(BLACK);
        DrawLine(Screen_Width/2, 0, Screen_Width/2, Screen_Height, WHITE);
        DrawRectangle(10, (Screen_Height/2)-60, 25, 120, WHITE);
        ball.Draw();
        DrawRectangle(Screen_Width-35, (Screen_Height/2)-60, 25, 120, WHITE);

        EndDrawing();



    }

    
    
    CloseWindow();
    
    
    
    return 0;
}