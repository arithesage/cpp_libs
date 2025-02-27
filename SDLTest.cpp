#include <SDL.hpp>

#include <SDLGraphic.hpp>
#include <Resource.hpp>
#include <Log.hpp>



int main ()
{
    SDL::Init ();

    SDL_Surface* testImage = SDL::GenerateImage (256, 256, 32);

    SDLGraphic testGraphic (testImage);

    SDL_Texture* tex = testGraphic.Texture();

    testGraphic.Dispose ();

    SDL::Shutdown ();

    return 0;
};