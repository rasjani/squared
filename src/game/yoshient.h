#ifndef YOSHIENT_H
#define YOSHIENT_H
#include "centity.h"


class YoshiEnt : public CEntity {
    public: 
    YoshiEnt(std::string image, int frames);

    virtual void think(const int& elapsedTime);                                                                                                                         
    virtual void render(SDL_Surface *destSurface);


    private:
        int startX; 
        int startY;
        int endX;
        int endY;
        int betweenX;
        int betweenY;
};

#endif