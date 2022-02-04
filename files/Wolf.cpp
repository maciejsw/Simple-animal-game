#include "Wolf.h"

Wolf::Wolf() : Animal() {
}

Wolf::Wolf(int x, int y, World* world)
	: Animal("Wolf", 'W',x,y,9,5,world){
}



