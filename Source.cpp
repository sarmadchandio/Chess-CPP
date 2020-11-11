#include <iomanip>
#include <stdlib.h>
#include <windows.h>

#include "ChessPiece.cpp"
#include "Bishop.cpp"
#include "King.cpp"
#include "Knight.cpp"
#include "Pawn.cpp"
#include "Queen.cpp"
#include "Rook.cpp"



using namespace std;

void InitializeChessBoard(ChessPiece *team1[16], ChessPiece *team2[16]);
void displayBoard(ChessPiece *team1[16], ChessPiece *team2[16]);
void MovePiece(ChessPiece *team1[16], ChessPiece *team2[16], int PlayerTurn);
void CapturedUnits(ChessPiece *team1[16], ChessPiece *team2[16]);
bool Green_Check(ChessPiece *team1[16], ChessPiece *team2[16]);	//Green team giving check
bool Red_Check(ChessPiece *team1[16], ChessPiece *team2[16]);  //Red team giving check
bool Check_Mate(ChessPiece *team1[16], ChessPiece *team2[16], int team);

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


int main() {



	ChessPiece **team1=new ChessPiece*[16]; //0-7 Pawn,8-9 Knight, 10-11 Bishop, 12-13 Rook, 14 Queen, 15 King! 
	ChessPiece **team2=new ChessPiece*[16];
	int turn = 1;
	bool Is_CheckMate = true;
	bool Is_NewGame = true;
	string menu;

	
	do {
		if(Is_NewGame){
			InitializeChessBoard(team1, team2);
			Is_CheckMate = false;
			Is_NewGame = false;
		}
		displayBoard(team1, team2);
		if (turn == 1) {
			if (Red_Check(team1, team2)) {
				if (Check_Mate(team1, team2, 1)) {
					Is_CheckMate =true;
				}
			}
			if (!Is_CheckMate) {
				cout << "Player1 (Green)\n";
				MovePiece(team1, team2, 1);
				turn = 2;
			}
			
		}
		else if (turn == 2) {
			if(Green_Check(team1, team2)) {
				if (Check_Mate(team1, team2, 1)) {
					Is_CheckMate = true;
				}
			}
			if (!Is_CheckMate) {
				cout << "Player2 (Red)\n";
				MovePiece(team1, team2, 2);
				turn = 1;
			}
			
		}

		if (Is_CheckMate) {
			cout << "Press Q to quit\n";
			cout << "Press any key(except Q) to restart the game\n";
			cin >> menu;
			if (menu != "Q") {
				Is_NewGame = true;
			}
		}
		
	} while (menu!="Q"); 


	system("pause");
	return 0;
}

void InitializeChessBoard(ChessPiece *team1[16], ChessPiece *team2[16]) {

	int c;


	for (int i = 0; i < 8; i++)
	{
		team1[i] = new Pawn(1,"P");		//Pawn(team,name)
		team1[i]->row = 1;
		team1[i]->col = i;

		team2[i] =new Pawn(2,"P");
		team2[i]->row = 6;
		team2[i]->col = i;

	}
	
	c = 1;
	for (int i = 8; i < 10; i++)
	{		
		team1[i] =new Knight(1,"N");
		team1[i]->row = 0;
		team1[i]->col = c;
			

		team2[i] =new Knight(2, "N");
		team2[i]->row = 7;
		team2[i]->col = c;
		c += 5;
	}

	c = 2;
	for (int i = 10; i < 12; i++) {
		team1[i] =new Bishop(1, "B");
		team1[i]->row = 0;
		team1[i]->col = c;


		team2[i] =new Bishop(2, "B");
		team2[i]->row = 7;
		team2[i]->col = c;
		c += 3;
	}

	c = 0;
	for (int i = 12; i < 14; i++) {
		team1[i] =new Rook(1, "R");
		team1[i]->row = 0;
		team1[i]->col = c;


		team2[i] =new Rook(2, "R");
		team2[i]->row = 7;
		team2[i]->col = c;
		c += 7;
	}
	team1[14] =new Queen(1, "Q");
	team1[14]->row = 0;
	team1[14]->col = 3;

	team2[14] =new Queen(2, "Q");
	team2[14]->row = 7;
	team2[14]->col = 3;

	team1[15] =new King(1, "K");
	team1[15]->row = 0;
	team1[15]->col = 4;

	team2[15] =new King(2, "K");
	team2[15]->row = 7;
	team2[15]->col = 4;

}

void displayBoard(ChessPiece *team1[16], ChessPiece *team2[16]) {
	bool ding = false;
	int counter = 0;
	int width = 8;
	char a = 'A';


	SetConsoleTextAttribute(hConsole, 7); //White color txt

	system("cls");
	cout <<"    ";
	for (int i = 0; i < 8; i++) {		//Horizontal Numbers
		cout << setw(width)<< a;
		a++;
	}
	cout << endl;


	for (int i = 0; i < 8; i++)				//Vertical Loop
	{

		cout << setw(width);
		for (int i = 0; i < 65; i++)
			cout <<"#";
		cout << endl;
		for (int l = 0; l < 9; l++)
			cout <<setw(width)<< "#";
		cout << endl;

		cout << i<<setw(width-1)<<"#" ;

		for (int j = 0; j < 8; j++)			//Horizontal Loop
		{
			ding = false;
			for (int k = 0; k < 16; k++)
			{
				
				if (i == team1[k]->row && j == team1[k]->col) {
					SetConsoleTextAttribute(hConsole, 10);
					cout << setw(width/2) << team1[k]->name;
					SetConsoleTextAttribute(hConsole, 15);
					cout << setw(width / 2) << "#";
					ding = true;
				}
				else if (i == team2[k]->row && j == team2[k]->col) {
					SetConsoleTextAttribute(hConsole, 12);
					cout  << setw(width / 2) << team2[k]->name;
					SetConsoleTextAttribute(hConsole, 15);
					cout << setw(width / 2) << "#";
					ding = true;
				}

			}
			if (!ding) {
				
				cout << setw(width) << "#";
			}
		}
		cout << endl;
		for (int l = 0; l < 9; l++)
			cout << setw(width) << "#";
		cout << endl;
	}
	cout << setw(width);
	for (int i = 0; i < 65; i++)
		cout << "#";
	cout << endl;

	SetConsoleTextAttribute(hConsole, 14);
	CapturedUnits(team1, team2);

}

void MovePiece(ChessPiece *team1[16], ChessPiece *team2[16], int PlayerTurn) {
	
	string current_location,move_to;
	int r, c;
	int new_r, new_c;
	bool Is_ChessPiece = false;

	do {
		cout << "SelectChessPiece: ";
		cin >> current_location;
		switch(current_location[0]){
		case 'A':
			c = 0;
			break;
		case 'B':
			c = 1;
			break;
		case 'C':
			c = 2;
			break;
		case 'D':
			c = 3;
			break;
		case 'E':
			c = 4;
			break;
		case 'F':
			c = 5;
			break;
		case 'G':
			c = 6;
			break;
		case 'H':
			c = 7;
			break;
		default:
			c = 8;
			break;
		}		
		r = int(current_location[1]) - 48;
		if (PlayerTurn == 1) {
			for (int i = 0; i < 16; i++) {
				if (team1[i]->row == r && team1[i]->col == c) {
					
					cout << "MoveTo: ";
					cin >> move_to;
					switch (move_to[0]) {
					case 'A':
						new_c = 0;
						break;
					case 'B':
						new_c = 1;
						break;
					case 'C':
						new_c = 2;
						break;
					case 'D':
						new_c = 3;
						break;
					case 'E':
						new_c = 4;
						break;
					case 'F':
						new_c = 5;
						break;
					case 'G':
						new_c = 6;
						break;
					case 'H':
						new_c = 7;
						break;
					default:
						new_c = 8;
						break;
					}
					new_r = int(move_to[1]) - 48;

					if (!team1[i]->movement(new_r, new_c, team1, team2, true)) {
						cout << "Invalid Move!\n";
						break;
					}
					
					Is_ChessPiece = true;
					break;
				}
			}

		}
		else if (PlayerTurn == 2) {
			for (int i = 0; i < 16; i++) {
				if (team2[i]->row == r && team2[i]->col == c) {
					cout << "MoveTo: ";
					cin >> move_to;
					switch (move_to[0]) {
					case 'A':
						new_c = 0;
						break;
					case 'B':
						new_c = 1;
						break;
					case 'C':
						new_c = 2;
						break;
					case 'D':
						new_c = 3;
						break;
					case 'E':
						new_c = 4;
						break;
					case 'F':
						new_c = 5;
						break;
					case 'G':
						new_c = 6;
						break;
					case 'H':
						new_c = 7;
						break;
					default:
						new_c = 8;
						break;
					}
					new_r = int(move_to[1]) - 48;
					if (!team2[i]->movement(new_r, new_c, team1, team2, true)) {
						cout << "Invalid Move!\n";
						break;
					}
					Is_ChessPiece = true;
					break;
				}
			}

		}
	} while (!Is_ChessPiece);
	
	

}

void CapturedUnits(ChessPiece *team1[16], ChessPiece *team2[16]) {
	
	SetConsoleTextAttribute(hConsole, 12);
	cout << "Red Captured: ";
	SetConsoleTextAttribute(hConsole, 10);

	for (int i = 0; i < 16; i++) {
		if (team1[i]->row == -1 && team1[i]->col == -1) {
			cout << team1[i]->name << " ";
		}
	}


	SetConsoleTextAttribute(hConsole, 10);
	cout << "\nGreen Captured: ";
	SetConsoleTextAttribute(hConsole, 12);
	for (int i = 0; i < 16; i++) {
		if (team2[i]->row == -1 && team2[i]->col == -1) {
			cout << team2[i]->name << " ";
		}
	}
	cout << endl;
	SetConsoleTextAttribute(hConsole, 14);
	for (int i = 0; i < 50; i++) {
		cout << "__";
	}
	cout << endl;
}

bool Green_Check(ChessPiece *team1[16], ChessPiece *team2[16]) {

	for (int i = 0; i < 15; i++) {
		if (team1[i]->Check(team1, team2) ) {
			cout << "Red King is Danger!\n";
			return true;
		}
	}

	return false;
}

bool Red_Check(ChessPiece *team1[16], ChessPiece *team2[16]) {
	for (int i = 0; i < 15; i++) {
		if (team2[i]->Check(team1, team2)) {
			cout << "Green King is Danger!\n";
			return true;
		}
	}
	return false;
}

bool Check_Mate(ChessPiece *team1[16], ChessPiece *team2[16],int team) {

	if (team == 1) {
		if (team1[15]->CheckMate(team1, team2)) {
			cout << "Red Wins!\n";
			return true;
		}
	}
	else if (team == 2) {
		if (team2[15]->CheckMate(team1, team2)) {
			cout << "Green Wins!\n";
			return true;
		}
	}
	
	return false;
}
