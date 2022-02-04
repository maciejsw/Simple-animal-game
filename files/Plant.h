#pragma once
#include "Organism.h"
#include "World.h"

class Plant : public Organism {
public:
	Plant();
	Plant(string species, char name, int x, int y, int strength, World* world);
	void Action() override;
	virtual void Collision(Organism* enemy) override;
	void Fight(Organism* enemy);
	Organism* CreateChild(int x, int y, World* world);
	void Flee(int distance) override {};
	void Sow();
};