#pragma once
#include "ChessPiece.h"

class Bishop:public ChessPiece
{
public:
	Bishop(int t, string n);
	bool movement(int new_row, int new_col, ChessPiece *team1[16], ChessPiece* team2[16], bool updatevalue);
	bool Check(ChessPiece *team1[16], ChessPiece* team2[16]);
	~Bishop();
};

