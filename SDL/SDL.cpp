#include <SDL.hpp>

#include <SDLEventListener.hpp>
#include <SDLKeyboardListener.hpp>
#include <SDLEvents.hpp>
#include <Log.hpp>


SDL::Resource::Resource (const char* name)
{
    this->name = name;
}


SDL::Resource::~Resource ()
{
    Dispose ();
}


const char* SDL::Resource::Name ()
{
    return name;
}




SDL_Event SDL::event;
SDL_Renderer* SDL::renderer = nullptr;
SDL_Window* SDL::window = nullptr;

SDLKeyboardEvent SDL::onKey;
SDLQuitEvent SDL::onQuit;
FuncPtrP2<bool, SDL_Keycode> SDL::onKeyCallback = nullptr;
FuncPtr SDL::onQuitCallback = nullptr;

bool SDL::ready = false;


bool SDL::Init ()
{
    if (SDL_Init (SDL_INIT_EVERYTHING) < 0)
    {
        Log::ec ("Failed initializing SDL.", SDL_GetError());
        return false;
    }

    Log::i ("SDL initialized.");
    ready = true;

    return true;
}


bool SDL::Init (int systems)
{
    if (SDL_Init (systems) < 0)
    {
        Log::ec ("Failed initializing SDL.", SDL_GetError());
        return false;
    }

    Log::i ("SDL initialized.");
    ready = true;
    
    return true;
}


bool SDL::Init (const char* windowTitle, int width, int height)
{
    if (Init ())
    {
        return CreateWindow (windowTitle, width, height);
    }

    return false;
}


void SDL::Shutdown ()
{
    if (ready)
    {
        if (renderer != nullptr)
        {
            SDL_DestroyRenderer (renderer);
        }

        if (window != nullptr)
        {
            SDL_DestroyWindow (window);
        }

        Log::i ("Shutting down SDL.");

        SDL_Quit ();

        ready = false;
    }
}


bool SDL::IsReady ()
{
    return ready;
}


bool SDL::CreateWindow (const char* windowTitle, int width, int height)
{
    if (!ready)
    {
        if (!Init ())
        {
            return false;
        }
    }

    window = SDL_CreateWindow (
        windowTitle,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        width,
        height,
        SDL_WINDOW_SHOWN
    );

    if (window == nullptr)
    {
        Log::ec ("Failed creating window.", SDL_GetError ());
        return false;
    }

    renderer = SDL_CreateRenderer (
        window, 
        -1,
        SDL_RENDERER_ACCELERATED | 
        SDL_RENDERER_PRESENTVSYNC |
        SDL_RENDERER_TARGETTEXTURE
    );

    if (renderer == nullptr)
    {
        Log::ec ("Failed creating renderer.", SDL_GetError ());
        return false;
    }

    return true;
}


void SDL::CheckForEvents ()
{
    SDL_PollEvent (&event);

    if (event.type == SDL_QUIT)
    {
        
    }

    if ((event.type == SDL_KEYUP) || (event.type == SDL_KEYDOWN))
    {

    }
}


SDL_Texture* SDL::CreateTextureFrom (SDL_Surface* surface)
{
    if (renderer == nullptr)
    {
        Log::e ("Cannot access renderer. Create a window first.");
        return nullptr; 
    }

    SDL_Texture* texture = nullptr;

    if (surface == nullptr)
    {
        Log::e ("Cannot create texture. Invalid surface.");
    }
    else
    {
        texture = SDL_CreateTextureFromSurface (renderer, surface);

        if (texture == nullptr)
        {
            Log::ec ("Failed creating texture", SDL_GetError());
        }
    }

    return texture;
}


void SDL::DestroySurface (SDL_Surface* surface)
{
    if (surface != nullptr)
    {
        SDL_FreeSurface (surface);
    }
}


void SDL::DestroyTexture (SDL_Texture* texture)
{
    if (texture != nullptr)
    {
        SDL_DestroyTexture (texture);
    }
}


void SDL::DrawOn (SDL_Surface* image)
{
    if (image != nullptr)
    {
        SDL_LockSurface (image);

        SDL_UnlockSurface (image);
    }
}


SDL_Surface* SDL::GenerateImage (int width, int height, int depth)
{
    SDL_Surface* image = SDL_CreateRGBSurface (
        0,
        width,
        height,
        depth,
        0,
        0,
        0,
        0
    );
}


const char* SDL::KeyName (SDL_Keycode key)
{
    return SDL_GetKeyName (key);
}


void SDL::OnKey (SDLKeyboardListener* listener)
{
    if (listener != nullptr)
    {
        onKey.Subscribe (listener);
    }
}


void SDL::OnKey (FuncPtrP2<bool, SDL_Keycode> callback)
{
    if (callback != nullptr)
    {
        onKeyCallback = callback;
    }
}


void SDL::OnQuit (FuncPtr callback)
{
    if (callback != nullptr)
    {
        onQuitCallback = callback;
    }
}


void SDL::OnQuit (SDLEventListener* listener)
{
    if (listener != nullptr)
    {
        onQuit.Subscribe (listener);
    }
}


void SDL::RefreshWindow ()
{
    if (renderer != nullptr)
    {
        SDL_RenderPresent (renderer);
    }
}


SDL_Renderer* SDL::Renderer ()
{
    return renderer;
}


void SDL::SetClearColor (SDL_Color color)
{
    if (renderer != nullptr)
    {
        SDL_SetRenderDrawColor (renderer, color.r, color.g, color.b, color.a);
    }
}


SDL_Window* SDL::Window ()
{
    return window;
}