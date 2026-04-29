#ifndef SCENE_HPP
#define SCENE_HPP
#include "SDL3/SDL.h"
class Scene {
public:
	virtual void initialize() = 0;
	virtual void handleEvents(SDL_Event* event) = 0;
	virtual void update() = 0;
	virtual void render() = 0;
	bool running() { return is_running; }
private:
	bool is_running;
};


#endif 