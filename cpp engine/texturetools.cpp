#include <SFML/Graphics/Texture.hpp>
#include <iostream>
#include <vector>

#include "texturetools.h"

using namespace std;
using namespace sf;

Texture* loadTexture(string path)
{
    Texture* texture=new Texture;
    texture->loadFromFile(path);
    return texture;
}

bool collidePos(int mx,int my,int x,int y,int w,int h){
    if(mx>=x && my>=y && x+w>=mx && y+h>=my)
        return true;
    return false;
}
bool collideRect(int x,int y,int w,int h,int x1,int y1,int w1,int h1){
    if(collidePos(x,y,x1,y1,w1,h1) || collidePos(x+w,y,x1,y1,w1,h1) || collidePos(x,y+h,x1,y1,w1,h1) || collidePos(x+w,y+h,x1,y1,w1,h1))
        return true;
    return false;
}

EngineTexture::EngineTexture(int id,string name,Texture* texture)
{
    EngineTexture::id=id;
    EngineTexture::name=name;
    EngineTexture::texture=texture;
}
Texturelist::Texturelist()
{
    Texturelist::listsize=0;
}
EngineTexture* Texturelist::addTexture(string path,string name)
{
    EngineTexture* enginetexture = new EngineTexture(Texturelist::listsize,name,loadTexture(path));
    Texturelist::texturelist.push_back(enginetexture);
    Texturelist::listsize+=1;
    return enginetexture;
}
Texture* Texturelist::getTexture(string name)
{
    for(vector<EngineTexture*>::iterator it=Texturelist::texturelist.begin();it!=Texturelist::texturelist.end();it++)
    {
        EngineTexture enginetexture = **it;
        if(enginetexture.name==name)
        {
            return enginetexture.texture;
        }
    }
}
