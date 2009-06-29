#ifndef CENTITY_H
#define CENTITY_H
#include <string>
#include <SDL/SDL.h>

#include "csurface.h"
#include "canimation.h"

class CEntity
{
  public:
    CEntity(std::string image, int frames);

    virtual ~CEntity();


    virtual void think(const int& elapsedTime);
    virtual void render(SDL_Surface *destSurface);

  protected:
    int _x;
    int _y;
    int _width;
    int _height;
    int _frame;
    int  surfaceId;

    CAnimation *animControl;
    CSurface *surface;

};

#endif /* #ifndef CENTITY_H */
