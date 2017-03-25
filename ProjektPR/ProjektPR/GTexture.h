#ifndef _GTEXTURE_H_
#define _GTEXTURE_H_

#include <SFML/Graphics.hpp>
#include <iostream>

#define M_PI 3.14159265358979323846

class GTexture{

private:
	sf::RenderTexture texture;
	sf::Sprite sprite;
	sf::Uint8** pixels;
	int width;
	int height;
	
	
public:
	GTexture(int width, int height);
	void drawToTexture(sf::RectangleShape *rect, sf::Transform *t, int size, sf::Vector2f point);
	sf::Sprite *getSprite(){ return &sprite; }
	bool checkCollision(sf::Vector2f position);
	void setPixels(int radius, sf::Vector2f origin);

};


#endif