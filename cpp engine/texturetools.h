#ifndef TEXTURETOOLS_H_INCLUDED
#define TEXTURETOOLS_H_INCLUDED

#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <iostream>
#include <vector>

using namespace std;
using namespace sf;

Texture* loadTexture(string path);

bool collidePos(int mx,int my,int x,int y,int w,int h);
bool collideRect(int x,int y,int w,int h,int x1,int y1,int w1,int h1);

template <typename tmpl_vector>
bool collideRectGroup(int x,int y,int w,int h,vector<tmpl_vector>);

class EngineTexture
{
public:
    int id;
    string name;
    Texture* texture;
    EngineTexture(int id,string name,Texture* texture);
};
class Texturelist
{
private:
    int listsize;
    vector<EngineTexture*> texturelist;
public:
    Texturelist();
    EngineTexture* addTexture(string path,string name);
    Texture* getTexture(string name);
};
#endif // TEXTURETOOLS_H_INCLUDED
