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


SDL_Surface* SDLGraphic::Image ()
{
    return image;
}


bool SDLGraphic::IsValid ()
{
    return (image != nullptr);
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


int SDLGraphic::Width ()
{
    if (image == nullptr)
    {
        return -1;
    }

    return image->w;
}


int SDLGraphic::Height ()
{
    if (image == nullptr)
    {
        return -1;
    }

    return image->h;
}