// killerg_nc.cpp : ����Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include "common.h"
#include "cfg_file.h"
#include "engine.h"
#include "res_mgr.h"
#include "window.h"
#include "spirit.h"
#include "input.h"
#include "frame_rate.h"


int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	Engine::Init();

	Input input;
	input.Init();

	Window window;
	window.Init(800, 600, "killerg2d");

	ResMgr resmgr;
	resmgr.Init();
	
	FrameRate framerate;
	framerate.Init(600);

	Timer timer;
	timer.Init();

	SpiritAnimate spirit;
	spirit.Init("abc.txt");


	int x = 100, y = 100;
	int model = 0;
	while( !input.IsKeyDown(SDLK_ESCAPE) )
	{
		timer.Update();

		input.Update();

		if( input.IsKeyDown(SDLK_LEFT) )
			x-=1;

		if( input.IsKeyDown(SDLK_RIGHT) )
			x+=1;

		if( input.IsKeyDown(SDLK_UP) )
			y-=1;

		if( input.IsKeyDown(SDLK_DOWN) )
			y+=1;

		if( input.IsKeyDown(SDLK_x) )
			spirit.Play();

		if( input.IsKeyDown(SDLK_y) )
			spirit.Stop();

		spirit.Update(timer.GetIntervalF());

		window.Clear();

		spirit.Draw(&window, x, y);

		window.Flush();

		framerate.WaitFrame();
	}

	timer.Destroy();

	framerate.Destroy();

	resmgr.Destroy();

	window.Destroy();

	input.Destroy();


	Engine::Destroy();


	
}

