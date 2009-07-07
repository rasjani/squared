#include "animationmanager.h"
#include <SDL/SDL.h>

/**
 * @brief Default constructor
 *
 **/
AnimationManager::AnimationManager() :
        currFrame(0),
        frameInc(1),
        frameRate(100),
        oldTime(0),
        maxFrames(0),
        aStyle(AnimationManager::AnimStill),
        backup(aStyle) {
}

AnimationManager::AnimationManager(int frames, animStyle style) :
        currFrame(0),
        frameInc(1),
        frameRate(100),
        oldTime(0),
        maxFrames(frames),
        aStyle(style),
        backup(style) {
}

void AnimationManager::resetClass() {
    aStyle = backup;
    currFrame = 0;
}

void  AnimationManager::setAnimStyle(animStyle animationStyle) {
    aStyle = animationStyle;
}

void AnimationManager::setMaxFrames(int noFrames) {
    maxFrames = noFrames;
}

void AnimationManager::setFrameRate(int rate) {
    frameRate = rate;
}

void AnimationManager::setCurrentFrame(int frame) {
    currFrame = frame;
}

int AnimationManager::getCurrentFrame() {
    return currFrame;
}

void AnimationManager::animate() {
    if ((unsigned int) (oldTime + frameRate) > SDL_GetTicks()) {
        return;
    }

    oldTime = SDL_GetTicks();

    if (aStyle != AnimStill)  {
        currFrame += frameInc;
    }

    switch (aStyle) {
        case AnimSingle:

            if (currFrame >= maxFrames -1 ) {
                setAnimStyle(AnimStill);
            }

            break;

        case AnimLoop:

            if (currFrame >= maxFrames - 1) {
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
