SET SDL_LIB_DIR="C:\Users\martin\Documents\Projects\C++\SDL2-2.0.7\i686-w64-mingw32\lib"

SET SDL_INC_DIR="C:\Users\martin\Documents\Projects\C++\SDL2-2.0.7\i686-w64-mingw32\include"


g++ main.cpp texture_loading.cpp editor.cpp  -L%SDL_LIB_DIR% -I%SDL_INC_DIR%  -lSDL2 -Iinclude -o build/game.exe

cp build\game.exe bin\game.exe
