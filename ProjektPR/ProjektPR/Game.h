#ifndef _GAME_H_
#define _GAME_H_

#include <SFML/Graphics.hpp>
#include "Player.h"
#include "GTexture.h"

class Game{

private:
	static const int WIDTH = 800;
	static const int HEIGHT = 500;
	sf::RenderWindow window;
	sf::Clock clock;
	GTexture *texture;
	Player *player;

	void update();
	void render();
	void init();
	void events();

public:
	Game();
	void run();
	~Game();
};


#endif