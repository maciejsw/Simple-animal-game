#pragma once
#include "Plant.h"

class Grass : public Plant {
public:
	Grass();
	Grass(int x, int y, World* world);
};