#pragma once
#include <GLFW/glfw3.h> //그래픽 라이브러리 프레임워크
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Player.hpp"




#pragma comment(lib,"OpenGL32")

static void error_callback(int error, const char* description)
{
    fputs(description, stderr);
}
static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GL_TRUE);
}

namespace LJH_Engine
{
    class LeeJHLoop
    {
    private:
        Player player;
        bool _isGameRunning;
        float playerX1 = player.playerMovex1;
        float playerX2 = player.playerMovex2;
        float playerY1 = player.playerMovey1;
        float playerY2 = player.playerMovey2;

    public:

        void Run()
        {
            _isGameRunning = true;
            while (_isGameRunning)
            {
                main();
            }

        }
        int main(void)
        {
            GLFWwindow* window;


            glfwSetErrorCallback(error_callback);
            if (!glfwInit())
                exit(EXIT_FAILURE);
            window = glfwCreateWindow(640, 480, "Simple example", NULL, NULL);
            if (!window)
            {
                glfwTerminate();
                exit(EXIT_FAILURE);
            }
            glfwMakeContextCurrent(window); //Context를 장악, gpu정리 , conext = 클래스묶음?    s = 스레드 = 동시에 여러개를 돌린다
            glfwSetKeyCallback(window, key_callback);

            float ratio;
            int width, height;
            glfwGetFramebufferSize(window, &width, &height); //framebuffer = 화면에 담겨질 메모리 공간?
            ratio = width / (float)height;

            while (!glfwWindowShouldClose(window))
            {
                glEnable(GL_BLEND);
                glBlendFunc(GL_SRC_ALPHA, GL_ONE);

                glClearColor(0.0f, 0.0f, 0.0f, 0.0f); // 화면을 한가지 색으로 채운다(클리어하겠다)
                glClear(GL_COLOR_BUFFER_BIT);

                glPointSize(10);
                glBegin(GL_TRIANGLES);

                glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                glVertex2f(playerX1, playerY1);
                glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                glVertex2f(playerX1, playerY2);
                glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                glVertex2f(playerX2, playerY2);

                glEnd();

                glPointSize(10);
                glBegin(GL_TRIANGLES);

                glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                glVertex2f(playerX1, playerY1);
                glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                glVertex2f(playerX2, playerY1);
                glColor4f(1.0f, 1.0f, 0.0f, 1.0f);
                glVertex2f(playerX2, playerY2);

                glEnd(); // 사각형

                //glPointSize(5);
                //glBegin(GL_TRIANGLES);

                //glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                //glVertex2f(moveBoxPointx2, moveBoxPointy2);
                //glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                //glVertex2f(moveBoxPointx1, moveBoxPointy2);
                //glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                //glVertex2f(moveBoxPointx1, moveBoxPointy1);

                //glEnd(); // 삼각형

                //glPointSize(5);
                //glBegin(GL_TRIANGLES);

                //glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                //glVertex2f(moveBoxPointx2, moveBoxPointy1);
                //glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                //glVertex2f(moveBoxPointx1, moveBoxPointy1);
                //glColor4f(1.0f, 0.0f, 1.0f, 1.0f);
                //glVertex2f(moveBoxPointx2, moveBoxPointy2);

                //glEnd();

                //if (xPoint < -1.0f)
                //    xPoint = 0.8f;
                //else
                 //   xPoint = xPoint - 0.02f;
               // if (xPoint2 < -1.2f)
                 //   xPoint2 = 0.6f;
                //else
                  //  xPoint2 = xPoint2 - 0.02f;
                /*if (moveBoxPointx2 < boxPointx2 && moveBoxPointx2 > boxPointx1 &&
                    moveBoxPointy2 > boxPointy2 && moveBoxPointy2 < boxPointy1) std::cout << "충돌";
                if (moveBoxPointx1 < boxPointx2 && moveBoxPointx1 > boxPointx1 &&
                    moveBoxPointy1 > boxPointy2 && moveBoxPointy1 < boxPointy1) std::cout << "충돌";
                if (moveBoxPointx1 < boxPointx2 && moveBoxPointx1 > boxPointx1 &&
                    moveBoxPointy2 > boxPointy2 && moveBoxPointy2 < boxPointy1) std::cout << "충돌";
                if (moveBoxPointx2 < boxPointx2 && moveBoxPointx1 > boxPointx1 &&
                    moveBoxPointy1 > boxPointy2 && moveBoxPointy2 < boxPointy1) std::cout << "충돌";*/




                glfwSwapBuffers(window); //그림 그리는걸 다른데서 미리하고 버퍼스왑으로 가져옴? 그리는 과정 안보여짐
                glfwPollEvents(); // 이벤트를 계속 체크
            }
            glfwDestroyWindow(window);
            glfwTerminate();
            exit(EXIT_SUCCESS);
        }


        ////cout << "Rendering speed : " << renderDuration.count() << "sec" << endl;

        //int remainingFrameTime = 100 - (int)(renderDuration.count() * 1000.0);
        //if (remainingFrameTime > 0)
        //	this_thread::sleep_for(chrono::milliseconds(remainingFrameTime));




    };
    
}


