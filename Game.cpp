#include "Engine.h"
#include <stdlib.h>
#include <memory.h>
#include <algorithm>
#include "Game.h"
#include <iostream>
//
//  You are free to modify this file
//

//  is_key_pressed(int button_vk_code) - check if a key is pressed,
//                                       use keycodes (VK_SPACE, VK_RIGHT, VK_LEFT, VK_UP, VK_DOWN, 'A', 'B')
//
//  get_cursor_x(), get_cursor_y() - get mouse cursor position
//  is_mouse_button_pressed(int button) - check if mouse button is pressed (0 - left button, 1 - right button)
//  clear_buffer() - set all pixels in buffer to 'black'
//  is_window_active() - returns true if window is active
//  schedule_quit_game() - quit game after act()

int direction ;
bool rectCatch;
bool rectPlay;


// initialize game data in this function
void initialize()
{
    direction = 1;
    rectCatch = 0;
    rectPlay = 0;

}

// this function is called to update game data,
// dt - time elapsed since the previous update (in seconds)
void act(float dt)
{
  if (is_key_pressed(VK_ESCAPE))
    schedule_quit_game();

  if (is_key_pressed(VK_SPACE))
      direction *= -1;

}

// fill buffer in this function
// uint32_t buffer[SCREEN_HEIGHT][SCREEN_WIDTH] - is an array of 32-bit colors (8 bits per R, G, B)
void draw()
{
  // clear backbuffer
    FillWin();
	FillCircle(383, 513, 200, 0x8A9DB4);
    Craze(383, 513, 200,direction);
    
    //memset(buffer, 0, SCREEN_HEIGHT * SCREEN_WIDTH * sizeof(uint32_t));
}

// free game data in this function
void finalize()
{
}

void FillCircle(uint32_t x, uint32_t y, uint32_t r, uint32_t color)
{
    for (int rad = r; rad >= 0; rad--) {

        // stroke a circle
        for (double i = 0; i <= 3.1415926535 * 2; i += 0.001) {

            int pX = x + rad * cos(i);
            int pY = y + rad * sin(i);

            buffer[pX][pY] = color;

        }
    }
}

void FillWin()
{
    for (size_t i = 0; i < SCREEN_HEIGHT; i++)
    {
        for (size_t j = 0; j < SCREEN_WIDTH; j++)
        {
            buffer[i][j] = 0x94A9C1;
        }
    }
}

void Craze(uint32_t x, uint32_t y, uint32_t r, int32_t direction)
{
    static double angle1 = 0;

    angle1 += 0.1 *direction;  // or some other value.  Higher numbers = circles faster

    double x1 = cos(angle1) * r;
    double y1 = sin(angle1) * r;

    x1 += x;
    y1 += y;

    FillCircle((int)x1, (int)y1, 40, 0xffffff);

    static double angle2 = 600;

    angle2 += 0.1 * direction;  // or some other value.  Higher numbers = circles faster

    double x2 = cos(angle2) * r;
    double y2 = sin(angle2) * r;

    x2 += x;
    y2 += y;

    FillCircle((int)x2, (int)y2, 40, 0xffffff);


   static int cx;
   static int cy;
   static int color2;

    if (!rectPlay)
    {
          cx = 1 + rand() % SCREEN_WIDTH -1 ;
          cy = SCREEN_HEIGHT;


          if (!((0 + rand() % 10) % 2))
             color2 = 0xffffff;
          else
             color2 = 0x00000;

          rectPlay = true;
    }
    else
    {
        cx +=5;
        cy -= 5;
    }
   

    FillRect(cx, cy, 50, 50, color2);
   
    //ѕровер€ем входит ли наша точка в круг ???
    //если да переводим игру по новой
  
    //static double angle3 = 75;

    //angle3 += 0.1 * direction;  // or some other value.  Higher numbers = circles faster

    //double x3 = cos(angle3) * r;
    //double y3 = sin(angle3) * r;

    //x3 += x;
    //y3 += y;
    //FillCircle((int)x3, (int)y3, 5, 0xffffff);


    //static double angle4 = 100;

    //angle4 += 0.1 * direction;  // or some other value.  Higher numbers = circles faster

    //double x4 = cos(angle4) * r;
    //double y4 = sin(angle4) * r;

    //x4 += x;
    //y4 += y;
    //FillCircle((int)x4, (int)y4, 5, 0xffffff);

    //static double angle5 = 125;

    //angle5 += 0.1 * direction;  // or some other value.  Higher numbers = circles faster

    //double x5 = cos(angle5) * r;
    //double y5 = sin(angle5) * r;

    //x5 += x;
    //y5 += y;
    //FillCircle((int)x5, (int)y5, 3, 0xffffff);
    //
}

void FillRect(int32_t x, int32_t y, int32_t h, int32_t w, int32_t color)
{  
    if (x >= SCREEN_WIDTH || y <= 0)
    {
        //что кубик вне игры
        return;
    }

    for (size_t i = y - h; i <= y    ; i++)
    {
        for (size_t k =  x  ; k <= x + w; k++)
        {
           buffer[i][k] = color;
        }
    }
}