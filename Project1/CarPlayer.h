#pragma once
#include "Car.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class CarPlayer : public Car
{
	public:
		CarPlayer();
		float getLanePosition();
		void moveLeft();
		void moveRight();
};

