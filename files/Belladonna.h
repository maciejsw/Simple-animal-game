#pragma once
#include "Plant.h"

class Belladonna : public Plant {
public:
	Belladonna();
	Belladonna(int x, int y, World* world);
	void Collision(Organism* enemy) override;
};