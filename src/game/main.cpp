#include "squaredengine.h"

// Entry point
int main(int argc, char* argv[])  // <- this must match exactly, since SDL rewrites it
{
    UNUSED(argc);
    UNUSED(argv);

    SquaredEngine Engine;

    Engine.SetTitle( "Loading..." );
    Engine.Init();

    Engine.SetTitle( "SDL Testing!" );
    Engine.Start();

    Engine.SetTitle( "Quitting..." );
    return 0;
}

