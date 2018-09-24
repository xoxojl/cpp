#include <SFML/Graphics/Texture.hpp>
#include <iostream>

using namespace std;
using namespace sf;

Texture* loadImage(string path){
    Texture* texture;
    texture.loadFromFile(path);
    return texture;
}
