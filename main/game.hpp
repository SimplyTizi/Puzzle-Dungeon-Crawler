#include <SDL3/SDL.h>
#ifndef GAME_HPP
#define GAME_HPP
class Game {
public:
	int screenHeight;
	int screenWidth;
	SDL_AppResult sdl_AppResult;
	Game();
	~Game();

	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	void initialize();
	void handleEvents(SDL_Event* event);
	void update();
	void render();
	bool running() { return is_running; }

private:
	bool is_running;
	SDL_Window* window;
	SDL_Renderer* renderer;

};

#endif