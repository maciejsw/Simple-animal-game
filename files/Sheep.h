#pragma once
#include "Animal.h"
using namespace std;

class Sheep : public Animal {
public:
	Sheep();
	Sheep(int x, int y, World* world);
};