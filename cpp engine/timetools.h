#ifndef TIMETOOLS_H_INCLUDED
#define TIMETOOLS_H_INCLUDED

#include <SFML/System/Clock.hpp>
#include <iostream>

using namespace std;
using namespace sf;

float getFPS(Clock* clock);

class Timer
{
private:
    float time;
    float endtime;
    bool loop;
    bool playtimer;
    bool check;

    string name;
    unsigned int id;
public:
    Timer(float endtime,string name,bool loop);
    void update(float time);
    void play();
    void stop();
    void reset();
    bool resumeTime();

    void setTime(float time);
    void setEndtime(float time);
    void setId(int id);

    float getTime();
    float getEndtime();
    string getName();
    int getId();
    bool isPlay();
};

class TimerBase
{
private:
    vector<Timer*> timerlist;
public:
    void addTimer(Timer* timer);
    int createTimer(float endtime,string name,bool loop);
    void update(float time);
    Timer* getTimerFromName(string name);
    Timer* getTimerFromId(int id);

};
#endif // TIMETOOLS_H_INCLUDED
