#pragma once
#define GRID_SIZE 10
#include <string>
using namespace std;

void new_score(int arr[], int index, int arr_len);
void calculateFinalGrade(int arr[], int index);
void averageScore(int arr[], int index);
void showScores(int arr[], int index);
bool search_word(char grid[GRID_SIZE][GRID_SIZE], string word);
void print_board(char grid[GRID_SIZE][GRID_SIZE]);