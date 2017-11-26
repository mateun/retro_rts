#include <SDL2/SDL.h>
#include <editor.h>
#include <map>

extern std::map<std::string, SDL_Texture*> Textures;

static float camSpeed = 0.03;
static float camMoveX = 0;
static float camMoveY = 0;



void renderNeutralMap(int rows
		      , int cols
		      , SDL_Renderer* renderer
		      , SDL_Texture* backbuffer
		      , SDL_Texture* neutralTile)
{
  SDL_SetRenderTarget(renderer, backbuffer);
  SDL_SetRenderDrawColor(renderer, 0xcc, 0x00, 0x00, 0x00);
  SDL_RenderClear(renderer);
  SDL_Rect r;
  r.w = 64;
  r.h = 64;
  for (int x = 0; x < 64*10; x+=64)
    {
      for (int y = 0; y < 64*8; y+=64)
	{
	  r.x = x;
	  r.y = y;
	  SDL_RenderCopy(renderer, neutralTile, NULL, &r);
	  SDL_RenderDrawLine(renderer, x, 0, x, 800);
	  SDL_RenderDrawLine(renderer, 0, y, 600, y);
	}
    }
  SDL_RenderPresent(renderer);
}

std::string getTextureForMenuButton(const std::string& menu
				    , int mouseX
				    , int mouseY)
{
  int right = 0;
  int left = 0;
  int top = 0;
  int bot = 28;
  std::string baseMenuTextureName = "";
  if (menu == "new")
    {
      right = 64;
      left = 0;
      baseMenuTextureName = "btnNew";
    }
  if (menu == "save")
    {
      right = 128;
      left = 64;
      baseMenuTextureName = "btnSave";
    }

  if (mouseX > left
      && mouseX < right
      && mouseY > top
      && mouseY < bot)
    {
      return baseMenuTextureName + "Hovered"; 
    }
  else
    {
      return baseMenuTextureName; 
    }
}

void editorFrame(SDL_Renderer* renderer
		 , SDL_Event event
		 , SDL_Texture* backbuffer)
{
  if (event.type ==  SDL_KEYUP)
    {
      if (event.key.keysym.sym == SDLK_a)
	{
	  camMoveX += camSpeed;
	}
      if (event.key.keysym.sym == SDLK_d)
	{
	  camMoveX -= camSpeed;
	}
      if (event.key.keysym.sym == SDLK_w)
	{
	  camMoveY += camSpeed;
	}
      if (event.key.keysym.sym == SDLK_s)
	{
	  camMoveY -= camSpeed;
	}
    }
  SDL_SetRenderTarget(renderer, NULL);
  SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0x00);
  SDL_RenderClear(renderer);

  // We create a target rect which
  // is based on the current camera
  // position.
  // We essentially move the whole
  // backbuffer around.
  SDL_Rect r;
  r.x = camMoveX;
  r.y = camMoveY;
  r.w = 800;
  r.h = 600;
  SDL_RenderCopy(renderer, backbuffer, NULL, &r);

  // Render the main menu bar on top
  r.x = 0;
  r.y = 0;
  r.w = 800;
  r.h = 32;
  SDL_RenderCopy(renderer, Textures["menuBar"], NULL, &r);

  // We need the mouse coordinates to render
  // our menu buttons correctly,
  // e.g. when the mouse is hovering. 
  int mouseX =0;
  int mouseY = 0;
  SDL_GetMouseState(&mouseX, &mouseY);

  r.x = 0;
  r.y = 4;
  r.w = 64; 
  r.h = 24;
  SDL_RenderCopy(renderer, Textures[getTextureForMenuButton("new"
							    , mouseX
							    , mouseY)]
		 , NULL
		 , &r); 

  r.x = 64;

    SDL_RenderCopy(renderer
		 , Textures[getTextureForMenuButton("save"
						    , mouseX
						    , mouseY)]
		 , NULL, &r);
  
  SDL_RenderPresent(renderer);

}
