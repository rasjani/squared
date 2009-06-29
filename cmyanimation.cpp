#include "canimation.h"
#include <SDL/SDL.h>

CAnimation::CAnimation() :
    currFrame(0),
    frameInc(1),
    frameRate(100),
    oldTime(0),
    maxFrames(0),
    oscillate(false),
    aStyle(AnimStill)
{ 
}

void  CAnimation::setAnimStyle(animStyle animationStyle) {
    aStyle = animationStyle;
}

void CAnimation::setMaxFrames(int noFrames) {
  maxFrames = noFrames;
}

void CAnimation::setFrameRate(int rate) {
  frameRate = rate;
}

void CAnimation::setCurrentFrame(int frame) {
  currFrame = frame;
}

int CAnimation::getCurrentFrame() {
  return currFrame;
}

void CAnimation::animate() {
      if ((unsigned int) (oldTime + frameRate) > SDL_GetTicks()) {
        return;
    }

    oldTime = SDL_GetTicks();

    if (aStyle != AnimStill)  {
        currFrame += frameInc;
    }
    switch(aStyle) {
        case AnimSingle:
            if (currFrame >= maxFrames -1 ) {
                setAnimStyle(AnimStill);
            }
            break;
        case AnimLoop:
            if(currFrame >= maxFrames - 1) {
              currFrame = 0;
            }
            break;
        case AnimSingleThrobbing:
            if (frameInc > 0) {
                if (currFrame >= maxFrames - 1 ) {
                    frameInc = -frameInc;
                }
            } else {
                if (currFrame <= 0 ) {
                    setAnimStyle(AnimStill);
                    frameInc = -frameInc;
                }
            }
            break;
        case AnimThrobbing:
            if (frameInc > 0) {
                if (currFrame >= maxFrames - 1 ) {
                    frameInc = -frameInc;
                }
            } else {
                if (currFrame <= 0 ) {
                    frameInc = -frameInc;
                }
            }
            break;
        default:
            break;
    }
}
