#include "PCell.h"

PCell::PCell()
{
    //ctor
}

void PCell::init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int x, int y, bool dd)
{
    Gridx = x;
    Gridy = y;

    int index = 20; /// red cell
    RenA = RenZ;
    SHEET = TEXT;

    LOC.x = x*TileSize;
    LOC.y = y*TileSize;
    LOC.w = LOC.h = CLIP.w = CLIP.h = TileSize;

    CLIP.y = (index/SheetWidth) * TileSize;

    CLIP.x = (index-(index/SheetWidth) * SheetWidth) * TileSize;

    debug = dd;

}
void PCell::update(int offsetx, int offsety)
{
    LOC.x += offsetx*TileSize;
    LOC.y += offsety*TileSize;

}
void PCell::draw()
{
    if(debug && !Dead)
    SDL_RenderCopy(RenA, SHEET, &CLIP, &LOC);
}
