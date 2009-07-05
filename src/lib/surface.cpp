#include "surface.h"
#include "engine.h"

Surface::Surface() :
	RawSurface(),
    currentFrame(0),
    noOfFrames(0),
    animControl(0)
{
}

Surface::Surface(std::string filename, int frames ) :
	RawSurface(filename),
    currentFrame(0),
    noOfFrames(frames),
    animControl(0)
{
    animControl = new AnimationManager();
    animControl->setMaxFrames(frames);
    animControl->setAnimStyle(AnimationManager::AnimLoop);

}


Surface::~Surface() 
{
    if (animControl != 0)  {
        delete animControl;
        animControl = 0;
    }
}


void Surface:: think(const int& elapsedTime) {
    UNUSED(elapsedTime);
    if (animControl != 0) {
        animControl->animate();
    }
    currentFrame = animControl->getCurrentFrame();
}
    
void Surface::render(SDL_Surface *destSurface) {
    UNUSED(destSurface);

}
