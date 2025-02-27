#include <Texture.hpp>


Texture::Texture (const char* name, SDL_Texture* texture)
: Resource (name)
{

}


/**
 * Frees this resource
 */
void Texture::Dispose ()
{
    if (texture != nullptr)
    {
        
    }
}