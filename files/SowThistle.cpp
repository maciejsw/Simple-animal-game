#include "SowThistle.h"

SowThistle::SowThistle() : Plant()
{
}

SowThistle::SowThistle(int x, int y, World* world)
	: Plant("Sow thistle", 's', x, y, 0, world)
{
}

void SowThistle::Action()
{
	int random;
	for (int i = 0; i < 3; i++) {
		random = rand() % 10;
		if (!random) {
			this->Sow();
			break;
		}
	}
}


