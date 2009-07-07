#ifndef RAWSURFACE_H
#define RAWSURFACE_H

#include <string>
#include <SDL.h>

class RawSurface {
    public:
        RawSurface();
        RawSurface (std::string filename);
        virtual ~RawSurface();

        bool load(std::string filename);
        bool draw(SDL_Surface *dest, int x, int y);
        bool draw(RawSurface *dest, int x, int y);

        bool drawPartial(SDL_Surface *dest, int x, int y, int destX, int destY, int w, int h);
        bool drawPartial(RawSurface *dest, int x, int y, int destX, int destY, int w, int h);
        bool setTransparency(int r, int g, int b);
        SDL_Surface *getImage();

    protected:
        SDL_Surface *image;

};


#endif // RAWSURFACE_H
