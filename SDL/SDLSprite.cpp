#include <SDLSprite.hpp>

#include <SDL2/SDL.h>

#include <SDLGraphic.hpp>


Sprite::Sprite (SDLGraphic* graphic)
{
    if (graphic != nullptr)
    {
        rect = new SDL_Rect();
        rect->w = graphic->Width();
        rect->h = graphic->Height();
    }
}


Sprite::~Sprite ()
{
    if (rect != nullptr)
    {
        delete rect;
    }
}


int Sprite::Width ()
{
    return rect->w;
}


int Sprite::Height ()
{
    return rect->h;
}


SDL_Texture* Sprite::Texture ()
{
    return texture;
}