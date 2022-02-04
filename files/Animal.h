#pragma once
#include "World.h"
#include "Organism.h"

class Animal : public Organism{
public:
	Animal();
	Animal(string species, char name, int x, int y, int strength, int initiative, World* world);
	virtual void Action() override;
	virtual void Collision(Organism* enemy) override;
	virtual void Move(int distance);
	virtual void Fight(Organism* enemy);
	Organism* CreateChild(int x, int y, World* world);
	void Breed();
	void Flee(int distance) override;
};