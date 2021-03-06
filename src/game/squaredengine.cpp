#include "squaredengine.h"
#include "surface.h"
#include <SDL/SDL_ttf.h>
#include <sstream>
#include <iostream>
#include "filemanager.h"
#include "support.h"
#include "yoshient.h"
#include "yoshient2.h"
#include "logger.h"

SquaredEngine::SquaredEngine() :
        cm(0),
        fm(0),
        cem(0),
        fim(0) {}

int direction = 1;
void SquaredEngine::AdditionalInit() {
    LOG("Loading managers ...");
    // Load up additional data
    cm = INSTANCEPTROF(SurfaceManager);
    fm = new FontManager();
    cem = new EntityManager();
    fim = INSTANCEPTROF(FileManager);

    fim -> addSearchPath("./data");

    cem->addEntity( new YoshiEnt("yoshi.bmp",8));
    cem->addEntity( new YoshiEnt2("yoshi.bmp",8));

    myImageId = cm->addImage(new Surface("teatteri_nologo.jpg"));
    myFontId = fm->addFont("font.ttf");

    LOG("Loading managers ... done");
}

void SquaredEngine::think( const int& elapsedTime ) {
    cem->think(elapsedTime);

    // Do time-based calculations
}

void SquaredEngine::render( SDL_Surface* destSurface ) {
    // Display slick graphics on screen

    Surface *image = cm->getImage(myImageId);

    if (image != 0) {
        image->draw(destSurface,10,10);
    }

    cem->render(destSurface);

    if (myFontId != -1) {
        SDL_Rect d;
        d.x = 100;
        d.y = 100;
        SDL_Color fontcolor={250,250,250,0};
        std::stringstream ss;
        ss  << GetFPS();
        // ss  << a->getCurrentFrame();
        std::string foo;
        ss >> foo;
        SDL_Surface *temp =  TTF_RenderText_Solid(fm->getFont(myFontId),foo.c_str(),fontcolor);
        SDL_BlitSurface(temp,NULL,destSurface,&d);
        SDL_FreeSurface(temp);
    }
}

void SquaredEngine::End() {
    // Clean up
    if (cm != 0) {
        delete cm;
        cm = 0;
    }

    if (fm != 0) {
        delete fm;
        fm = 0;
    }

    if (cem != 0) {
        delete cem;
        cem = 0;
    }

    if (fim != 0) {
        delete fim;
        fim = 0;
    }
}

