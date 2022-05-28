#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <iostream>
#include <string>
#include <Windows.h>


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

    public:

        void Run()
        {
            bool GameRunning = true;
            float a, d = 0, b, c = 0.5;
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

                if (GetAsyncKeyState(VK_UP) & 0x8000 || GetAsyncKeyState(VK_UP) & 0x8001)
                {
                    b = 0.3;
                }
                
                else if (GetAsyncKeyState(VK_RIGHT) & 0x8000 || GetAsyncKeyState(VK_RIGHT) & 0x8001)
                {
                    a = 0.3;
                }

                else if (GetAsyncKeyState(VK_LEFT) & 0x8000 || GetAsyncKeyState(VK_LEFT) & 0x8001)
                {
                    a = -0.3;
                }
                else
                {
                    a = 0;
                    b = 0;
                }

                glClearColor(0, 0, 0, 0);
                glClear(GL_COLOR_BUFFER_BIT);
                glPointSize(30);
                glBegin(GL_POINTS);
                glColor3f(255, 255, 0);
                glVertex2f(a, b);

                if (GameRunning == true)
                {
                    if (c <= -1 && c != 0)
                    {
                        c -= 0.0005;
                        c = 1;
                    }
                    else if (c == 0.1)
                    {
                        c = 0.005;

                    }
                    else
                    {
                        c -= 0.0005;
                    }
                }
                if (GameRunning == false)
                {
                    if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
                    {
                        GameRunning = true;
                        c = 1;
                    }
                    if (GetAsyncKeyState(VK_SHIFT) & 0x8000 || GetAsyncKeyState(VK_SHIFT) & 0x8001)
                    {
                        break;
                    }
                }

                glPointSize(10);
                glBegin(GL_TRIANGLES);
                glColor3f(1, 1, 1);
                glVertex2f(c, d);
                glEnd();

                if (a == 0 && b == 0)
                {
                    if (c < 0.01 && c>-0.01)
                    {
                        GameRunning = false;
                        cout << "게임 오버";
                        glColor3f(0, 1, 0);

                        glEnd();
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
}// 어렵다 ㅠ