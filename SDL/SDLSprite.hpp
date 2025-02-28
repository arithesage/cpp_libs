#ifndef __SDL_SPRITE__
#define __SDL_SPRITE__

struct SDL_Rect;
struct SDL_Texture;

class SDLGraphic;

class Sprite
{
    private:
        SDL_Texture* texture = nullptr;

        int width = 0;
        int height = 0;

    public:
//        Sprite (SDLGraphic* graphic);
//        ~Sprite ();

        int Width ();
        int Height ();

        SDL_Texture* Texture ();
};

#endif
