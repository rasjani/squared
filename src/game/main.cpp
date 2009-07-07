#include "squaredengine.h"
#include "support.h"
#include "logger.h"

// Entry point
int main(int argc, char* argv[]) { // <- this must match exactly, since SDL rewrites it
    UNUSED(argc);
    UNUSED(argv);
    Logger *logger = Logger::getInstance();

    LOG( "Setting up the engine");
    SquaredEngine Engine;

    LOG( "Loading ...");
    Engine.SetTitle( "Loading..." );
    Engine.Init();

    LOG( "SDL Testing!");
    Engine.SetTitle( "SDL Testing!" );

    LOG( "Gameloop running!");
    Engine.Start();
    LOG( "Gameloop exited!");

    LOG( "SDL Testing!");
    Engine.SetTitle( "Quitting..." );
    LOG( "quit!!");

    if (! (ISREALLYNULL(logger)))
        delete logger;

    return 0;
}

