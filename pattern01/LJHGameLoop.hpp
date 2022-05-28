#pragma once
#include <GLFW/glfw3.h> //그래픽 라이브러리 프레임워크
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <iostream>
#include <chrono>
#include <thread>
#include "Player.hpp"

using namespace std;

namespace MuSeoun_Engine
{
	class LJHGameLoop
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
				Input();
			}

		}
		void Stop()
		{
			_isGameRunning = false;
		}

	private:
		void Input()
		{
			playerX1 = player.playerMovex1;
			playerX2 = player.playerMovex2;
			playerY1 = player.playerMovey1;
			playerY2 = player.playerMovey2;

			if (GetAsyncKeyState(VK_SPACE) & 0x8000 || GetAsyncKeyState(VK_SPACE) & 0x8001)
			{
				player.isKeyPressed();
			}
			else
			{
				player.isKeyUnpressed();
			}

		}

		void Update()
		{

			
		}
	};
}