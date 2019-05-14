#pragma once
#include <SDL2/SDL.h>

#ifndef CMAIN_H
#define CMAIN_H

class CMain
{
	private:
		int iWeight, iHeight;
		SDL_Window* win;
        bool quit;
        SDL_Event event;
	public:
		CMain(int iWeight, int iHeight);
		~CMain();

		void loop();
};

#endif
