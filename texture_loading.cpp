#include <SDL2/SDL.h>
#include <string>
#include <map>

static SDL_Surface* surface;
static SDL_Texture* texture;
static SDL_Texture* house;
static SDL_Texture* texBtnNew;
static SDL_Texture* texBtnSave;
static SDL_Texture* backbuffer;
static SDL_Texture* neutralTile;
static SDL_Texture* texMenuBar;

std::map<std::string, SDL_Texture*> Textures;

void loadTextures(SDL_Renderer* renderer)
{
  std::string basePath = std::string(SDL_GetBasePath());
  SDL_Log("basePath: %s", basePath.c_str());

  surface = SDL_LoadBMP("C:\\Users\\martin\\Documents\\Projects\\C++\\sdl_space_strategy\\bin\\grass.bmp");
  if (!surface)
    {
      SDL_Log("surface error: %s", SDL_GetError());
      return;
    }

  texture = SDL_CreateTextureFromSurface(renderer, surface);
  if (!texture)
    {
      SDL_Log("texture error");
      return;
    }

  std::string fullPath = basePath + "house.bmp";
  surface = SDL_LoadBMP(fullPath.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, 0);
  house = SDL_CreateTextureFromSurface(renderer, surface);

  fullPath = basePath + "btnNew.bmp";
  surface = SDL_LoadBMP(fullPath.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, 0);
  texBtnNew = SDL_CreateTextureFromSurface(renderer, surface);

  fullPath = basePath + "MenuBar.bmp";
  surface = SDL_LoadBMP(fullPath.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, 0);
  texMenuBar = SDL_CreateTextureFromSurface(renderer, surface);

  fullPath = basePath + "btnSave.bmp";
  surface = SDL_LoadBMP(fullPath.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, 0);
  texBtnSave = SDL_CreateTextureFromSurface(renderer, surface);

  fullPath = basePath + "btnSave_hovered.bmp";
  surface = SDL_LoadBMP(fullPath.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, 0);
  SDL_Texture* texBtnSaveHovered = SDL_CreateTextureFromSurface(renderer
								, surface);

  fullPath = basePath + "btnNew_hovered.bmp";
  surface = SDL_LoadBMP(fullPath.c_str());
  SDL_SetColorKey(surface, SDL_TRUE, 0);
  SDL_Texture* texBtnNewHovered = SDL_CreateTextureFromSurface(renderer
								, surface);



  SDL_FreeSurface(surface);

  backbuffer = SDL_CreateTexture(renderer, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_TARGET, 800, 600);

  Textures["backbuffer"] = backbuffer;
  Textures["btnNew"] = texBtnNew;
  Textures["btnSave"] = texBtnSave;
  Textures["btnSaveHovered"] = texBtnSaveHovered;
  Textures["btnNewHovered"] = texBtnNewHovered;
  Textures["house"] = house;
  Textures["neutral"] = texture;
  Textures["menuBar"] = texMenuBar;

}

