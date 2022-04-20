#include "ChessPiece.h"
#include "Board.h"
#include "Game.h"
#include "Pawn.h"

ChessPiece::ChessPiece(sf::Vector2i _position, int _color, std::string _pieceType) {
	//white
	if (_color == 0) {
		pieceTexture.loadFromFile("Images/white" + _pieceType + ".png");
	}
	//black
	else {
		pieceTexture.loadFromFile("Images/black" + _pieceType + ".png");
	}
	pieceImage.setTexture(pieceTexture);
	pieceImage.setPosition(_position.x, _position.y);
	position = _position;
	color = _color;
}
void ChessPiece::move(sf::Vector2i movePos, std::map<int, ChessPiece*>& boardMap, bool testMove) {
	if (!testMove) {
		pieceImage.setPosition(sf::Vector2f(movePos.x, movePos.y));
		if (boardMap[boardMapping[movePos.y / 100][movePos.x / 100]] != nullptr) {
			delete boardMap[boardMapping[movePos.y / 100][movePos.x / 100]];
			boardMap[boardMapping[movePos.y / 100][movePos.x / 100]] = nullptr;
		}
	}
	boardMap[boardMapping[position.y / 100][position.x / 100]] = nullptr;
	position = movePos;
	boardMap[boardMapping[position.y / 100][position.x / 100]] = this;

}

ChessPiece::ChessPiece(ChessPiece* piece) :
	pieceTexture(piece->pieceTexture), pieceImage(piece->pieceImage), position(piece->position), color(piece->color),
	moved(piece->moved) {}