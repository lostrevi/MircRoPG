#include "game.h"

void Game::AI_UPDATE()
{
    ///Find AIs
    for(int i = 0; i < MOBs.size(); i++)
    {
        if(!MOBs[i].isPlayer() && !MOBs[i].isShopkeeper() && MOBs[i].Check_doaction()) ///check if not player and if do action is true.
        {
            ///Do ai logic;

            ///putting dumb ai logic in just for testing.
                int Dir = rand() % 4 + 1;

                if(Dir == 1)
                {
                    if(WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,-1) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,-1,i)) //up
                    {
                        MOBs[i].Move(0,-1);
                    }
                }
                else if(Dir == 2)
                {
                    if(WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,1) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,1,i)) //down
                    {
                        MOBs[i].Move(0,1);
                    }
                }
                else if(Dir == 3)
                {
                    if(WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),-1,0) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),-1,0,i)) //left
                    {
                        MOBs[i].Move(-1,0);
                    }
                }
                else if(Dir == 4)
                {
                    if(WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),1,0) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),1,0,i)) //right
                    {
                        MOBs[i].Move(1,0);
                        updateMobVision(); ///Might need it to be tile witch does both but if does it auto if the player moves so i should only need to check mobs
                    }
                }




            MOBs[i].Did_Action();
        }




    }
    //updateTileVision();


}
