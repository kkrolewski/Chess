#include "Pawn.h"
#include "Board.h"

Pawn::Pawn(sf::Vector2i _position, int _color, std::string _pieceType) :
	ChessPiece(_position, _color, _pieceType) {}

std::vector<sf::Vector2i> Pawn::calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn) {
	std::vector<sf::Vector2i> possible;
	if (colorTurn == color) {
		if (color == 0) {
			//normal move
			if (boardMap[boardMapping[(position.y - 100) / 100][position.x / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x, position.y - 100));
			}
			if (!hasMoved()) {
				if (boardMap[boardMapping[(position.y - 200) / 100][position.x / 100]] == nullptr
					&& boardMap[boardMapping[(position.y - 100) / 100][position.x / 100]] == nullptr) {
					possible.push_back(sf::Vector2i(position.x, position.y - 200));
				}
			}

			//beat
			//left-up
			if (!(position.y - 100 < 0 || position.x - 100 < 0)) {
				if (boardMap[boardMapping[(position.y - 100) / 100][(position.x - 100) / 100]] != nullptr) {
					if (boardMap[boardMapping[(position.y - 100) / 100][(position.x - 100) / 100]]->getColor() != 0) {
						possible.push_back(sf::Vector2i(position.x - 100, position.y - 100));
					}
				}
			}
			//right-up
			if (!(position.y - 100 < 0 || position.x + 100 > 700)) {
				if (boardMap[boardMapping[(position.y - 100) / 100][(position.x + 100) / 100]] != nullptr) {
					if (boardMap[boardMapping[(position.y - 100) / 100][(position.x + 100) / 100]]->getColor() != 0) {
						possible.push_back(sf::Vector2i(position.x + 100, position.y - 100));
					}
				}
			}
		}
		else {
			if (boardMap[boardMapping[(position.y + 100) / 100][position.x / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x, position.y + 100));
			}
			if (!hasMoved()) {
				if (boardMap[boardMapping[(position.y + 200) / 100][position.x / 100]] == nullptr &&
					boardMap[boardMapping[(position.y + 100) / 100][position.x / 100]] == nullptr) {
					possible.push_back(sf::Vector2i(position.x, position.y + 200));
				}
			}

			//beat
			//left-down
			if (!(position.y + 100 > 700 || position.x - 100 < 0)) {
				if (boardMap[boardMapping[(position.y + 100) / 100][(position.x - 100) / 100]] != nullptr) {
					if (boardMap[boardMapping[(position.y + 100) / 100][(position.x - 100) / 100]]->getColor() != 1) {
						possible.push_back(sf::Vector2i(position.x - 100, position.y + 100));
					}
				}
			}
			//right-down
			if (!(position.y + 100 > 700 || position.x + 100 > 700)) {
				if (boardMap[boardMapping[(position.y + 100) / 100][(position.x + 100) / 100]] != nullptr) {
					if (boardMap[boardMapping[(position.y + 100) / 100][(position.x + 100) / 100]]->getColor() != 1) {
						possible.push_back(sf::Vector2i(position.x + 100, position.y + 100));
					}
				}
			}
		}
	}
	return possible;
}

void Pawn::move(sf::Vector2i movePos, std::map<int, ChessPiece*>& boardMap, bool testMove) {
	if (!testMove) {
		pieceImage.setPosition(sf::Vector2f(movePos.x, movePos.y));
		if (!hasMoved()) moved = true;
		// if there is a beat
		if (boardMap[boardMapping[movePos.y / 100][movePos.x / 100]] != nullptr) {
			delete boardMap[boardMapping[movePos.y / 100][movePos.x / 100]];
			boardMap[boardMapping[movePos.y / 100][movePos.x / 100]] = nullptr;
		}
	}

	boardMap[boardMapping[position.y / 100][position.x / 100]] = nullptr;
	position = movePos;
	boardMap[boardMapping[position.y / 100][position.x / 100]] = this;

}

