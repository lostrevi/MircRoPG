#include "MOB.h"

MOB::MOB()
{
    //ctor
}

/// if dicover is 1 gray them out and don't update there movement unless it is in the players sight.

void MOB::init(SDL_Renderer *RenZ, SDL_Texture *TEXT, int xa, int ya, int index, bool Playeris)
{
    RenA = RenZ;
    SHEET = TEXT;

    Money = 0;

    Money = rand() % 10;


        HP = 0;
        STR = 0;
        DEX = 0;
        CON = 0;
        INT = 0;
        WIS = 0;
        CHA = 0;

        MobTimerAMAX = 0;


    UseSlot.set_DonotUSE(true);

    MobTimerAMAX = rand() % 40 + 10;

    if(rand() % 2 + 1 == 2)
        Sex = false;
    else
        Sex = true;

    if(Playeris)
    {
        Discover = 5;
    }
    else
        Discover = 0;

    x = xa;
    y = ya;

    Sight = 3;

    type = index;

    player = Playeris;

    RollStats();

    TLOC.x = LOC.x = x*TileSize;
    TLOC.y = LOC.y = y*TileSize;
    TLOC.h = TLOC.w = LOC.w = LOC.h = CLIP.w = CLIP.h = TileSize;

    CLIP.y = (index/SheetWidth) * TileSize;

    CLIP.x = (index-(index/SheetWidth) * SheetWidth) * TileSize;

    FillWithItems();

    if(player == false)
    {
        for(int i = 0; i < Invnetory.size(); i++) /// look for weps and armor and equpit the to the monsters
        {
            if(Invnetory[i].Get_type() == 1)
            {
                if(rand() % 10 + 1 > 2)
                {
                    UnEquippedallofType(1);
                    Invnetory[i].Set_Equipped(1);
                }
            }
            else if(Invnetory[i].Get_type() == 2)
            {
                if(rand() % 10 + 1 > 2)
                {
                    UnEquippedallofType(2);
                    Invnetory[i].Set_Equipped(2);
                }
            }
        }
    }


}
void MOB::update(int offsetx, int offsety)
{
    if(MobTimerA != MobTimerAMAX && !DoAction)
        MobTimerA ++;

    if(TimerZZ != TimerZZMAX)
    TimerZZ ++;

    if(TimerZZ == TimerZZMAX)
    {
        ItemEqupit = false;
        for(int i = 0; i < Invnetory.size(); i++)
        {
            if(Invnetory[i].Get_Equipped() != 0)
            {
                ItemEqupit = true;
            }

        }
        TimerZZ = 0;
    }



    if(MobTimerA == MobTimerAMAX)
    {
        MobTimerA = 0;
        DoAction = true;
    }

    LOC.x += offsetx*TileSize;
    LOC.y += offsety*TileSize;
    TLOC.x += offsetx*TileSize;
    TLOC.y += offsety*TileSize;

    Update_UseSlot();
}
void MOB::draw()
{
    if(Discover != 0 && Discover != 1)
    {
        if(Varenet == 0)
        SDL_RenderCopy(RenA, SHEET, &CLIP, &LOC);
            if(ItemEqupit)
                SDL_RenderCopy(RenA, EQDRAW, NULL, &LOC);

        else if(Varenet == 1)
        {
            SDL_SetTextureColorMod(SHEET, 255,0,0); //red
            SDL_RenderCopy(RenA, SHEET, &CLIP, &LOC);
            SDL_SetTextureColorMod(SHEET, 255,255,255);
            if(ItemEqupit)
                SDL_RenderCopy(RenA, EQDRAW, NULL, &LOC);
        }

        else if(Varenet == 2)
        {
            SDL_SetTextureColorMod(SHEET, 0,0,255); //blue
            SDL_RenderCopy(RenA, SHEET, &CLIP, &LOC);
            SDL_SetTextureColorMod(SHEET, 255,255,255);
            if(ItemEqupit)
                SDL_RenderCopy(RenA, EQDRAW, NULL, &LOC);
        }
    }

    if(Discover == 1)
    {
            SDL_SetTextureColorMod(SHEET, 155,155,155); //blue
            SDL_RenderCopy(RenA, SHEET, &CLIP, &LOC);
            SDL_SetTextureColorMod(SHEET, 255,255,255);
    }

}


void MOB::Move(int xa,int ya)
{
    x += xa;
    y += ya;

    if(Discover != 1) // because 0 doesn't matter
    {
        LOC.x += xa*TileSize;
        LOC.y += ya*TileSize;
    }

    TLOC.x += xa*TileSize;
    TLOC.y += ya*TileSize;

}



void MOB::RollStats()
{

        bool SnowFlake = false;
        if(rand() % 50 + 1 == 50)
        {
            SnowFlake = true;
        }

    if(player)
    {

        STR = _3D6Roller(SnowFlake);
        DEX = _3D6Roller(SnowFlake);
        CON = _3D6Roller(SnowFlake);
        INT = _3D6Roller(SnowFlake);
        WIS = _3D6Roller(SnowFlake);
        CHA = _3D6Roller(SnowFlake);



        HP = rand() % 10 + 1; /// standered hit die for all PCs a d10
        HP += rand() % 10 + 1; /// doing 4 because your kinda just thrown in here.
        HP += rand() % 10 + 1;
        HP += rand() % 10 + 1;
        HP += Get_Mod(CON);
        MAXHP = HP;

    }
    else
    {

        if( type == 3 ) ///SkellyBelly Mob
        {
            int VMOD = rand() % 50 + 1;
            if(VMOD > 40) // Red var
            {
                Varenet = 1;
            }
            if(VMOD > 49) // Red var
            {
                Varenet = 2;
            }
            VMOD = 0;

            if(Varenet != 0)
                VMOD = rand() % 6*Varenet + 1;
            STR = 10 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 6*Varenet + 1;
            DEX = 14 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 6*Varenet + 1;
            CON = 15 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 6*Varenet + 1;
            INT = 6 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 6*Varenet + 1;
            WIS = 8 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 6*Varenet + 1;
            CHA = 5 + VMOD;

            if(Varenet != 0)
            VMOD = rand() % 10*Varenet + 1;

            HP += VMOD;
            HP += rand() % 8 + 1;
            HP += rand() % 8 + 1;
            HP += 4;
            MAXHP = HP;

        }
        else if( type == 4 ) ///BatMons
        {
            int VMOD = rand() % 50 + 1;
            if(VMOD > 40) // Red var
            {
                Varenet = 1;
            }
            if(VMOD == 50) // Red var
            {
                Varenet = 2;
            }
            VMOD = 0;

            if(Varenet != 0)
                VMOD = rand() % 3*Varenet + 1;
            STR = 2 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 3*Varenet + 1;
            DEX = 15 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 3*Varenet + 1;
            CON = 8 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 3*Varenet + 1;
            INT = 2 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 3*Varenet + 1;
            WIS = 12 + VMOD;
            if(Varenet != 0)
                VMOD = rand() % 3*Varenet + 1;
            CHA = 4 + VMOD;

            if(Varenet != 0)
            VMOD = rand() % 10*Varenet + 1;

            HP += VMOD;
            HP += rand() % 5 + 1;
            MAXHP = HP;

        }
    }

        if(player)
        std::cout << "\nPlayer Spawned with HP : " << HP << "/" << MAXHP << "\n";
        else
        std::cout << "MOB Spawned with HP : " << HP << "/" << MAXHP << "\n";

}



int MOB::_3D6Roller(bool snowFlake)
{
    int output = 0;
    for(int i = 0; i < 3; i++)
    {
        output += rand() % 6 + 1;
    }

    if(snowFlake) ///Extra die roll
        output += rand() % 6 + 1;

    return output;

}


int MOB::GetAttack() /// STR and DEX based
{
    int total = 0;
    bool Wepused = false;

    for(int i = 0; i < Invnetory.size(); i ++)
    {
        if(Invnetory[i].Get_Equipped() == 1) /// 1 is a WEP were 2 is a shild and 0 is nothing
        {
            Wepused = true;
            total += Invnetory[i].Get_WEP_DEF_ROLL();
            if( Invnetory[i].Get_StatMOD() == "STR" )
            {
                total += Get_Mod(STR);
            }
            else if( Invnetory[i].Get_StatMOD() == "DEX" )
            {
                total += Get_Mod(DEX);
            }
        }
    }

    total += rand() % 6 + 1;

    if(!Wepused)
    {

        total += Get_Mod(STR);

    }

            if(total < 0 )
            total = 0;

    return total;


}
int MOB::GetDeffence() /// CON / WIS based will use items once those are in the game
{
    int total = 0;
    bool DEFUSED = false;

    for(int i = 0; i < Invnetory.size(); i ++)
    {
        if(Invnetory[i].Get_Equipped() == 2) /// 1 is a WEP were 2 is a shild and 0 is nothing
        {
            DEFUSED = true;
            total += Invnetory[i].Get_WEP_DEF_ROLL();
            if( Invnetory[i].Get_StatMOD() == "CON" )
            {
                total += Get_Mod(CON);
            }
            else if( Invnetory[i].Get_StatMOD() == "WIS" )
            {
                total += Get_Mod(WIS);
            }
        }
    }

    if(!DEFUSED)
    {
        total += Get_Mod(CON);
    }

            if(total < 0 )
            total = 0;


    return total;

}






int MOB::Get_Mod(int Stat)
{

    if(Stat < 2)
        return -5;
    else if(Stat == 2 || Stat == 3)
        return -4;
    else if(Stat == 4 || Stat == 5)
        return -3;
    else if(Stat == 6 || Stat == 7)
        return -2;
    else if(Stat == 8 || Stat == 9)
        return -1;
    else if(Stat == 10 || Stat == 11)
        return 0;
    else if(Stat == 12 || Stat == 13)
        return 1;
    else if(Stat == 14 || Stat == 15)
        return 2;
    else if(Stat == 16 || Stat == 17)
        return 3;
    else if(Stat == 18 || Stat == 19)
        return 4;
    else if(Stat == 20 || Stat == 21)
        return 5;
    else if(Stat == 22 || Stat == 23)
        return 6;
    else if(Stat == 24 || Stat == 25)
        return 7;
    else if(Stat == 26 || Stat == 27)
        return 8;
    else if(Stat == 28 || Stat == 29)
        return 9;
    else if(Stat == 29 || Stat == 30)
        return 10;
    else if(Stat == 31 || Stat == 32)
        return 11;
    else if(Stat == 33 || Stat == 34)
        return 12;
    else if(Stat == 35 || Stat == 36)
        return 13;
    else if(Stat == 37 || Stat == 38)
        return 14;
    else if(Stat == 39 || Stat == 40)
        return 15;
    else if(Stat > 40)
        return 16;
    /// next time work smarter not harder.


///1	−5/
///2–3	−4/
///4–5	−3/
///6–7	−2/
///8–9	−1
///10–11	+0
///12–13	+1
///14–15	+2
///16–17	+3
///18–19	+4
///20–21	+5
///22–23	+6
///24–25	+7
///26–27	+8
///28–29	+9
///30	+10
}


void MOB::Update_UseSlot() ///This is where potion right now are used.
{
    if( !UseSlot.Check_DonotUse() && !UseSlot.Check_Destory())
    {
        //std::cout << "ITEM BEING USED IN MOB! this is good.\n";

        STR += UseSlot.Get_STRBonus();
        DEX += UseSlot.Get_DEXBonus();
        CON += UseSlot.Get_CONBonus();
        INT += UseSlot.Get_INTBonus();
        WIS += UseSlot.Get_WISBonus();
        CHA += UseSlot.Get_CHABonus();
        MAXHP += UseSlot.Get_MaxHPBounus();
        HP  += UseSlot.Get_HPBouns();
        if(HP > MAXHP)
            HP = MAXHP;

    }

    UseSlot.set_DonotUSE(true);
}




void MOB::GenName()
{
    /// add stuff later check sex to pick a female or male name.
}



void MOB::FillWithItems()
{
    if(isShopkeeper())
    {

    }
    else
    {
        for(int i = 0; i < 3; i++)
        {
            if(rand() % 4 + 1 == 2)
            {
                GItemID++;
                item NEWITEM;
                NEWITEM.init(GItemID);
                NEWITEM.GenItem();
                Invnetory.push_back(NEWITEM);
            }

        }
    }

}



