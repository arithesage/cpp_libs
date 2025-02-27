#include <SDLGraphic.hpp>

#include <SDL.hpp>
#include <Log.hpp>


SDLGraphic::SDLGraphic (const char* filePath)
{

}


SDLGraphic::SDLGraphic (SDL_Surface* image)
{
    if (image != nullptr)
    {
        this->image = image;
    }
}


void SDLGraphic::Dispose ()
{
    SDL::DestroySurface (image);
}


void SDLGraphic::freeTexture ()
{
    if (texture != nullptr)
    {
        Log::i ("Freeing unused texture...");
        SDL::DestroyTexture (texture);
        Log::i ("Done.");
    }
}


SDL_Texture* SDLGraphic::Texture ()
{
    if (image == nullptr)
    {
        return nullptr;
    }

    if (texture == nullptr)
    {
        Log::i ("Preparing texture...");

        texture = SDL::CreateTextureFrom (image);

        if (texture == nullptr)
        {
            return nullptr;
        }

        Log::i ("Done.");
    }

    return texture;
}