#include "game.h"


void Game::Object_enity_Cleaner()
{
    TimerCL++;
    if(TimerCL == TimerCLMAX)
    {

        //Tiles

        //Objects
        for(int i = 0; i < Objects.size(); i++)
        {
            for(int j = 0; j < Objects[i].Get_Contents().size(); j++)
            {
                if(Objects[i].Get_Contents()[j].Check_Delete())
                {
                    Objects[i].Delete_ITEM(j);
                }
            }

            if(Objects[i].Get_Contents().size() < 1 && (Objects[i].Get_type() == 5 || Objects[i].Get_type() == 19))
            {
                    if(i != 0)
                    Objects.erase(Objects.begin() + i);
                    else
                    Objects.erase(Objects.begin());
            }
        }

        //MOBs
        for(int i = 0; i < MOBs.size(); i ++)
        {
            for(int j = 0; j < MOBs[i].Get_Invenotry().size(); j++)
            {
                if(MOBs[i].Get_Invenotry()[j].Check_Delete())
                {
                    MOBs[i].Delete_ITEM(j);
                }
            }

            if(MOBs[i].Check_Destory())
            {
                //if(i != 0)
                //MOBs.erase(MOBs.begin() + i);
                //else
                //MOBs.erase(MOBs.begin());
            }
        }

    //TimerCL = 0; // Because there is another thing that runs right after this that uses this timer and if it reset it here it would skip the other
    }
}



void Game::restart_game()
{
    PlayerDead = false;
    SetAllMenusFalse();
    updateTilesV = true;
    updateMOBV = true;
    updateObjectV = true;
    LastHP = 0;
    MOBs.clear();
    Objects.clear();
    PCells.clear();
    Tiles.clear();
    OffsetXTOTAL = 0;
    OffsetYTOTAL = 0;

    Level_Generator(worldsizeX,worldsizeY);
}


void Game::Check_Floor_Clear()
{
    if(TimerCL == TimerCLMAX)
    {
        int Total_monsters = 0;
        for(int i = 0; i < MOBs.size(); i++)
        {
            if(!MOBs[i].isPlayer() && !MOBs[i].isShopkeeper())
                Total_monsters ++;
        }

        if(Total_monsters == 0)
        {
            FLOOR_CLEAR = true;
            std::cout << "\n\n\n!!!!! THE FLOOR IS CLEAR !!!!!\n\n";
            Push_Info("Floor Cleared");
        }

        TimerCL = 0;
    }


}







