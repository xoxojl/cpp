#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include "gameplayengine.h"

using namespace std;
using namespace sf;

objgm_target::objgm_target(int x,int y,int w,int h,float speed,int id,RectangleShape* rect)
{
    objgm_target::x=x;
    objgm_target::y=y;
    objgm_target::w=w;
    objgm_target::h=h;
    objgm_target::speed=speed;
    objgm_target::id=id;
    objgm_target::animrect=rect;

    objgm_target::dirx=0.f;
    objgm_target::diry=1.f;
    objgm_target::del=false;
}
void objgm_target::moving(float x,float y,float time){
    objgm_target::x+=x*objgm_target::speed;
    objgm_target::y+=y*objgm_target::speed;
}
void objgm_target::update(float time)
{
    if(!objgm_target::del)
    {
        objgm_target::rect=*objgm_target::animrect;
        objgm_target::moving(objgm_target::dirx,objgm_target::diry,time);
    }
}
void objgm_target::draw(RenderWindow* window)
{
    if(!objgm_target::del){
        objgm_target::rect.setPosition(Vector2f(objgm_target::x,objgm_target::y));
        objgm_target::rect.setSize(Vector2f(objgm_target::w,objgm_target::h));
        window->draw(objgm_target::rect);
    }
}
RectangleShape* objgm_target::getRect()
{
    return &(objgm_target::rect);
}
// ### setters ###

void objgm_target::setSize(int w,int h){
    objgm_target::w=w;
    objgm_target::h=h;
}
void objgm_target::setPosition(int x,int y){
    objgm_target::x=x;
    objgm_target::y=y;
}
void objgm_target::setSpeed(float speed){
    objgm_target::speed=speed;
}
void objgm_target::setId(int id){
    objgm_target::id=id;
}
void objgm_target::setDirection(float x,float y){
    objgm_target::dirx=x;
    objgm_target::diry=y;
}
void objgm_target::setDel(bool del){
    objgm_target::del=del;
}

// ### getters ###

int objgm_target::getX(){
    return objgm_target::x;
}
int objgm_target::getY(){
    return objgm_target::y;
}
int objgm_target::getW(){
    return objgm_target::w;
}
int objgm_target::getH(){
    return objgm_target::h;
}
int objgm_target::getId(){
    return objgm_target::id;
}
bool objgm_target::getDel(){
    return objgm_target::del;
}
