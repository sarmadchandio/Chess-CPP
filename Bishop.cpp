#include "Bishop.h"



Bishop::Bishop(int t, string n) :ChessPiece(t,n)
{

}


bool Bishop::Check(ChessPiece *team1[16], ChessPiece* team2[16]) {

	if (row == -1 && col == -1) {		//Dead Men tell no tales
		return false;
	}

	int c = col;
	int r = row;

	if (team == 1) {

		if (abs(team2[15]->row - row) != abs(team2[15]->col - col)) {		//Invalid Bishop Move
			return false;
		}
		if (team2[15]->row < row) {
			for (r = row - 1; r > team2[15]->row; r--) {
				if (team2[15]->col > col) {
					c++;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}


				else if (team2[15]->col < col) {
					c--;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}
			}
		}

		else if (team2[15]->row > row) {
			for (r = row + 1; r < team2[15]->row; r++) {
				if (team2[15]->col > col) {
					c++;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}


				else if (team2[15]->col < col) {
					c--;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}
			}
		}
	}
	
	else if (team == 2) {

		if (abs(team1[15]->row - row) != abs(team1[15]->col - col)) {		//Invalid Bishop Move
			return false;
		}

		if (team1[15]->row < row) {
			for (r = row - 1; r > team1[15]->row; r--) {
				if (team1[15]->col > col) {
					c++;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}


				else if (team1[15]->col < col) {
					c--;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}
			}
		}

		else if (team1[15]->row > row) {
			for (r = row + 1; r < team1[15]->row; r++) {
				if (team1[15]->col > col) {
					c++;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}


				else if (team1[15]->col < col) {
					c--;
					for (int i = 0; i < 16; i++) {
						if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
							return false;
					}
				}
			}
		}
	}
	



	return true;
}

bool Bishop::movement(int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16], bool Update_Value) {
	int index = 0;
	int temp_row, temp_col;
	int c = col;
	int r = row;
	bool Is_Kill = false;
	
	if (new_row > 7 || new_row < 0 || new_col>7 || new_col < 0 ||
		abs(new_row-row)!=abs(new_col-col)) {		//Invalid Bishop Move
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

	
	//(Collision Check)
	if (new_row < row) {
		for (r = row - 1; r > new_row; r--) {
			if (new_col > col) {
				c++;
				for (int i = 0; i < 16; i++) {
					if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
						return false;
				}
			}


			else if (new_col < col) {
				c--;
				for (int i = 0; i < 16; i++) {
					if((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
						return false;
				}
			}
		}
	}

	else if (new_row > row) {
		for (r = row + 1; r < new_row; r++) {
			if (new_col > col) {
				c++;
				for (int i = 0; i < 16; i++) {
					if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
						return false;
				}
			}


			else if (new_col < col) {
				c--;
				for (int i = 0; i < 16; i++) {
					if ((team2[i]->row == r && team2[i]->col == c) || (team1[i]->row == r && team1[i]->col == c))
						return false;
				}
			}
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

Bishop::~Bishop()
{

}
