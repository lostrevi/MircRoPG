#include "game.h"


void Game::Load_CharSheet(bool loadorunload)
{
    if(loadorunload)
    {
        SetAllMenusFalse();/// start with this

        DrawCharSheet = true; /// this draws the box in Game.cpp

        /// init all the strings
        std::string HP = "HP : ";
        std::string  STR = "STR : "; // use for str based wep asl this is a punch
        std::string  DEX = "DEX : "; // used for dex based weaps
        std::string  CON = "CON : "; // used to find mobs hp
        std::string  INT = "INT : "; // not sure yet
        std::string  WIS = "WIS : "; // getting item stats and discriptons
        std::string  CHA = "CHA : "; // lol
        std::string Sex = "";

        std::string Wep = "Weapon : ";
        std::string DEF = "Shield : ";


        /// fill all the strings with player info
        for(int i = 0; i < MOBs.size(); i++)
        {
            if(MOBs[i].isPlayer())
            {
                ///do stuff here
                HP += int_to_string(MOBs[i].Get_HP()) += "/";
                HP += int_to_string(MOBs[i].Get_MHP());

                STR += int_to_string(MOBs[i].Get_STR()) + " | " + int_to_string(MOBs[i].Get_Mod(MOBs[i].Get_STR()));
                DEX += int_to_string(MOBs[i].Get_DEX()) + " | " + int_to_string(MOBs[i].Get_Mod(MOBs[i].Get_DEX()));
                CON += int_to_string(MOBs[i].Get_CON()) + " | " + int_to_string(MOBs[i].Get_Mod(MOBs[i].Get_CON()));
                INT += int_to_string(MOBs[i].Get_INT()) + " | " + int_to_string(MOBs[i].Get_Mod(MOBs[i].Get_INT()));
                WIS += int_to_string(MOBs[i].Get_WIS()) + " | " + int_to_string(MOBs[i].Get_Mod(MOBs[i].Get_WIS()));
                CHA += int_to_string(MOBs[i].Get_CHA()) + " | " + int_to_string(MOBs[i].Get_Mod(MOBs[i].Get_CHA()));

                Sex = MOBs[i].Get_Sex();


                for(int j = 0; j < MOBs[i].Get_Invenotry().size(); j++)
                {
                    if(MOBs[i].Get_Invenotry()[j].Get_Equipped() == 1)
                    {
                        Wep += MOBs[i].Get_Invenotry()[j].Get_Name();
                    }
                    if(MOBs[i].Get_Invenotry()[j].Get_Equipped() == 2)
                    {
                        DEF += MOBs[i].Get_Invenotry()[j].Get_Name();
                    }

                }

            }
        }




        Create_Text(HP,465,230,12,16,false,White);

        Create_Text(Sex,465,300,12,16,false,White);


        Create_Text("STATS",80,65,12,16,false,White);



        Create_Text(STR,80,85,12,16,false,White);
        Create_Text(DEX,80,103,12,16,false,White);
        Create_Text(CON,80,121,12,16,false,White);
        Create_Text(INT,80,139,12,16,false,White);
        Create_Text(WIS,80,157,12,16,false,White);
        Create_Text(CHA,80,175,12,16,false,White);

        Create_Text(Wep,80,360,12,16,false,White);
        Create_Text(DEF,80,378,12,16,false,White);


    }
    else
    {
        SetAllMenusFalse();
    }




}



void Game::ItemViewer(std::vector<item> Contents, int ContetnsVectroLoc , bool PlayersInv,bool loadorunload)
{
    if(loadorunload)
    {
        SetAllMenusFalse(); /// make sure this is on top.

        ContentsVectorLOCsva = ContetnsVectroLoc;

        DrawHand = true;
        PlayerzInv = PlayersInv;
        PlayersInvSign = PlayersInv;

        CurrentMAXINV = Contents.size();

        DrawItemScreen = true;
        int barW = 655;
        int barH = 50;
        int startingX = 50; /// was 32
        int startingY = 32;
        int NextYAMOUNT = 10;

        for(int i = 0; i < Contents.size(); i ++)
        {
            SDL_Rect NEWRECT;
            NEWRECT.x = startingX;
            NEWRECT.y = startingY + ((NextYAMOUNT+barH)*i);
            NEWRECT.w = barW;
            NEWRECT.h = barH;

            int ID_GET = 0;

            ID_GET = Contents[i].Get_ID();

            ID_OFTIMES.push_back(ID_GET); /// Puts the ID into a vector


            LOCSforBars.push_back(NEWRECT);



            NEWRECT.x += 3;
            NEWRECT.y += 3;
            NEWRECT.w = 45;
            NEWRECT.h = 45;

            ICONSforBars.push_back(NEWRECT);
            if(Contents[i].Get_Equipped() != 0)
            EquiptICONLOCs.push_back(NEWRECT);
            else
            {
                SDL_Rect NEWNEWRECT = {14502,14502,14502,14502};
                EquiptICONLOCs.push_back(NEWNEWRECT); //just dummy data to keep it in track don't change dummy data because it looks to see if it should ignor 14502 on x
            }

            int TargetINDEX = Contents[i].Get_DrawINDEX();
            int WidthOFITEMSHEET = 10;

            SDL_Rect NEWICONLOC;

            NEWICONLOC.x = TargetINDEX % WidthOFITEMSHEET;
            NEWICONLOC.y = (TargetINDEX - NEWICONLOC.x) / WidthOFITEMSHEET;
            NEWICONLOC.w = NEWICONLOC.h = 25;

            NEWICONLOC.x = NEWICONLOC.x * 25;
            NEWICONLOC.y = NEWICONLOC.y * 25;




            ICONSCLIPforBars.push_back(NEWICONLOC);

            TargetINDEX = Contents[i].Get_effectINDEX();
            if(TargetINDEX == 0)
                TargetINDEX = 1; //because it will not draw it.
            else
            {
                std::cout << "TargetINDEX IS : " << TargetINDEX << std::endl;
            }

            NEWICONLOC.x = TargetINDEX % WidthOFITEMSHEET;
            NEWICONLOC.y = (TargetINDEX - NEWICONLOC.x) / WidthOFITEMSHEET;


            NEWICONLOC.x = NEWICONLOC.x * 25;
            NEWICONLOC.y = NEWICONLOC.y * 25;

            EffectsforICONS.push_back(NEWICONLOC);

            std::string ItemName = "ERROR: item not found. DevCH UI.cpp ItemViewer()";

            ItemName = Contents[i].Get_Name();

            Create_Text(ItemName,NEWRECT.x+53,NEWRECT.y+19 ,12,16,false,White);

        }


    }
    else
    {
        SetAllMenusFalse();
    }




}


void Game::ItemViewerDraw()
{
    /// draw this ItemViewerBar

    /// Kinda Bad Code but this will also update here as well

    if(SpacePressed && !SubMenu_notP && !subMenu_isP)
    {
        SpacePressed = false;
        if(PlayerzInv)
        {
            //Do player inv sub menu
            subMenu_isP = true;
            LASTKNOWBAR = SelectedBar;

            IDofITEMSELECTED = ID_OFTIMES[SelectedBar];

            SubMenu_P_LOC.x = LOCSforBars[SelectedBar].x + 40;
            SubMenu_P_LOC.y = LOCSforBars[SelectedBar].y + 20;

            SelectedBar = 0;

        }
        else
        {
            SubMenu_notP = true;
            LASTKNOWBAR = SelectedBar;

            IDofITEMSELECTED = ID_OFTIMES[SelectedBar];

            SubMenu_nonP_LOC.x = LOCSforBars[SelectedBar].x + 40;
            SubMenu_nonP_LOC.y = LOCSforBars[SelectedBar].y + 20;

            SelectedBar = 0;

        }

    }

    if ((BackAMenu && SubMenu_notP) ) //|| (BackAMenu && subMenu_isP))
    {
        SpacePressed = false;
        BackAMenu = false;
        if(PlayerzInv)
        {
            Hand_LOC.w = 60;
            Hand_LOC.h = 60;
            subMenu_isP = false;
            SelectedBar = LASTKNOWBAR;
        }
        else
        {
            Hand_LOC.w = 60;
            Hand_LOC.h = 60;
            SubMenu_notP = false;
            SelectedBar = LASTKNOWBAR;
        }
    }





    /// THIS IS THE UPDATE PART
    if(SubMenu_notP ) /// add or for the other;
    {
        Hand_LOC.w = 30;
        Hand_LOC.h = 30;

        int Menu_Max = 2;

        if(SelectedBar > Menu_Max)
            SelectedBar = 0;
        if(SelectedBar < 0)
            SelectedBar = Menu_Max;

        Hand_LOC.x = SubMenu_nonP_LOC.x - 15;
        Hand_LOC.y = SubMenu_nonP_LOC.y  + 5;

        Hand_LOC.y += SelectedBar * 30;
    }

    if(subMenu_isP ) /// This is the player just incase they dont match size later
    {
        Hand_LOC.w = 30;
        Hand_LOC.h = 30;

        int Menu_Max = 2;

        if(SelectedBar > Menu_Max)
            SelectedBar = 0;
        if(SelectedBar < 0)
            SelectedBar = Menu_Max;

        Hand_LOC.x = SubMenu_P_LOC.x - 15;
        Hand_LOC.y = SubMenu_P_LOC.y  + 5;

        Hand_LOC.y += SelectedBar * 30;
    }


    /// Just so it all in one methoid



    /// This is the options for the menus
    if(SpacePressed && SubMenu_notP ) /// this is for non player inv
    {
        item *TEMP; /// Gets the object address
        int target_i = 0;
            for(int i = 0; i < Objects[ContentsVectorLOCsva].Get_Contents().size(); i ++)
            {
                if(Objects[ContentsVectorLOCsva].Get_Contents()[i].Get_ID() == IDofITEMSELECTED)
                {
                    target_i = i;
                    TEMP = Objects[ContentsVectorLOCsva].Get_ContentsA(i);


                    /// NEED TO POINT TO THE OBJECT TO DO THIS.

                }
            }



        if(SelectedBar == 0 ) ///take (puts the item in your inventory)
        {
            std::cout << "Giving item to player : "<< IDofITEMSELECTED << std::endl;
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer())
                {
                    if(MOBs[i].Room_in_Inventory())
                    {

                            MOBs[i].Put_Item(Objects[ContentsVectorLOCsva].Get_Contents()[target_i]);
                            TEMP->Set_Dead();


                    }
                    else
                    {
                        Push_Info("Player Inventory Full");
                    }
                }
            }
        }
        else if(SelectedBar == 1) /// use (use a potion might make it so it can equipt as well)
        {
            std::cout << "Using item : "<< IDofITEMSELECTED << std::endl;
            for(int i = 0; i < MOBs.size(); i++)
                        {
                            if(MOBs[i].isPlayer())
                            {
                                if(MOBs[i].Room_in_Inventory())
                                {

                                        if(TEMP->Get_type() == 4)
                                        {
                                            MOBs[i].Use_Item(Objects[ContentsVectorLOCsva].Get_Contents()[target_i]);
                                            TEMP->set_Destroy();
                                        }

                                        else
                                        Push_Info("You can't eat that.");

                                }
                                else
                                {
                                    Push_Info("Player Inventory Full");
                                }
                            }
                        }
        }
        else if(SelectedBar == 2) /// delete (destory the item to make room for more)
        {
            std::cout << "Getting rid of  : "<< IDofITEMSELECTED << std::endl;

             TEMP->Set_Dead();

        }

        SetAllMenusFalse();
    }


    ///For Player
    if(SpacePressed && subMenu_isP ) /// this is for non player inv
    {
        item *TEMP; /// Gets the object address
        int target_i = 0;
            for(int i = 0; i < MOBs[ContentsVectorLOCsva].Get_Invenotry().size(); i ++)
            {
                if(MOBs[ContentsVectorLOCsva].Get_Invenotry()[i].Get_ID() == IDofITEMSELECTED)
                {
                    target_i = i;
                    TEMP = MOBs[ContentsVectorLOCsva].Get_InvenotryA(i);


                    /// NEED TO POINT TO THE OBJECT TO DO THIS.

                }
            }



        if(SelectedBar == 0 ) ///Equpited
        {

            std::cout << "Equpiting item or using it : "<< IDofITEMSELECTED << std::endl;

            for(int i = 0; i < MOBs.size(); i++)
            {
                if( MOBs[i].isPlayer() )
                {
                    //std::cout << "TYPE IS : " << TEMP->Get_type() << "     | it should be for if potion\n";
                    if(TEMP->Get_type() == 4) ///check to see if it is an usable item and not equptment
                    {
                        MOBs[i].Use_Item(MOBs[i].Get_Invenotry()[target_i]);
                        TEMP->set_Destroy();
                    }

                    else if(TEMP->Get_type() == 1) ///WEP
                    {
                        MOBs[i].UnEquippedallofType(1); /// makeing sure you dont eq more then one wep
                        TEMP->Set_Equipped(1); /// setting selected to wep
                    }
                    else if(TEMP->Get_type() == 2) ///ARMOR
                    {
                        MOBs[i].UnEquippedallofType(2); /// makeing sure you dont eq more then one DEF
                        TEMP->Set_Equipped(2); /// setting selected to DEF
                    }


                }
            }



        }
        else if(SelectedBar == 1) /// use (use a potion might make it so it can equipt as well)
        {
            std::cout << "Dropping item : "<< IDofITEMSELECTED << std::endl;

            int PlayerX = 0;
            int PlayerY = 0;
            int PlayerI = 0;
            for(int i = 0; i < MOBs.size(); i++)
            {
                if(MOBs[i].isPlayer())
                {
                    PlayerX = MOBs[i].Get_X();
                    PlayerY = MOBs[i].Get_Y();
                    PlayerI = i;
                }
            }



            bool GenChest = true;
            bool ChestFull = false;

            for(int i = 0; i < Objects.size(); i++)
            {
                if(Objects[i].Get_X() == PlayerX && Objects[i].Get_Y() == PlayerY )
                {



                    if( !Objects[i].check_Full() )
                    {
                        Objects[i].Put_Item(MOBs[PlayerI].Get_Invenotry()[target_i]);
                        GenChest = false;
                    }
                    else
                    {
                        ChestFull = true;
                        Push_Info("There is no more room.");
                    }
                }
                else /// make chest
                {


                    //break;

                }
            }

            if(GenChest) /// MakeChest
            {
                    Object NewObject;
                    NewObject.init(Ren0,MainTiles,PlayerX,PlayerY,5);
                    NewObject.Clear_Contents();
                    NewObject.Put_Item(MOBs[PlayerI].Get_Invenotry()[target_i]);
                    NewObject.update(OffsetXTOTAL,OffsetYTOTAL);
                    Objects.push_back(NewObject);
            }



            if(!ChestFull)
            TEMP->Set_Dead();

        }
        else if(SelectedBar == 2) /// delete (destory the item to make room for more)
        {
            std::cout << "Getting rid of  : "<< IDofITEMSELECTED << std::endl;

             TEMP->Set_Dead();

        }

        SetAllMenusFalse();
    }


/// Draw Staments /// ----------------------------------------------------------------------------------------------- /// Draw Staments ///

    for(int i = 0; i < LOCSforBars.size(); i++)
    {
        if(SelectedBar != i || SubMenu_notP || subMenu_isP)
        SDL_RenderCopy(Ren0,ItemViewerBar,NULL,&LOCSforBars[i]);
        else
        {
            if(!SubMenu_notP || !subMenu_isP)
            {

                Hand_LOC.x = LOCSforBars[i].x - 50;
                Hand_LOC.y = LOCSforBars[i].y - 5;



            SDL_SetTextureColorMod(ItemViewerBar, 0,0,255); //red
            SDL_RenderCopy(Ren0,ItemViewerBar,NULL,&LOCSforBars[i]);
            SDL_SetTextureColorMod(ItemViewerBar, 255,255,255); //clear
            }


        }



        if(EffectsforICONS[i].y != 0)
        SDL_RenderCopy(Ren0,ITEMS,&EffectsforICONS[i],&ICONSforBars[i]);


        ///std::cout << "STUFF : " << ICONSCLIPforBars[i].x << " , " << ICONSCLIPforBars[i].y << " , " << ICONSCLIPforBars[i].w << " , " << ICONSCLIPforBars[i].h << std::endl;

        SDL_RenderCopy(Ren0,ITEMS,&ICONSCLIPforBars[i],&ICONSforBars[i]);

        if(EquiptICONLOCs[i].x != 14502)
        SDL_RenderCopy(Ren0,EquippedICON, NULL, & EquiptICONLOCs[i]);
    }

}







