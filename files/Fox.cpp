#include "Fox.h"

Fox::Fox() : Animal() {}

Fox::Fox(int x, int y, World* world)
	: Animal("Fox",'F', x, y, 3, 7, world) {
}

void Fox::Move(int distance) {
	world->PlaceOrganism(place.first, place.second, nullptr);
	int pointsX[4];
	int pointsY[4];
	int count = 0;
	Organism* enemies[4];
	if ((place.second - distance >= 0) && (world->GetField(place.first, place.second - distance)
		== nullptr || (world->GetField(place.first, place.second - distance)->GetStrength()
			<= this->GetStrength()))) {
		pointsX[count] = place.first;
		pointsY[count] = place.second - distance;
		count++;
	}
	if ((place.first - distance >= 0) && (world->GetField(place.first - distance, place.second)
		== nullptr || (world->GetField(place.first - distance, place.second)->GetStrength()
			<= this->GetStrength()))) {
		pointsX[count] = place.first - distance;
		pointsY[count] = place.second;
		count++;
	}
	if ((place.first + distance < world->GetWidth()) && (world->GetField(place.first + distance, place.second)
		== nullptr || (world->GetField(place.first + distance, place.second)->GetStrength()
			<= this->GetStrength()))) {
		pointsX[count] = place.first + distance;
		pointsY[count] = place.second;
		count++;
	}
	if ((place.second + distance < world->GetHeight()) && (world->GetField(place.first, place.second + distance)
		== nullptr || (world->GetField(place.first, place.second + distance)->GetStrength()
			<= this->GetStrength()))) {
		pointsX[count] = place.first;
		pointsY[count] = place.second + distance;
		count++;
	}

	if (count) {
		int random = rand() % count;
		if ((world->GetField(pointsX[random], pointsY[random]) == nullptr) ||
			((world->GetField(pointsX[random], pointsY[random]))->GetName() != 't') ||
			(typeid(*this) != typeid(world->GetField(pointsX[random], pointsY[random])))){
			place.first = pointsX[random];
			place.second = pointsY[random];
		}
	
	}
}
