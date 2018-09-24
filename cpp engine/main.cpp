#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <ostream>
#include <sstream>

#include "texturetools.h"
#include "animation.h"
#include "engineobjects.h"
#include "timetools.h"
#include "enginecontrol.h"
#include "gameplayengine.h"

using namespace std;
using namespace sf;

int getrandint(int min, int max){
    return rand()%max + 1 + min;
}

template<typename T>
string toString(T temp)
{
    stringstream buff (stringstream::in | stringstream::out);
    buff<<temp;
    return buff.str();
}

int main()
{
    // ###############
    // - WINDOW INIT -
    // ###############
    int width=1080;
    int height=720;
    RenderWindow* window=new RenderWindow(VideoMode(width,height),"HardAward");
    window->setVerticalSyncEnabled(true);
    Color color_bg=Color(0,0,0);
    // ###############
    // - SYSTEM INIT -
    // ###############
    srand(time(NULL));
    Vector2i mpos;
    bool winfocus=true;
    float fps;
    string scene="game";

    // ################
    // - TEXTURE INIT -
    // ################
    Texturelist texturelist;
    texturelist.addTexture("data/textures/airstrike.png","airstrike_spritesheet");
    texturelist.addTexture("data/textures/explode.png","explode_spritesheet");
    texturelist.addTexture("data/textures/hitmaker.png","hitmaker_spr");

    // #############
    // - ANIM INIT -
    // #############
    Animation animtarget(100,100,13*3,32*3,0,"airstrike",texturelist.getTexture("airstrike_spritesheet"));
    animtarget.setAnimationOptions(13,32,0.005,4.0);
    animtarget.playAnim();

    Animation animexplode(10,125,160,166,0,"explode",texturelist.getTexture("explode_spritesheet"));
    animexplode.setAnimationOptions(166,157,0.01,24.0);
    animexplode.stopWhenEnd(false);

    // #############
    // - TEXT INIT -
    // #############
    Font font_demibold;
    font_demibold.loadFromFile("data/fonts/din2014-demibold.otf");

    Text text_fps;
    text_fps.setFont(font_demibold);
    text_fps.setCharacterSize(30*(-window->getSize().x+width+1));
    text_fps.setPosition(Vector2f(0,-10));

    Text text_score;
    text_score.setFont(font_demibold);
    text_score.setCharacterSize(80);
    text_score.setPosition(Vector2f(5,height-80-5));
    text_score.setColor(Color::Black);

    Text text_taaog;
    text_taaog.setFont(font_demibold);
    text_taaog.setCharacterSize(30*(-window->getSize().x+width+1));
    text_taaog.setString("By Ridgen");
    text_taaog.setColor(Color::Black);
    text_taaog.setPosition(Vector2f(width-4.5*(30*(-window->getSize().x+width+1)),-10));

    // #############
    // - TIME INIT -
    // #############
    TimerBase timerbase;

    Timer timer_getfps(500,"getfps",true);
    Timer timer_gameintro(50000000,"gameintro",false);
    timerbase.addTimer(&timer_getfps);
    timerbase.addTimer(&timer_gameintro);
    timer_getfps.play();
    timer_gameintro.play();

    // ################
    // - OBJECTS INIT -
    // ################
    ObjGUI objg_hitmaker(0,0,64,64,texturelist.getTexture("hitmaker_spr"));

    // ##############
    // - VALUE INIT -
    // ##############
    int gamescore=1;
    bool survivalmode=true;

    vector<AnimationStruct*> vector_animestrexplode;
    vector<obj_animpos*> vector_targets;
    vector<AnimationStruct*> vector_hitmakers;

    // ############
    // - MAINLOOP -
    // ############
    Clock clock;
    float time;

    bool run=true;
    while(run)
    {
        time=clock.getElapsedTime().asMicroseconds();
        if(timerbase.getTimerFromName("getfps")->resumeTime())
        fps=getFPS(&clock);
        time=time/800;
        clock.restart();

        Event event;
        if(window->pollEvent(event)){
            switch(event.type){
                case Event::Closed: run=false;
                case Event::MouseButtonPressed: winfocus=true;
                case Event::LostFocus: winfocus=false;
            }
        }
        ///### UPDATE PART ###
        mpos=convertMousePos(window,width,height);
        timerbase.update(time);
        window->clear(color_bg);

        if(timer_gameintro.getTime()<timer_gameintro.getEndtime()){
            int tempint=0;
            color_bg=Color(tempint,tempint,tempint);
        }
        else{
        color_bg=Color(255,255,255);
        text_fps.setString("FPS "+toString(int(fps)));
        text_score.setString("Score: "+toString(gamescore));
        animtarget.update(time);
        animexplode.update(time);
        animexplode.setVisible(false);
        objg_hitmaker.setVisible(false);
        for(vector<obj_animpos*>::iterator it=vector_targets.begin();it!=vector_targets.end();it++)
        {
            (*it)->y=(*it)->y+(*it)->speed;
            animtarget.setPosition((*it)->x,(*it)->y);
            window->draw(*animtarget.getRect());
            if((*it)->y>height){
                (*it)->x=getrandint(0,width-96);
                (*it)->y=getrandint(-192,-96);
                if(survivalmode){
                    cout<<"Game over! Your score: "<<gamescore<<"\n\n\n\n";
                    scene="gameover";
                    run=false;
                    break;
                }
            }
            if(collidePos(mpos.x,mpos.y,(*it)->x,(*it)->y,(*it)->w,(*it)->h)){
                gamescore+=1;
                (*it)->x=getrandint(0,width-96);
                (*it)->y=getrandint(-192,-96);
                if(!(*it)->del){
                    AnimationStruct animstruct_explode(mpos.x,mpos.y,160,166,0.005,24.0,vector_animestrexplode.size(),"explode");
                    animstruct_explode.frame=0;
                    vector_animestrexplode.push_back(&animstruct_explode);
                    AnimationStruct animstruct_hitmaker(mpos.x,mpos.y,64,64,0.007,1.5,vector_hitmakers.size(),"hitmaker");
                    animstruct_hitmaker.frame=0;
                    vector_hitmakers.push_back(&animstruct_hitmaker);
                }
            }
        }
        if(gamescore*0.2>vector_targets.size()){
            obj_animpos* target=new obj_animpos(getrandint(0,width-39),getrandint(-192,-96),39,96,0);
            target->speed=getrandint(1,2);
            vector_targets.push_back(target);
        }
        cout<<vector_animestrexplode.size()<<endl;
        for(vector<AnimationStruct*>::iterator it=vector_animestrexplode.begin();it!=vector_animestrexplode.end();it++)
        {
            animexplode.setVisible(true);
            (*it)->frame+=(*it)->speed*time;
            if((*it)->frame>(*it)->maxframe)
            {
                delete (*it);
                vector_animestrexplode.erase(it);
                break;
            }
            animexplode.setFrame((*it)->frame);
            animexplode.setPosition((*it)->x-(*it)->w/2,(*it)->y-(*it)->h/2);
            window->draw(*animexplode.getRect());
        }
        /// ### GUI ###
        for(vector<AnimationStruct*>::iterator it=vector_hitmakers.begin();it!=vector_hitmakers.end();it++)
        {
            objg_hitmaker.setVisible(true);
            (*it)->frame=(*it)->frame+(*it)->speed*time;
            if((*it)->frame>(*it)->maxframe)
            {
                delete (*it);
                vector_hitmakers.erase(it);
                break;
            }
            objg_hitmaker.setPosition((*it)->x-(*it)->w/2,(*it)->y-(*it)->h/2);
            window->draw(*objg_hitmaker.getRect());
        }
        if(int(fps)>=45)
            text_fps.setColor(Color(15,240,15));
        else if(int(fps)>=25)
            text_fps.setColor(Color(240,240,15));
        else
            text_fps.setColor(Color(240,15,15));
        window->draw(text_fps);
        window->draw(text_score);
        window->draw(text_taaog);
        }
        window->display();
    }
    window->close();
    delete window;

    return 0;
}
