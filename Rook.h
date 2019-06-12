#pragma once
#include "ChessPiece.h"

class Rook:public ChessPiece
{
public:
	Rook(int t, string n);
	bool movement( int new_row, int new_col, ChessPiece *team1[16], ChessPiece *team2[16], bool update);
	bool Check(ChessPiece *team1[16], ChessPiece *team2[16]);
	~Rook();
};

