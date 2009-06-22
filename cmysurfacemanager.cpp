#include "csurfacemanager.h"
#include <iostream>
#include <stdexcept>

 CSurfaceManager::CSurfaceManager() :
         images(0)
{
    images = new std::vector<CSurface *>();
}

int CSurfaceManager::addImage(CSurface *image) {
    if (image != 0 && images != 0) {
        images->push_back(image);
        return images->size()-1;
    }
    return -1;
 }


 CSurface *CSurfaceManager::getImage(int imageId) {
    if (images != 0) {
      CSurface *s = 0;
      try  {
        s = images->at(imageId);
      } catch (std::out_of_range &e) {

      }
      return s;
    }
    return 0;
 }


CSurfaceManager::~CSurfaceManager() {
    // TODO: We are propably leaking memory here ?  
    if (images != 0) {
        std::vector<CSurface *>::iterator it;
        while (!images->empty() ) {
          CSurface *tmp  = 0;
          it = images->begin();
          tmp = (*it);
          images->erase(it);
          delete tmp;
        }
        delete images;
        images = 0;
    }
}

