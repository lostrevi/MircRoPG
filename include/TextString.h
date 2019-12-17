#ifndef TEXTSTRING_H
#define TEXTSTRING_H

#include "../timer.h"

class TextString
{
    public:
        TextString();

        void init(SDL_Renderer *RenZ, std::string InputText, int xa,int ya, int WidthUnitA, int HeigthUnitA, TTF_Font *FONT, SDL_Color TCOLOR);
        void update();
        void draw();

        void updateText(std::string UpdatedText); /// this will update the texture as will as the LOC.w

        void changecolor(SDL_Color NewColor);

        void Lock_Width(int w)
        {
            LOC.w = w;
            LockWidth = true;
        }


    private:


    void SetText_Width();

    SDL_Color COLOR;

    TTF_Font *Font0; /// just have it load somthing easy;
    std::string Text = "";
    int x, y;
    int WidthUnit, HeigthUnit;
    bool LockWidth = false;

    SDL_Renderer *RenA;
    SDL_Texture *TexTure;
    SDL_Rect LOC;

};

#endif // TEXTSTRING_H
