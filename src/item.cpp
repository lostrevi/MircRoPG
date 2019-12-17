#include "item.h"




item::item()
{
    //ctor
}

item::~item()
{
    //dtor
}

void item::init(int ID)
{
    id = ID;
}
void item::GenItem()
{
    ///Gen all that junk.
    int roll = rand() % 3 + 1; /// will add other 2 types later
    if(roll == 1) ///WEP;
    {
        type = 1;
        int Roll2 = rand() % 2 + 1;

        Uses += rand() % 30 + 5;

        if(Roll2 == 1) /// Sword (uses Dex)
        {
            Class = 1;
            Name = "Sword";
            Amount_Of_Dice = rand() % 4 + 1;
            if(Amount_Of_Dice == 1)
            {
                Name = "Wood " + Name;
                drawindex = 0;
            }

            else if(Amount_Of_Dice == 2)
            {
                Name = "Iron " + Name;
                drawindex = 2;
            }

            else if(Amount_Of_Dice == 3)
            {
                Name = "Blood Steel " + Name;
                drawindex = 4;
            }
            else if(Amount_Of_Dice == 4)
            {
                Name = "Dark " + Name;
                drawindex = 6;
            }


            Amount_Per_Die = 6;

            if(rand() % 100 + 1 == 100)
            {
                effect = 1;
                if(effect == 1 && rand() % 100 + 1 == 100)
                effect = 2;
            }


        }
        else if(Roll2 == 2) /// Axe (uses STR)
        {
            Class = 2;
            Name = "Axe";

            Amount_Of_Dice = rand() % 4 + 1;
             if(Amount_Of_Dice == 1)
            {
                Name = "Wood " + Name;
                drawindex = 10;
            }

            else if(Amount_Of_Dice == 2)
            {
                Name = "Iron " + Name;
                drawindex = 2 + 10;
            }

            else if(Amount_Of_Dice == 3)
            {
                Name = "Blood Steel " + Name;
                drawindex = 4 + 10;
            }
            else if(Amount_Of_Dice == 4)
            {
                Name = "Dark " + Name;
                drawindex = 6 + 10;
            }

            Amount_Per_Die = 8;

            if(rand() % 25 + 1 == 1)
            {
                std::string NameAdd = "";
                effect = 1;
                NameAdd = " (+FIRE)";
                //std::cout << "Spawned it!\n";
                if(effect == 1 && rand() % 30 + 1 == 30)
                {
                    NameAdd = " (++FIRE)";
                    effect = 2;
                }

                Name += NameAdd;

            }
        }
    }
    else if(roll == 2) ///shields
    {
            type = 2;
            Uses += rand() % 30 + 15;

            Class = 1;
            Name = "Shield";
            Amount_Of_Dice = rand() % 3 + 1;
            if(Amount_Of_Dice == 1)
            {
                Name = "Parry " + Name;
                drawindex = 40;
            }

            else if(Amount_Of_Dice == 2)
            {
                Name = "Iron " + Name;
                drawindex = 2 + 40;
            }

            else if(Amount_Of_Dice == 3)
            {
                Name = "Wall " + Name;
                drawindex = 4 + 40;
            }

            Amount_Per_Die = 4;
    }

    else if(roll == 3 ) /// Potion;
    {
        type = 4;
        Name = "Potion of ";
        Uses = 1;

        if(rand() % 50 + 1 == 50)
            Uses += rand() % 4 + 1;

        int Roll2 = rand() % 6 + 1;

        if(Roll2 == 1 || Roll2 == 2)
            drawindex = 20;

        else if(Roll2 == 3 || Roll2 == 4)
        {
            drawindex = 22;
            Name += "Great ";
        }

        else if(Roll2 == 5 )
        {
            drawindex = 24;
            Name += "Super ";
        }

        else if(Roll2 == 6 && rand() % 5 + 1 == 5)
        {

            Name = "God's Potion of ";
            drawindex = 28;
            Roll2 = 10;
        }
        else
        {
            Name += "OutStanding ";
            drawindex = 26;
        }



        ///Now finding what stat it will bost
        int Roll3 = rand() % 8 + 1;

        switch(Roll3)
        {
            case 1 : STRBonus = Roll2; Name += "Power"; break;
            case 2 : DEXBonus = Roll2; Name += "Swiftness"; break;
            case 3 : CONBonus = Roll2; Name += "Constitution"; break;
            case 4 : INTBonus = Roll2; Name += "Intelligence"; break;
            case 5 : WISBonus = Roll2; Name += "Wisdom"; break;
            case 6 : CHABonus = Roll2; Name += "Beauty"; break;
            case 7 : HPBouns = Roll2*3; Name += "Heath"; break;
            case 8 : MaxHPBouns = Roll2*3; Name += "Healing"; break;
        }


        /// ADD CODE TO FIND WOULD INDEX WOULD FIT.


    }



}
int item::Get_Damange(int STRb, int DEXb, int INTb, int CHAb)
{
    int total = 0;
    total = RollDice(Amount_Of_Dice, Amount_Per_Die);

    if(effect == 1) /// Fire LV1
    {
        total += RollDice(2, 12);
    }
    if(effect == 2) /// Fire LV1
    {
        total += RollDice(4, 20);
    }

    if(Class == 1)
        total += DEXb;
    else if(Class == 2)
        total += STRb;



    Uses --;
    if(Uses == 0)
        Destory = true;



    if(Destory)
    {
        total = 0;
    }

    return total;
}
Change_Stats item::Use()
{
    Change_Stats OUTPUT;

    /// just zeroing out.
    OUTPUT.CHAADD = 0;
    OUTPUT.CONADD = 0;
    OUTPUT.DEXADD = 0;
    OUTPUT.HP = 0; /// just a heal not adding to max hp
    OUTPUT.MaxHPADD = 0;
    OUTPUT.INTADD = 0;
    OUTPUT.STRADD = 0;
    OUTPUT.WISADD = 0;


    OUTPUT.CHAADD = CHABonus;
    OUTPUT.CONADD = CONBonus;
    OUTPUT.DEXADD = DEXBonus;
    OUTPUT.HP = MaxHPBouns; /// just a heal not adding to max hp
    OUTPUT.MaxHPADD = MaxHPBouns;
    OUTPUT.INTADD = INTBonus;
    OUTPUT.STRADD = STRBonus;
    OUTPUT.WISADD = WISBonus;


    Uses --;
    if(Uses == 0)
    {
        Destory = true;
        ///Delete = true;
    }

    return OUTPUT;
}










int item::RollDice(int amount, int sides)
{
    int total = 0;
    for(int i = 0; i < amount; i++)
    {
        total += rand() % sides + 1;
    }

    return total;
}
