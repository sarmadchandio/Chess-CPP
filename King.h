#pragma once
#include "ChessPiece.h"
class King:public ChessPiece
{
public: 
	King(int t, string n);
	bool movement(int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16],bool update_value);
	bool CheckMate(ChessPiece *team1[16], ChessPiece *team2[16]);
	~King();
};

