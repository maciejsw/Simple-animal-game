#pragma once
#include "Animal.h"

class Fox : public Animal {
public:
	Fox();
	Fox(int x, int y, World* world);
	void Move(int distance) override;
};