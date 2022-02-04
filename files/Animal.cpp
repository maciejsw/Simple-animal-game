#include "Animal.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
using namespace std;

Animal::Animal() : Organism() {
}

Animal::Animal(string species, char name, int x, int y, int strength, int initiative,  World* world)
	: Organism(species, name, x, y, strength, initiative,world)
{
}

void Animal::Action() {
	this->Move(1);
}

void Animal::Move(int distance) {
	world->PlaceOrganism(place.first, place.second, nullptr);
	int pointsX[4];
	int pointsY[4];
	int count = 0;

	if (place.second - distance >= 0) {
		pointsX[count] = place.first;
		pointsY[count] = place.second - distance;
		count++;
	}
	if (place.first - distance >= 0) {
		pointsX[count] = place.first - distance;
		pointsY[count] = place.second;
		count++;
	}
	if (place.first + distance < world->GetWidth()) {
		pointsX[count] = place.first + distance;
		pointsY[count] = place.second;
		count++;
	}
	if (place.second + distance < world->GetHeight()) {
		pointsX[count] = place.first;
		pointsY[count] = place.second + distance;
		count++;
	}

	if (count) {
		int random = rand() % count;
		if ((world->GetField(pointsX[random], pointsY[random]) == nullptr) ||
			((world->GetField(pointsX[random], pointsY[random]))->GetName() != 't') || 
			((this->GetStrength()) >= 5) ||
			(typeid(*this) != typeid(world->GetField(pointsX[random], pointsY[random])))) {
			place.first = pointsX[random];
			place.second = pointsY[random];
		}	
	}
}

void Animal::Collision(Organism* enemy) {
	if (typeid(*this) == typeid(*enemy)) {
		if (enemy->GetCooldown() > 1) this->Breed();
			
	}
	else this->Fight(enemy);
}

void Animal::Fight(Organism* enemy) {
	if (this->GetStrength() > enemy->GetStrength()) {
		world->AddComment(enemy->CommentDeath(this));
		world->RemoveOrganism(enemy);	
	}
	else {
		world->AddComment(enemy->CommentKill(this));
		world->PlaceOrganism(this->GetX(), this->GetY(), enemy);
		world->RemoveOrganism(this);
		enemy->Draw();
	}
}

Organism* Animal::CreateChild(int x, int y, World* world)
{
	if (typeid(*this) == typeid(Wolf)) return new Wolf(x, y, world);
	else if (typeid(*this) == typeid(Sheep)) return new Sheep(x, y, world);
	else if (typeid(*this) == typeid(Fox)) return new Fox(x, y, world);
	else if (typeid(*this) == typeid(Turtle)) return new Turtle(x, y, world);
	else if (typeid(*this) == typeid(Antelope)) return new Antelope(x, y, world);
}

void Animal::Breed() {
	if (((this->age) > 3)) {
		int pointsX[4];
		int pointsY[4];
		int count = 0;
		if ((place.second - 1 >= 0) && (world->GetField(place.first, place.second - 1)
			== nullptr)) {
			pointsX[count] = place.first;
			pointsY[count] = place.second - 1;
			count++;
		}
		if ((place.first - 1 >= 0) && (world->GetField(place.first - 1, place.second)
			== nullptr)) {
			pointsX[count] = place.first - 1;
			pointsY[count] = place.second;
			count++;
		}
		if ((place.first + 1 < world->GetWidth()) && (world->GetField(place.first + 1, place.second)
			== nullptr)) {
			pointsX[count] = place.first + 1;
			pointsY[count] = place.second;
			count++;
		}
		if ((place.second + 1 < world->GetHeight()) && (world->GetField(place.first, place.second + 1) == nullptr)) {
			pointsX[count] = place.first;
			pointsY[count] = place.second + 1;
			count++;
		}
		if (count) {
			int random = rand() % count;
			world->AddOrganism(this->CreateChild(pointsX[random], pointsY[random], world));
			world->AddComment(this->CommentChild());
			this->cooldown = 0;
		}
	}
}

void Animal::Flee(int distance)
{
	world->PlaceOrganism(place.first, place.second, nullptr);
	int pointsX[4];
	int pointsY[4];
	int count = 0;
	if ((place.second - distance >= 0) && (world->GetField(place.first, place.second - distance)
		== nullptr)) {
		pointsX[count] = place.first;
		pointsY[count] = place.second - distance;
		count++;
	}
	if ((place.first - distance >= 0) && (world->GetField(place.first - distance, place.second)
		== nullptr)) {
		pointsX[count] = place.first - distance;
		pointsY[count] = place.second;
		count++;
	}
	if ((place.first + distance < world->GetWidth()) && (world->GetField(place.first + distance, place.second)
		== nullptr)) {
		pointsX[count] = place.first + distance;
		pointsY[count] = place.second;
		count++;
	}
	if ((place.second + distance < world->GetHeight()) && (world->GetField(place.first, place.second + distance)
		== nullptr)) {
		pointsX[count] = place.first;
		pointsY[count] = place.second + distance;
		count++;
	}

	if (count) {
		int random = rand() % count;
		place.first = pointsX[random];
		place.second = pointsY[random];
	}
}

