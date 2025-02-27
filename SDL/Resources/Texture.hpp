#ifndef __SDL_TEXTURE_RESOURCE__
#define __SDL_TEXTURE_RESOURCE__

#include <SDL.hpp>

struct SDL_Texture;

class Texture : public SDL::Resource
{
    private:
        SDL_Texture* texture = nullptr;

    public:
        Texture (const char* name, SDL_Texture* texture);

        /**
         * Frees this resource
         */
        void Dispose () override;
};

#endif