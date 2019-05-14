#include "CMain.h"
#include <iostream>

CMain::CMain(int passed_iWeight, int passed_iHeight)
{
    iWeight = passed_iWeight, iHeight = passed_iHeight;
    win = nullptr;
    quit = false;
    SDL_Init(SDL_INIT_EVERYTHING);
	win = SDL_CreateWindow("sp5", 100, 100, iWeight, iHeight, SDL_WINDOW_SHOWN);
}

CMain::~CMain()
{
    SDL_DestroyWindow(win);
	SDL_Quit();
}

void CMain::loop()
{
    while (!quit)
    {
        while (SDL_PollEvent(&event) != 0)
        {
            if (event.type == SDL_QUIT)
                quit = true;
        }
    }
}
