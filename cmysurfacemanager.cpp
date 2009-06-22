#include "csurfacemanager.h"


 CSurfaceManager::CSurfaceManager() :
         images(0)
{
    images = new std::vector<CSurface *>();
}

 bool CSurfaceManager::addImage(CSurface *image) {
    if (image != 0 && images != 0) {
        images->push_back(image);
        return true;
    }
    return false;
 }


 CSurface *CSurfaceManager::getImage(std::string name) {
    if (images != 0) {
        std::vector<CSurface *>::iterator it;
        for (it = images->begin(); it < images->end(); it ++ ) {
             if ( (*it)->getName() == name )
                 return (*it);
        }

    }
    return 0;
 }


CSurfaceManager::~CSurfaceManager() {
    // TODO: We are propably leaking memory here ?  
    if (images != 0) {
        std::vector<CSurface *>::iterator it;
        while (!images->empty() ) {
            it = images->begin();
            SDL_FreeSurface((*it)->getImage());
            images->erase(it);
        }
        delete images;
        images = 0;
    }
}

