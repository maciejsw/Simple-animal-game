#include "Sheep.h"

Sheep::Sheep() : Animal() {}

Sheep::Sheep(int x, int y, World* world)
	: Animal("Sheep",'S',x,y,4,4,world){}

