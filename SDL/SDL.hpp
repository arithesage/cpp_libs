#ifndef __SDL__
#define __SDL__

#include <FunctionPointers.hpp>

struct SDL_Event;
struct SDL_Renderer;
struct SDL_Window;

class SDLEventListener;
class SDLKeyboardListener;

class SDLKeyboardEvent;
class SDLQuitEvent;


/**
 * Class for managing SDL
 */
class SDL
{
    private:
        static SDL_Event event;
        static SDL_Renderer* renderer;
        static SDL_Window* window;

        static SDLKeyboardEvent onKey;
        static SDLQuitEvent onQuit;

        static FuncPtrP2<bool, SDL_Keycode> onKeyCallback;
        static FuncPtr onQuitCallback;

        static bool ready;

    public:
        /**
         * Initializes SDL (all systems)
         */
        static bool Init ();


        /**
         * Initializes SDL (only the specified systems)
         */
        static bool Init (int systems);


        /**
         * Initializes SDL (all systems) and also creates
         * a window and its renderer
         */
        static bool Init (const char* windowTitle,
                          int width,
                          int height);


        /**
         * Shutdowns SDL (destroy renderer and window if they were created)
         */
        static void Shutdown ();


        /**
         * Returns if SDL is initialized
         */
        static bool IsReady ();


        /**
         * Checks if there is any SDL event to handle and, if so,
         * fires the corresponding event to notify their subscribers
         */
        static void CheckForEvents ();


        /**
         * Creates a texture from a surface (uploads an image to the GPU VRAM)
         */
        static SDL_Texture* SDL::CreateTextureFrom (SDL_Surface* surface);


        /**
         * Creates a window with the given config
         */
        static bool CreateWindow (const char* windowTitle,
                                  int width,
                                  int height);


        /**
         * Frees the RAM used by a surface
         */
        static void SDL::DestroySurface (SDL_Surface* surface);


        /**
         * Frees the VRAM used by a texture
         */
        static void SDL::DestroyTexture (SDL_Texture* texture);


        /**
         * Returns the name of the given key
         */
        static const char* SDL::KeyName (SDL_Keycode key);


        /**
         * Sets a callback for keyboard events
         * 
         * @param callback Provides two parameters: 
         *                 - the status of the key 
         *                   (false: released, true: pressed)
         *                 
         *                 - the key itself
         */
        static void OnKey (FuncPtrP2<bool, SDL_Keycode> callback);


        /**
         * Subscribe for keyboard events.
         * 
         * The event provides the status of the key 
         * (false: released, true: pressed) and the key itself.
         */
        static void OnKey (SDLKeyboardListener* listener);


        /**
         * Sets a callback for SDL events like 'shutdown'
         */
        static void OnQuit (FuncPtr callback);


        /**
         * Subscribe for SDL events
         */
        static void OnQuit (SDLEventListener* listener);


        /**
         * Refresh the window
         */
        static void SDL::RefreshWindow ();


        /**
         * Returns the renderer
         */
        static SDL_Renderer* SDL::Renderer ();


        /**
         * Sets the rendering clear color
         */
        static void SetClearColor (SDL_Color color);


        /**
         * Returns the window
         */
        static SDL_Window* Window ();
};

#endif