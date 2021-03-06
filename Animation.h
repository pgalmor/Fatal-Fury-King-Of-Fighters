#ifndef __ANIMATION_H__
#define __ANIMATION_H__

#include "SDL/include/SDL_rect.h"
#define MAX_FRAMES 25

class Animation
{
public:
	bool loop = true;
	float speed = 1.0f;
	SDL_Rect frames[MAX_FRAMES];

	int pivotx[MAX_FRAMES];
	int pivoty[MAX_FRAMES];
	int pivotx2[MAX_FRAMES];
	int pivoty2[MAX_FRAMES];

	bool animend = false;
	float current_frame;
	int last_frame = 0;
	
private:

	int loops = 0;


public:

	void PushBack(const SDL_Rect& rect)
	{
		frames[last_frame++] = rect;
	}


	SDL_Rect& GetCurrentFrame()
	{
		animend = false;
		current_frame += speed;
		if (current_frame >= last_frame)
		{
			current_frame = (loop) ? 0.0f : last_frame - 1;
			loops++;
			animend = true;
		}

		return frames[(int)current_frame];
	}
	bool AnimFinished(){
	
		return animend;
	}

	bool Finished() const
	{
		return loops > 0;
	}

	int returnCurrentFrame() {
		return (int)current_frame;
	}

	void Reset()
	{
		current_frame = 0;
	}
};

#endif