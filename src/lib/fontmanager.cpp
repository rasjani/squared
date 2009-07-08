#include "fontmanager.h"
#include <SDL/SDL_ttf.h>
#include <stdexcept>
#include "filemanager.h"

FontManager::FontManager() :
        fonts(0) {
    fonts = new std::vector<TTF_Font*>();
    TTF_Init();
}

FontManager::~FontManager() {
    if (fonts != 0 ) {
        std::vector<TTF_Font*>::iterator it;

        while (!fonts->empty()) {
            TTF_Font *fnt  = 0;
            it = fonts->begin();
            fnt = (*it);
            fonts->erase(it);
            TTF_CloseFont(fnt);
            fnt = 0 ;
        }

        delete fonts;

        fonts = 0;
    }

    TTF_Quit();

}


int FontManager::addFont(std::string fontName, int defaultSize ) {
    TTF_Font *f = 0;
    std::string *fullFile = 0;
    fullFile = INSTANCEOF(FileManager).searchFile(fontName);

    if (fullFile != 0) {
        f = TTF_OpenFont(fullFile->c_str(),defaultSize);
        delete fullFile;

        if (f != 0) {
            fonts->push_back(f);
            return fonts->size()-1;
        }
    }

    delete fullFile;

    return -1;

}

TTF_Font *FontManager::getFont(int fontId) {
    if (fonts != 0) {
        TTF_Font *f = 0;

        try  {
            f = fonts->at(fontId);
        } catch (std::out_of_range &e) {

        }

        return f;
    }

    return 0;
}
