#include <iostream>
#include <raylib.h>
 
using namespace std;
Color Green = {0, 255, 0, 255};
Color Maroon = {171, 40, 82,245};
Color Yellow = {255, 255, 0, 240};
Color Pink = {255, 0, 191, 255};
Color Black = {0, 0, 0, 255};
Color Red = {255, 20, 20, 255};


int player_score = 0;
int cpu_score = 0;

class Ball{
    public:
    float x, y;
    int speed_x, speed_y;
    int radius;

    void Draw(){

        DrawCircle(x, y, radius, Yellow);

    }
    void Update(){
        x +=speed_x;
        y +=speed_y;

        if(y + radius >= GetScreenHeight() || y - radius <= 0){
            speed_y *= -1;
        }

        if(x + radius >= GetScreenWidth() )// cpu wins 
        {
            cpu_score ++;
            reset_ball();
        } 
        if(x - radius <= 0){    //player wins
            player_score ++;
            reset_ball();
        }

    }
    void reset_ball(){
        x = GetScreenWidth() / 2 ;
        y = GetScreenHeight() / 2 ;

        int speed_choice[2] = {-1,1};
        speed_x *= speed_choice[GetRandomValue(0,1)];
        speed_y *= speed_choice [GetRandomValue(0, 1)];

    }


};

class Paddle{
    protected:
        void limitMovement(){
        
        if (y <= 0){
            y = 0;
         }
        if(y + Height >= GetScreenHeight()){
            y = GetScreenHeight() - Height;
         }
    }   

    public:
    float x, y;
    float Height, Width;
    int speed;

    void Draw(){

    DrawRectangleRounded(Rectangle{x,y, Width, Height}, 0.8, 0, WHITE);
    }

    void update(){
       
         if(IsKeyDown(KEY_UP)){
            y = y - speed;
         }
         if (IsKeyDown(KEY_DOWN)) {
            y = y + speed;
         }

         limitMovement();



    }

    


};
class cpuPaddle :public Paddle{
    
    public:
    void Update(int ball_y){

        if(y + Height / 2 > ball_y){
            y = y - speed;

        }
        if(y + Height / 2 <= ball_y){
            y = y + speed;

        }
        void limitMovement();

    }

};


Ball ball;
Paddle player;
cpuPaddle cpu;

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

    cpu.Height = 120;
    cpu.Width = 25;
    cpu.x = 10;
    cpu.y = Screen_Height / 2 - cpu.Height / 2;
    cpu.speed = 6;

    while(WindowShouldClose() == false){

        BeginDrawing();
    //updating

        ball.Update();
        player.update();
        cpu.Update(ball.y);

    //check for collision
        
        //player

        if(CheckCollisionCircleRec(Vector2 {ball.x, ball.y}, ball.radius, Rectangle{player.x, player.y, player.Width, player.Height})){
        ball.speed_x *= -1;
       } 
    
       //cpu

       if (CheckCollisionCircleRec(Vector2{ball.x, ball.y}, ball.radius, Rectangle {cpu.x, cpu.y, cpu.Width, cpu.Height})) {
        ball.speed_x *= -1;
       
       }

    //Drawing
        ClearBackground(Red);
        DrawRectangle(Screen_Width/2, 0, Screen_Width/2, Screen_Height, Maroon);
        DrawLine(Screen_Width/2, 0, Screen_Width/2, Screen_Height, Black);
        DrawCircle(Screen_Width / 2, Screen_Height / 2, 65,Black);
        DrawCircle(Screen_Width / 2, Screen_Height / 2, 60,Red);
        DrawCircleSector(Vector2{640, 400}, 60, 0, 180, 24, WHITE); 
        DrawLineEx((Vector2){ Screen_Width/2-60,Screen_Height / 2  },(Vector2){ Screen_Width/2+60, Screen_Height / 2  },5.0f,BLACK); 
        DrawCircle(Screen_Width / 2, Screen_Height / 2, 20,Black);
        DrawCircle(Screen_Width / 2, Screen_Height / 2, 15,WHITE);
        ball.Draw();
        cpu.Draw();
        DrawText(TextFormat("%i",cpu_score), Screen_Width / 4 - 20, 20, 60, WHITE);
        player.Draw();
        DrawText(TextFormat("%i",player_score), 3 * Screen_Width / 4- 20, 20, 60, WHITE);

        EndDrawing();



    }

    
    
    CloseWindow();
    
    
    
    return 0;
}
