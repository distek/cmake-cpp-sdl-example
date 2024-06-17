#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char **argv) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		fprintf(stderr, "ERROR: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_LogSetAllPriority(SDL_LOG_PRIORITY_VERBOSE);

	SDL_Window *window =
	    SDL_CreateWindow("Test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			     SCREEN_WIDTH, SCREEN_HEIGHT, 0);
	if (window == NULL) {
		fprintf(stderr, "ERROR: can't create window: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	SDL_Renderer *renderer = SDL_CreateRenderer(
	    window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL) {
		fprintf(stderr, "ERROR: can't create renderer: %s\n", SDL_GetError());
		return EXIT_FAILURE;
	}

	// The above call to SDL_LogSetAllPriority() should make SDL print which
	// backend was used when creating the renderer, but do it ourselves anyway.
	SDL_RendererInfo info;
	SDL_GetRendererInfo(renderer, &info);
	printf("Renderer backend: %s\n", info.name);

	int running = 1;
	while (running) {
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = 0;
				break;
			}
		}

		SDL_SetRenderDrawColor(renderer, 12, 34, 56, 255);
		SDL_RenderClear(renderer);

		SDL_Rect rect = {20, 20, SCREEN_WIDTH - 40, SCREEN_HEIGHT - 40};
		SDL_SetRenderDrawColor(renderer, 78, 9, 10, 255);
		SDL_RenderFillRect(renderer, &rect);

		SDL_RenderPresent(renderer);
	}

	SDL_Quit();

	return EXIT_SUCCESS;
}
