#include <stdio.h>
#include <string>
#include <map>

#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <editor.h>

// Two base modes of the program,
// we run either in editor mode
// to build maps and campaigns.
// Or we run in game mode to play
// and have fun :) 
#define BM_UNDEF -1
#define BM_EDITOR 0
#define BM_GAME 1

extern loadTextures(SDL_Renderer*);
extern std::map<std::string, SDL_Texture*> Textures;

static int BASE_MODE = BM_UNDEF;

int main(int argc, char** args)
{

  SDL_Window* window;
  SDL_Renderer* renderer;
  SDL_Event event;
  
  if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
      SDL_Log("Error init %s", SDL_GetError());
      return 1;
    }

  SDL_Log("init ok");

  SDL_CreateWindowAndRenderer(640, 480, SDL_WINDOW_SHOWN,
			      &window, &renderer);

  loadTextures(renderer);

  // Check for editor mode
  if (argc == 2)
    {
      std::string mode = std::string(args[1]);
      if (mode == "editor")
	{
	  BASE_MODE = BM_EDITOR;
	  renderNeutralMap(10, 10
			   , renderer
			   , Textures["backbuffer"]
			   , Textures["neutral"]);
	}
      else
	{
	  BASE_MODE = BM_GAME;
	}
    }
  
    while(true)
    {
      SDL_PollEvent(&event);
      if (event.type == SDL_QUIT)
	{
	  break;
	}


      if (BASE_MODE == BM_EDITOR) editorFrame(renderer, event
					      , Textures["backbuffer"]);
      // TODO add Game rendering here!

      
    }

  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();

  
  return 0;
}
