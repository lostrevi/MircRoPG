#ifndef TILE_H
#define TILE_H

#include "MOB.h"

class Tile
{
    public:
        Tile();

    void init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int xa, int ya, int index);
    void update(int offsetx, int offsety);
    void draw();

    int Discover;

    int Get_Discover()
    {
        return Discover;
    }
    void Set_Discover(int a)
    {
        Discover = a;
    }


    int Get_X()
    {
        return x;
    }
    int Get_Y()
    {
        return y;
    }
    int Get_Index()
    {
        return Index;
    }

    private:
    int x;
    int y;

    int Index;

    SDL_Renderer *RenA;
    SDL_Texture *SHEET;
    SDL_Rect LOC;
    SDL_Rect CLIP;

    int TileSize = 25;
    int SheetWidth = 5;
};

#endif // TILE_H
