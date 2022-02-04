#pragma once
#include "Plant.h"

class Guarana : public Plant {
public:
	Guarana();
	Guarana(int x, int y, World* world);
	void Collision(Organism* enemy) override;
};