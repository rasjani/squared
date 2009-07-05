#include "surface.h"
#include "support.h"

Surface::Surface() :
    AnimationManager(),
	RawSurface()
{
}

Surface::Surface(std::string filename, int frames, AnimationManager::animStyle aStyle ) : 
    AnimationManager(frames, aStyle),
	RawSurface(filename)
{

}


Surface::~Surface() 
{
}


void Surface:: think(const int& elapsedTime) {
    UNUSED(elapsedTime);
    animate();
}
    
void Surface::render(SDL_Surface *destSurface) {
    UNUSED(destSurface);
}
