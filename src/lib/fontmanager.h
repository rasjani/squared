#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <vector>
#include <string>
#include <SDL/SDL_ttf.h>

class FontManager {
    public:
        FontManager();
        ~FontManager();

        int addFont(std::string fontName, int defaultSize = 16);
        TTF_Font *getFont(int fontId);

    private:
        std::vector<TTF_Font*> *fonts;
};

#endif // FONTMANAGER_H
