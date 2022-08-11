// Joy de Ruijter - 2022

#pragma once
#include "Roaduser.h"
#include <SFML/Graphics.hpp>
#include "Rigidbody.h"
#include "Vector2D.h"
#include "Collider.h"

using namespace sf;
using namespace std;

class CarPlayer : public Roaduser
{
	private:
		RenderWindow renderWindow;

	public:
		CarPlayer(float _startX, float _startY, float _force);

		float playerSpeed;
		
		void moveLeft();
		void moveRight();
		void update(float _time);
};

