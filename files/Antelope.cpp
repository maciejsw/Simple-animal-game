#include "Antelope.h"

Antelope::Antelope() : Animal()
{
}

Antelope::Antelope(int x, int y, World* world)
	: Animal("Antelope", 'A', x, y, 4, 4, world)
{
}

void Antelope::Action()
{
	this->Move(2);
}

void Antelope::Collision(Organism* enemy)
{
	int random = rand() % 2;
	if (random) this->Fight(enemy);
	else this->Flee(1);
}



