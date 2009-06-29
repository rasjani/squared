#ifndef ENTITY_H
#define ENTITY_H
#include <string>
#include <SDL/SDL.h>

#include "surface.h"
#include "animationmanager.h"

class Entity
{
  public:
    Entity(std::string image, int frames);

    virtual ~Entity();


    virtual void think(const int& elapsedTime);
    virtual void render(SDL_Surface *destSurface);

  protected:
    int _x;
    int _y;
    int _width;
    int _height;
    int _frame;
    int  surfaceId;

    AnimationManager *animControl;
    Surface *surface;

};

#endif /* #ifndef ENTITY_H */
