#include "Organism.h"
using namespace std;

Organism::Organism() {
	name = ' ';
	place.first = 0;
	place.second = 0;
	strength = 0;
	initiative = 0;
	age = 0;
	cooldown = 0;
	world = nullptr;
}

Organism::Organism(string species, char name, int x, int y, int strength, int initiative, World* world)
	: species{species}, name{ name }, place{ make_pair(x,y) }, strength{ strength }, initiative{ initiative }, age{ 0 }, world{ world }{}

void Organism::Draw() {
	world->PlaceOrganism(place.first, place.second, this);
};

int Organism::GetX() {
	return place.first;
}

int Organism::GetY() {
	return place.second;
}

const int Organism::GetAge() const
{
	return age;
}

const int Organism::GetCooldown() const
{
	return cooldown;
}

const int Organism::GetInitiative() const {
	return initiative;
}

const int Organism::GetStrength() const
{
	return strength;
}

void Organism::SetStrength(int value)
{
	this->strength = value;
}

void Organism::SetAge(int value)
{
	this->age = value;
}

void Organism::SetCooldown(int value)
{
	this->cooldown = value;
}

void Organism::MakeOlder()
{
	this->age++;
	this->cooldown++;
}

bool CompareInitiative(const Organism* first, const Organism* second) {
	if (first->GetInitiative() > second->GetInitiative()) return true;
	else if (first->GetInitiative() < second->GetInitiative()) return false;
	else return first->GetAge() > second->GetAge();
}

char Organism::GetName() {
	return name;
}

string Organism::GetSpecies()
{
	return species;
}

void Organism::BuffStrength(int value) {
	this->strength += value;
}

string Organism::CommentDeath(Organism* enemy)
{
	return this->GetSpecies() + " tried to attack " + enemy->GetSpecies() + " and died!";
}

string Organism::CommentKill(Organism* enemy)
{
	return this->GetSpecies() + " attacked " + enemy->GetSpecies() + " and killed it!";
}

string Organism::CommentChild() {
	return "There's a new " + this->GetSpecies() + " in our world!";
}

string Organism::Write() {
	return to_string(this->GetName()) + " " + to_string(this->GetX()) + " " + to_string(this->GetY()) +
		" " + to_string(this->GetStrength()) + " " + to_string(this->GetAge()) + " "
		+ to_string(this->GetCooldown());
}

