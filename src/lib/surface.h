#ifndef SURFACE_H
#define SURFACE_H

#include <string>
#include <SDL/SDL.h>

class Surface {
    public:
        Surface();
        Surface (std::string filename);
        ~Surface();

        bool load(std::string filename);
        bool draw(SDL_Surface *dest, int x, int y);
        bool draw(Surface *dest, int x, int y);

        bool drawPartial(SDL_Surface *dest, int x, int y, int destX, int destY, int w, int h);
        bool drawPartial(Surface *dest, int x, int y, int destX, int destY, int w, int h);
        bool setTransparency(int r, int g, int b);
        SDL_Surface *getImage();

    private:
        SDL_Surface *image;

};


#endif // SURFACE_H
