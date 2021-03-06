#include "King.h"



King::King(int t, string n):ChessPiece(t,n)
{
}

bool King::CheckMate(ChessPiece *team1[16], ChessPiece *team2[16]) {

	bool check = false;

	if (team == 1) {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					if (team1[i]->movement(j, k, team1, team2, false)) {
						return false;
					}
				}
				
			}
		}
	}

	else if (team == 2) {
		for (int i = 0; i < 16; i++) {
			for (int j = 0; j < 8; j++) {
				for (int k = 0; k < 8; k++) {
					if (team2[i]->movement(j, k, team1, team2, false)) {
						return false;
					}
				}

			}
		}
	}
	

	return true;

}

bool King::movement(int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16], bool Update_Value) {
	
	int index = 0;
	int temp_row, temp_col;
	bool Is_Kill = false;

	if (new_row > 7 || new_row < 0 || new_col>7 || new_col < 0) {	//Out of bounds
		return false;
	}

	if ((new_row > row + 1) ||		//Invalid King Moves
		(new_row < row - 1) ||
		(new_col > col + 1) ||
		(new_col < col - 1)) {
		return false;
	}

	for (int i = 0; i < 16; i++) {											//If unit of same team is standing at the move_to place, return false!
		if (team == 1) {
			if (team1[i]->row == new_row && team1[i]->col == new_col)
				return false;
		}
		else if (team == 2) {
			if (team2[i]->row == new_row && team2[i]->col == new_col)
				return false;
		}
	}


	for (int i = 0; i < 16; i++) {
		if (team == 1) {
			if (team2[i]->row == new_row && team2[i]->col == new_col) {
				Is_Kill = true;
				index = i;
				team2[i]->row = -1;
				team2[i]->col = -1;
				break;
			}
		}
		else if (team == 2) {
			if (team1[i]->row == new_row && team1[i]->col == new_col) {
				Is_Kill = true;
				index = i;
				team1[i]->row = -1;
				team1[i]->col = -1;
				break;
			}
		}
	}

	temp_row = row;
	temp_col = col;
	row = new_row;
	col = new_col;

	// if Own King gets in check return false
	for (int i = 0; i < 15; i++) {
		if (team == 1) {
			if (team2[i]->Check(team1, team2)) {		//team 2 giving check
				row = temp_row;
				col = temp_col;
				if (Is_Kill) {
					team2[index]->row = new_row;
					team2[index]->col = new_col;
				}

				return false;
			}
		}

		else if (team == 2) {
			if (team1[i]->Check(team1, team2)) {		//team 1 giving check
				row = temp_row;
				col = temp_col;
				if (Is_Kill) {
					team1[index]->row = new_row;
					team1[index]->col = new_col;
				}
				return false;
			}
		}
	}
	if (!Update_Value) {
		row = temp_row;
		col = temp_col;
	}
	return true;

}
King::~King()
{
}
