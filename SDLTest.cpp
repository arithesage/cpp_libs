#include <SDL.hpp>

#include <Resource.hpp>
#include <Log.hpp>


class SDLGraphic : public Resource
{
    private:
        SDL_Surface* image = nullptr;
        SDL_Texture* texture = nullptr;

    public:
        SDLGraphic (const char* filePath)
        {

        }

        SDLGraphic (SDL_Surface* image)
        {
            if (image != nullptr)
            {
                this->image = image;
            }
        }

        void Dispose () override
        {
            SDL::DestroySurface (image);
        }

    private:
        void freeTexture ()
        {
            if (texture != nullptr)
            {
                Log::i ("Freeing unused texture...");
                SDL::DestroyTexture (texture);
                Log::i ("Done.");
            }
        }

    public:
        SDL_Texture* Texture ()
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
};


class Sprite
{
    private:
        SDLGraphic* graphic = nullptr;

    public:
        Sprite (SDLGraphic* graphic)
        {
            this->graphic = graphic;
        }


        ~Sprite ()
        {
            
        }
};


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