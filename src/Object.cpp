#include "Object.h"

Object::Object()
{
    //ctor
}

void Object::init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int x, int y, int index)
{
    RenA = RenZ;
    SHEET = TEXT;

    type = index;

    X = x;
    Y = y;

    //LOC.x = x*TileSize;
    //LOC.y = y*TileSize;
    //LOC.w = LOC.h = CLIP.w = CLIP.h = TileSize;

    TLOC.x = LOC.x = x*TileSize;
    TLOC.y = LOC.y = y*TileSize;
    TLOC.h = TLOC.w = LOC.w = LOC.h = CLIP.w = CLIP.h = TileSize;

    CLIP.y = (index/SheetWidth) * TileSize;

    CLIP.x = (index-(index/SheetWidth) * SheetWidth) * TileSize;

    if(index == 5 || index == 19)
    FillWithItems();

}
void Object::update(int offsetx, int offsety)
{
    LOC.x += offsetx*TileSize;
    LOC.y += offsety*TileSize;
    TLOC.x += offsetx*TileSize;
    TLOC.y += offsety*TileSize;

}
void Object::draw()
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

void Object::FillWithItems()
{
    for(int i = 0; i < MaxContents; i++)
    {
        if(rand() % 2 + 1 == 2)
        {
            GItemID++;
            item NEWITEM;
            NEWITEM.init(GItemID);
            NEWITEM.GenItem();
            Contents.push_back(NEWITEM);
        }

    }
}









