#ifndef MOB_H
#define MOB_H

#include "PCell.h"

class MOB
{
    public:
        MOB();

    void init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int xa, int ya, int index, bool Playeris);
    void update(int offsetx, int offsety);
    void draw();

    int _3D6Roller(bool snowFlake);

    int Get_Mod(int Stat);

    int GetAttack(); /// STR and DEX based
    int GetDeffence(); /// CON / WIS based will use items once those are in the game

    void RollStats();

    void Take_Damage(int a) ///Take Damage is what it sounds like it lowers HP and then check to see if it is dead.
    {
        HP -= a;
        if(HP < 1)
            Dead = true;
    }

    void Set_ShopKeeper(bool a)
    {
        ShopKeeper = a;
    }

    bool isShopkeeper()
    {
        return ShopKeeper;
    }

    int Get_HP()
    {
        return HP;
    }
    int Get_MHP()
    {
        return MAXHP;
    }

    int Get_Sight()
    {
        return Sight;
    }

    int Get_X()
    {
        return x;
    }
    int Get_Y()
    {
        return y;
    }

    bool isPlayer()
    {
        return player;
    }

    SDL_Rect Get_LOC()
    {
        return LOC;
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

    bool Check_Effect_FarSite()
    {
        return FarSite;
    }
    void Set_Effect_FarSite(bool a)
    {
        FarSite = a;
    }

    bool Check_doaction()
    {
        return DoAction;
    }
    void Did_Action()
    {
        DoAction = false;
    }

    int Get_STR()
    {
        return STR;
    }

    int Get_DEX()
    {
        return DEX;
    }

    int Get_CON()
    {
        return CON;
    }

    int Get_INT()
    {
        return INT;
    }

    int Get_WIS()
    {
        return WIS;
    }

    int Get_CHA()
    {
        return CHA;
    }

    std::string Get_Sex()
    {
        if(Sex)
            return "Male";
        else
            return "Female";

    }

    void Delete_ITEM(int i)
    {
        Money ++;

            if(i != 0)
            Invnetory.erase(Invnetory.begin() + i);
            else
            Invnetory.erase(Invnetory.begin());
    }

    std::vector<item> Get_Invenotry()
    {
        return Invnetory;
    }

    bool Room_in_Inventory() /// Will return true if there is room in the inventory
    {
        if(Inventory_size > Invnetory.size())
            return true;
        else
            return false;
    }
    void Put_Item(item PUT) /// Put an item into the inventory;
    {
        Invnetory.push_back(PUT);
    }

    void Use_Item(item USE) /// This put the item in the Mobs uses spot and they will get the effect
    {
        UseSlot = USE;
    }


    bool Check_Dead() /// when this is true and object should be made where the object is with its contents then it should be deleted
    {
        return Dead;
    }
    bool Check_Destory() /// when this is true the clean up should delete it.
    {
        return Destory;
    }

    item* Get_InvenotryA(int i)
    {
        return &Invnetory[i];
    }

    void UnEquippedallofType(int a)
    {
        for(int i = 0; i < Invnetory.size(); i ++)
        {
            if(Invnetory[i].Get_Equipped() == a)
            {
                Invnetory[i].Set_Equipped(0);
            }
        }
    }

    int Get_type()
    {
        return type;
    }

    void Change_Gold(int a) /// put a number in here and it will add it or sub it;
    {
        Money += a;
    }

    int Get_Gold()
    {
        return Money;
    }

    void FillWithItems();

    void SetEQDRAW(SDL_Texture *a)
    {
        EQDRAW = a;
    }


    void Move(int xa,int ya);

private:
    bool player = false;
    bool ShopKeeper = false;

    bool ItemEqupit = false;
    SDL_Texture *EQDRAW;

    int Money;

    int TimerZZ = 0;
    int TimerZZMAX = 40;

    std::string Name = "Bob"; //default

    void GenName();

    int Varenet = 0;

    int Sight;

    int Discover;

    int x;
    int y;

    int type;

    // They die first then it will make an object at there x and y with there items after this it will set the Destory Bool to true and clean up will destory it.
    bool Dead = false;
    bool Destory = false;


    int MobTimerA = 0;
    int MobTimerAMAX;

    bool DoAction = false;


    bool FarSite = false;

    int STR; // use for str based wep asl this is a punch
    int DEX; // used for dex based weaps
    int CON; // used to find mobs hp
    int INT; // not sure yet
    int WIS; // getting item stats and discriptons
    int CHA; // lol

    int HP;
    int MAXHP;

    bool Sex; /// Male or Female

    std::vector<item> Invnetory;

    item UseSlot;

    int Inventory_size = 7;

    void Update_UseSlot();


    SDL_Renderer *RenA;
    SDL_Texture *SHEET;
    SDL_Rect LOC;
    SDL_Rect TLOC;
    SDL_Rect CLIP;

    int TileSize = 25;
    int SheetWidth = 5;
};





#endif // MOB_H
