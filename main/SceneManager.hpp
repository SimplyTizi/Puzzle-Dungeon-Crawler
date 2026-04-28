#ifndef SceneManager_hpp
#define SceneManager_hpp
#include "SDL3/sdl.h"
#include "Scene.hpp"

class SceneManager {
public:
	Scene* currentScene;

	
private:
	bool is_running;
	SDL_Window* window;
	SDL_Renderer* renderer;

};



#endif