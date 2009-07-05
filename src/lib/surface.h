#ifndef SURFACE_H
#define SURFACE_H

#include "tasks.h"
#include "rawsurface.h"
#include "animationmanager.h"
/**
 * @brief Surface ... short description ...
 * @author Jani Mikkonen <ext-jani.3.mikkonen@nokia.com>
 * @date 2009-07-05
 * ... description ...
 */

class Surface : public RawSurface, public Tasks
{
  public:

    /**
     * Default constructor
     */
    Surface();

    Surface(std::string filename, int frames = 1 );

    /**
     * Destructor
     */
    virtual ~Surface();


    // Inherited from Tasks
    virtual void think(const int& elapsedTime);
    virtual void render(SDL_Surface *destSurface);


  protected:
    int currentFrame;
  private:

    int noOfFrames;
    AnimationManager *animControl;
};

#endif /* #ifndef SURFACE_H */
