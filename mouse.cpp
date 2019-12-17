#include "game.h"


void Game::initmouse()
{
    SDL_ShowCursor(SDL_DISABLE);

    TargetMouse.x = 0;
    TargetMouse.y = 0;
    TargetMouse.w = 4;
    TargetMouse.h = 4;
}


void Game::updatemouse()
{

    TargetMouse.x = INPUTS.GetMouseX();
    TargetMouse.y = INPUTS.GetMouseY();


    if(INPUTS.LCPressed())
    {
        std::cout << "Left Click\n";
    }
    if(INPUTS.RCPressed())
    {
        std::cout << "Right Click\n";
    }
    if(INPUTS.MCPressed())
    {
      std::cout << "Middle Click\n";
    }
    else if(!INPUTS.MCPressed())
    {
        //Release
    }



    if(INPUTS.GetWheelUp())
    {
        std::cout << "mouse wheel up\n";
    }
    if(INPUTS.GetWheelDown())
    {
        std::cout << "mouse wheel down\n";
    }


}

void Game::drawmouse()
{
    SDL_SetRenderDrawColor( Ren0, 255, 0, 0, 0xFF );
    SDL_RenderDrawRect(Ren0,&TargetMouse);
}

