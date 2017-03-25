#include "Player.h"


Player::Player(sf::Vector2f startPosition, DIRECTION direction, sf::Color color, GTexture *texture) 
: circle(RADIUS), dist(1, 100), timePassed(minGap,maxGap){
	
	rng.seed(std::random_device()());

	speed = 0.1f;

	circle.setFillColor(color);	
	this->color = color;
	circle.setOrigin(RADIUS, RADIUS);
	this->position = circle.getOrigin();
	transform.rotate(direction, startPosition); // pocz¹tkowy kierunek
	circle.move(startPosition); //pocz¹tkowe po³o¿enie
	
	isPressed = false;

	beginTime = 0;
	isGap = false;
	setRect(color, sf::Vector2f(RADIUS*2, RADIUS*2), startPosition);
	
}

void Player::setRect(sf::Color color, sf::Vector2f size, sf::Vector2f startPosition){

	rect.setOrigin(size.x, size.y / 2);
	rect.setFillColor(color);
	rect.setSize(size);
	rect.move(startPosition);
}


bool Player::move(GTexture *texture, int time){ 


	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		if (!isPressed){

			position.x = circle.getPosition().x + cos((45- circle.getRotation())*M_PI / 180);
			position.y = circle.getPosition().y + sin((45 - circle.getRotation())* M_PI / 180) +RADIUS_ROTATION;

			isPressed = true;
		}

		transform.rotate(speed*time*2, position);

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
		if (!isPressed){

			position.x = circle.getPosition().x + cos((45 - circle.getRotation())*M_PI / 180);
			position.y = circle.getPosition().y + sin((45 - circle.getRotation())*M_PI / 180) -RADIUS_ROTATION;

			isPressed = true;
		}

		transform.rotate(-speed*time*2, position);
	}
	else{
		float dX = cos(circle.getRotation()*M_PI / 180)*speed*time;
		float dY = sin(circle.getRotation()*M_PI / 180)*speed*time;

		transform.translate(dX, dY);
		isPressed = false;
	}

	
	
	int tempx = circle.getPosition().x + cos(circle.getRotation()*M_PI / 180) *(RADIUS+1); 
	int tempy = circle.getPosition().y + sin(circle.getRotation()*M_PI / 180) *(RADIUS+1);

	sf::Vector2f col = transform.transformPoint(tempx, tempy);


	if (texture->checkCollision(col)) 
		return false;

	sf::Vector2f  point = transform.transformPoint(rect.getPosition());



	if (!createGap())
		texture->drawToTexture(&rect, &transform, RADIUS, point);


	return true;
}

bool Player::createGap(){
	

	if (!isGap){
		int num = dist(rng);
		if (num == 1){
			beginTime =
				std::chrono::duration_cast<std::chrono::milliseconds>
				(std::chrono::system_clock::now().time_since_epoch()).count();
			isGap = true;
		}
		
	}
	else{
		long long c =
			std::chrono::duration_cast<std::chrono::milliseconds>
			(std::chrono::system_clock::now().time_since_epoch()).count();

		if ((c - beginTime) <= timePassed(rng)){

			return true;
		}
		else{
			isGap = false;
		}
	}

	return false;
}