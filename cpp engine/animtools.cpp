#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include "animtools.h"

using namespace std;
using namespace sf;

Animation::Animation(Texture *spritesheet,int framew,int frameh,float maxframe,float speed)
{
    Animation::spriteframe->setTexture(*spritesheet);
    Animation::framew=framew;
    Animation::frameh=frameh;
    Animation::maxframe=maxframe;
    Animation::speed=speed;

    Animation::frame=0.0;
    Animation::run=true;
}
void Animation::update(float time)
{
    Animation::frame+=time*Animation::speed;
    if(Animation::frame>Animation::maxframe)
        Animation::frame-=Animation::maxframe;
}
Sprite Animation::getFrameSprite()
{
    Animation::spriteframe->setTextureRect(IntRect(int(Animation::frame)*Animation::framew,0,Animation::framew,Animation::frameh));
    return *Animation::spriteframe;
}
void Animation::setSpriteOptions(int x,int y,int w,int h)
{
    Animation::x=x;
    Animation::y=y;
    Animation::w=w;
    Animation::h=h;
    Animation::spriteframe->setScale(Vector2f(Animation::w,Animation::h));
    Animation::spriteframe->setPosition(Vector2f(Animation::x,Animation::y));
    Animation::spriteframe->setTexture(*Animation::spritesheet);
}

