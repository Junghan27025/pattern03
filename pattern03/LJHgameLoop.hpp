#define _CRT_SECURE_NO_WARNINGS

#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <Windows.h>
#include "Player.hpp"
#include "Enemy.hpp"
#include "WindowScreen.hpp"



#pragma comment(lib,"OpenGL32")
using namespace std;


namespace LeeJungHan_Engine
{
    class LJHGameLoop
    {

    private:
        Player player;
        Enemy enemy;    
        bool GameRunning = true;
        WindowScreen windowScreen;
        bool startGame = false;
    private:
        void reStart() {
            if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || GetAsyncKeyState(VK_SHIFT) & 0x8001)
            {
                GameRunning = true;
                enemy.enemyX[0] = 1;
                enemy.enemyX[1] = 1;
                enemy.enemyX[2] = 1;
                enemy.enemy1Y[0] = 1;
                enemy.enemy1Y[1] = 1;
                enemy.enemy1Y[2] = 1;
            }
        }
        void Input() {
            if (GetAsyncKeyState(0x51) & 0x8000 || GetAsyncKeyState(0x51) & 0x8001)
            {
                player.qPressed();
            }
            else if (GetAsyncKeyState(0x57) & 0x8000 || GetAsyncKeyState(0x57) & 0x8001)
            {
                player.wPressed();
            }
            else if (GetAsyncKeyState(0x45) & 0x8000 || GetAsyncKeyState(0x45) & 0x8001)
            {
                player.ePressed();
            }
            else if (GetAsyncKeyState(0x41) & 0x8000 || GetAsyncKeyState(0x41) & 0x8001)
            {
                player.aPressed();
            }
            else if (GetAsyncKeyState(0x53) & 0x8000 || GetAsyncKeyState(0x53) & 0x8001)
            {
                player.sPressed();
            }
            else if (GetAsyncKeyState(0x44) & 0x8000 || GetAsyncKeyState(0x44) & 0x8001)
            {
                player.dPressed();
            }
            else if (GetAsyncKeyState(0x5A) & 0x8000 || GetAsyncKeyState(0x5A) & 0x8001)
            {
                player.zPressed();
            }
            else if (GetAsyncKeyState(0x58) & 0x8000 || GetAsyncKeyState(0x58) & 0x8001)
            {
                player.xPressed();
            }
            else if (GetAsyncKeyState(0x43) & 0x8000 || GetAsyncKeyState(0x43) & 0x8001)
            {
                player.cPressed();
            }
            else if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
            {
                startGame = true;
            }
        }

        static void error_callback(int error, const char* description)
        {
            fputs(description, stderr);
        }
        static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
        {
            if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
                glfwSetWindowShouldClose(window, GL_TRUE);
        }
    public:
             

        
        void Run()
        {
            
            {
                
                GameRunning = true;
                windowScreen.sizeWindow();  //윈도우 조건 체크
                while (!windowScreen.windowwhile()) {
                    Input();
                    if (startGame = true)
                    {
                        Update();
                    }
                    else if(startGame = false)
                    {
                        windowScreen.startScreen();
                        windowScreen.checkWindowEvent();
                    }
                }
            }
            windowScreen.endWindow(); //윈도우 종료

        }

        
    private:
        void Update() {
            if (GameRunning == true)
            {
                Input();
                enemy.enemyMove();
                glClearColor(0, 0, 0, 0);
                glClear(GL_COLOR_BUFFER_BIT);
                //road

                // 가로
                glBegin(GL_QUADS);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                glVertex3f(-1.0f, 0.2f, 0.0f);
                glVertex3f(-1.0f, 0.4f, 0.0f);
                glVertex3f(1.0f, 0.4f, 0.0f);
                glVertex3f(1.0f, 0.2f, 0.0f);
                glEnd();

                glBegin(GL_QUADS);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                glVertex3f(-1.0f, -0.08f, 0.0f);
                glVertex3f(-1.0f, 0.08f, 0.0f);
                glVertex3f(1.0f, 0.08f, 0.0f);
                glVertex3f(1.0f, -0.08f, 0.0f);
                glEnd();

                glBegin(GL_QUADS);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                glVertex3f(-1.0f, -0.2f, 0.0f);
                glVertex3f(-1.0f, -0.4f, 0.0f);
                glVertex3f(1.0f, -0.4f, 0.0f);
                glVertex3f(1.0f, -0.2f, 0.0f);
                glEnd();



                // 세로
                glBegin(GL_QUADS);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                glVertex3f(-0.5f, 1.0f, 0.0f);
                glVertex3f(-0.5f, -1.0f, 0.0f);
                glVertex3f(-0.4f, -1.0f, 0.0f);
                glVertex3f(-0.4f, 1.0f, 0.0f);
                glEnd();

                glBegin(GL_QUADS);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                glVertex3f(0.5f, 1.0f, 0.0f);
                glVertex3f(0.5f, -1.0f, 0.0f);
                glVertex3f(0.4f, -1.0f, 0.0f);
                glVertex3f(0.4f, 1.0f, 0.0f);
                glEnd();

                glBegin(GL_QUADS);
                glColor4f(1.0f, 1.0f, 1.0f, 1.0f);
                glVertex3f(0.08f, 1.0f, 0.0f);
                glVertex3f(0.08f, -1.0f, 0.0f);
                glVertex3f(-0.08f, -1.0f, 0.0f);
                glVertex3f(-0.08f, 1.0f, 0.0f);
                glEnd();

                ///player
                glPointSize(30);
                glBegin(GL_POINTS);
                glColor3f(0.3f, 0.9f, 0.8f);
                glVertex2f(player.playerX, player.playerY);

                //enemy
                glPointSize(10);
                glBegin(GL_POINTS);
                glColor3f(0.0f, 0.0f, 0.0f);
                for (int i = 0; i < 3; i++) {
                    glVertex2f(enemy.enemyX[i], enemy.enemyY[i]);
                }
                glEnd();

                glBegin(GL_POINTS);
                glColor3f(0.0f, 0.0f, 0.0f);
                for (int i = 0; i < 3; i++) {
                    glVertex2f(enemy.enemy1X[i], enemy.enemy1Y[i]);
                }
                glEnd();

                if (player.playerX == 0 && player.playerY == 0.3f)
                {
                    if (enemy.enemyX[0] < 0.03f && enemy.enemyX[0] > -0.03f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[1] < 0.35f && enemy.enemy1Y[1] > 0.25f)
                    {
                        GameRunning = false;
                    }
                }
                if (player.playerX == 0 && player.playerY == 0)
                {
                    if (enemy.enemyX[1] < 0.03f && enemy.enemyX[1] > -0.03f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[1] < 0.03f && enemy.enemy1Y[1] > -0.03f)
                    {
                        GameRunning = false;
                    }
                }
                if (player.playerX == 0 && player.playerY == -0.3f)
                {
                    if (enemy.enemyX[2] < 0.03f && enemy.enemyX[2] > -0.03f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[1] < -0.25f && enemy.enemy1Y[1] > -0.35f)
                    {
                        GameRunning = false;
                    }
                }


                if (player.playerX == 0.45f && player.playerY == 0.3f)
                {
                    if (enemy.enemyX[0] < 0.5f && enemy.enemyX[0] > 0.4f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[0] < 0.35f && enemy.enemy1Y[0] > 0.25f)
                    {
                        GameRunning = false;
                    }
                }
                if (player.playerX == 0.45f && player.playerY == 0)
                {
                    if (enemy.enemyX[1] < 0.5f && enemy.enemyX[1] > 0.4f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[0] < 0.03f && enemy.enemy1Y[0] > -0.03f)
                    {
                        GameRunning = false;
                    }
                }
                if (player.playerX == 0.45f && player.playerY == -0.3f)
                {
                    if (enemy.enemyX[2] < 0.5f && enemy.enemyX[2] > 0.4f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[0] < -0.25f && enemy.enemy1Y[0] > -0.35f)
                    {
                        GameRunning = false;
                    }
                }


                if (player.playerX == -0.45f && player.playerY == 0.3f)
                {
                    if (enemy.enemyX[0] < -0.4f && enemy.enemyX[0] > -0.5f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[2] < 0.35f && enemy.enemy1Y[2] > 0.25f)
                    {
                        GameRunning = false;
                    }
                }
                if (player.playerX == -0.45f && player.playerY == 0)
                {
                    if (enemy.enemyX[1] < -0.4f && enemy.enemyX[1] > -0.5f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[2] < 0.03f && enemy.enemy1Y[2] > -0.03f)
                    {
                        GameRunning = false;
                    }
                }
                if (player.playerX == -0.45f && player.playerY == -0.3f)
                {
                    if (enemy.enemyX[2] < -0.4f && enemy.enemyX[2] > -0.5f)
                    {
                        GameRunning = false;
                    }
                    else if (enemy.enemy1Y[2] < -0.25f && enemy.enemy1Y[2] > -0.35f)
                    {
                        GameRunning = false;
                    }
                }
                   
            }
            if (GameRunning == false)
            {
               
                
  
                windowScreen.endScreen();
                    

                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

                glEnable(GL_TEXTURE_2D);
                glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
                glBindTexture(GL_TEXTURE_2D, texName);

                glBegin(GL_QUADS);
                glTexCoord2f(0.0, 0.0);  glVertex3f(-1.0f, -1.0f, 0.0f);
                glTexCoord2f(0.0, 1.0);  glVertex3f(-1.0f, 1.0f, 0.0f);
                glTexCoord2f(1.0, 1.0);  glVertex3f(1.0f, 1.0f, 0.0f);
                glTexCoord2f(1.0, 0.0);  glVertex3f(1.0f, -1.0f, 0.0f);

                

               



                glEnd();
                glFlush();
                glDisable(GL_TEXTURE_2D);
                reStart();
            }
            windowScreen.checkWindowEvent();
        }
    };
}