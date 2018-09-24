#ifndef GAMEPLAYENGINE_H_INCLUDED
#define GAMEPLAYENGINE_H_INCLUDED

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <cstdlib>

using namespace std;
using namespace sf;

class objgm_target
{
private:
    int x;
    int y;
    unsigned int w,h;
    float speed;
    float dirx,diry;
    unsigned int id;

    RectangleShape* animrect;
    RectangleShape rect;

    bool del;
public:
    objgm_target(int x,int y,int w,int h,float speed,int id,RectangleShape* rect);
    void update(float time);
    void moving(float x,float y,float time);
    void draw(RenderWindow* window);

    void setPosition(int x,int y);
    void setSize(int w,int h);
    void setSpeed(float speed);
    void setDirection(float x,float y);
    void setId(int id);
    void setDel(bool del);

    RectangleShape* getRect();
    int getX();
    int getY();
    int getW();
    int getH();
    int getId();
    bool getDel();
};

#endif // GAMEPLAYENGINE_H_INCLUDED
