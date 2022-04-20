#include "Board.h"

#include "Pawn.h"
#include "Rook.h"
#include "Bishop.h"
#include "Knight.h"
#include "Queen.h"
#include "King.h"

using namespace std;

Board::Board() {
	//adding board image
	boardTexture.loadFromFile("Images/Board.png");
	boardImage.setTexture(boardTexture);

	//initialize map
	boardMap = map<int, ChessPiece*>();
	for (int i = 1; i <= 64; i++) {
		boardMap.insert({ i,nullptr });
	}

	//adding pieces
	initializePieces();
}

void Board::initializePieces() {
	for (int i = 0; i < 8; i++) {
		sf::Vector2i pos;

		//white pawn
		pos = sf::Vector2i(i * 100, 600);
		ChessPiece* whitePawn = new Pawn(pos, 0, "Pawn");
		boardMap[i + 49] = whitePawn;

		//black pawn
		pos = sf::Vector2i(i * 100, 100);
		ChessPiece* blackPawn = new Pawn(pos, 1, "Pawn");
		boardMap[i + 9] = blackPawn;

		//rooks
		if (i == 0 || i == 7) {
			//white
			pos = sf::Vector2i(i * 100, 700);
			ChessPiece* whiteRook = new Rook(pos, 0, "Rook");
			boardMap[i + 57] = whiteRook;

			//black
			pos = sf::Vector2i(i * 100, 0);
			ChessPiece* blackRook = new Rook(pos, 1, "Rook");
			boardMap[i + 1] = blackRook;
		}

		//knights
		else if (i == 1 || i == 6) {
			//white
			pos = sf::Vector2i(i * 100, 700);
			ChessPiece* whiteKnight = new Knight(pos, 0, "Knight");
			boardMap[i + 57] = whiteKnight;

			//black
			pos = sf::Vector2i(i * 100, 0);
			ChessPiece* blackKnight = new Knight(pos, 1, "Knight");
			boardMap[i + 1] = blackKnight;
		}

		//bishops
		else if (i == 2 || i == 5) {
			//white
			pos = sf::Vector2i(i * 100, 700);
			ChessPiece* whiteBishop = new Bishop(pos, 0, "Bishop");
			boardMap[i + 57] = whiteBishop;

			//black
			pos = sf::Vector2i(i * 100, 0);
			ChessPiece* blackBishop = new Bishop(pos, 1, "Bishop");
			boardMap[i + 1] = blackBishop;
		}

		//queens
		else if (i == 3) {
			//white
			pos = sf::Vector2i(300, 700);
			ChessPiece* whiteQueen = new Queen(pos, 0, "Queen");
			boardMap[i + 57] = whiteQueen;

			//black
			pos = sf::Vector2i(300, 0);
			ChessPiece* blackQueen = new Queen(pos, 1, "Queen");
			boardMap[i + 1] = blackQueen;
		}

		//kings
		else {
			//white
			pos = sf::Vector2i(400, 700);
			ChessPiece* whiteKing = new King(pos, 0, "King");
			boardMap[i + 57] = whiteKing;

			//black
			pos = sf::Vector2i(400, 0);
			ChessPiece* blackKing = new King(pos, 1, "King");
			boardMap[i + 1] = blackKing;
		}
	}
}