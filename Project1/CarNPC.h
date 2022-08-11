// Joy de Ruijter - 2022

#pragma once
#include "Roaduser.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class CarNPC : public Roaduser
{
	public:
		CarNPC(float _startX, float _startY, float _force);

		float direction;

		void hitEnd();
		void update(float _time);
		float setStartPosition();
		float setDirection();
};

