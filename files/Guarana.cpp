#include "Guarana.h"
Guarana::Guarana() : Plant() {

}

Guarana::Guarana(int x, int y, World* world)
	: Plant("Guarana", 'y', x, y, 0, world)
{
}

void Guarana::Collision(Organism* enemy)
{
	enemy->BuffStrength(3);
	this->Fight(enemy);
}
