#include "Hogweed.h"

Hogweed::Hogweed() : Plant()
{
}

Hogweed::Hogweed(int x, int y, World* world)
	: Plant("Hogweed", 'h', x, y, 10, world)
{
}

void Hogweed::Action()
{
	int left = max(this->GetX()-1, 0);
	int right = min(this->GetX()+1, world->GetWidth()-1);
	int up = max(this->GetY()-1, 0);
	int down = min(this->GetY()+1, world->GetHeight()-1);
	Plant* plant;
	for (int i = left; i <= right; i++) {
		for (int j = up; j <= down; j++) {
			if (world->GetField(i, j) != nullptr && world->GetField(i, j) != this && !(plant = dynamic_cast<Plant*>(world->GetField(i, j)))) {
				world->AddComment(this->CommentKill(world->GetField(i, j)));
				world->RemoveOrganism(world->GetField(i, j));
			}
				
		}
	}
	int random = rand() % 10;
	if(!random) this->Sow();
}

void Hogweed::Collision(Organism* enemy)
{
	world->AddComment(enemy->CommentKill(this));
	world->AddComment(this->CommentDeath(enemy));
	world->RemoveOrganism(enemy);
	world->RemoveOrganism(this);
}
