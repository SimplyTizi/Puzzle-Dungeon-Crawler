#include "game.hpp"
#include <iostream>

Game::Game(){
    renderer = NULL;
    window = NULL;
    screenHeight = 0;
    screenWidth = 0;
    sdl_AppResult = SDL_APP_FAILURE;
    is_running = true;
}

Game::~Game() {

}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen) {

}

void Game::initialize() {
    SDL_SetAppMetadata("Example Renderer Clear", "1.0", "com.example.renderer-clear");

    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        std::cout << "no se pudo inicializar SDL" << SDL_GetError();
        sdl_AppResult = SDL_APP_FAILURE;
        return; // exits function
    }

    screenHeight = 800;
    screenWidth = 600;

    if (!SDL_CreateWindowAndRenderer("examples/renderer/clear", screenWidth, screenHeight, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window/renderer: %s", SDL_GetError());
        std::cout << "no se creo la ventana/renderer " << SDL_GetError();
        sdl_AppResult = SDL_APP_FAILURE;
        return; 
    }
    SDL_SetRenderLogicalPresentation(renderer, 640, 480, SDL_LOGICAL_PRESENTATION_LETTERBOX);
    sdl_AppResult = SDL_APP_CONTINUE;
}

void Game::handleEvents(SDL_Event * event) {
    if (event->type == SDL_EVENT_QUIT) {
        sdl_AppResult = SDL_APP_SUCCESS;  /* end the program, reporting success to the OS. */
        return;
    };
    sdl_AppResult = SDL_APP_CONTINUE;
}

void Game::update() {
    // fafafa
}


void Game::render() {
    const double now = ((double)SDL_GetTicks()) / 1000.0;  /* convert from milliseconds to seconds. */
    /* choose the color for the frame we will draw. The sine wave trick makes it fade between colors smoothly. */
    const float red = (float)(0.5 + 0.5 * SDL_sin(now));
    const float green = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 2 / 3));
    const float blue = (float)(0.5 + 0.5 * SDL_sin(now + SDL_PI_D * 4 / 3));
    SDL_SetRenderDrawColorFloat(renderer, red, green, blue, SDL_ALPHA_OPAQUE_FLOAT);  /* new color, full alpha. */

    /* clear the window to the draw color. */
    SDL_RenderClear(renderer);

    /* put the newly-cleared rendering on the screen. */
    SDL_RenderPresent(renderer);
}

