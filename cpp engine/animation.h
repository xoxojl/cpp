#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

using namespace std;
using namespace sf;

struct AnimationStruct
{
    int x,y;
    int w,h;
    float frame;
    float speed;
    float maxframe;
    int id;
    string name;
    AnimationStruct(int x,int y,int w,int h,float speed,float maxframe,int id,string name);
};
class obj_animpos
{
public:
    float x,y;
    int w,h;
    float speed;
    int id;
    string name;
    bool del;
    obj_animpos(int x,int y,int w,int h,int id);
};
class Animation
{
private:
    int x,y;
    unsigned int w;
    unsigned int h;

    string name;
    unsigned int id;

    unsigned int rectx;
    unsigned int recty;
    unsigned int rectw;
    unsigned int recth;

    Texture texturesheet;
    RectangleShape rect;
    float frame;
    float maxframe;
    float animspeed;

    bool visible;
    bool stopwhenend;
    bool loop;
    bool play;
public:
    Animation(int x,int y,int w,int h,int id,string name,Texture* texture);
    void setAnimationOptions(int rectw,int recth,float speed,float maxframe);
    void update(float time);
    void draw(RenderWindow* window);

    void startAnim();
    void playAnim();
    void stopAnim();
    void playFrame(float frame);
    void stopFrame(float frame);

    void setFrame(float frame);

    void setVisible(bool state);
    void stopWhenEnd(bool state);
    void setLoop(bool state);
    void setPosition(int x,int y);

    int getX();
    int getY();
    int getW();
    int getH();
    float getFrame();
    RectangleShape* getRect();
};
#endif // ANIMATION_H_INCLUDED
