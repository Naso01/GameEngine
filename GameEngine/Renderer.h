#ifndef RENDERER_H
#define RENDERER_H

#include "StandardIncludes.h"
#include "Texture.h"

class Asset;

class Renderer : public Singleton<Renderer>
{
public:
    //Constuctors/Destructors
    Renderer();
    virtual ~Renderer();

    // Accessors
    SDL_Window* GetWindow() { return m_window; }
    SDL_Renderer* GetRenderer() { return m_renderer; }
    SDL_Texture* GetSDLTexture(Texture* _texture);

    // Methods
    void Initialize(int xResolution, int yResolution);
    Point GetWindowSize();//returns view size (Wrapper function)

    void SetDrawColor(Color _color);
    void ClearScreen();
    void SetViewport(Rect _viewport);

    void RenderPoint(Point _position);
    void RenderLine(Rect _points);
    void RenderRectangle(Rect _rect);
    void RenderFillRectangle(Rect _rect);

    //Renders at full size and from a point
    void RenderTexture(Texture* _texture, Point _point);
    //Renders at the size of the rectangle
    void RenderTexture(Texture* _texture, Rect _rect);
    //grabs a fraction of the texture to be rendered only
    void RenderTexture(Texture* _texture, Rect _srcRect, Rect _destRect);
    //Renders Texture with possible rotation angle
    void RenderTexture(SDL_Texture* _texture, Rect _srcRect, Rect _desRect, double _angle);


    void Shutdown();

private:             
    // Members
    SDL_Window* m_window;
    SDL_Renderer* m_renderer;

    SDL_Rect m_srcRect;
    SDL_Rect m_destRect;

    SDL_Surface* m_surface;
    SDL_Rect m_viewPort; 
    map<string, SDL_Texture*> m_textures;


};

#endif // RENDERER_H