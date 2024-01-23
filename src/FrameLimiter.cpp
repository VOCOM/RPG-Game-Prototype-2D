#include "FrameLimiter.hpp"

Uint32 FrameLimiter::FPS = 60;

void FrameLimiter::SetFPS(Uint32 newFPS) {
	FPS = newFPS;
}

FrameLimiter::FrameLimiter() : frameDelay((Uint64)1000 / FPS), frameStart(SDL_GetTicks64()), frameTime() {
	/* Empty by Design */
}

FrameLimiter::~FrameLimiter() {
	frameTime = SDL_GetTicks64() - frameStart;
	if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
}
