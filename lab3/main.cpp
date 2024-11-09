#include <iostream>
#include <string>
#include "functions.h"
#include <fstream>
#include <cctype>
#include <algorithm>

using namespace std;



int main() {
	
	
	int score[10] = { 8, 10, 8, 5, 7, 8, 9, 10, 6, 7 };
	int userinput, testNum, newScore;
	
	cout << "Menu:" << endl;
	cout << "1. Modify Score: " << endl;
	cout << "2. Show Final Score: " << endl;
	cout << "3. Show Average Score:" << endl;
	cout << "4. Show All Scores: " << endl;
	cout << "0. Exit" << endl;
	cin >> userinput;

	while (userinput != 0) {
		if (userinput == 1) {
			cout << " Enter a test number (1-10): ";
			cin >> testNum;
			cout << endl;
			cout << "Enter a new score: ";
			cin >> newScore;
			new_score(score, testNum - 1, newScore);
		}
		if (userinput == 2) {
			calculateFinalGrade(score, 10);
		}
		if (userinput == 3) {
			cout << "Average Score: ";
			averageScore(score, 10);
			cout << endl; 
		}
		if (userinput == 4) {
			showScores(score, 10);
		}
		cout << "Menu:" << endl;
		cout << "1. Modify Score: " << endl;
		cout << "2. Show Final Score: " << endl;
		cout << "3. Show Average Score:" << endl;
		cout << "4. Show All Scores: " << endl;
		cout << "0. Exit" << endl;
		cin >> userinput;
	}
	
	
	
	char grid[GRID_SIZE][GRID_SIZE];
	ifstream file("ingredient.txt");
	if (file.is_open()) {
		for (int i = 0; i < GRID_SIZE; i++) {
			for (int j = 0; j < GRID_SIZE; j++) {
				file >> grid[i][j];
			}
		}
		file.close();
	}
	else {
		cout << "Unable to open file." << endl;
		return 1;
	}
	string ingredients[] = { "GARLIC", "SPINACH", "TOMATO", "BREAD", "SUGAR", "PASTA", "ORANGE", "MILK" };
	int num_ingredients = static_cast<int>(sizeof(ingredients) / sizeof(ingredients[0]));

	int choice = -1;

	while (choice != 0) {
		cout << "\n Menu Option:\n";
		cout << "1) Print Board Game " << endl;
		cout << "2) Check brother ingredient" << endl;
		cout << "3) Find an ingredient" << endl;
		cout << "0) Exit" << endl;
		cin >> choice;

		if (choice == 1) {
			print_board(grid);
		}
		if (choice == 2) {
			for (int i = 0; i < num_ingredients; i++) {
				search_word(grid, ingredients[i]);
			}
		}
		if (choice == 3) {
			string search_ingredients;
			cout << "Enter the ingredient to search for: ";
			cin >> search_ingredients;
			transform(search_ingredients.begin(), search_ingredients.end(), search_ingredients.begin(), [](unsigned char c) { return toupper(c); });
			search_word(grid, search_ingredients);
		}
		if (choice == 0) {
			break;
		}
	}
	

	return 0;
}