#include "Car.h"
#include <iostream>

Car::Car() : Roaduser()
{
	currentLane = startLane;
	initializeLanePositions();
	rigidbody = Rigidbody(position, 1, 56, 100, 0.8f);
}

void Car::initializeLanePositions()
{
	float firstLanePosition = 176.8f;
	float secondLanePosition = 381.6f;
	float thirdLanePosition = 586.4f;
	float fourthLanePosition = 791.2f;

	lanePositions.push_back(firstLanePosition);
	lanePositions.push_back(secondLanePosition);
	lanePositions.push_back(thirdLanePosition);
	lanePositions.push_back(fourthLanePosition);
}