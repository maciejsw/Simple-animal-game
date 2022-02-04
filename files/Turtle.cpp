#include "Turtle.h"

Turtle::Turtle()
{
}

Turtle::Turtle(int x, int y, World* world)
	: Animal("Turtle", 'T', x, y, 2, 1, world){
}

void Turtle::Action() {
	int random = rand() % 4;
	if (!random) this->Move(1);
	else this->Move(0);
}
