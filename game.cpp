#include "Game.h"


void Game::run() //main game loop this will also keep game time.
{
    srand(time(NULL));
    init();
    std::cout << Name_of_app << " $> Basic systems running. \n";

    const int SCREEN_FPS = 60;
    const int SCREEN_TICKS_PER_FRAME = 1000 / SCREEN_FPS;

    //The frames per second timer
    GTimer fpsTimer;

    //The frames per second cap timer
    GTimer capTimer;


    //Start counting frames per second
    int countedFrames = 0;
    fpsTimer.start();

    while(Running) //game loop
    {
            //Start cap timer
            capTimer.start();



            //Calculate and correct fps
            float avgFPS = countedFrames / ( fpsTimer.getTicks() / 1000.f );
            if( avgFPS > 2000000 )
            {

                avgFPS = 0;
            }

            //INPUTS.update();
            //Running = INPUTS.Quit();


                        INPUTS.update();
                        Running = INPUTS.Quit();

                draw();
                update();


                //If frame finished early
                int frameTicks = capTimer.getTicks();
                if( frameTicks < SCREEN_TICKS_PER_FRAME )
                {
                    //Wait remaining time
                    SDL_Delay( SCREEN_TICKS_PER_FRAME - frameTicks );
                }
    }


//   Destroy_all();// exits everything

}



void Game::init()
{
    initmouse();

     UI_Bar = loadTexture("Data/SideBar.png");
     MainTiles = loadTexture("Data/MainTiles.png");
     CharSheet = loadTexture("Data/UI/CharSheetTemplate.png");
     ItemViewerBar = loadTexture("Data/UI/itemScreenbar.png");
     ITEMS = loadTexture("Data/Items.png");
     HAND = loadTexture("Data/UI/Arrow.png");
     SubMenu_nonP = loadTexture("Data/UI/subMenu_nonPinv.png");
     SubMenu_P = loadTexture("Data/UI/subMenu_P.png");
     PlayerInvSign = loadTexture("Data/UI/PlayerINVSign.png");
     EquippedICON = loadTexture("Data/UI/Equipped.png");
     DeathScreen = loadTexture("Data/UI/Death.png");
     UISkeleton = loadTexture("Data/Faces/Skeleton.png");
     UIBat = loadTexture("Data/Faces/Bat.png");
     UIBLANK = loadTexture("Data/Faces/BLANK.png");
     EQMOB = loadTexture("Data/UI/MOBEQ.png");


     UI_BarR = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};


     UPERUIFACE = UIBLANK;
     LOWERUIFACE = UIBLANK;



     FONTA = TTF_OpenFont("Data/Fonts/clacon.ttf", 24);

     TestText.init(Ren0, "NULL", 0,0,16,16,FONTA,White);

     HPinfo.init(Ren0, "HP", 610,110,18,16,FONTA,Red);
     HPinfo.Lock_Width(100);
     ohterHPinfo.init(Ren0, "EHP", 610, 350, 18,16,FONTA,Red);
     ohterHPinfo.Lock_Width(100);

     Goldinfo.init(Ren0, "Gold", 610, 130, 18,16,FONTA,Gold);
     Goldinfo.Lock_Width(100);

     INFO.init(Ren0,"",0,480-40,18,16,FONTA,White);

     UI_TOPFACE = {613,13,97,83};
     UI_LOWFACE = {613,383,97,83};


     SubMenu_nonP_LOC = {0,0,120,160};
     SubMenu_P_LOC = {0,0,120,160};
     Hand_LOC = {0 , 0, 60, 60};
     Hand_CLIP = {0,0,30,30};


    Level_Generator(worldsizeX,worldsizeY);
}

void Game::draw()
{
        //Clear screen
        SDL_SetRenderDrawColor( Ren0, 29, 30, 34, 0xFF );
        SDL_RenderClear( Ren0 );


        TestText.draw();



        for(int i = 0; i < Tiles.size(); i++)
        {
            Tiles[i].draw();
        }

        for(int i = 0; i < Objects.size(); i++)
        {
            Objects[i].draw();
        }

        for(int i = 0; i < MOBs.size(); i++)
        {
            MOBs[i].draw();
        }

        for(int i = 0; i < PCells.size(); i++)
        {
            PCells[i].draw();
        }

        SDL_RenderCopy(Ren0, UI_Bar, NULL, &UI_BarR);
        SDL_RenderCopy(Ren0, UPERUIFACE ,NULL, &UI_TOPFACE);
        SDL_RenderCopy(Ren0, LOWERUIFACE ,NULL, &UI_LOWFACE);



        HPinfo.draw();
        Goldinfo.draw();
        ohterHPinfo.draw();

        if(DrawCharSheet)
            SDL_RenderCopy(Ren0,CharSheet,NULL,&Screen);

        if(DrawItemScreen)
            ItemViewerDraw();

        if(PlayersInvSign)
        {
            SDL_RenderCopy(Ren0, PlayerInvSign, NULL, &Screen);
        }


        for(int i = 0; i < Texts.size(); i++)
        {
            Texts[i].draw();
        }

        if(SubMenu_notP)
            SDL_RenderCopy(Ren0, SubMenu_nonP, NULL, &SubMenu_nonP_LOC);
        if(subMenu_isP)
            SDL_RenderCopy(Ren0, SubMenu_P,NULL,&SubMenu_P_LOC);


        if(DrawHand)
            SDL_RenderCopy(Ren0,HAND,&Hand_CLIP,&Hand_LOC);

        if(PlayerDead)
            SDL_RenderCopy(Ren0,DeathScreen,NULL,&Screen);


        if(INFOtimer != INFOtimerMAX)
            INFO.draw();



        drawmouse();

                SDL_RenderPresent( Ren0 );

}

void Game::update()
{
    Cam_ON_Player();
    updatekeys();
    updatemouse();
    AI_UPDATE();

    TimerH++;

    if(TimerH == TImerHMAX)
    {
        Hand_CLIP.x += 30;
        if(Hand_CLIP.x == 150)
        Hand_CLIP.x = 0;
        TimerH = 0;
    }



    std::string outputxy;

    for(int i = 0; i < MOBs.size(); i++)
    {
        if(MOBs[i].isPlayer())
        {
            outputxy = "X : ";
            std::stringstream ss;
            ss << MOBs[i].Get_X();
            std::string str = ss.str();
            ss.str("");
            outputxy += str += " Y : ";
            ss << MOBs[i].Get_Y();
            str = ss.str();
            outputxy += str;
        }
    }

    TestText.updateText(outputxy);
    GetRightHUDstuff();

    if(updateTilesV)
    {
        updateMOBV = true;
        updateObjectV = true;

        updateTileVision();
    }


    for(int i = 0; i < Tiles.size(); i++)
    {
        Tiles[i].update(OffsetX,OffsetY);
    }

    for(int i = 0; i < Texts.size(); i++)
    {
        Texts[i].update();
    }

    for(int i = 0; i < Objects.size(); i++)
    {
        Objects[i].update(OffsetX,OffsetY);
    }

    for(int i = 0; i < MOBs.size(); i++)
    {
        MOBs[i].update(OffsetX,OffsetY);

        if(MOBs[i].Check_Dead()) /// if dead get rid of it and make a chest of it inventory
        {


            MOBs[i].UnEquippedallofType(1);
            MOBs[i].UnEquippedallofType(2);
            MOBs[i].UnEquippedallofType(3);

                if(MOBs[i].Get_Invenotry().size() != 0)
                {
                Object NewObject;
                NewObject.init(Ren0,MainTiles,MOBs[i].Get_X(),MOBs[i].Get_Y(),19);
                NewObject.Clear_Contents();
                for(int j = 0; j < MOBs[i].Get_Invenotry().size(); j ++)
                {
                    NewObject.Put_Item(MOBs[i].Get_Invenotry()[j]);
                }
                NewObject.update(OffsetXTOTAL,OffsetYTOTAL);
                Objects.push_back(NewObject);
                }


                if(MOBs[i].isPlayer())
                {
                    Push_Info("You have Died Press N for NewWorld");
                            PlayerDead = true;
                }



                if(i != 0)
                MOBs.erase(MOBs.begin() + i);
                else
                MOBs.erase(MOBs.begin());

        }




    }

    for(int i = 0; i < PCells.size(); i++)
    {
        PCells[i].update(OffsetX,OffsetY);
    }

                    if(MOBs[EHPindex].Get_HP() != otherLastHP)
                    {
                        std::string HPString = "EHP: ";
                        otherLastHP = MOBs[EHPindex].Get_HP();
                        HPString += int_to_string(otherLastHP) += "/";
                        HPString += int_to_string(MOBs[EHPindex].Get_MHP());

                        ohterHPinfo.updateText(HPString);

                    }


    if(INFOtimer != INFOtimerMAX)
        INFOtimer++;



    OffsetXTOTAL += OffsetX;
    OffsetYTOTAL += OffsetY;

    OffsetX = 0;
    OffsetY = 0;


    Object_enity_Cleaner();
    Check_Floor_Clear();
}










bool Game::WallCheck(int x, int y, int Dx, int Dy)
{
    int targetx = x + Dx;
    int targety = y + Dy;



    for(int i = 0; i < Tiles.size(); i++)
    {

        if(Tiles[i].Get_X() == targetx && Tiles[i].Get_Y() == targety)
        {

            if(Tiles[i].Get_Index() == 0) /// this only checks for walls right now but i could a doors later
            {

                return false;
            }
        }

    }
    return true;
}

bool Game::CombatCheck(int x, int y, int Dx, int Dy, int TargetIndex)
{
    int targetx = x + Dx;
    int targety = y + Dy;

    for(int i = 0; i < MOBs.size(); i++)
    {

        if(MOBs[i].Get_X() == targetx && MOBs[i].Get_Y() == targety)
        {
            if(MOBs[i].isPlayer() || rand() % 25 + 1 == 25) /// if it is the player or if it is Mob attack player
            {

                if(MOBs[i].isPlayer())
                {
                    Set_LowFace(MOBs[TargetIndex].Get_type(),TargetIndex);


                }


                int ATT = MOBs[TargetIndex].GetAttack();
                int DEF = MOBs[i].GetDeffence();

                int DMG = ATT - DEF;
                if(DMG > 0 )
                {
                    std::cout << "-Monster attacked for : " << DMG << std::endl;

                    MOBs[i].Take_Damage(DMG);
                }

                DEF = MOBs[TargetIndex].GetAttack();
                ATT = MOBs[i].GetDeffence();

                DMG = ATT - DEF;

                if(rand() % 10 + 1 > 1 + MOBs[TargetIndex].Get_DEX()) ///chance of counter attack; it adds your doge to the roll to make it harder on them.
                {
                    std::cout << "\m -you Attacked for : "<< DMG << "\n";

                    MOBs[TargetIndex].Take_Damage(DMG);
                }
                 else
                std::cout << "\m -you MISSED\n";

            }

            if( MOBs[TargetIndex].isPlayer() ) /// if The player attacks the mob
            {
                int ATT = MOBs[TargetIndex].GetAttack();
                int DEF = MOBs[i].GetDeffence();

                Set_LowFace(MOBs[i].Get_type(),i);

                int DMG = ATT - DEF;
                if(DMG > 0 )
                {
                    std::cout << "You attacked for : " << DMG << std::endl;

                    MOBs[i].Take_Damage(DMG);
                }

                DEF = MOBs[TargetIndex].GetAttack();
                ATT = MOBs[i].GetDeffence();

                DMG = ATT - DEF;

                if(rand() % 10 + 1 > 3 + MOBs[TargetIndex].Get_DEX()) ///chance of counter attack; it adds your doge to the roll to make it harder on them.
                {
                    std::cout << "\m Monster Attacked for : "<< DMG << "\n";

                    MOBs[TargetIndex].Take_Damage(DMG);
                }
                 else
                std::cout << "\m Monster MISSED\n";

            }


                return false;

        }

    }

    return true;

}



void Game::Set_LowFace(int type, int index)
{

    EHPindex = index;

    if(type == 3)
    LOWERUIFACE = UISkeleton;
    else if(type == 4)
    LOWERUIFACE = UIBat;
    else
    LOWERUIFACE = UIBLANK;

}



void Game::GetRightHUDstuff()
{
    std::string HPString = "";


    for(int i = 0; i < MOBs.size(); i++)
    {
        if(MOBs[i].isPlayer())
        {
            if(MOBs[i].Get_HP() != LastHP)
            {
                HPString = "HP: ";
                LastHP = MOBs[i].Get_HP();
                HPString += int_to_string(LastHP) += "/";
                HPString += int_to_string(MOBs[i].Get_MHP());

                HPinfo.updateText(HPString);
            }
            if(MOBs[i].Get_Gold() != LastGold)
            {
                std::string GoldString = "Gold: ";
                LastGold = MOBs[i].Get_Gold();
                GoldString += int_to_string(LastGold);

                Goldinfo.updateText(GoldString);
            }
        }
    }




}











void Game::Cam_ON_Player()
{

    for(int i = 0; i < MOBs.size(); i++)
    {
        if(MOBs[i].isPlayer())
        {



            if(MOBs[i].Get_LOC().x > (SCREEN_WIDTH-100) - 120)
            {
                OffsetX = -1;
            }
            if(MOBs[i].Get_LOC().x < 120)
            {
                OffsetX = 1;
            }

            if(MOBs[i].Get_LOC().y < 120)
            {
                OffsetY = 1;
            }
            if(MOBs[i].Get_LOC().y > SCREEN_HEIGHT - 120)
            {
                OffsetY = -1;
            }




        }
    }


}




















void Game::ADD_Tile(int x, int y, int index)
{
    Tile NEWTILE;
    NEWTILE.init(Ren0,MainTiles,x,y,index);
    Tiles.push_back(NEWTILE);
}


void Game::ADD_MOB(int x, int y, int index, bool player,  bool ShopKeeper)
{
    MOB NEWMOB;
    NEWMOB.init(Ren0,MainTiles,x,y,index,player);
    NEWMOB.Set_ShopKeeper(ShopKeeper);
    NEWMOB.SetEQDRAW(EQMOB);
    MOBs.push_back(NEWMOB);
}

void Game::ADD_Object(int x, int y, int index)
{
    Object NEWOBJECT; ///objects are map objects not items. itmes are used the the players and such but they are menu and logic based not map based. objects are just chests that will gen an object to the player inventory or hold the object or repersent the object. aslo they are keys and swtichs and such
    NEWOBJECT.init(Ren0,MainTiles,x,y,index);
    Objects.push_back(NEWOBJECT);
}

bool Game::Create_Cell(int x, int y)
{
    int Get_Compairx;
    int Get_Compairy;
    for(int i = 0; i < PCells.size(); i++)
    {
        Get_Compairx = PCells[i].Get_GridX();
        Get_Compairy = PCells[i].Get_GridY();
    }
        if(x ==  Get_Compairx && y == Get_Compairy)
        {

            return false;
        }
        else
        {

            PCell NEWCELL;
            NEWCELL.init(Ren0,MainTiles,x,y,true);
            PCells.push_back(NEWCELL);
            return true;
        }

}



/// Vission stuff;
void Game::updateTileVision()
{
    int targetX;
    int targetY;
    int Sight;
    bool FarSite;

    FlatenTileVision();

    for(int i = 0; i < MOBs.size(); i++)
    {
        if(MOBs[i].isPlayer())
        {
            targetX = MOBs[i].Get_X();
            targetY = MOBs[i].Get_Y();
            Sight = MOBs[i].Get_Sight();
            FarSite = MOBs[i].Check_Effect_FarSite();

         }
    }



    for(int i = 0; i < Tiles.size(); i++) /// Error checking.
        for(int j = 0; j < Tiles.size(); j++)
    {
        if(i != j && Tiles[i].Get_X() == Tiles[j].Get_X() && Tiles[i].Get_Y() == Tiles[j].Get_Y())
            std::cout << "conflict in the tile X and Y";
    }






            for(int i = 0; i < Tiles.size(); i++) // set first tile to thing
            {

                //std::cout << "tx and x ty and y " << Tiles[i].Get_X() << " : " << targetX << " | " << Tiles[i].Get_X() << " : " << targetX << std::endl;

                if(Tiles[i].Get_X() == targetX && Tiles[i].Get_Y() == targetY)
                {
                    Tiles[i].Set_Discover(2); /// 2 is a tile that has not seeded yet while a 3 is a tile that has.
                }


            }



    int Moves = 0;

    std::vector<int> FlipThese;

    while (Moves != Sight)
    {
            for(int i = 0; i < Tiles.size(); i++)
            {
                if(Tiles[i].Get_Discover() == 2 && Tiles[i].Get_Index() == 1) /// reslove tile and plant seeds
                {
                    ///Plant new tiles chasers

                    targetX = Tiles[i].Get_X();
                    targetY = Tiles[i].Get_Y();


                    for(int j = 0; j < Tiles.size(); j ++)
                    {

                        if(targetX == Tiles[j].Get_X() && targetY-1 == Tiles[j].Get_Y()&& (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// up
                            FlipThese.push_back(j);


                        if(targetX-1 == Tiles[j].Get_X() && targetY == Tiles[j].Get_Y()&& (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// left
                            FlipThese.push_back(j);

                        if(targetX+1 == Tiles[j].Get_X() && targetY == Tiles[j].Get_Y()&& (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// right
                            FlipThese.push_back(j);


                        if(targetX == Tiles[j].Get_X() && targetY+1 == Tiles[j].Get_Y()&& (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// down
                            FlipThese.push_back(j);


                            if(FarSite)
                            {
                                if(targetX+1 == Tiles[j].Get_X() && targetY+1 == Tiles[j].Get_Y()&& (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// down-right
                                    FlipThese.push_back(j);
                                if(targetX-1 == Tiles[j].Get_X() && targetY+1 == Tiles[j].Get_Y()&& (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// down-left
                                    FlipThese.push_back(j);
                                if(targetX+1 == Tiles[j].Get_X() && targetY-1 == Tiles[j].Get_Y()&& (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// up-right
                                   FlipThese.push_back(j);
                                if(targetX-1 == Tiles[j].Get_X() && targetY-1 == Tiles[j].Get_Y() && (Tiles[j].Get_Discover() != 2 || Tiles[j].Get_Discover() != 3)) /// up-left
                                   FlipThese.push_back(j);
                            }
                    }


                    ///set this tile to 3
                    Tiles[i].Set_Discover(3);

                }








            }


                for(int i = 0; i < FlipThese.size(); i++)
                {
                    Tiles[FlipThese[i]].Set_Discover(2);

                }

                FlipThese.clear();

            //std::cout << "Step\n";

            Moves++;
    }

    updateTilesV = false;
    updateMobVision();

}


void Game::FlatenTileVision()
{
    for(int i = 0; i < Tiles.size(); i++)
    {
        if(Tiles[i].Get_Discover() != 0)
            Tiles[i].Set_Discover(1);
    }
}



void Game::updateMobVision() /// MOBs Vision //also putting chests in here.
{
/*
    for(int i = 0; i < MOBs.size(); i++)
    {
        for(int j = 0; j < Tiles.size(); j++)
        {
            if(MOBs[i].Get_X() == Tiles[j].Get_X() && MOBs[i].Get_Y() == Tiles[j].Get_Y())
            {
                MOBs[i].Set_Discover(Tiles[j].Get_Discover());
            }
        }
    }

    for(int i = 0; i < Objects.size(); i++)
    {
        for(int j = 0; j < Tiles.size(); j++)
        {
            if(Objects[i].Get_X() == Tiles[j].Get_X() && Objects[i].Get_Y() == Tiles[j].Get_Y())
            {
                Objects[i].Set_Discover(Tiles[j].Get_Discover());
            }
        }
    }
*/

        for(int j = 0; j < Tiles.size(); j++)
        {

                for(int i = 0; i < MOBs.size(); i++)
                {
                    if(MOBs[i].Get_X() == Tiles[j].Get_X() && MOBs[i].Get_Y() == Tiles[j].Get_Y())
                    {
                        MOBs[i].Set_Discover(Tiles[j].Get_Discover());
                    }
                }

                for(int i = 0; i < Objects.size(); i++)
                {
                    if(Objects[i].Get_X() == Tiles[j].Get_X() && Objects[i].Get_Y() == Tiles[j].Get_Y())
                    {
                        Objects[i].Set_Discover(Tiles[j].Get_Discover());
                    }
                }


        }


}

void Game::FlatenMobVision()
{
    for(int i = 0; i < MOBs.size(); i++)
    {
        if(MOBs[i].Get_Discover() != 0)
            MOBs[i].Set_Discover(1);
    }
}


void Game::Create_Text(std::string Text, int x, int y, int w, int h, bool FixedSize, SDL_Color TColor)
{
    TextString NEWTEXT;
    NEWTEXT.init(Ren0,Text,x,y,w,h,FONTA,TColor);
    if(FixedSize)
        NEWTEXT.Lock_Width(w);
    Texts.push_back(NEWTEXT);
}
void Game::Clear_Texts()
{
    Texts.clear();
}












int Game::Group_and_Destroy()
{

    int GroupID = 1;

    int HUNT = -2;
    bool KeepRunning = true;


while(KeepRunning)
{



    for(int i = 0; i < PCells.size(); i++)
    {

        //std::cout << "PCell id : " << PCells[i].Get_Group() << " | HUNT : " << HUNT << std::endl;
        if(PCells[i].Get_Group() == -1 && HUNT == -2)
        {

            std::cout << "Bing a seed was planted\n";

            PCells[i].Set_Group(GroupID);
            HUNT = GroupID;
            PCells[i].Set_Looked(true);
            GroupID++;

            int Tx = PCells[i].Get_GridX();
            int Ty = PCells[i].Get_GridY();

            ///Looking for more cells above it.
            for(int z = 0; z < PCells.size(); z++)
            {
                if(Tx+1 == PCells[z].Get_GridX() && Ty == PCells[z].Get_GridY())
                {
                    //if(!PCells[z].Get_Looked())
                   PCells[z].Set_Group(PCells[i].Get_Group());
                }
                if(Tx-1 == PCells[z].Get_GridX() && Ty == PCells[z].Get_GridY())
                {
                    //if(!PCells[z].Get_Looked())
                    PCells[z].Set_Group(PCells[i].Get_Group());
                }
                if(Tx == PCells[z].Get_GridX() && Ty+1 == PCells[z].Get_GridY())
                {
                    //if(!PCells[z].Get_Looked())
                    PCells[z].Set_Group(PCells[i].Get_Group());
                }
                if(Tx == PCells[z].Get_GridX() && Ty-1 == PCells[z].Get_GridY())
                {
                    //if(!PCells[z].Get_Looked())
                    PCells[z].Set_Group(PCells[i].Get_Group());
                }
            }


            draw();
        } /// END of Seed Cell.
        }


        if(HUNT != -2)
        {

            for(int z = 0; z < PCells.size(); z++)
            {
                if(PCells[z].Get_Group() == HUNT && !PCells[z].Get_Looked())
                {


                    bool Hunt_done = true;
                PCells[z].Set_Looked(true);


                        int Tx = PCells[z].Get_GridX();
                        int Ty = PCells[z].Get_GridY();
                    for(int h = 0; h < PCells.size(); h++)
                    {
                            if(Tx+1 == PCells[h].Get_GridX() && Ty == PCells[h].Get_GridY())
                                {
                                    //if(!PCells[h].Get_Looked())
                                   PCells[h].Set_Group(PCells[z].Get_Group());
                                }
                            if(Tx-1 == PCells[h].Get_GridX() && Ty == PCells[h].Get_GridY())
                                {
                                    //if(!PCells[h].Get_Looked())
                                    PCells[h].Set_Group(PCells[z].Get_Group());
                                }
                            if(Tx == PCells[h].Get_GridX() && Ty+1 == PCells[h].Get_GridY())
                                {
                                    //if(!PCells[h].Get_Looked())
                                    PCells[h].Set_Group(PCells[z].Get_Group());
                                }
                            if(Tx == PCells[h].Get_GridX() && Ty-1 == PCells[h].Get_GridY())
                                {
                                    //if(!PCells[h].Get_Looked())
                                    PCells[h].Set_Group(PCells[z].Get_Group());
                                }
                    }

                }



            }

        }




            bool End_Hunt = true;
            for(int z = 0; z < PCells.size(); z++)
            {
                if(PCells[z].Get_Group() == HUNT && !PCells[z].Get_Looked())
                    End_Hunt = false;

            }
            if(End_Hunt)
            {
                HUNT = -2;
                std::cout << "A new Hunt.\n";
            }


            draw();
            //usleep(100);

    ///} //this is end the end of a for l


        KeepRunning = false;
    for(int z = 0; z < PCells.size(); z++)
    {
        if(!PCells[z].Get_Looked())
            KeepRunning = true;
    }
    //KeepRunning = false; /// removing for right now



    }




return GroupID;



}

void Game::ClearDead_PCells()
{
    for(int i = 0; i < PCells.size(); i++)
    {
        if(PCells[i].Check_Dead())
        {
            if(i != 0)
            PCells.erase(PCells.begin() + i);
            else
            PCells.erase(PCells.begin());
        }
    }
}









/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
   int i, key, j;
   for (i = 1; i < n; i++)
   {
       key = arr[i];
       j = i-1;

       /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
       while (j >= 0 && arr[j] > key)
       {
           arr[j+1] = arr[j];
           j = j-1;
       }
       arr[j+1] = key;
   }
}



