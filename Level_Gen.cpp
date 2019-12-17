#include "game.h"

void Game::Level_Generator(int MapSizex, int MapSizey) ///Mapsize is in a chunk witch is 5 tiles.
{
    bool Debug = false;

    bool LayoutTEST = false;



    /// This Layer is online Tiles so walls floors and doors Player, items and mobs will be added in the next faze.
    /// z - Nothing don't put a tile there just skip setting in up
    /// D - Door Tile these will check if there by each other and if the are the will ether make a door or a opening else they will make a wall.
    /// Need to make somthing that will find if there is a door so it spawns a key where it is needed  this might be done after the player is spawn in entiy.

    int totalrooms = 16;

    std::string SRoom[5] = {"00D00",
                            "01110",
                            "D111D",
                            "01110",
                            "00D00"};

    std::string SsRoom[5] = {"00D00",
                            "01110",
                            "D101D",
                            "01110",
                            "00D00"};

    std::string HALLUP[5] = {"z0D0z",
                             "z010z",
                             "z010z",
                             "z010z",
                             "z0D0z"};

    std::string HALLSIDE[5] = {"zzzzz",
                               "00000",
                               "D111D",
                               "00000",
                               "zzzzz"};

    std::string CrossHALL[5] =  {"z0D0z",
                                 "00100",
                                 "D111D",
                                 "00100",
                                 "z0D0z"};


    std::string TUPSIDE[5] =  {"z0D0z",
                               "00100",
                               "D111D",
                               "00000",
                               "zzzzz"};


    std::string TDWSIDE[5] =  {"zzzzz",
                               "00000",
                               "D111D",
                               "00100",
                               "z0D0z"};

    std::string LDRSIDE[5] =  {"zzzzz",
                               "z0000",
                               "z011D",
                               "z0100",
                               "z0D0z"};

    std::string LURSIDE[5] =  {"z0D0z",
                               "z0100",
                               "z011D",
                               "z0000",
                               "zzzzz"};

    std::string LULSIDE[5] =  {"z0D0z",
                               "0010z",
                               "D110z",
                               "0000z",
                               "zzzzz"};

    std::string LDLSIDE[5] =  {"zzzzz",
                               "0000z",
                               "D110z",
                               "0010z",
                               "z0D0z"};

    std::string TriRoom[5] = {"z0D00",
                              "01110",
                              "D1100",
                              "0100z",
                              "000zz",};

    std::string BallRoom[5] = {"z0D0z",
                               "01110",
                               "D101D",
                               "01010",
                               "00000",};

    std::string SnapRoom[5] = {"0D0D0",
                               "01110",
                               "D111D",
                               "01110",
                               "0D0D0",};

    std::string ERROR_ROOM[5] = {"zzzzz",
                                 "zzzzz",
                                 "zzzzz",
                                 "zzzzz",
                                 "zzzzz",};


    std::string WRoom[5] = {"00D00",
                            "0111D",
                            "D1110",
                            "0111D",
                            "00D00"};

    std::string W2Room[5] = {"00D00",
                             "D1110",
                             "0111D",
                             "D1110",
                             "00D00"};

    std::string SHOP1Room[5] = {"00000",
                                "0pp11",
                                "S111k",
                                "0p1p1",
                                "00000"};

    std::string SHOP2Room[5] = {"00000",
                                "1ppp0",
                                "11sp0",
                                "111p0",
                                "00000"};



    bool Taken[MapSizex*Chunk_Size][MapSizey*Chunk_Size];

    for(int i = 0; i < MapSizey*Chunk_Size; i++) /// setting the mto false
        for(int j = 0; j < MapSizex*Chunk_Size; j++)
            Taken[i][j] = true;




    ///Mapsize is in a chunk witch is 5 tiles. // use Chunk_Size
            ///Gen Rooms
    std::string RoomData[MapSizey*Chunk_Size];

    for(int i = 0; i < MapSizey*Chunk_Size; i++) ///Filling with z
    {
        for(int j = 0; j < MapSizex; j++)
        {
            RoomData[i] += "zzzzz";
        }
    }

    /// //////////////////////////////////////////////////////
    std::cout << "Filling Room String will NULL objects\n";
    for(int i = 0; i < MapSizey*Chunk_Size; i++)
    {
        std::cout << RoomData[i] << std::endl;
    }
    std::cout << "\n\n";
    /// //////////////////////////////////////////////////////


    /// put stuff in the chuncks
    int lastis = 0;

    for(int i = 0; i < MapSizey; i++)
    {
        for(int j = 0; j < MapSizex; j++)
        {
            int type = rand() % totalrooms + 1; /// this uses the things on the top add more up there and incress this number as well

            std::string ChunkData[Chunk_Size];


            if(lastis == 4)
            {
                type = 995;
                lastis = 0;
            }

            if(lastis == 16)
            {
                type = 993;
                lastis = 0;
            }




            if(type == 1)
                for(int ff = 0; ff < Chunk_Size; ff++)
                ChunkData[ff] = SRoom[ff];

            if(type == 2)
                for(int ff = 0; ff < Chunk_Size; ff++)
                ChunkData[ff] = HALLUP[ff];

            if(type == 3)
                for(int ff = 0; ff < Chunk_Size; ff++)
                ChunkData[ff] = HALLSIDE[ff];

            if(type == 4)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = WRoom[ff];

            if(type == 5)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = CrossHALL[ff];

            if(type == 6)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = TUPSIDE[ff];

            if(type == 7)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = TDWSIDE[ff];


            if(type == 8)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = SsRoom[ff];

            if(type == 9)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = TriRoom[ff];

            if(type == 10)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = LDRSIDE[ff];

            if(type == 11)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = LURSIDE[ff];

            if(type == 12)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = LDLSIDE[ff];

            if(type == 13)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = LULSIDE[ff];

            if(type == 14)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = BallRoom[ff];

            if(type == 15)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = SnapRoom[ff];

            if(type == 16)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = SHOP1Room[ff];




            if(type == 993)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = SHOP2Room[ff];

            if(type == 995)
                for(int ff = 0; ff < Chunk_Size; ff++)
                    ChunkData[ff] = W2Room[ff];

            lastis = type;


            if(ChunkData[0] != "")
            {

                /// Put the chunk into the map data
                //RoomData[0+i][0] = ChunkData[i][0];
                for(int zz = 0; zz < 5; zz++)
                {
                    for(int ss = 0; ss < 5; ss++)
                    {
                                        //std::cout << ChunkData[zz] << "\n";


                        //std::cout << "Before : " << RoomData[(i*Chunk_Size)+zz][ss+(j*Chunk_Size)] << std::endl;

                        RoomData[(i*Chunk_Size)+zz][ss+((j*Chunk_Size))] = ChunkData[zz][ss];

                        //std::cout << "After : " << RoomData[(i*Chunk_Size)+zz][ss+(j*Chunk_Size)] << std::endl;

                        ///std::cout << "Room data targets are x and y: " << (i)+zz << " | " << ss + (j*Chunk_Size) << "\n";

                                        if(Debug && ChunkData[zz][ss] != ',' && ChunkData[zz][ss] != 'z' )
                                        {
                                            system("CLS");
                                            /// //////////////////////////////////////////////////////
                                            std::cout << "Map is now\n";
                                            for(int i = 0; i < MapSizey*Chunk_Size; i++)
                                            {
                                                std::cout << RoomData[i] << std::endl;
                                            }
                                            std::cout << "\n\n";
                                            /// //////////////////////////////////////////////////////
                                            //usleep(25);
                                        }



                    }
                }


            ChunkData[0] = "";
            ChunkData[1] = "";
            ChunkData[2] = "";
            ChunkData[3] = "";
            ChunkData[4] = "";

            }


        }
    }


                /// //////////////////////////////////////////////////////
                std::cout << "Map is now\n";
                for(int i = 0; i < MapSizey*Chunk_Size; i++)
                {
                    std::cout << RoomData[i] << std::endl;
                }
                std::cout << "\n\n";
                /// //////////////////////////////////////////////////////


                ///DEBUG SHOP MAP
if(LayoutTEST)
{

    std::cout << "NOTE : LayoutTEST is true forcing layout map. Make sure to turn this off before giving the game to people. make the bool LayoutTEST in Level_Gen.cpp to false. to turn this off. That is the only way to turn this off since it was code quick. So don't forget to.\n";

RoomData[0] = "zzzzzzzzzz0000000000z0D0z0000000000z0D00";
RoomData[1] = "00000000000pp111ppp0001000pp111ppp001110";
RoomData[2] = "D111DD111DS111k11sp0D111DS111k11sp0D1100";
RoomData[3] = "00000001000p1p1111p0001000p1p1111p00100z";
RoomData[4] = "zzzzzz0D0z0000000000z0D0z0000000000000zz";
RoomData[5] = "zzzzzz0D0zz0D0zzzzzz0D0D00000000000zzzzz";
RoomData[6] = "z000000100z010000000011100pp111ppp0z0000";
RoomData[7] = "z011DD111Dz011DD111DD111DS111k11sp0z011D";
RoomData[8] = "z010000100z000000000011100p1p1111p0z0100";
RoomData[9] = "z0D0zz0D0zzzzzzzzzzz0D0D00000000000z0D0z";
RoomData[10] = "zzzzzz0D0z00D00zzzzzzzzzz00D0000D00zzzzz";
RoomData[11] = "0000000100011100000z000000111DD11100000z";
RoomData[12] = "D111DD111DD101DD110zD111DD11100111DD110z";
RoomData[13] = "0010000100011100010z000000111DD11100010z";
RoomData[14] = "z0D0zz0D0z00D00z0D0zzzzzz00D0000D00z0D0z";
RoomData[15] = "00D00z0D0zz0D0zz0D0zzzzzzzzzzz0000000000";
RoomData[16] = "01110z010z011100111000000z00000pp111ppp0";
RoomData[17] = "D111Dz010zD101DD101DD111Dz011DS111k11sp0";
RoomData[18] = "01110z010z010100101000000z01000p1p1111p0";
RoomData[19] = "00D00z0D0z0000000000zzzzzz0D0z0000000000";
RoomData[20] = "z0D0z0D0D0z0D00z0D0zz0D0zz0D0z00D000D0D0";
RoomData[21] = "z010z011100111000100z010z001000111001110";
RoomData[22] = "z010zD111DD1100D111Dz010zD111DD111DD111D";
RoomData[23] = "z010z011100100z00000z010z000000111001110";
RoomData[24] = "z0D0z0D0D0000zzzzzzzz0D0zzzzzz00D000D0D0";
RoomData[25] = "zzzzzz0D0zzzzzz00D00z0D000000000000z0D0z";
RoomData[26] = "00000z010z0000001110011100pp111ppp000100";
RoomData[27] = "D111Dz010zD111DD101DD1100S111k11sp0D111D";
RoomData[28] = "00100z010z00100011100100z0p1p1111p000100";
RoomData[29] = "z0D0zz0D0zz0D0z00D00000zz0000000000z0D0z";
RoomData[30] = "00D0000D00zzzzzz0D00z0D0zzzzzzz0D0z00D00";
RoomData[31] = "0111DD11100000z01110z010z000000111001110";
RoomData[32] = "D11100111DD110zD1100z010zD111DD101DD101D";
RoomData[33] = "0111DD11100010z0100zz010z000000101001110";
RoomData[34] = "00D0000D00z0D0z000zzz0D0zzzzzz0000000D00";
RoomData[35] = "z0D0zzzzzzz0D0zz0D0z0000000000z0D0000D00";
RoomData[36] = "0010z0000001110001000pp111ppp0011100111D";
RoomData[37] = "D110zD111DD101DD111DS111k11sp0D1100D1110";
RoomData[38] = "0000z0000001010000000p1p1111p00100z0111D";
RoomData[39] = "zzzzzzzzzz00000zzzzz0000000000000zz00D00";
}
/*

*/



    ///MakeDoors and such
    for(int i = 0; i < MapSizey*Chunk_Size; i++)
    {
        for(int j = 0; j < MapSizex*Chunk_Size; j++)
        {
            bool update_debug = false;
            if( RoomData[i][j] == 'D' )
            {
                update_debug = true;
                /// Sinces it is checking from top to bottom left to right it should only need to check left and down.
                if(i != (MapSizey*Chunk_Size)-1 && j != MapSizex*Chunk_Size*2)
                {
                    if(RoomData[i+1][j] == 'D' || RoomData[i+1][j] == 'S')
                    {
                                                //std::cout << "THING "<< RoomData[i][j] << std::endl;
                        ///PUT RNG LATER for if it a door or not
                        RoomData[i][j] = '1';
                        if(RoomData[i+1][j] == 'S')
                            RoomData[i+1][j] ='7';
                        else
                            RoomData[i+1][j] ='1';
                                                //std::cout << "THING2 "<< RoomData[i][j] << std::endl;

                    }


                    else if(RoomData[i][j+1] == 'D' || RoomData[i][j+1] == 'S')
                    {
                        ///PUT RNG LATER

                        RoomData[i][j] = '1';
                        if(RoomData[i][j+1] == 'S')
                            RoomData[i][j+1] ='7';
                        else
                            RoomData[i][j+1] ='1';

                    }
                    else
                    {
                       RoomData[i][j] = '0';
                    }
                }

                    else
                    {
                       RoomData[i][j] = '0';
                    }



            }
                else if (RoomData[i][j] == 'S' )
                {
                    RoomData[i][j] = '7';
                }
                else if (RoomData[i][j] == 'k')
                {
                    RoomData[i][j] = '1';
                    //ADD_Object(j,i,15);
                    ADD_MOB(j,i,15,false,true);

                }
                else if (RoomData[i][j] == 'p')
                {
                    RoomData[i][j] = '1';
                    ADD_Object(j,i,16);

                }
                else if (RoomData[i][j] == 's')
                {
                    RoomData[i][j] = '1';
                    ADD_Object(j,i,17);

                }



                                                    if(Debug && update_debug)
                                        {

                                            system("CLS");
                                            /// //////////////////////////////////////////////////////
                                            std::cout << "Looking for doors\n";
                                            for(int i = 0; i < MapSizey*Chunk_Size; i++)
                                            {
                                                std::cout << RoomData[i] << std::endl;
                                            }
                                            std::cout << "\n\n";
                                            /// //////////////////////////////////////////////////////
                                            //std::cin.get();
                                        }

        }
    }



                                            /// //////////////////////////////////////////////////////
                                            std::cout << "Doors removed\n";
                                            for(int i = 0; i < MapSizey*Chunk_Size; i++)
                                            {
                                                std::cout << RoomData[i] << std::endl;
                                            }
                                            std::cout << "\n\n";
                                            /// //////////////////////////////////////////////////////







    ///MapCleanup and such This makes a cell map
    for(int i = 0; i < MapSizey*Chunk_Size; i++)
    {
        for(int j = 0; j < MapSizex*Chunk_Size; j++)
        {
            if(RoomData[i][j] == '1' || RoomData[i][j] == '7') // it looks for the floor and counts all that it can for an area.
            {
                Create_Cell(j,i); //put a setting for room type

            }
        }
    }


    int Amount_Of_Groupts = Group_and_Destroy(); /// well it does group them

int GroupTotal[Amount_Of_Groupts];

for(int i = 0; i < Amount_Of_Groupts; i ++)
{
    GroupTotal[i] = 0;
}


for(int i = 0; i < PCells.size(); i++)
{
    //std::cout << i <<" PCell : " << PCells[i].Get_Group() << std::endl;
    GroupTotal[PCells[i].Get_Group()]++;
}

for(int i = 0; i < Amount_Of_Groupts; i ++)
{
    std::cout << i << "# : " << GroupTotal[i] << std::endl;
}


int Use_Group = -1;
/*
for(int i = 0; i < Amount_Of_Groupts; i ++)
    for(int j = 0; j < Amount_Of_Groupts; j ++)
    {
        if(i != j)
        {
            if(GroupTotal[i] > GroupTotal[j] )
            {
                Use_Group = i;
            }
        }
    }
*/
int valueofGroup = 0;
for(int i = 0; i < Amount_Of_Groupts; i ++)
{
    if(GroupTotal[i] > valueofGroup)
    {
        Use_Group = i;
        valueofGroup = GroupTotal[i];
    }
}

std::cout << "Group : " << Use_Group << " is the largest setting to green and setting the rest to red";

for(int i = 0; i < PCells.size(); i++)
{
    if(PCells[i].Get_Group() == Use_Group)
    {
        PCells[i].Set_Placeable(true);
        PCells[i].Set_MODE(1);
    }
    else
        PCells[i].Set_MODE(2);
}


/// Destorying them from the map data
for(int i = 0; i < PCells.size(); i++)
{
    if(PCells[i].Get_Group() != Use_Group)
    {
        RoomData[PCells[i].Get_GridY()][PCells[i].Get_GridX()] = 'z';

        RoomData[PCells[i].Get_GridY()+1][PCells[i].Get_GridX()] = 'z';
        RoomData[PCells[i].Get_GridY()-1][PCells[i].Get_GridX()] = 'z';
        RoomData[PCells[i].Get_GridY()][PCells[i].Get_GridX()+1] = 'z';
        RoomData[PCells[i].Get_GridY()][PCells[i].Get_GridX()-1] = 'z';

        RoomData[PCells[i].Get_GridY()+1][PCells[i].Get_GridX()-1] = 'z'; // up right
        RoomData[PCells[i].Get_GridY()+1][PCells[i].Get_GridX()+1] = 'z'; // up left
        RoomData[PCells[i].Get_GridY()-1][PCells[i].Get_GridX()+1] = 'z'; // down right
        RoomData[PCells[i].Get_GridY()-1][PCells[i].Get_GridX()-1] = 'z'; // down left

        //std::cout << " i : " << i << std::endl;


        PCells[i].Destory();
    }

}

ClearDead_PCells();











    for(int i = 0; i < MapSizey*Chunk_Size; i++)
    {
        for(int j = 0; j < MapSizex*Chunk_Size; j++)
        {
            if( RoomData[i][j] != 'z')
            {
                char temp = RoomData[i][j];
                int III = temp - '0';
                ADD_Tile(j,i,III);
                if(III == 1)
                    Taken[j][i] = false;

            }

        }
    }




/// !!!!!!!!!!!!!!!!!!!!!!!!! Use the left over cell grid to place items and such !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

    /// NOTE SPAWN KEYS AFTER PLAYER And make sure there are keys for the doors at lest.
/// Adding Objects and MOBs (player)
/// look for 1 tiles that have not been used keep track with an array.
    /// if it is free put the player first then use RNG for the rest of the objects and mark that it is taken in the array




    ///Spawn player
for(int i = 0; i < PCells.size(); i++)
{
    if(PCells[i].Get_Placeable())
    {
        ADD_MOB(PCells[i].Get_GridX(), PCells[i].Get_GridY(), 2 , true, false);
        PCells[i].Destory();
        PCells[i].Set_Placeable(false);
        break;
    }
}

ClearDead_PCells();


/// Place Higher prioridty stuff like keys/ not setupyet.





/// Spawn Monsters /// Make monster more RNG BASED IN ADD_MOB with random stats and such and change the color of the sprite. i think i can do that in sdl2 with render copyex
for(int i = 0; i < PCells.size(); i++)
{
    if(PCells[i].Get_Placeable())
    {

        int ROLL = rand() % 12 + 1;

        if(ROLL == 12)
        {
                ROLL = rand() % 2 + 1;

                if(ROLL == 1)
                {
                    ADD_MOB(PCells[i].Get_GridX(), PCells[i].Get_GridY(), 3 , false,false);

                }

                else if(ROLL == 2)
                {
                    ADD_MOB(PCells[i].Get_GridX(), PCells[i].Get_GridY(), 4 , false,false);

                }


        }
        if(ROLL == 11) /// Objects Keys will be here as well.
        {
            ADD_Object(PCells[i].Get_GridX(), PCells[i].Get_GridY(), 5);
        }


        PCells[i].Destory();
        PCells[i].Set_Placeable(false);

    }
}

ClearDead_PCells();














}
