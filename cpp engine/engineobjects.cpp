#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "engineobjects.h"

using namespace std;
using namespace sf;

ObjGUI::ObjGUI(int x,int y,int w,int h,Texture *texture)
{
    ObjGUI::x=x;
    ObjGUI::y=y;
    ObjGUI::w=w;
    ObjGUI::h=h;
    ObjGUI::rect.setSize(Vector2f(w,h));
    ObjGUI::rect.setTexture(texture);
}
RectangleShape* ObjGUI::getRect(){
    if(ObjGUI::visible)
        return &(ObjGUI::rect);
}
void ObjGUI::setPosition(int x,int y)
{
    ObjGUI::x=x;
    ObjGUI::y=y;
    ObjGUI::rect.setPosition(Vector2f(ObjGUI::x,ObjGUI::y));
}
int ObjGUI::getIntParam(string param)
{
    if(param=="x")
        return ObjGUI::x;
    if(param=="y")
        return ObjGUI::y;
    if(param=="w")
        return ObjGUI::w;
    if(param=="h")
        return ObjGUI::h;
}
void ObjGUI::setVisible(bool state)
{
    ObjGUI::visible=state;
}
///\brief Get a int param
