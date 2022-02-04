#pragma once
#include <utility>
#include "World.h"

using namespace std;

class Organism {
protected:
	string species;
	char name;
	pair<int, int> place;
	int strength;
	int initiative;
	int age;
	int cooldown;
	World* world;
public:
	Organism();
	Organism(string species, char name, int x, int y, int strength, int initiative, World* world);
	virtual void Action() = 0;
	virtual void Collision(Organism* enemy) = 0;
	virtual void Flee(int distance) = 0;
	void Draw();
	int GetX();
	int GetY();
	const int GetAge() const;
	const int GetCooldown() const;
	const int GetInitiative() const;
	const int GetStrength() const;
	void SetStrength(int value);
	void SetAge(int value);
	void SetCooldown(int value);
	void MakeOlder();
	char GetName();
	string GetSpecies();
	void BuffStrength(int value);
	virtual string CommentDeath(Organism* enemy);
	virtual string CommentKill(Organism* enemy);
	string CommentChild();
	virtual string Write();
};

bool CompareInitiative(const Organism* first, const Organism* second);