#include "csurface.h"
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

CSurface::CSurface() :
        name(""),
        image(0) {
}

CSurface::CSurface(char *filename) :
        name(""),
        image(0)
{
    load(filename);
}

CSurface::~CSurface() {
    if (image != 0) {
        SDL_FreeSurface(image);
        image = 0;
    }
}
SDL_Surface *CSurface::getImage() {
    return image;
}

std::string CSurface::getName() {
    return name;
}


bool CSurface::load(char *filename) {
    SDL_Surface *tmp;

    if (image != 0) {
        return false;
    }

    if((tmp = IMG_Load(filename)) == NULL) {
        return false;
    }


    name = std::string(filename);
    image = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    return true;
}

bool CSurface::draw(SDL_Surface* dest, int x, int y) {
    if ( dest != 0 || image != 0) {
        SDL_Rect d;
        d.x = x;
        d.y = y;

        SDL_BlitSurface(image, NULL, dest, &d);
        return true;
    }
    return false;
}


bool CSurface::draw(CSurface* dest, int x, int y) {
    if ( dest != 0) {
        return draw(dest->getImage(),x,y);
    }
    return false;
}


bool CSurface::drawPartial(CSurface *dest, int x, int y, int destX, int destY, int w, int h) {
    if (dest != 0) {
        return drawPartial(dest->getImage(),x,y,destX,destY,w,h);
    }
    return false;
}

bool CSurface::drawPartial(SDL_Surface *dest, int x, int y, int destX, int destY, int w, int h) {
    if ( dest != 0 || image != 0) {
        SDL_Rect d;
        SDL_Rect s;
        d.x = x;
        d.y = y;

        s.x = destX;
        s.y = destY;
        s.h = h;
        s.w = w;

        SDL_BlitSurface(image, &s, dest, &d);
        return true;
    }
    return false;
}
