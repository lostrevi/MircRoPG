#ifndef PCELL_H
#define PCELL_H

#include "item.h"

class PCell
{
public:
        PCell();

    void init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int x, int y, bool dd);
    void update(int offsetx, int offsety);
    void draw();
    int Get_GridX()
    {
        return Gridx;
    }
    int Get_GridY()
    {
        return Gridy;
    }

    void Toggle_debug()
    {
        if(debug)
            debug = false;
        else
            debug = true;
    }

    void Set_Group(int a)
    {
        CLIP.x = TileSize;
        Group = a;
    }

    int Get_Group()
    {
        return Group;
    }

    void Destory()
    {
        Dead = true;
    }
    bool Check_Dead()
    {
        return Dead;
    }

    void Set_MODE(int a)
    {
        if(a == 1)
            CLIP.x = TileSize * 4;
        else
            CLIP.x = 0;
    }

    void Set_Looked(bool a)
    {
        CLIP.x = TileSize * 2;
        Looked = a;
    }

    bool Get_Looked()
    {
        return Looked;
    }

    void Set_Placeable(bool a)
    {
        Paceable = a;
    }

    bool Get_Placeable()
    {
        return Paceable;
    }

private:
    bool debug;
    bool Looked = false;
    bool Dead = false;

    int Group = -1;

    int Gridx;
    int Gridy;

    bool Paceable = false;

    SDL_Renderer *RenA;
    SDL_Texture *SHEET;
    SDL_Rect LOC;
    SDL_Rect CLIP;


    int TileSize = 25;
    int SheetWidth = 5;
};

#endif // PCELL_H
