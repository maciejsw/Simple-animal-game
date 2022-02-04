#pragma once
#include "Animal.h"

class Antelope : public Animal {
public:
	Antelope();
	Antelope(int x, int y, World* world);
	void Action() override;
	void Collision(Organism* enemy) override;
};