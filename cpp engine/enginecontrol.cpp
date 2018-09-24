#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Mouse.hpp>
#include <iostream>
#include "enginecontrol.h"

using namespace std;
using namespace sf;

Vector2i convertMousePos(RenderWindow* window,int width,int height)
{
    Vector2u windowsize=window->getSize();
    Vector2i mousepos=Mouse::getPosition(*window);
    mousepos.x=float(mousepos.x/float(windowsize.x))*float(width);
    mousepos.y=float(mousepos.y/float(windowsize.y))*float(height);
    return Vector2i(mousepos.x,mousepos.y);
}
