#include "Pawn.h"



Pawn::Pawn(int t, string n):ChessPiece(t,n)
{
	moves = 0;
}

bool Pawn::movement( int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16], bool Update_Value) {

	int index = 0;
	bool Is_Kill = false;
	int temp_row, temp_col;
	string promote;

	temp_row = row;
	temp_col = col;


	if (new_row > 7 || new_row < 0 || new_col>7 || new_col<0) {
		return false;
	}

	//Team2 is the Red team (Lower side of the board)
	if (team == 2) {
		if (new_row == row - 1 && new_col == col) {			//Straight movement of pawn for team 2
			for (int i = 0; i < 16; i++) {
				if ((team2[i]->row == new_row && team2[i]->col == new_col) || (team1[i]->row == new_row && team1[i]->col == new_col)) {		//Avoid Collision with units of both teams
					return false;
				}
			}
			// if Own King gets in check return false
			row = new_row;
			col = new_col;
			for (int i = 0; i < 15; i++) {
				if (team1[i]->Check(team1, team2)) {		//team 1 giving check
					row = temp_row;
					col = temp_col;
					return false;
				}
			}
			if (Update_Value && row == 0) {
				do {
					cout << "Promote a Pawn into one of the captured units: ";
					cin >> promote;
					for (int i = 0; i < 15; i++) {
						if ((promote == team2[i]->name) && (team2[i]->col == -1) && (team2[i]->row = -1)) {
							team2[i]->row = row;
							team2[i]->col = col;
							row = -1;
							col = -1;
							return true;
						}
					}
				} while (true);
			}

			if (!Update_Value) {
				row = temp_row;
				col = temp_col;
			}
			moves++;
			return true;

		}

		else if (new_row == row - 2 && new_col == col && !moves) {			//2 steps for first move
			for (int i = 0; i < 16; i++) {
				if ((team2[i]->row == new_row && team2[i]->col == new_col) || (team1[i]->row == new_row && team1[i]->col == new_col)) {		//Avoid Collision with units of both teams
					return false;
				}
			}
			// if Own King gets in check return false
			row = new_row;
			col = new_col;
			for (int i = 0; i < 15; i++) {
				if (team1[i]->Check(team1, team2)) {		//team 1 giving check
					row = temp_row;
					col = temp_col;
					return false;
				}
			}
			if (!Update_Value) {
				row = temp_row;
				col = temp_col;
			}
			moves++;
			return true;
		}

		else if ((new_row == row - 1 && new_col == col + 1) || (new_row == row - 1 && new_col == col - 1)) {		//Can only move diagonal when there is an enemy unit

			for (int i = 0; i < 16; i++) {
				if ((team1[i]->row == new_row && team1[i]->col == new_col)) {
					index = i;
					Is_Kill = true;
					team1[i]->row = -1;
					team1[i]->col = -1;
					// if Own King gets in check return false
					row = new_row;
					col = new_col;
					for (int i = 0; i < 15; i++) {
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
					if (Update_Value && row == 0) {
						do {
							cout << "Promote a Pawn into one of the captured units: ";
							cin >> promote;
							for (int i = 0; i < 15; i++) {
								if ((promote == team2[i]->name) && (team2[i]->col == -1) && (team2[i]->row = -1)) {
									team2[i]->row = row;
									team2[i]->col = col;
									row = -1;
									col = -1;
									return true;
								}
							}
						} while (true);
					}
					if (!Update_Value) {
						row = temp_row;
						col = temp_col;
					}
					moves++;
					return true;
				}
			}
			return false;
		}
		
		
	}

	//Team1 is the Green team (Upper side of the board)
	else if (team == 1) {
		if (new_row==row+1 && new_col==col) {	//Straight movement of pawn for team 1
			for (int i = 0; i < 16; i++) {
				if ((team2[i]->row == new_row && team2[i]->col == new_col) || (team1[i]->row == new_row && team1[i]->col == new_col)) {	//Avoid Collision with units of both teams
					return false;
				}
			}
			// if Own King gets in check return false
			row = new_row;
			col = new_col;
			for (int i = 0; i < 15; i++) {
				if (team2[i]->Check(team1, team2)) {		//team 2 giving check
					row = temp_row;
					col = temp_col;
					return false;
				}
			}
			if (Update_Value && row == 7) {
				do {
					cout << "Promote a Pawn into one of the captured units: ";
					cin >> promote;
					for (int i = 0; i < 15; i++) {
						if ((promote == team1[i]->name) && (team1[i]->col == -1) && (team1[i]->row = -1)) {
							team1[i]->row = row;
							team1[i]->col = col;
							row = -1;
							col = -1;
							return true;
						}
					}
				} while (true);
			}
			if (!Update_Value) {
				row = temp_row;
				col = temp_col;
			}
			moves++;
			return true;
		}

		else if (new_row == row + 2 && new_col == col && !moves) {	//2 steps in first move
			for (int i = 0; i < 16; i++) {
				if ((team2[i]->row == new_row && team2[i]->col == new_col) || (team1[i]->row == new_row && team1[i]->col == new_col)) {	//Avoid Collision with units of both teams
					return false;
				}
			}
			// if Own King gets in check return false
			row = new_row;
			col = new_col;
			for (int i = 0; i < 15; i++) {
				if (team2[i]->Check(team1, team2)) {		//team 2 giving check
					row = temp_row;
					col = temp_col;
					return false;
				}
			}
			if (!Update_Value) {
				row = temp_row;
				col = temp_col;
			}
			moves++;
			return true;
		}

		else if ((new_row == row + 1 && new_col == col + 1) || (new_row == row + 1 && new_col == col - 1)) {	//Can only move diagonal when there is an enemy unit
			for (int i = 0; i < 16; i++) {
				if ((team2[i]->row == new_row && team2[i]->col == new_col)) {
					index = i;
					Is_Kill = true;
					team2[i]->row = -1;
					team2[i]->col = -1;
					// if Own King gets in check return false
					row = new_row;
					col = new_col;
					for (int i = 0; i < 15; i++) {
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
					if (Update_Value && row == 7) {
						do {
							cout << "Promote a Pawn into one of the captured units: ";
							cin >> promote;
							for (int i = 0; i < 15; i++) {
								if ((promote == team1[i]->name) && (team1[i]->col == -1) && (team1[i]->row = -1)) {
									team1[i]->row = row;
									team1[i]->col = col;
									row = -1;
									col = -1;
									return true;
								}
							}
						} while (true);
					}
					if (!Update_Value) {
						row = temp_row;
						col = temp_col;
					}
					moves++;
					return true;
				}
			}
			return false;
		}
		
	}
	return false;
}

bool Pawn::Check(ChessPiece *team1[16], ChessPiece *team2[16]) {

	if (row == -1 && col == -1) {		//Dead Men tell no tales
		return false;
	}

	if (team == 1) {
		if ((row + 1 == team2[15]->row && col + 1 == team2[15]->col) || (row + 1 == team2[15]->row && col - 1 == team2[15]->col)) {
			return true;
		}
	}

	else if (team == 2) {
		if ((row - 1 == team1[15]->row && col + 1 == team1[15]->col) || (row - 1 == team1[15]->row && col - 1 == team1[15]->col)) {
			return true;
		}
	}

	return false;
}

Pawn::~Pawn()
{
}
