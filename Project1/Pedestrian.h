#pragma once
#include "Roaduser.h"
#include <SFML/Graphics.hpp>
using namespace sf;

class Pedestrian : public Roaduser
{
	private:

	public:
		Pedestrian();
		void update() override;
};

