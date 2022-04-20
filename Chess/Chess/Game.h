#ifndef GAME_H
#define GAME_H

#include "Board.h"

class Game
{
private:
	Board* board;
	sf::Vector2i whiteKingPos = sf::Vector2i(400, 700);
	sf::Vector2i blackKingPos = sf::Vector2i(400, 0);
public:
	int play();
	bool isCheckOn(std::map<int, ChessPiece*> boardMap, int attackingColor);
	bool isCheckmate(std::map<int, ChessPiece*> boardMap, int defendingColor);
	std::vector<sf::Vector2i> deleteMovesThatDontPreventCheck(ChessPiece* pieceToMove, std::vector<sf::Vector2i> possibleMoves,
		std::map<int, ChessPiece*> boardMap, int attackingColor);
};

#endif

