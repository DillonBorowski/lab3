#include <string>
#include <iostream>

using namespace std;
#define GRID_SIZE 10


void new_score(int arr[], int index, int arr_len) {	//the index is amount of tests & arr_len is what the score can be between
	if (index >= 0 && index < 10 && arr_len >= 0 && arr_len <= 10) {
		arr[index] = arr_len;
		cout << "score updated." << endl;
	}
	else {
		cout << "Invalid input." << endl;
	}
}

void calculateFinalGrade(int arr[], int index) {
	int total = 0;
	for (int i = 0; i < index; i++) {
		total += arr[i];
	}


	if (total < 60){
		cout << "Grade is F" << endl;
	}
	else if (total <= 69) {
		cout << "Grade is D" << endl;
	}
	else if (total <= 84) {
		cout << "Grade is C" << endl;
	}
	else if (total <= 92) {
		cout << "Grade is B" << endl;
	}
	else if (total >= 93) {
		cout << "Grade is A" << endl;
	}
}

void averageScore(int arr[], int index) {
	int total = 0;
	for (int i = 0; i < index; i++) {
		total += arr[i];
	}
	float avg;
	avg = (float) total / index;

	cout << avg;
}
void showScores(int arr[], int index) {
	cout << "Scores: ";
	for (int i = 0; i < index; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void print_board(char grid[GRID_SIZE][GRID_SIZE]) {
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			cout << grid[i][j] << " ";
		}
		cout << endl;
	}
}

bool search_word(char grid[GRID_SIZE][GRID_SIZE], string word) {
	int word_len = word.length();
	//search left to right
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = 0; j <= GRID_SIZE - word_len; j++) {
			int k;
			for (k = 0; k < word_len; k++) {
				if (grid[i][j + k] != word[k]) {
					break;
				}
			}
			if (k == word_len) {
				cout << "Found " << word << " at (" << i << ", " << j << ") going left to right" << endl;
				return true;
			}
		}
	}

	//right to left
	for (int i = 0; i < GRID_SIZE; i++) {
		for (int j = word_len - 1; j < GRID_SIZE; j++) {
			int k;
			for (k = 0; k < word_len; k++) {
				if (grid[i][j - k] != word[k]) {
					break;
				}
			}
			if (k == word_len) {
				cout << "Found " << word << " at (" << i << ", " << j << ") going right to left" << endl;
				return true;
			}
		}
	}

	// top to bottom
	for (int i = 0; i <= GRID_SIZE - word_len; i++) {
		for (int j = 0; j < GRID_SIZE; j++) {
			int k;
			for (k = 0; k < word_len; k++) {
				if (grid[i + k][j] != word[k]) {
					break;
				}
			}
			if (k == word_len) {
				cout << "Found " << word << " at (" << i << "," << j << ") going down." << endl;
				return true;
			}
		}
	}
	cout << word << " not found " << endl;
	return false;

	//search bottom to top // not working
	for (int i = GRID_SIZE - 1; i > word_len - 1; i--) {
		for (int j = 0; j < GRID_SIZE; j++) {
			int k;
			for (k = 0; k < word_len; k++) {
				if (grid[i - k][j] != word[k]) {
					break;
				}
			}
			if (k == word_len) {
				cout << "Found " << word << " at (" << i << ", " << j << ") going up." << endl;
				return true;
			}
		}
	}

	cout << word << " not found." << endl;
	return false;
}