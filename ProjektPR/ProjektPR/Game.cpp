#include "Game.h"

Game::Game() : window(sf::VideoMode(WIDTH, HEIGHT), "Game"){

	init();
}

void Game::init(){
	window.setFramerateLimit(60);
	texture = new GTexture(WIDTH, HEIGHT);
	player = new Player(sf::Vector2f(WIDTH / 4, HEIGHT / 2), DIRECTION::RIGHT, sf::Color::Blue, texture);

}

void Game::run(){

	while (window.isOpen()){

		events();
		update();
		render();

	}
}

void Game::events(){

	sf::Event event;
	while (window.pollEvent(event)){

		if (event.type == sf::Event::Closed)
			window.close();
		
	}
}

void Game::update(){

	sf::Time time = clock.getElapsedTime();
	if (!player->move(texture, time.asMilliseconds()))
		window.close();

	clock.restart().asMilliseconds();
}

void Game::render(){

	window.clear();

	window.draw(*texture->getSprite());
	window.draw(*player->getCircle(), *player->getTransform());
	
	window.display();
}

Game::~Game(){
	delete texture;
	delete player;
}
