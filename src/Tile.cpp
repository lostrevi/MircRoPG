#include "Tile.h"

Tile::Tile()
{
    //ctor
}


void Tile::init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int xa, int ya, int index)
{
    RenA = RenZ;
    SHEET = TEXT;
    x = xa;
    y = ya;

    Discover = 0; /// 0 is the player has not seen this tile yet. | 1 is the player has scene this tile but is not in sight of it | 2 is the player is now looking at the tiles.


    Index = index;

    LOC.x = x*TileSize;
    LOC.y = y*TileSize;
    LOC.w = LOC.h = CLIP.w = CLIP.h = TileSize;

    CLIP.y = (index/SheetWidth) * TileSize;

    CLIP.x = (index-(index/SheetWidth) * SheetWidth) * TileSize;

}
void Tile::update(int offsetx, int offsety)
{
    LOC.x += offsetx*TileSize;
    LOC.y += offsety*TileSize;

}
void Tile::draw()
{
    if(Discover == 0)
    {

    }
    else if (Discover == 1)
    {
        SDL_SetTextureColorMod(SHEET, 155,155,155);
        SDL_RenderCopy(RenA, SHEET, &CLIP, &LOC);
        SDL_SetTextureColorMod(SHEET, 255,255,255);
    }
    else
    {
        SDL_RenderCopy(RenA, SHEET, &CLIP, &LOC);
    }



}
