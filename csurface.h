#ifndef CSURFACE_H
#define CSURFACE_H

#include <string>
#include <SDL/SDL.h>

class CSurface {
    public:
        CSurface();
        CSurface (char *filename);
        ~CSurface();

        bool load(char *filename);
        bool draw(SDL_Surface *dest, int x, int y);
        bool draw(CSurface *dest, int x, int y);

        bool drawPartial(SDL_Surface *dest, int x, int y, int destX, int destY, int w, int h);
        bool drawPartial(CSurface *dest, int x, int y, int destX, int destY, int w, int h);

        SDL_Surface *getImage();
        std::string getName();

    private:
        std::string  name;
        SDL_Surface *image;

};


#endif // CSURFACE_H
