#pragma once
#include "World.h"
using namespace std;

class Generator {
private:
	World** world;
public:
	Generator(World** world);
	void Generate();
	pair<int, int> FindPlace();
	void Save();
	void LoadGame();
	void LoadOrganism(char name, int x, int y, int strength, int age, int cooldown);
};