#ifndef CFONTMANAGER_H
#define CFONTMANAGER_H

#include <vector>
#include <string>
#include <SDL/SDL_ttf.h>

class CFontManager {
    public:
        CFontManager();
        ~CFontManager();

        int addFont(std::string fontName, int defaultSize = 16);
        TTF_Font *getFont(int fontId);

    private:
        std::vector<TTF_Font*> *fonts;
};

#endif // CFONTMANAGER_H
