#include "Belladonna.h"

Belladonna::Belladonna() : Plant()
{
}

Belladonna::Belladonna(int x, int y, World* world)
	: Plant("Belladonna", 'b', x, y, 99, world)
{
}

void Belladonna::Collision(Organism* enemy)
{
	world->AddComment(enemy->CommentDeath(this));
	world->AddComment(this->CommentDeath(enemy));
	world->RemoveOrganism(enemy);
	world->RemoveOrganism(this);
}

