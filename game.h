#ifndef GAME_H
#define GAME_H

#include "input.h"

class Game
{
private:
    static const int SCREEN_WIDTH = 720;
    static const int SCREEN_HEIGHT = 480; //I want these to be change able via an ini or somthing but this is fine for now.
    bool Running = true; //this condition will be set to false if the game loop falls or stops working.

    bool FLOOR_CLEAR = false;

    void Check_Floor_Clear(); /// check that all mobs are died but not the shop keeper.

    void restart_game();

    bool PlayerDead = false;

    SDL_Texture *DeathScreen;

    std::string Name_of_app = "MiRoPG 0.0.1a";

    void Object_enity_Cleaner();
    int TimerCL = 0;
    int TimerCLMAX = 5;

    input INPUTS;

    int TimerM = 0;
    int TimerMMAX = 15;

    ///UI JUNK
    SDL_Texture *CharSheet;
    bool DrawCharSheet = false;
    SDL_Rect Screen = {0,0,SCREEN_WIDTH,SCREEN_HEIGHT};

    SDL_Texture *EQMOB;

    void Load_CharSheet(bool loadorunload); /// if true ti loads it if false it unloads it.

    SDL_Texture *ItemViewerBar;
    SDL_Texture *ITEMS;
    void ItemViewer(std::vector<item> Contents, int ContetnsVectroLoc,  bool PlayersInv,bool loadorunload); ///IN UI.CPP
    std::vector<SDL_Rect> LOCSforBars;
    std::vector<SDL_Rect> ICONSforBars;
    std::vector<SDL_Rect> ICONSCLIPforBars;
    std::vector<SDL_Rect> EffectsforICONS;
    std::vector<int> ID_OFTIMES;
    bool subMenu_isP = false;
    int ContentsVectorLOCsva = 0;
    void ItemViewerDraw();
    bool DrawItemScreen = false;
    int SelectedBar = 0;
    int CurrentMAXINV = 0;
    SDL_Texture *SubMenu_P;
    SDL_Rect SubMenu_P_LOC;
    SDL_Texture *SubMenu_nonP;
    SDL_Rect SubMenu_nonP_LOC;
    bool SpacePressed = false;
    bool BackAMenu = false;
    bool SubMenu_notP = false;
    bool DrawHand = false;
    int TimerH = 0;
    int TImerHMAX = 8;
    SDL_Texture *HAND;
    SDL_Rect Hand_LOC;
    SDL_Rect Hand_CLIP;
    bool PlayerzInv = false;
    int IDofITEMSELECTED = -1;
    int LASTKNOWBAR = 0;

    SDL_Texture *EquippedICON;
    std::vector<SDL_Rect> EquiptICONLOCs;

    SDL_Texture *PlayerInvSign;
    bool PlayersInvSign = false;

    int OffsetXTOTAL = 0;
    int OffsetYTOTAL = 0;

    SDL_Texture *UISkeleton;
    SDL_Texture *UIBat;
    SDL_Texture *UIBLANK;

    SDL_Rect UI_TOPFACE;
    SDL_Rect UI_LOWFACE;

    SDL_Texture *LOWERUIFACE;
    SDL_Texture *UPERUIFACE;

    void SetAllMenusFalse()
    {
        Hand_LOC.w = 60;
        Hand_LOC.h = 60;
        ContentsVectorLOCsva = 0;
        IDofITEMSELECTED = -1;
        LASTKNOWBAR = 0;
        PlayersInvSign = false;
        BackAMenu = false;
        PlayerzInv = false;
        SpacePressed = false;
        SubMenu_notP = false;
        DrawItemScreen = false;
        subMenu_isP = false;
        DrawCharSheet = false;
        DrawHand = false;
        LOCSforBars.clear();
        ICONSforBars.clear();
        ICONSCLIPforBars.clear();
        EffectsforICONS.clear();
        ID_OFTIMES.clear();
        EquiptICONLOCs.clear();
        SelectedBar = 0;
        CurrentMAXINV = 0;
        Clear_Texts();
    }

    TextString INFO;
    int INFOtimer = 0;
    int INFOtimerMAX = 120;
    void Push_Info(std::string info)
    {
        INFOtimer = 0;
        INFO.updateText(info);
    }



    int WorldSize = 8; ///8
    int worldsizeX = WorldSize;
    int worldsizeY = WorldSize;

    int Tilesize = 25;

    void updatekeys();
    void updatemouse();
    void drawmouse();
    void initmouse();

    bool updateTilesV = true;
    bool updateMOBV = true;
    bool updateObjectV = true;

    void updateTileVision();
    void FlatenTileVision(); //just sets the tiles to 0 or or 1;

    void updateMobVision();
    void FlatenMobVision(); //just sets the tiles to 0 or or 1;

    TTF_Font *FONTA;

    TextString TestText;

    TextString Goldinfo;

    int LastGold = 0;

    TextString HPinfo;
    TextString ohterHPinfo;

    int EHPindex = 0;

    int LastHP = 0;
    int otherLastHP = 0;

    std::vector<TextString> Texts;

     SDL_Color White = {255,255,255};
     SDL_Color Red = {225,50,50};
     SDL_Color Green = {0,255,0};
     SDL_Color Black = {0,0,0};
     SDL_Color Blue = {0,0,255};
     SDL_Color Gold = {255,215,0};



    void Create_Text(std::string Text, int x, int y, int w, int h, bool FixedSize, SDL_Color TColor);
    void Clear_Texts();

    void GetRightHUDstuff();


    //SDL objects
    SDL_Window* win0 = NULL;
    SDL_Renderer* Ren0 = NULL;
    SDL_Texture* Tex0 = NULL;
    SDL_Event e;

    SDL_Rect TargetMouse;

    void run(); //starts to run all of the other game loops and such

    void draw(); // handles all the drawing
    void update(); //handles like changing hp or checking for a hit
    void input(); // handles input such as key presses and such
    void commandline(); // stuff with the command line if it used at all.
    void init(); //init's stuff like filling vars.

    void Level_Generator(int MapSizex, int MapSizey); ///Mapsize is in a chunk witch is 5 tiles.

    int Chunk_Size = 5;

    std::vector<Tile> Tiles;

    void ADD_Tile(int x, int y, int index);

    std::vector<MOB> MOBs;

    void ADD_MOB(int x, int y, int index, bool player, bool ShopKeeper);


    std::vector<Object> Objects;

    std::vector<PCell> PCells;

    bool Create_Cell(int x, int y); /// will return false if the grid spot is taken and true if it adds another tile.

    int Group_and_Destroy(); // for Pcells

    void ClearDead_PCells();

    bool WallCheck(int x, int y, int Dx, int Dy);

    bool CombatCheck(int x, int y, int Dx, int Dy, int TargetIndex);

    void AI_UPDATE();



    void ADD_Object(int x, int y, int index);

    int OffsetX = 0;
    int OffsetY = 0;

    int TimerA = 0;
    int TimerAMAX = 5;

    int TimerB = 0;
    int TimerBMAX = 10;

    void insertionSort(int arr[], int n);

    void Cam_ON_Player();

    void Set_LowFace(int type, int index);


    //tool
     SDL_Texture* loadTexture(std::string path);

     SDL_Texture *UI_Bar;
     SDL_Texture *MainTiles;

     SDL_Rect UI_BarR;

     std::string int_to_string(int a)
     {
            std::stringstream ss;
            ss << a;
            std::string str = ss.str();
            return str;
     }



public:

    void Startup();

};


#endif
