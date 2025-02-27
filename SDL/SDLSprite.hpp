#ifndef __SDL_SPRITE__
#define __SDL_SPRITE__

struct SDL_Rect;
struct SDL_Texture;

class SDLGraphic;

class Sprite
{
    private:
        SDL_Texture* texture = nullptr;
        SDL_Rect* rect = nullptr;

    public:
        Sprite (SDLGraphic* graphic);
        ~Sprite ();

        int Width ();
        int Height ();
        
        SDL_Texture* Texture ();
};

#endif