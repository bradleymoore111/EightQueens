#include <iostream>
using namespace std;

bool test(int[8][8], int);
void copy(int [8][8], int [8][8]);
bool boardWorks(int [8][8]);

int main() {
	// int board[8][8] = { {0,0,0,0,0,0,0,0},{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 },{ 0,0,0,0,0,0,0,0 }, };

	/*int vals[8];
	for (int i = 0; i < 8; i++) {
		int temp[8][8]; // Should be an array of 0's
		temp[0][i] = 1;
		vals[i] = test(&temp, 1);
		cout << vals[i] << endl;
	}*/

	int board[8][8];

	board[0][0] = 1;
	board[5][0] = 1;

	cout << boardWorks(board) << endl;

	return 0;
}

bool test(int board[8][8], int loc) {
	bool vals[8];
	for (int i = 0; i < 8; i++) {
		int temp[8][8];
		copy(board, temp);
		temp[loc][i] = 1;
		if (boardWorks(board)) {
			if (loc == 7) {
				return true;
			}
			else {
				vals[i] = true;
			}
		}
		else {
			vals[i] = false;
		}
	}
	for (int i = 0; i < 8; i++) {
		if (vals[i]) {
			return true;
		}
	}
	return false;
}

void copy(int old[8][8], int goal[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; i++) {
			goal[i][j] = old[i][j];
		}
	}
}

bool boardWorks(int board[8][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (board[i][j] == 1) {

				// right
				for (int k = i+1; k < 8; k++) {
					if (board[k][j] == 1) {
						return false;
					}
				}

				// left
				for (int k = i - 1; k >= 0; k--) {
					if (board[k][j] == 1) {
						return false;
					}
				}

				// up
				for (int k = j + 1; k < 8; k++) {
					if (board[i][k] == 1) {
						return false;
					}
				}

				// down
				for (int k = j - 1; k >= 0; k--) {
					if (board[i][k] == 1) {
						return false;
					}
				}

				// up right diagonal
				for (int k = 0; k + i < 8 && k + j < 8; k++) {
					if (board[i + k][j + k] == 1) {
						return false;
					}
				}

				// up left diagonal
				for (int k = 0; i - k >= 0 && j + k < 8; k++) {
					if (board[i + k][j + k] == 1) {
						return false;
					}
				}

				// down right diagonal
				for (int k = 0; i + k < 8 && j - k >= 0; k++) {
					if (board[i + k][j - k] == 1) {
						return false;
					}
				}

				// down left diagonal
				for (int k = 0; i - k >= 0 && j - k >= 0; k++) {
					if (board[i - k][j - k] == 1) {
						return false;
					}
				}
			}
		}
	}
	return true;
}
