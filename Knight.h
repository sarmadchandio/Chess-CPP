#pragma once
#include "ChessPiece.h"

class Knight:public ChessPiece
{
public:
	Knight(int t, string n);
	bool movement(int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16], bool update_value);
	bool Check(ChessPiece *team1[16], ChessPiece *team2[16]);
	~Knight();
};

