#include "cmyengine.h"
 
void CMyEngine::AdditionalInit()
{
        // Load up additional data
}
 
void CMyEngine::Think( const int& iElapsedTime )
{
        // Do time-based calculations
}
 
void CMyEngine::Render( SDL_Surface* pDestSurface )
{
        // Display slick graphics on screen
}
 
void CMyEngine::KeyDown(const int& iKeyEnum)
{        
    switch (iKeyEnum)
    {
    case SDLK_LEFT:
      // Left arrow pressed
      break;
    case SDLK_RIGHT:
      // Right arrow pressed
      break;
    case SDLK_UP:
      // Up arrow pressed
      break;
    case SDLK_DOWN:
      // Down arrow pressed
      break;
    }
}
 
 
void CMyEngine::KeyUp(const int& iKeyEnum)
{
        switch (iKeyEnum)
        {
        case SDLK_LEFT:
          // Left arrow released
          break;
        case SDLK_RIGHT:
          // Right arrow released
          break;
        case SDLK_UP:
          // Up arrow released
          break;
        case SDLK_DOWN:
          // Down arrow released
          break;
        }
}
 
void CMyEngine::MouseMoved(const int& iButton, 
                           const int& iX, 
                           const int& iY, 
                           const int& iRelX, 
                           const int& iRelY)
{
        // Handle mouse movement
 
        // iX and iY are absolute screen positions
        // iRelX and iRelY are screen position relative to last detected mouse movement
}
 
void CMyEngine::MouseButtonUp(const int& iButton, 
                              const int& iX, 
                              const int& iY, 
                              const int& iRelX, 
                              const int& iRelY)
{
        // Handle mouse button released
}
 
void CMyEngine::MouseButtonDown(const int& iButton, 
                                const int& iX, 
                                const int& iY, 
                                const int& iRelX, 
                                const int& iRelY)
{
        // Handle mouse button pressed
}
 
void CMyEngine::WindowInactive()
{
        // Pause game
}
 
void CMyEngine::WindowActive()
{
        // Un-pause game
}
 
 
void CMyEngine::End()
{
        // Clean up
}

