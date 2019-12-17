#ifndef ITEM_H
#define ITEM_H

#include "TextString.h"

extern int GItemID;

struct Change_Stats
{
    int STRADD; /// its a passive bonus that you can get.
    int DEXADD; // used for dex based weaps
    int CONADD; // used to find mobs hp
    int INTADD; // not sure yet
    int WISADD; // getting item stats and discriptons
    int CHAADD; // lol
    int HP;
    int MaxHPADD;
};


class item
{
    public:
        item();
        virtual ~item();

        void init(int ID); /// just stuff it for sure needs.
        void GenItem(); /// make a random wep
        int Get_Damange(int STRb, int DEXb, int INTb, int CHAb);
        Change_Stats Use();

    int Get_Class()
    {
        return Class;
    }

    std::string Get_StatMOD() /// This will return what you should add to it so if it is DEX then Dex if STR then Str mod for the wep.
    {
        if(Class == 1)
            return "DEX";
        else if (Class == 2)
            return "STR";
    }

    int Get_STRBonus()
    {
        return STRBonus;
    }
    int Get_type() /// the type is 1 wep 2 def /// 3 ring? /// 4 potion
    {
        return type;
    }
    int Get_DEXBonus()
    {
        return DEXBonus;
    }
    int Get_CONBonus()
    {
        return CONBonus;
    }
    int Get_INTBonus()
    {
        return INTBonus;
    }
    int Get_WISBonus()
    {
        return WISBonus;
    }
    int Get_CHABonus()
    {
        return CHABonus;
    }

    int Get_HPBouns() /// This is like a healing potion
    {
        return HPBouns;
    }

    int Get_MaxHPBounus() /// THis Brings up your max only;
    {
        return MaxHPBouns;
    }

    int Get_AC()
    {
        return AC;
    }

    bool Check_Destory() /// this is if it is broken.
    {
        return Destory;
    }
    std::string Get_Name() /// Gets the name
    {
        return Name;
    }

    int Get_ID()
    {
        return id;
    }

    int Get_WEP_DEF_ROLL()
    {
        Uses -- ;
        int total = 0;
        for(int i = 0; i < Amount_Of_Dice; i ++)
        {
            total += rand() % Amount_Per_Die + 1;
        }

        if(Uses < 1)
        {
            std::cout << "!!! item Break !!!   -  and an vissual thing later\n ";

            Destory = true;
            Equipped = 0;
        }


        return total;

    }

    void set_Destroy()
    {
        Destory = true;
    }

    void Set_Dead()
    {
        Destory = true;
        Delete = true;
    }

    bool Check_Delete() /// like check dead but this will tell the cleanup to delete it
    {
        return Delete;
    }

    int Get_DrawINDEX()
    {

        if(Destory)
            return drawindex+1;
        else
            return drawindex;
    }

    int Get_effectINDEX()
    {
        //std::cout << "\m EFFECT IS " << effect << "\m";

        if(effect == 1)
            return 30;
        else if(effect == 2)
            return 31;
        else
            return 0;
    }

    bool Check_DonotUse() /// this is used for mob to see of the object should be used or not.
    {
        return DONOTUSE;
    }
    void set_DonotUSE(bool a)
    {
        DONOTUSE = a;
    }

    int Get_Equipped() /// 0 is not Equipped, 1 is as attack wep (sword,axe), 2 is as def.
    {
        return Equipped;
    }

    void Set_Equipped(int a) /// 0 is not Equipped, 1 is as attack wep (sword,axe), 2 is as def.
    {
        Equipped = a;
    }

    private:
        int id = -1;


        std::string Name = "";

        int Equipped = 0; /// 0 is not Equipped, 1 is as attack wep, 2 is as def.

        int drawindex = 0; ///add later but this points to an icon;

        int type = 0; /// 1 = wep /// 2 = Sheld /// 3 = charm/ring /// 4 = potion
        int Class = 0;/// 1 = sword // 2 = axe /// so on

        int Uses = 1; /// onlice it hits zero the item breaks;

        bool Destory = false;
        bool Delete = false; /// use when drop
        bool DONOTUSE = false; /// Do not use for anything else this is not to check if it is useable this is a checker for MOBs do not change and don't use for anything else.

        int AC = 0;


        int Amount_Of_Dice = 0;
        int Amount_Per_Die = 0;
        /// like this 0D0

        int effect = 0; /// like fire damage

    int STRBonus = 0; /// its a passive bonus that you can get.
    int DEXBonus = 0; // used for dex based weaps
    int CONBonus = 0; // used to find mobs hp
    int INTBonus = 0; // not sure yet
    int WISBonus = 0; // getting item stats and discriptons
    int CHABonus = 0; // lol
    int HPBouns = 0;
    int MaxHPBouns = 0;


    int RollDice(int amount, int sides);
};

#endif // ITEM_H
