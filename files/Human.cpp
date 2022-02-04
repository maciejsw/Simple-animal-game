#include "Human.h"
#include <conio.h>

#define UP_KEY 72
#define RIGHT_KEY 77
#define DOWN_KEY 80
#define LEFT_KEY 75
#define UP 1
#define RIGHT 2
#define DOWN 3
#define LEFT 4
#define SPECIAL 224

Human::Human() : Animal()
{
}

Human::Human(int x, int y, World* world)
	: Animal("Human", 'H', x, y, 5, 4, world)
{
	this->cooldown = 99;
}

void Human::Move(int distance)
{
	world->PlaceOrganism(place.first, place.second, nullptr);
	if ((direction == UP) && (this->GetY() - distance > 0)) place.second--;
	if ((direction == LEFT) && (this->GetX() - distance  > 0)) place.first--;
	if ((direction == DOWN) && (this->GetY() + distance < world->GetHeight())) place.second++;
	if ((direction == RIGHT) && (this->GetX() + distance < world->GetWidth())) place.first++;
}

void Human::GetDirection(char order)
{
	if (order == UP_KEY) direction = UP;
	else if (order == RIGHT_KEY) direction = RIGHT;
	else if (order == DOWN_KEY) direction = DOWN;
	else if (order == LEFT_KEY) direction = LEFT;
	else world->AddComment("Wrong key, doing nothing!");
}

bool Human::GetActive()
{
	return this->active;
}

void Human::SetActive(bool value)
{
	this->active = value;
}

void Human::Collision(Organism* enemy)
{
	if (this->active) {
		enemy->Flee(1);
		world->AddComment(enemy->GetSpecies() + " got repelled from human!");
	}
	else this->Fight(enemy);
}

string Human::Write()
{
	return Organism::Write() + " " + to_string(this->GetActive());
}

void Human::Action() {
	if (this->cooldown == 5) {
		world->AddComment("Alzur's shield deactivated!");
		this->active = false;
	}
	int command = _getch();
	if (command == SPECIAL) {
		command = _getch();
		this->GetDirection(command);
		this->Move(1);
	}
	else if (command == 'r' && this->cooldown > 10) {
		this->cooldown = 0;
		this->active = true;
		world->AddComment("Alzur's shield activated!");
	}
	else {
		world->AddComment("Human decided not to move!");
	}
	
}

