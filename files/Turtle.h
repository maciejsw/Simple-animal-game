#pragma once
#include "Animal.h"

class Turtle : public Animal {
public:
	Turtle();
	Turtle(int x, int y, World* world);
	void Action() override;
};