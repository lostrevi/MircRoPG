#include "game.h"

void Game::updatekeys()
{

    if(TimerA != TimerAMAX)
    {
        TimerA++;
    }

    if(TimerB != TimerBMAX)
    {
        TimerB++;
    }

    if(TimerM != TimerMMAX)
    {
        TimerM++;
    }

    if( INPUTS.Qispressed()) //Q
    {
        std::cout << "Q" << std::endl;
    }
    if( INPUTS.Wispressed()) //W
    {
        std::cout << "W" << std::endl;
    }
    if( INPUTS.Eispressed()) //E
    {

       if(TimerM == TimerMMAX )
        {
            if(!DrawItemScreen)
            {



                for(int i = 0; i < MOBs.size(); i++) /// will need to add omsthing for mobs later
                {
                    //std::cout << "found : x and y " << Objects[i].Get_X() << " , " << Objects[i].Get_Y() << " | " << TNGx << " , " << TNGy << std::endl;
                    if(MOBs[i].isPlayer())
                    {
                        ItemViewer(MOBs[i].Get_Invenotry(),i,true,true);
                    }

                }



            //ItemViewer(Objects[1].Get_Contents(), false,true);

            }
            else
            {
                std::vector<item> EMPTYTHING;

                ItemViewer(EMPTYTHING,0, false,false);
            }


            TimerM = 0;

        }
    }
    if( INPUTS.Rispressed()) //R
    {
        std::cout << "R" << std::endl;
    }
    if( INPUTS.Tispressed()) //T
    {
        std::cout << "T" << std::endl;
    }
    if( INPUTS.Yispressed()) //Y
    {
        std::cout << "Y" << std::endl;
    }
    if( INPUTS.Uispressed()) //U
    {
        std::cout << "U" << std::endl;
    }
    if( INPUTS.Iispressed()) //I
    {
        //std::cout << "I" << std::endl;
        if(TimerA == TimerAMAX)
        {
            OffsetY = 1;
            TimerA = 0;
        }
    }
    if( INPUTS.Oispressed()) //O
    {
        //std::cout << "O" << std::endl;
        ///Setup for testing
       if(TimerM == TimerMMAX)
        {
        ItemViewer(Objects[1].Get_Contents(),1, false,true);
        TimerM = 0;
        }


    }
    if( INPUTS.Pispressed()) //P
    {
        std::cout << "P" << std::endl;
    }
    if( INPUTS.Aispressed()) //A
    {
        std::cout << "A" << std::endl;
    }
    if( INPUTS.Sispressed()) //S
    {
        std::cout << "S" << std::endl;
    }
    if( INPUTS.Dispressed()) //D
    {
        std::cout << "D" << std::endl;
    }
    if( INPUTS.Fispressed()) //F
    {
        std::cout << "F" << std::endl;
    }
    if( INPUTS.Gispressed()) //G
    {
        //std::cout << "G" << std::endl;

       if(TimerM == TimerMMAX )
        {
            if(!DrawItemScreen)
            {
                int TNGx = 0;
                int TNGy = 0;


                for(int i = 0; i < MOBs.size(); i ++ ) ///get x and y of player
                {
                    if(MOBs[i].isPlayer())
                    {
                        TNGx = MOBs[i].Get_X();
                        TNGy = MOBs[i].Get_Y();
                    }
                }



                for(int i = 0; i < Objects.size(); i++) /// will need to add omsthing for mobs later
                {
                    //std::cout << "found : x and y " << Objects[i].Get_X() << " , " << Objects[i].Get_Y() << " | " << TNGx << " , " << TNGy << std::endl;
                    if(Objects[i].Get_X() == TNGx && Objects[i].Get_Y() == TNGy )
                    {


                        ItemViewer(Objects[i].Get_Contents(),i,false,true);
                        break;
                    }

                }



            //ItemViewer(Objects[1].Get_Contents(), false,true);

            }
            else
            {
                std::vector<item> EMPTYTHING;

                ItemViewer(EMPTYTHING,0, false,false);
            }


            TimerM = 0;

        }


    }
    if( INPUTS.Hispressed()) //H
    {
        std::cout << "H" << std::endl;
    }
    if( INPUTS.Jispressed()) //J
    {
        //std::cout << "J" << std::endl;
        if(TimerA == TimerAMAX)
        {
            OffsetX = 1;
            TimerA = 0;
        }
    }
    if( INPUTS.Kispressed()) //K
    {
        //std::cout << "K" << std::endl;
        if(TimerA == TimerAMAX)
        {
            OffsetY = -1;
            TimerA = 0;
        }
    }
    if( INPUTS.Lispressed()) //L
    {
        //std::cout << "L" << std::endl;
        if(TimerA == TimerAMAX)
        {
            OffsetX = -1;
            TimerA = 0;
        }
    }
    if( INPUTS.Zispressed()) //Z
    {
        std::cout << "Z" << std::endl;
    }
    if( INPUTS.Xispressed()) //X
    {
        std::cout << "X" << std::endl;
    }
    if( INPUTS.Cispressed()) //C
    {
        //std::cout << "C" << std::endl;
        if(TimerM == TimerMMAX)
        {
                if(DrawCharSheet)
                Load_CharSheet(false);
                else
                Load_CharSheet(true);
            TimerM = 0;
        }

    }
    if( INPUTS.Vispressed()) //V
    {
        std::cout << "V" << std::endl;
    }
    if( INPUTS.Bispressed()) //B
    {
        std::cout << "B" << std::endl;
    }
    if( INPUTS.Nispressed()) //N
    {
        std::cout << "bing";
        if(TimerM == TimerMMAX)
        {

            if(PlayerDead)
            {
            std::cout << "Spawning new world" << std::endl;
            Push_Info("Spawning new world");

            restart_game();
            }
            else
            {
                std::cout << "Player is not dead. Cannot spawn new world." << std::endl;
                Push_Info("Player is not dead. Cannot spawn new world.");
            }


           TimerM = 0;
        }
    }
    if( INPUTS.Mispressed()) //M
    {
        std::cout << "M" << std::endl;
    }

    if( INPUTS.NUM1ispressed()) //1
    {
        std::cout << "1" << std::endl;
    }
    if( INPUTS.NUM2ispressed()) //2
    {
        std::cout << "2" << std::endl;
    }
    if( INPUTS.NUM3ispressed()) //3
    {
        std::cout << "3" << std::endl;
    }
    if( INPUTS.NUM4ispressed()) //4
    {
        std::cout << "4" << std::endl;
    }
    if( INPUTS.NUM5ispressed()) //5
    {
        std::cout << "5" << std::endl;
    }
    if( INPUTS.NUM6ispressed()) //6
    {
        std::cout << "6" << std::endl;
    }
    if( INPUTS.NUM7ispressed()) //7
    {
        std::cout << "7" << std::endl;
    }
    if( INPUTS.NUM8ispressed()) //8
    {
        std::cout << "8" << std::endl;
    }
    if( INPUTS.NUM9ispressed()) //9
    {
        std::cout << "9" << std::endl;
    }
    if( INPUTS.NUM0ispressed()) //0
    {
        std::cout << "0" << std::endl;
    }


    if( INPUTS.NUMLK1ispressed()) //KP_1
    {
        if(TimerB == TimerBMAX)
        {

            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),-1,1))
                    MOBs[i].Move(-1,1);
            }

            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK2ispressed()) //KP_2
    {
        if(TimerB == TimerBMAX)
        {
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,1))
                    MOBs[i].Move(0,1);
                    updateTilesV = true;
            }
            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK3ispressed()) //KP_3
    {
        if(TimerB == TimerBMAX)
        {
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),1,1))
                    MOBs[i].Move(1,1);
                                        updateTilesV = true;
            }
            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK4ispressed()) //KP_4
    {
        if(TimerB == TimerBMAX)
        {
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),-1,0))
                    MOBs[i].Move(-1,0);
                                        updateTilesV = true;
            }
            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK5ispressed()) //KP_5
    {
        if(TimerB == TimerBMAX)
        {
            //Wait Command or somthing idk
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() )
                                        updateTilesV = true;
            }            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK6ispressed()) //KP_6
    {
        if(TimerB == TimerBMAX)
        {
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),1,0))
                    MOBs[i].Move(1,0);
                                        updateTilesV = true;
            }
            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK7ispressed()) //KP_7
    {
        if(TimerB == TimerBMAX)
        {
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),-1,-1))
                    MOBs[i].Move(-1,-1);
                      updateTilesV = true;
            }
            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK8ispressed()) //KP_8
    {
        if(TimerB == TimerBMAX)
        {
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,-1))
                    MOBs[i].Move(0,-1);
                      updateTilesV = true;
            }
            TimerB = 0;
        }
    }
    if( INPUTS.NUMLK9ispressed()) //KP_9
    {
        if(TimerB == TimerBMAX)
        {
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),1,-1))
                    MOBs[i].Move(1,-1);
                      updateTilesV = true;
            }
            TimerB = 0;
        }
    }





    if( INPUTS.RIGHTispressed()) //RIGHT
    {
        //std::cout << "Right\n";
        if(TimerB == TimerBMAX)
        {
            if(!DrawItemScreen)
            {
                for(int i = 0; i < MOBs.size(); i++)
                {
                    if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),1,0) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),1,0,i))
                        MOBs[i].Move(1,0);
                          updateTilesV = true;
                }
            }
            else if(DrawItemScreen)
            {
                SpacePressed = true;
            }

            TimerB = 0;
        }

    }
    if( INPUTS.LEFTispressed()) //LEFT
    {
        if(TimerB == TimerBMAX )
        {
            if(!DrawItemScreen)
            {
                for(int i = 0; i < MOBs.size(); i++)
                {
                    if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),-1,0) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),-1,0,i))
                        MOBs[i].Move(-1,0);
                          updateTilesV = true;
                }

            }
            else if(DrawItemScreen)
            {
                BackAMenu = true;
            }

            TimerB = 0;
        }

    }
    if( INPUTS.DOWNispressed()) //DOWN
    {
        //std::cout << "Down\n";
        if(TimerB == TimerBMAX)
        {
            if(!DrawItemScreen)
            {
                for(int i = 0; i < MOBs.size(); i++)
                {
                    if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,1) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,1,i))
                        MOBs[i].Move(0,1);
                          updateTilesV = true;
                }
}
            else
            {
                if(SelectedBar < CurrentMAXINV-1 || SubMenu_notP || subMenu_isP)
                SelectedBar ++;
            }
            TimerB = 0;
        }


    }
    if( INPUTS.UPispressed()) //UP
    {
        //std::cout << "UP\n";
        if(TimerB == TimerBMAX)
        {
            if(!DrawItemScreen)
            {
                for(int i = 0; i < MOBs.size(); i++)
                {
                    if(MOBs[i].isPlayer() && WallCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,-1) && CombatCheck(MOBs[i].Get_X(),MOBs[i].Get_Y(),0,-1,i))
                        MOBs[i].Move(0,-1);
                          updateTilesV = true;
                }
            }
            else
            {
                if(SelectedBar > 0 || SubMenu_notP || subMenu_isP)
                SelectedBar --;
            }

            TimerB = 0;
        }

    }
    if( INPUTS.SPACEispressed()) //Space
    {
        //std::cout << "SPACE" << std::endl;
        if(TimerM == TimerMMAX)
        {
            SpacePressed = true;

            TimerM = 0;
        }
    }



}

















