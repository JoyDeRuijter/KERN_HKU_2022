#pragma once
#include "Roaduser.h"
#include <SFML/Graphics.hpp>

using namespace sf;

class Car : public Roaduser
{
	protected:
		int startLane = 0;
		int currentLane = 0;
		std::vector<float> lanePositions;

	public:
		Car();
		void initializeLanePositions();
};

