#include "Generator.h"
#include "Wolf.h"
#include "Sheep.h"
#include "Fox.h"
#include "Turtle.h"
#include "Antelope.h"
#include "Grass.h"
#include "SowThistle.h"
#include "Guarana.h"
#include "Belladonna.h"
#include "Hogweed.h"
#include "Human.h"
#include <fstream>;

#define SPECIES 10
#define FREE_SPACE 50

Generator::Generator(World** world) : world{world}{}

void Generator::Generate()
{
	int animalsCount = (((*world)->GetHeight()) * ((*world)->GetWidth())) / (SPECIES + FREE_SPACE);
	pair<int, int> place = this->FindPlace();
	(*world)->AddOrganism(new Human(place.first, place.second, (*world)));
	for (int i = 0; i < animalsCount; i++) {
		place = this->FindPlace();
		(*world)->AddOrganism(new Wolf(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Sheep(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Antelope(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Fox(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Turtle(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Grass(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new SowThistle(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Guarana(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Hogweed(place.first, place.second, (*world)));
		place = this->FindPlace();
		(*world)->AddOrganism(new Belladonna(place.first, place.second, (*world)));
	}
}

pair<int, int> Generator::FindPlace() {
	pair<int, int> place;
	place.first = rand() % (*world)->GetWidth();
	place.second = rand() % (*world)->GetHeight();
	while ((*world)->GetField(place.first, place.second) != nullptr) {
		place.first = rand() % (*world)->GetWidth();
		place.second = rand() % (*world)->GetHeight();
	}
	return place;
}

void Generator::Save()
{
	ofstream save("save.txt");
	save << (*world)->GetPopulation() << ' ' << (*world)->GetWidth() << ' ' << (*world)->GetHeight() << ' ' << (*world)->GetTurn() << endl;
	for (int i = 0; i < (*world)->GetPopulation(); i++) {
		save << (*world)->GetOrganism(i)->Write() << endl;
	}
	save.close();
}

void Generator::LoadGame()
{
	ifstream save("save.txt");
	if (save.good()) {
		int population, width, height, turn;
		save >> population >> width >> height >> turn;
		delete (*world);
		(*world) = new World(width, height);
		(*world)->SetTurn(turn);
		unsigned int name;
		int x, y, strength, age, cooldown;
		bool active = false;
		for (int i = 0; i < population; i++) {
			save >> name >> x >> y >> strength >> age >> cooldown;
			this->LoadOrganism(name, x, y, strength, age, cooldown);
			if (name == 'H') {
				save >> active;
			}
		}
		for (int i = 0; i < population; i++) {
				Human* human = dynamic_cast<Human*>((*world)->GetOrganism(i));
				if (human) {
					human->SetActive(active);
					break;
				}
		}
		save.close();
		cout << "Loaded the game sucesfully!" << endl;
	}
	else {
		cout << "No save file found" << endl;
	}
}

void Generator::LoadOrganism(char name, int x, int y, int strength, int age, int cooldown) {
	Organism* organism = nullptr;
	switch (name) {
	case 'W':
		organism = new Wolf(x, y, (*world));
		break;
	case 'S':
		organism = new Sheep(x, y, (*world));
		break;
	case 'F':
		organism = new Fox(x, y, (*world));
		break;
	case 'T':
		organism = new Turtle(x, y, (*world));
		break;
	case 'A':
		organism = new Antelope(x, y, (*world));
		break;
	case 'g':
		organism = new Grass(x, y, (*world));
		break;
	case 's':
		organism = new SowThistle(x, y, (*world));
		break;
	case 'h':
		organism = new Hogweed(x, y, (*world));
		break;
	case 'b':
		organism = new Belladonna(x, y, (*world));
		break;
	case 'y':
		organism = new Guarana(x, y, (*world));
		break;
	case 'H':
		organism = new Human(x, y, (*world));
		break;
	default:
		break;
	}

	if (organism != nullptr) {
		organism->SetStrength(strength);
		organism->SetAge(age);
		organism->SetCooldown(cooldown);
		(*world)->AddOrganism(organism);
	}
}
