#ifndef __SDL_GRAPHIC__
#define __SDL_GRAPHIC__

#include <Resource.hpp>


class SDLGraphic : public Resource
{
    private:
        SDL_Surface* image = nullptr;
        SDL_Texture* texture = nullptr;

    public:
        SDLGraphic (const char* filePath);
        SDLGraphic (SDL_Surface* image);

        void Dispose () override;

    private:
        void freeTexture ();

    public:
        SDL_Texture* Texture ();
};

#endif