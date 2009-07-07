#ifndef TASKS_H
#define TASKS_H


#include <SDL.h>


/**
 * @brief Tasks ... short description ...
 * @author Jani Mikkonen <ext-jani.3.mikkonen@nokia.com>
 * @date 2009-07-05
 * ... description ...
 */

class Tasks {
    public:

        virtual void think(const int& elapsedTime) = 0;
        virtual void render(SDL_Surface *destSurface) = 0;

};

#endif /* #ifndef TASKS_H */
