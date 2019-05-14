#pragma once
#include <SDL2/SDL.h>

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
