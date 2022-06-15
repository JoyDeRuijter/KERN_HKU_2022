#pragma once
class Vector2D
{
	public:
		float x;
		float y;

		Vector2D(float _x, float _y);

		Vector2D add(Vector2D _otherVector2);
		Vector2D subtract(Vector2D _otherVector2);
		float distance(Vector2D _otherVector2);
		float magnitude();
};

