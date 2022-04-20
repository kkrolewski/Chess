#include "King.h"
#include "Board.h"

King::King(sf::Vector2i _position, int _color, std::string _pieceType) :
	ChessPiece(_position, _color, _pieceType) {}

std::vector<sf::Vector2i> King::calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn) {
	std::vector<sf::Vector2i> possible;
	if (colorTurn == color) {
		int x = position.x;
		int y = position.y;

		//up-down
		if (!(position.y - 100 < 0)) {
			if (boardMap[boardMapping[(position.y - 100) / 100][position.x / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x, y - 100));
			}
			else if (boardMap[boardMapping[(position.y - 100) / 100][position.x / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x, y - 100));
			}
		}

		if (!(position.y + 100 > 700)) {
			if (boardMap[boardMapping[(position.y + 100) / 100][position.x / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x, y + 100));
			}
			else if (boardMap[boardMapping[(position.y + 100) / 100][position.x / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x, y + 100));
			}
		}

		//left-right
		if (!(position.x - 100 < 0)) {
			if (boardMap[boardMapping[position.y / 100][(position.x - 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x - 100, y));
			}
			else if (boardMap[boardMapping[position.y / 100][(position.x - 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x - 100, y));
			}
		}

		if (!(position.x + 100 > 700)) {
			if (boardMap[boardMapping[position.y / 100][(position.x + 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x + 100, y));
			}
			else if (boardMap[boardMapping[position.y / 100][(position.x + 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x + 100, y));
			}
		}

		//left-up,left-down
		if (!(position.y - 100 < 0 || position.x - 100 < 0)) {
			if (boardMap[boardMapping[(position.y - 100) / 100][(position.x - 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x - 100, y - 100));
			}
			else if (boardMap[boardMapping[(position.y - 100) / 100][(position.x - 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x - 100, y - 100));
			}
		}

		if (!(position.y + 100 > 700 || position.x - 100 < 0)) {
			if (boardMap[boardMapping[(position.y + 100) / 100][(position.x - 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x - 100, y + 100));
			}
			else if (boardMap[boardMapping[(position.y + 100) / 100][(position.x - 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x - 100, y + 100));
			}
		}

		//right-up,right-down
		if (!(position.y - 100 < 0 || position.x + 100 > 700)) {
			if (boardMap[boardMapping[(position.y - 100) / 100][(position.x + 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x + 100, y - 100));
			}
			else if (boardMap[boardMapping[(position.y - 100) / 100][(position.x + 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x + 100, y - 100));
			}
		}

		if (!(position.y + 100 > 700 || position.x + 100 > 700)) {
			if (boardMap[boardMapping[(position.y + 100) / 100][(position.x + 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(x + 100, y + 100));
			}
			else if (boardMap[boardMapping[(position.y + 100) / 100][(position.x + 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(x + 100, y + 100));
			}
		}
	}
	return possible;
}
