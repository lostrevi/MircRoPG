#ifndef OBJECT_H
#define OBJECT_H

#include "Tile.h"

class Object
{
public:
        Object();


    void init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int x, int y, int index);
    void update(int offsetx, int offsety);
    void draw();

    std::vector<item> Get_Contents()
    {
        return Contents;
    }

    void Clear_Contents()
    {
        Contents.clear();
    }

    int Get_type()
    {
        return type;
    }

    bool check_Full()
    {
        if(Contents.size() > MaxContents)
        return true;
        else
        return false;
    }

    item* Get_ContentsA(int i)
    {
        return &Contents[i];
    }

    void Set_Discover(int a)
    {
        Discover = a;
        if(Discover != 1)
        {
            LOC = TLOC;
        }
    }

    int Get_Discover()
    {
        return Discover;
    }

    int Get_X()
    {
        return X;
    }

    int Get_Y()
    {
        return Y;
    }

    void Delete_ITEM(int i)
    {
                    if(i != 0)
                    Contents.erase(Contents.begin() + i);
                    else
                    Contents.erase(Contents.begin());
    }

    bool Room_in_Contents() /// Will return true if there is room in the inventory
    {
        if(MaxContents > Contents.size())
            return true;
        else
            return false;
    }
    void Put_Item(item PUT) /// Put an item into the inventory;
    {
        Contents.push_back(PUT);
    }


private:


    SDL_Renderer *RenA;
    SDL_Texture *SHEET;
    SDL_Rect LOC;
    SDL_Rect TLOC;
    SDL_Rect CLIP;

    int Discover = 0;

    int type = 0;

    int X = 0;
    int Y = 0;

    std::vector<item> Contents;
    int MaxContents = 5;
    void FillWithItems();

    int TileSize = 25;
    int SheetWidth = 5;
};

#endif // OBJECT_H
