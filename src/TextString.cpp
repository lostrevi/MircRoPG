#include "TextString.h"

TextString::TextString()
{
    //ctor
}

void TextString::init(SDL_Renderer *RenZ, std::string InputText, int xa,int ya, int WidthUnitA, int HeigthUnitA, TTF_Font *FONT, SDL_Color TCOLOR)
{
    RenA = RenZ;
    Text = InputText;
    x = xa;
    y = ya;
    WidthUnit = WidthUnitA;
    HeigthUnit = HeigthUnitA;
    LockWidth = false;

    COLOR = TCOLOR;

    Font0 = FONT;

    LOC.x = x;
    LOC.y = y;
    LOC.h = HeigthUnit;
    LOC.w = WidthUnitA;

    updateText(Text);


}
void TextString::update()
{

}
void TextString::draw()
{
        SDL_RenderCopy(RenA,TexTure,NULL,&LOC);
}

void TextString::updateText(std::string UpdatedText) /// this will update the texture as will as the LOC.w
{
    Text = UpdatedText;

    SDL_Surface * surface = TTF_RenderText_Solid(Font0,Text.c_str(), COLOR);

    TexTure = SDL_CreateTextureFromSurface(RenA, surface);

    if(!LockWidth)
        SetText_Width();

    SDL_FreeSurface(surface);

}

void TextString::SetText_Width()
{
    LOC.w = 0;

    for(int i = 0; i < Text.size(); i++)
    {
        LOC.w += WidthUnit;
    }
}

void TextString::changecolor(SDL_Color NewColor)
{
    COLOR = NewColor;
}


