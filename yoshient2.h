#ifndef YOSHIENT2_H
#define YOSHIENT2_H
#include "centity.h"


class YoshiEnt2 : public CEntity {
    public: 
    YoshiEnt2(std::string image, int frames);

    virtual void think(const int& elapsedTime);                                                                                                                         
    virtual void render(SDL_Surface *destSurface);


    private:
        int startX; 
        int startY;
        int endX;
        int endY;
};

#endif
