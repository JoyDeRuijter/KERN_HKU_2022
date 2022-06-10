#pragma once
#include "Car.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class CarNPC : public Car
{
	public:
		CarNPC();
		float getStartLane();
		void update() override;
};

