#include "FrameLimiter.hpp"

Uint32 FrameLimiter::FPS = 60;

FrameLimiter::FrameLimiter() : frameDelay((Uint64)1000 / FPS), frameStart(SDL_GetTicks64()), frameTime() {
	/* Empty by Design */
}

FrameLimiter::~FrameLimiter() {
	frameTime = SDL_GetTicks64() - frameStart;
	if (frameDelay > frameTime) SDL_Delay(frameDelay - frameTime);
}
