#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Organism.h"
#include "Generator.h"
#include <conio.h>

int main() {
	srand(time(NULL));

	unsigned int command = 0;
	int x, y;
	World* world = nullptr;
	Generator* generator = nullptr;
	cout << "Welcome!" << endl << endl;
	cout << "Author: Maciej Swietlik 184809" << endl << endl;
	cout << "Press N to start new game" << endl;
	cout << "Press L to load the save" << endl;
	while (command != 'n' && command != 'l') {
		command = _getch();
		system("cls");
		switch (command) {
		case 'n':
			cout << "Choose the size of the world" << endl;
			cin >> x >> y;
			world = new World(x, y);
			generator = new Generator(&world);
			generator->Generate();
			break;
		case 'l':
			world = new World();
			generator = new Generator(&world);
			generator->LoadGame();
			break;
		default:
			cout << "Wrong key" << endl;
			break;
		}
	}
	system("cls");
	cout << "Author: Maciej Swietlik" << endl << endl;
	cout << "## HOW TO PLAY ##" << endl;
	cout << "Press N to begin new game" << endl;
	cout << "Press S to save" << endl;
	cout << "Press ENTER to start new turn" << endl;
	cout << "Move with ARROWS" << endl;
	cout << "Press R to activate special ability" << endl << endl;
	cout << "Press ENTER to proceed" << endl;

	while (command != 13) {
		command = _getch();
		if (command != 13) cout << "Wrong key" << endl;
	}

	system("cls");
	world->DrawWorld();

	while (true) {
		command = _getch();
		switch (command) {
		case 13:
			world->MakeTurn();
			system("cls");
			world->DrawWorld();
			break;
		case 'n':
			system("cls");
			cout << "Choose size of the world" << endl;
			cin >> x >> y;
			system("cls");
			world = new World(x, y);
			generator = new Generator(&world);
			generator->Generate();
			world->DrawWorld();
			
			break;
		case 's':
			generator->Save();
			cout << "Saved sucesfully!" << endl;
			break;
		default:
			cout << "Wrong key" << endl;
			break;
		}
	}
	return 0;
}