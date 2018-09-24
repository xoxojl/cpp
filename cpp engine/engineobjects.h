#ifndef ENGINEOBJECTS_H_INCLUDED
#define ENGINEOBJECTS_H_INCLUDED

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class ObjGUI
{
private:
    int x,y;
    unsigned int w,h;
    RectangleShape rect;
    bool visible;
public:
    ObjGUI(int x,int y,int w,int h,Texture* texture);
    RectangleShape* getRect();
    void setVisible(bool state);
    void setPosition(int x,int y);
    void setSize(int w,int h);
    int getIntParam(string param);
};

#endif // ENGINEOBJECTS_H_INCLUDED
