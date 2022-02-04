#pragma once
#include "Animal.h"
using namespace std;

class Wolf : public Animal {

public:
	Wolf();
	Wolf(int x, int y, World* world);
};