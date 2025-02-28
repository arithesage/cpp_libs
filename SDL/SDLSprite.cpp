#include <SDLSprite.hpp>

#include <SDL2/SDL.h>

//#include <SDLGraphic.hpp>

/*
Sprite::Sprite (SDLGraphic* graphic)
{
    if (graphic != nullptr)
    {
        width = graphic->Width ();
        height = graphic->Height ();
    }
}


Sprite::~Sprite ()
{

}
*/

int Sprite::Width ()
{
    return width;
}


int Sprite::Height ()
{
    return height;
}


SDL_Texture* Sprite::Texture ()
{
    return texture;
}
