#include "Knight.h"



Knight::Knight(int t, string n):ChessPiece(t, n)
{
	
}

bool Knight::Check(ChessPiece *team1[16], ChessPiece *team2[16]) {

	if (row == -1 && col == -1) {		//Dead Men tell no tales
		return false;
	}

	if (team == 1) {
		if ((team2[15]->row == row - 2 && team2[15]->col == col - 1) ||
			(team2[15]->row == row - 2 && team2[15]->col == col + 1) ||
			(team2[15]->row == row + 2 && team2[15]->col == col - 1) ||
			(team2[15]->row == row + 2 && team2[15]->col == col + 1) ||
			(team2[15]->row == row - 1 && team2[15]->col == col - 2) ||
			(team2[15]->row == row - 1 && team2[15]->col == col + 2) ||
			(team2[15]->row == row + 1 && team2[15]->col == col - 2) ||
			(team2[15]->row == row + 1 && team2[15]->col == col + 2)) {
			return true;
		}
	}
	else if (team == 2) {
		if ((team1[15]->row == row - 2 && team1[15]->col == col - 1) ||
			(team1[15]->row == row - 2 && team1[15]->col == col + 1) ||
			(team1[15]->row == row + 2 && team1[15]->col == col - 1) ||
			(team1[15]->row == row + 2 && team1[15]->col == col + 1) ||
			(team1[15]->row == row - 1 && team1[15]->col == col - 2) ||
			(team1[15]->row == row - 1 && team1[15]->col == col + 2) ||
			(team1[15]->row == row + 1 && team1[15]->col == col - 2) ||
			(team1[15]->row == row + 1 && team1[15]->col == col + 2)) {
			return true;
		}
	}
	
	return false;
}

bool Knight::movement(int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16], bool Update_Value) {
	int index = 0;
	int temp_row, temp_col;
	bool Is_Kill = false;



	if (new_row > 7 || new_row < 0 || new_col>7 || new_col < 0) {
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

	if ((new_row == row - 2 && new_col == col - 1) ||
		(new_row == row - 2 && new_col == col + 1) ||
		(new_row == row + 2 && new_col == col - 1) ||
		(new_row == row + 2 && new_col == col + 1) ||
		(new_row == row - 1 && new_col == col - 2) ||
		(new_row == row - 1 && new_col == col + 2) ||
		(new_row == row + 1 && new_col == col - 2) ||
		(new_row == row + 1 && new_col == col + 2)) {
		for (int i = 0; i < 16; i++) {
			if (team == 1) {
				if (team2[i]->row == new_row && team2[i]->col == new_col) {
					index=i;
					Is_Kill = true;
					team2[i]->row = -1;
					team2[i]->col = -1;
					break;
				}
			}
			else if (team == 2) {
				if (team1[i]->row == new_row && team1[i]->col == new_col) {
					index = i;
					Is_Kill = true;
					team1[i]->row = -1;
					team1[i]->col = -1;
					break;
				}
			}
		}

		// if Own King gets in check return false
		temp_row = row;
		temp_col = col;
		row = new_row;
		col = new_col;
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

	return false;			//Al other moves are invalid 
}

Knight::~Knight()
{
}
