#include "fontmanager.h"
#include <SDL/SDL_ttf.h>
#include <stdexcept>

FontManager::FontManager() :
  fonts(0)
{
  fonts = new std::vector<TTF_Font*>();
  TTF_Init();
}

FontManager::~FontManager() {
  if (fonts != 0 ) {
    std::vector<TTF_Font*>::iterator it;

    while(!fonts->empty()) {
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
  f = TTF_OpenFont(fontName.c_str(),defaultSize);
  if (f != 0) {
    fonts->push_back(f);
    return fonts->size()-1;
  }
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
