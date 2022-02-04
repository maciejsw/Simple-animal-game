#include <string>
#include <algorithm>
#include "World.h"
#include "Organism.h"

using namespace std;

World::World(int width, int height) : width(width), height(height) {
	population = 0;
	turn = 0;
	organisms = new Organism * [width * height];
	board = new Organism ** [height];
	for (int i = 0; i < height; i++) board[i] = new Organism * [width];
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			board[i][j] = nullptr;
		}
	}
	comments = new string[width * height];
	count_comments = 0;
}

Organism* World::GetField(int x, int y) const {
	return board[y][x];
}

void World::PlaceOrganism(int x, int y, Organism* organism)
{
	board[y][x] = organism;
}

void World::AddOrganism(Organism* organism) {
	if ((population < height * width) && (board[organism->GetY()][organism->GetX()]==nullptr)) {
		organisms[population++] = organism;
		sort(organisms, organisms + population, CompareInitiative);
		organism->Draw();
	}
	else delete organism;
}

void World::RemoveOrganism(Organism* organism) {
	Organism* villain = board[organism->GetY()][organism->GetX()];
	if(villain == organism) board[organism->GetY()][organism->GetX()] = nullptr;
	for (int i = 0; i < population; i++) {
		if (organisms[i] == organism) {
			organisms[i] = nullptr;
			for (int j = i + 1; j < population; j++) organisms[j - 1] = organisms[j];
			population--;
			break;
		}
	}
	delete organism;
}

void World::MakeTurn() {
	Organism* villain;
	for (int i = 0; i < population; i++) {
		organisms[i]->Action();
		organisms[i]->MakeOlder();
		villain = board[organisms[i]->GetY()][organisms[i]->GetX()];
		if (villain == nullptr) organisms[i]->Draw();
		else if(villain!=organisms[i]) villain->Collision(organisms[i]);
	}
	turn++;
}

void World::DrawWorld() {
	
	for (int i = 0; i < population; i++) organisms[i]->Draw();
	cout << "Author: Maciej Swietlik 184809" << endl << endl;
	cout << endl << "Turn: " << turn << endl << endl;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			if (GetField(j, i) == nullptr) cout << " ";
			else {
				cout << GetField(j, i)->GetName();
			}
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < count_comments; i++) {
		cout << comments[i] << endl;
	}
	count_comments = 0;
}

void World::AddComment(string comment) {
	comments[count_comments++] = comment;
}

int World::GetHeight()
{
	return height;
}

int World::GetWidth()
{
	return width;
}

int World::GetPopulation()
{
	return this->population;
}

int World::GetTurn()
{
	return this->turn;
}

void World::SetHeight(int value)
{
	this->height = value;
}

void World::SetWidth(int value)
{
	this->width = value;
}

void World::SetPopulation(int value)
{
	this->population = value;
}

void World::SetTurn(int value)
{
	this->turn = value;
}

Organism* World::GetOrganism(int i)
{
	return organisms[i];
}

World::~World() {
	delete[] organisms;
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			delete board[i][j];
		}
	}
	delete[] comments;
}