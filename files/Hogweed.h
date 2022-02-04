#pragma once
#include "Plant.h"

class Hogweed : public Plant {
public:
	Hogweed();
	Hogweed(int x, int y, World* world);
	void Action() override;
	void Collision(Organism* enemy) override;
};