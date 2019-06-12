#pragma once
#include "ChessPiece.h"
class Pawn: public ChessPiece
{
private:
	int moves;
public:
	Pawn(int t,string n);
	bool movement(int move_row, int move_col, ChessPiece *team1[16], ChessPiece *team2[16], bool update);
	bool Check(ChessPiece *team1[16], ChessPiece *team2[16]);
	~Pawn();
};

