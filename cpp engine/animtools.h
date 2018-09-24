#ifndef ANIMTOOLS_H_INCLUDED
#define ANIMTOOLS_H_INCLUDED

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Animation
{
private:
    float maxframe;
    float frame;
    float speed;

    string animname;
    Texture* spritesheet;
    unsigned int framew;
    unsigned int frameh;

    int x,y;
    unsigned int w;
    unsigned int h;

    bool run;
public:
    Sprite* spriteframe;
    Animation(Texture* spritesheet,int framew,int frameh,float maxframe,float speed);
    void setSpriteOptions(int x,int y,int w,int h);
    void update(float time);
    Sprite getFrameSprite();
    IntRect getRect();
    void init();
    void stop();
    void play();
};

#endif // ANIMTOOLS_H_INCLUDED
