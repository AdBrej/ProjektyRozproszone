#ifndef _PLAYER_H_
#define _PLAYER_H_

#include <SFML/Graphics.hpp>
#include <random>
#include <math.h>
#include <iostream>
#include <chrono>
#include "GTexture.h"
#include "direction.h"


#define M_PI 3.14159265358979323846

class Player{

private:
	sf::CircleShape circle;
	sf::RectangleShape rect;
	sf::Color color;
	sf::Vector2f position;
	sf::Transform transform;
	static const int RADIUS = 4;
	static const int RADIUS_ROTATION = 30;
	static const int minGap = 150;
	static const int maxGap = 500;

	float speed;

	bool isPressed;
	long long beginTime;
	bool isGap;

	std::mt19937 rng;
	std::uniform_int_distribution<std::mt19937::result_type> dist;
	std::uniform_int_distribution<std::mt19937::result_type> timePassed;

	void setRect(sf::Color color, sf::Vector2f size, sf::Vector2f startPosition);
	bool createGap();

public:
	Player(sf::Vector2f startPosition, DIRECTION direction, sf::Color color, GTexture *texture);
	bool move(GTexture *texture, int time);
	sf::Transform *getTransform(){ return &transform; }
	sf::CircleShape *getCircle(){ return &circle; }
	sf::Color getColor() { return color; }
	int getRadius(){ return RADIUS; }
};


#endif