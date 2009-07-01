#include "surface.h"
#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "filemanager.h"
#include <stdexcept>
#include <iostream>


bool Surface::setTransparency(int r, int g, int b)
{
  if(image == NULL) {
    return false;
  }

  SDL_SetColorKey(image , SDL_SRCCOLORKEY | SDL_RLEACCEL, SDL_MapRGB(image->format, r, g, b));
  return true;
}

Surface::Surface() :
        image(0) {
}

Surface::Surface(std::string filename) :
        image(0)
{
    load(filename);
}

Surface::~Surface() {
    if (image != 0) {
        SDL_FreeSurface(image);
        image = 0;
    }
}
SDL_Surface *Surface::getImage() {
    return image;
}

bool Surface::load(std::string filename) {
    SDL_Surface *tmp;
    std::string *fullFile = FileManager::getInstance()->searchFile(filename);
    
    if (fullFile == 0) {
        return false;
    }

    if((tmp = IMG_Load(fullFile->c_str())) == NULL) {
        delete fullFile;
        return false;
    }

    image = SDL_DisplayFormat(tmp);
    SDL_FreeSurface(tmp);
    tmp = 0;
    delete fullFile;
    return true;
}

bool Surface::draw(SDL_Surface* dest, int x, int y) {
    if ( dest != 0 || image != 0) {
        SDL_Rect d;
        d.x = x;
        d.y = y;

        SDL_BlitSurface(image, NULL, dest, &d);
        return true;
    }
    return false;
}


bool Surface::draw(Surface* dest, int x, int y) {
    if ( dest != 0) {
        return draw(dest->getImage(),x,y);
    }
    return false;
}


bool Surface::drawPartial(Surface *dest, int x, int y, int destX, int destY, int w, int h) {
    if (dest != 0) {
        return drawPartial(dest->getImage(),x,y,destX,destY,w,h);
    }
    return false;
}

bool Surface::drawPartial(SDL_Surface *dest, int x, int y, int destX, int destY, int w, int h) {
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
