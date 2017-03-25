#include "GTexture.h"

GTexture::GTexture(int width, int height) {

	if (!texture.create(width, height, false)){
		std::cout << "Nie mozna stworzyc tekstury!";
		exit(1);
	}

	texture.setSmooth(true);
	sprite.setTexture(texture.getTexture());
	texture.clear();

	this->width = width;
	this->height = height;

	pixels = new sf::Uint8*[width];
	for (int i = 0; i < width; ++i)
		pixels[i] = new sf::Uint8[height];
	
}

void GTexture::drawToTexture(sf::RectangleShape *rect, sf::Transform *t, int size, sf::Vector2f point){

	setPixels(size, point);

	texture.draw(*rect, *t);
	texture.display();
}


bool GTexture::checkCollision(sf::Vector2f position){
	if (position.x >= width || position.y >= height || position.x <= 0 || position.y <= 0 
		|| pixels[(int)position.x][(int)position.y] == 1){
		
		std::cout << "KOLIZJA!" << std::endl;
		return true;

	}
	return false;
	
}

void GTexture::setPixels(int radius, sf::Vector2f origin){
	for (int y = -radius; y <= radius; y++){
		for (int x = -radius; x <= radius; x++){
			if (x*x + y*y <= radius*radius){
				int tempx = (int)origin.x + x;
				int tempy = (int)origin.y + y;
				if (tempx >=0 && tempx <width && tempy >=0 && tempy <height)
					pixels[tempx][tempy] = 1;				
			}
		}
	}

}

