#pragma once
#include <string>
#include <iostream>

using namespace std;

class ChessPiece
{
protected:
	int team;

public:
	string name;
	int row;
	int col;

	ChessPiece();
	ChessPiece(int t, string n);
	virtual bool Check(ChessPiece *team1[16], ChessPiece *team2[16]);
	virtual bool movement(int move_row, int move_col, ChessPiece *team1[16], ChessPiece *team2[16], bool Update_Value);
	virtual bool CheckMate(ChessPiece *team1[16], ChessPiece *team2[16]);
	virtual bool PeekStep(ChessPiece *team1[16], ChessPiece *team2[16]);
	~ChessPiece();
};

