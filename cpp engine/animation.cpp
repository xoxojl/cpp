#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <iostream>
#include "animation.h"

using namespace std;
using namespace sf;

Animation::Animation(int x,int y,int w,int h,int id,string name,Texture* texture)
{
    Animation::x=x;
    Animation::y=y;
    Animation::w=w;
    Animation::h=h;
    Animation::name=name;
    Animation::id=id;
    Animation::texturesheet=*texture;

    Animation::rect.setSize(Vector2f(w,h));
    Animation::rect.setPosition(Vector2f(x,y));
    Animation::rect.setTexture(texture);
    Animation::visible=true;
    Animation::stopwhenend=false;
    Animation::play=false;
}
void Animation::setAnimationOptions(int rectw,int recth,float speed,float maxframe)
{
    Animation::rectw=rectw;
    Animation::recth=recth;
    Animation::rect.setTextureRect(IntRect(0,0,Animation::rectw,Animation::recth));
    Animation::animspeed=speed;
    Animation::maxframe=maxframe;
}
void Animation::update(float time)
{
    if(Animation::play)
    {
        Animation::frame+=time*Animation::animspeed;
        if(Animation::maxframe<Animation::frame)
            Animation::frame=0;
            if(Animation::stopwhenend)
                Animation::play=false;
                Animation::visible=false;
    }
    Animation::rect.setTextureRect(IntRect( (int)Animation::frame*Animation::rectw,0,Animation::rectw,Animation::recth ));
}
void Animation::draw(RenderWindow* window){
    if(Animation::visible)
        window->draw(Animation::rect);
}
void Animation::playAnim(){
    Animation::play=true;
}
void Animation::stopAnim(){
    Animation::play=false;
}
void Animation::playFrame(float frame){
    Animation::frame=frame;
    Animation::play=true;
}
void Animation::stopFrame(float frame){
    Animation::frame=frame;
    Animation::play=false;
}

// ### setters ###
void Animation::setFrame(float frame){
    Animation::frame=frame;
}
void Animation::setVisible(bool state){
    Animation::visible=state;
}
void Animation::stopWhenEnd(bool state){
    Animation::stopwhenend=state;
}
void Animation::setLoop(bool state){
    Animation::loop=state;
}
void Animation::setPosition(int x,int y)
{
    Animation::x=x;
    Animation::y=y;
    Animation::rect.setPosition(Vector2f(x,y));
}
// ### getters ###
int Animation::getX(){
    return Animation::x;
}
int Animation::getY(){
    return Animation::y;
}
int Animation::getW(){
    return Animation::w;
}
int Animation::getH(){
    return Animation::h;
}
float Animation::getFrame(){
    return Animation::frame;
}
RectangleShape* Animation::getRect(){
    return &(Animation::rect);
}

AnimationStruct::AnimationStruct(int x,int y,int w,int h,float speed,float maxframe,int id,string name){
    AnimationStruct::x=x;
    AnimationStruct::y=y;
    AnimationStruct::w=w;
    AnimationStruct::h=h;
    AnimationStruct::id=id;
    AnimationStruct::name=name;
    AnimationStruct::speed=speed;
    AnimationStruct::maxframe=maxframe;
}
obj_animpos::obj_animpos(int x,int y,int w,int h,int id){
    obj_animpos::x=x;
    obj_animpos::y=y;
    obj_animpos::w=w;
    obj_animpos::h=h;
    obj_animpos::id=id;
    obj_animpos::name=name;
}
