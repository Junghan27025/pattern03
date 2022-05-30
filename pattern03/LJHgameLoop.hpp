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



#pragma comment(lib,"OpenGL32")
using namespace std;

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

namespace LeeJungHan_Engine
{
    class LJHGameLoop
    {

    private:
        Player player;
        Enemy enemy;
        bool GameRunning = true;

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
    public:
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

        }
        void Run()
        {
            Update();
        }
    private:
        void Update() {

            GLFWwindow* window;
            glfwSetErrorCallback(error_callback);
            if (!glfwInit())
            {
                exit(EXIT_FAILURE);
            }
            window = glfwCreateWindow(1080, 640, "Simple example", NULL, NULL);
            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
            glfwMakeContextCurrent(window);
            glfwSetKeyCallback(window, key_callback);

            do
            {

                float ratio;
                int width, height;
                glfwGetFramebufferSize(window, &width, &height);
                ratio = width / (float)height;

                if (GameRunning == true)
                {
                    Input();
                    enemy.enemyMove();
                   
                }
                if (GameRunning == false)
                {
                    cout << " 게임 종료";
                    glClearColor(1, 0, 0, 0);
                    glClear(GL_COLOR_BUFFER_BIT);

                    glEnd();
                    reStart();
                }

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

                glfwSwapBuffers(window);
                glfwPollEvents();

            } while (!glfwWindowShouldClose(window));

            glfwDestroyWindow(window);
            glfwTerminate();
            exit(EXIT_SUCCESS);
        }
    };
}