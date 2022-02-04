#pragma once
#include "Animal.h"

class Human : public Animal {
private:
	char direction = 0;
	bool active = false;
public:
	Human();
	Human(int x, int y, World* world);
	void Move(int distance) override;
	void Action() override;
	void GetDirection(char order);
	bool GetActive();
	void SetActive(bool value);
	void Collision(Organism* enemy) override;
	string Write() override;
};