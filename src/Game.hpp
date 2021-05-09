#ifndef Game_hpp 
#define Game_hpp

#include <SDL2/SDL.h>
#include <iostream>


class Game {
public:
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean(); 
	bool running() {return isRunning;}



private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_Surface *valcron = SDL_LoadBMP("valcron.bmp");
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, valcron);


};


#endif /* Game_hpp */