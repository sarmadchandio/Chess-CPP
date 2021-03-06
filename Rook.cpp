#include "Rook.h"



Rook::Rook(int t, string n) :ChessPiece(t, n)
{

}

bool Rook::Check(ChessPiece *team1[16], ChessPiece *team2[16]) {
	
	if (row == -1 && col == -1) {		//Dead Men tell no tales
		return false;
	}
	

	if (team == 1) {
		

		if ((team2[15]->col > col && row != team2[15]->row) || (team2[15]->col < col && row != team2[15]->row) || (team2[15]->row < row && col != team2[15]->col) || (team2[15]->row < row && col != team2[15]->col)) {		//Invalid moves for a Rook
			return false;
		}

		if (team2[15]->row > row) {																//For Row++
			for (int i = 0; i < 16; i++) {
				for (int r = row + 1; r < team2[15]->row; r++) {
					if ((team2[i]->row == r && team2[i]->col == col) || (team1[i]->row == r && team1[i]->col == col))
						return false;
				}
			}
		}
		else if (team2[15]->row < row) {		//For Row--
			for (int i = 0; i < 16; i++) {
				for (int r = row - 1; r > team2[15]->row; r--) {
					if ((team2[i]->row == r && team2[i]->col == col) || (team1[i]->row == r && team1[i]->col == col))
						return false;
				}
			}

		}
		else {
			if (team2[15]->col > col) {				//For Col++;
				for (int i = 0; i < 16; i++) {
					for (int c = col + 1; c < team2[15]->col; c++) {
						if ((team2[i]->row == row && team2[i]->col == c) || (team1[i]->row == row && team1[i]->col == c))
							return false;
					}
				}

			}

			else {			//For Col--;
				for (int i = 0; i < 16; i++) {
					for (int c = col - 1; c > team2[15]->col; c--) {
						if ((team2[i]->row == row && team2[i]->col == c) || (team1[i]->row == row && team1[i]->col == c))
							return false;
					}
				}


			}

		}
	}
	
	else if (team == 2) {

		if ((team1[15]->col > col && row != team1[15]->row) || (team1[15]->col < col && row != team1[15]->row) || (team1[15]->row < row && col != team1[15]->col) || (team1[15]->row < row && col != team1[15]->col)) {		//Invalid moves for a Rook
			return false;
		}

		if (team1[15]->row > row) {																//For Row++
			for (int i = 0; i < 16; i++) {
				for (int r = row + 1; r < team1[15]->row; r++) {
					if ((team2[i]->row == r && team2[i]->col == col) || (team1[i]->row == r && team1[i]->col == col))
						return false;
				}
			}
		}
		else if (team1[15]->row < row) {		//For Row--
			for (int i = 0; i < 16; i++) {
				for (int r = row - 1; r > team1[15]->row; r--) {
					if ((team2[i]->row == r && team2[i]->col == col) || (team1[i]->row == r && team1[i]->col == col))
						return false;
				}
			}

		}
		else {
			if (team1[15]->col > col) {				//For Col++;
				for (int i = 0; i < 16; i++) {
					for (int c = col + 1; c < team1[15]->col; c++) {
						if ((team2[i]->row == row && team2[i]->col == c) || (team1[i]->row == row && team1[i]->col == c))
							return false;
					}
				}

			}

			else {			//For Col--;
				for (int i = 0; i < 16; i++) {
					for (int c = col - 1; c > team1[15]->col; c--) {
						if ((team2[i]->row == row && team2[i]->col == c) || (team1[i]->row == row && team1[i]->col == c))
							return false;
					}
				}
			}

		}
	}
	
	return true;

}

bool Rook::movement( int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16], bool Update_Value) {


	
	int index = 0, temp_row, temp_col;
	bool Is_Kill = false;


	if (new_row > 7 || new_row < 0 || new_col>7 || new_col < 0 ) {		//new location is out of board
		return false;
	}
	if ( (new_col > col && row!=new_row) || (new_col < col && row != new_row) || (new_row < row && col != new_col) || (new_row < row && col != new_col) ) {		//Invalid moves for a Rook
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
	if (new_row > row) {																//For Row++
		for (int i = 0; i < 16; i++) {
			for (int r = row + 1; r < new_row; r++) {
				if ((team2[i]->row == r && team2[i]->col == col) || (team1[i]->row == r && team1[i]->col == col))
					return false;
			}
		}
	}
	else if (new_row < row) {		//For Row--
		for (int i = 0; i < 16; i++) {
			for (int r = row-1; r > new_row; r--) {
				if ((team2[i]->row == r && team2[i]->col == col) || (team1[i]->row == r && team1[i]->col == col))
					return false;
			}
		}
		
	}
	else {
		if (new_col > col) {				//For Col++;
			for (int i = 0; i < 16; i++) {
				for (int c = col+1; c < new_col; c++) {
					if ((team2[i]->row == row && team2[i]->col == c) || (team1[i]->row == row && team1[i]->col == c))
						return false;
				}
			}
			
		}

		else {			//For Col--;
			for (int i = 0; i < 16; i++) {
				for (int c = col-1; c > new_col; c--) {
					if ((team2[i]->row == row && team2[i]->col == c) || (team1[i]->row == row && team1[i]->col == c))
						return false;
				}
			}
			

		}
			
	}
		
	//Kill the Enemy Unit
	for (int i = 0; i < 16; i++) {
		if (team == 1) {
			if (team2[i]->row == new_row && team2[i]->col == new_col) {
				index = i;
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

Rook::~Rook()
{
}
