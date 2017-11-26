#pragma once
#include <SDL2/SDL.h>

void editorFrame(SDL_Renderer* renderer
		 , SDL_Event event
		 , SDL_Texture* backbuffer);

void renderNeutralMap(int rows, int cols
		      , SDL_Renderer*
		      , SDL_Texture* backbuffer
		      , SDL_Texture* neutral);
