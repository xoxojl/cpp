#ifndef TEXTURETOOLS_H_INCLUDED
#define TEXTURETOOLS_H_INCLUDED
#include <SFML/Graphics/Image.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <vector>

using namespace std;
using namespace sf;

Texture* loadTexture(string path);

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

#endif // LOADIMAGE_H_INCLUDED
