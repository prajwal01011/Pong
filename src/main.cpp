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

        if(y + radius >= GetScreenHeight() || y - radius <= 0){
            speed_y *= -1;
        }

        if(x + radius >= GetScreenWidth() || x - radius <= 0){
            speed_x *= -1;

        }

    }


};

class Paddle{

    public:
    float x, y;
    float Height, Width;
    int speed;

    void Draw(){

    DrawRectangle(x, y, Width,Height, WHITE);


    }

    void update(){
       
         if(IsKeyDown(KEY_UP)){
            y = y - speed;
         }
         if (IsKeyDown(KEY_DOWN)) {
            y = y + speed;
         }


    }   



};


Ball ball;
Paddle player;


int main(){
    
    
    cout<<"starting the game...\n";

    const int Screen_Width= 1280;
    const int Screen_Height = 800;
    
    
    
    InitWindow(Screen_Width, Screen_Height, "Pong");

    SetTargetFPS(60);

    ball.radius = 20;
    ball.x = Screen_Width / 2;
    ball.y = Screen_Height / 2;
    ball.speed_x = 7;
    ball.speed_y = 7;

    player.Height = 120;
    player.Width = 25;
    player.x = Screen_Width - player.Width - 10;
    player.y = Screen_Height / 2 - player.Height / 2;
    player.speed = 6;


    while(WindowShouldClose() == false){

        BeginDrawing();
        //updating
        ball.Update();
        player.update();

        //Drawing
        ClearBackground(BLACK);
        DrawLine(Screen_Width/2, 0, Screen_Width/2, Screen_Height, WHITE);
        ball.Draw();
        DrawRectangle(10, (Screen_Height/2)-60, 25, 120, WHITE);
        player.Draw();

        EndDrawing();



    }

    
    
    CloseWindow();
    
    
    
    return 0;
}
