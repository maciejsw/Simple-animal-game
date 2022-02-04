#include "Grass.h"

Grass::Grass() : Plant()
{
}

Grass::Grass(int x, int y, World* world)
	: Plant("Grass", 'g', x, y, 0, world)
{
}
