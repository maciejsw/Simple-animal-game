#pragma once
#include "Plant.h"

class SowThistle : public Plant {
public:
	SowThistle();
	SowThistle(int x, int y, World* world);
	void Action() override;
};