#include "Plant.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"

Plant::Plant() : Organism()
{
}

Plant::Plant(string species, char name, int x, int y, int strength, World* world)
	: Organism(species, name, x, y, strength, 0, world) {
}

void Plant::Action()
{
	int random = rand() % 10;
	if(!random) this->Sow();	
}

void Plant::Sow()
{
	
	if (((this->age) > 2)) {
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
		}
	}
}

void Plant::Collision(Organism* enemy)
{
	this->Fight(enemy);
}

void Plant::Fight(Organism* enemy) {
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

Organism* Plant::CreateChild(int x, int y, World* world)
{
	if (typeid(*this) == typeid(Grass)) return new Grass(x, y, world);
	else if (typeid(*this) == typeid(SowThistle)) return new SowThistle(x, y, world);
	else if (typeid(*this) == typeid(Guarana)) return new Guarana(x, y, world);
	else if (typeid(*this) == typeid(Belladonna)) return new Belladonna(x, y, world);
	else if (typeid(*this) == typeid(Hogweed)) return new Hogweed(x, y, world);
}
