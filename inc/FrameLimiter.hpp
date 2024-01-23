/*****************************************************************//**
 * \file   FrameLimiter.h
 * \brief  
 * 
 * \author Muhammad Syamim
 * \date   21/01/2024
 *********************************************************************/
#pragma once
#include <SDL.h>

class FrameLimiter {
public:
	static Uint32 FPS;
	
	static void SetFPS(Uint32);

	FrameLimiter();
	~FrameLimiter();

private:
	Uint64 frameDelay;
	Uint64 frameTime;
	Uint64 frameStart;
};

