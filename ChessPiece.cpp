#include "ChessPiece.h"


ChessPiece::ChessPiece() {

}

ChessPiece::ChessPiece(int t, string n)
{
	team = t;
	name = n;
}

bool ChessPiece::movement(int move_row, int move_col, ChessPiece *team1[16], ChessPiece *team2[16],bool Update_value) {
	cout << "Virtual Movement Called!\n";
	return true;
}

bool ChessPiece::PeekStep(ChessPiece *team1[16], ChessPiece *team2[16]) {
	cout << "Virtual PeekStep Called\n";
	return true;
}

bool ChessPiece::CheckMate(ChessPiece *team1[16], ChessPiece *team2[16]) {
	cout << "Virtual CheckMate Called\n";
	return true;
}

bool ChessPiece::Check(ChessPiece *team1[16], ChessPiece *team2[16]) {
	cout << "Virtual Check Called\n";
	return true;
}

ChessPiece::~ChessPiece()
{
}