#pragma once
#include <iostream>
#include <string>

using namespace std;

#define HEIGHT 10
#define WIDTH 10

class Organism;

class World {
private:
	Organism** organisms;
	int population;
	Organism*** board;
	int width;
	int height;
	int turn;
	string* comments;
	int count_comments;
public:
	World(int width = WIDTH, int height = HEIGHT);

	void AddOrganism(Organism* organism);
	void RemoveOrganism(Organism* organism);
	void MakeTurn();
	void DrawWorld();
	void AddComment(string comment);
	int GetHeight();
	int GetWidth();
	int GetPopulation();
	int GetTurn();
	void SetHeight(int value);
	void SetWidth(int value);
	void SetPopulation(int value);
	void SetTurn(int value);
	Organism* GetOrganism(int i);
	Organism* GetField(int x, int y) const;
	void PlaceOrganism(int x, int y, Organism* organism);



	~World();
};