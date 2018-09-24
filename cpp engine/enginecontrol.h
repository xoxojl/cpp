#ifndef ENGINECONTROL_H_INCLUDED
#define ENGINECONTROL_H_INCLUDED

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Vector2i convertMousePos(RenderWindow* window,int width,int height);

#endif // ENGINECONTROL_H_INCLUDED
