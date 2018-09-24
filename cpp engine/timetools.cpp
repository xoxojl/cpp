#include <SFML/System/Clock.hpp>
#include <iostream>
#include <vector>
#include "timetools.h"

using namespace std;
using namespace sf;

float getFPS(Clock* clock)
{
    float time=clock->getElapsedTime().asSeconds();
    float fps=1.f/time;
    return fps;
}

Timer::Timer(float endtime,string name,bool loop)
{
    Timer::endtime=endtime;
    Timer::name=name;
    Timer::playtimer=false;
    Timer::loop=loop;
    Timer::check=false;
}
void Timer::update(float time)
{
    if(Timer::playtimer && Timer::check)
    {
        Timer::time+=time;
        if(Timer::time>Timer::endtime){
            Timer::time=0.f;
            Timer::check=false;
            if(!Timer::loop)
                Timer::playtimer=false;
        }
    }
}
void Timer::play(){
    Timer::playtimer=true;
}
void Timer::stop(){
    Timer::playtimer=false;
}
void Timer::reset(){
    Timer::time=0.f;
}
// ### setters ###
void Timer::setTime(float time){
    Timer::time=time;
}
void Timer::setEndtime(float time){
    Timer::endtime=time;
}
void Timer::setId(int id){
    Timer::id=id;
}
// ### getters ###
float Timer::getTime(){
    return Timer::time;
}
float Timer::getEndtime(){
    return Timer::endtime;
}
string Timer::getName(){
    return Timer::name;
}
int Timer::getId(){
    return Timer::id;
}
bool Timer::isPlay(){
    return Timer::playtimer;
}
bool Timer::resumeTime(){
    if(!Timer::check){
        Timer::check=true;
        return true;
    }
    return false;
}
// ###############
//  - TimerBase -
// ###############

void TimerBase::addTimer(Timer* timer)
{
    TimerBase::timerlist.push_back(timer);
    timer->setId(TimerBase::timerlist.size());
}
int TimerBase::createTimer(float endtime,string name,bool loop)
{
    Timer* timer=new Timer(endtime,name,loop);
    TimerBase::addTimer(timer);
    return timer->getId();
}
void TimerBase::update(float time)
{
    for(vector<Timer*>::iterator it=TimerBase::timerlist.begin();it!=TimerBase::timerlist.end();it++)
        (*it)->update(time);
}

Timer* TimerBase::getTimerFromName(string name)
{
    for(vector<Timer*>::iterator it=TimerBase::timerlist.begin();it!=TimerBase::timerlist.end();it++){
        if((**it).getName()==name)
            return *it;
    }
}
