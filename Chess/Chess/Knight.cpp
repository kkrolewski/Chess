#include "Knight.h"
#include "Board.h"

Knight::Knight(sf::Vector2i _position, int _color, std::string _pieceType) :
	ChessPiece(_position, _color, _pieceType) {}

std::vector<sf::Vector2i> Knight::calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn) {
	std::vector<sf::Vector2i> possible;
	if (colorTurn == color) {
		if (!(position.y - 200 < 0 || position.x - 100 < 0)) {
			if (boardMap[boardMapping[(position.y - 200) / 100][(position.x - 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x - 100, position.y - 200));
			}
			//beat
			else if (boardMap[boardMapping[(position.y - 200) / 100][(position.x - 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x - 100, position.y - 200));
			}
		}

		if (!(position.y - 200 < 0 || position.x + 100 > 700)) {
			if (boardMap[boardMapping[(position.y - 200) / 100][(position.x + 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x + 100, position.y - 200));
			}
			//beat
			else if (boardMap[boardMapping[(position.y - 200) / 100][(position.x + 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x + 100, position.y - 200));
			}
		}

		if (!(position.y - 100 < 0 || position.x - 200 < 0)) {
			if (boardMap[boardMapping[(position.y - 100) / 100][(position.x - 200) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x - 200, position.y - 100));
			}
			//beat
			else if (boardMap[boardMapping[(position.y - 100) / 100][(position.x - 200) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x - 200, position.y - 100));
			}
		}

		if (!(position.y - 100 < 0 || position.x + 200 > 700)) {
			if (boardMap[boardMapping[(position.y - 100) / 100][(position.x + 200) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x + 200, position.y - 100));
			}
			//beat
			else if (boardMap[boardMapping[(position.y - 100) / 100][(position.x + 200) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x + 200, position.y - 100));
			}
		}

		if (!(position.y + 100 > 700 || position.x - 200 < 0)) {
			if (boardMap[boardMapping[(position.y + 100) / 100][(position.x - 200) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x - 200, position.y + 100));
			}
			//beat
			else if (boardMap[boardMapping[(position.y + 100) / 100][(position.x - 200) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x - 200, position.y + 100));
			}
		}

		if (!(position.y + 100 > 700 || position.x + 200 > 700)) {
			if (boardMap[boardMapping[(position.y + 100) / 100][(position.x + 200) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x + 200, position.y + 100));
			}
			//beat
			else if (boardMap[boardMapping[(position.y + 100) / 100][(position.x + 200) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x + 200, position.y + 100));
			}
		}

		if (!(position.y + 200 > 700 || position.x - 100 < 0)) {
			if (boardMap[boardMapping[(position.y + 200) / 100][(position.x - 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x - 100, position.y + 200));
			}
			//beat
			else if (boardMap[boardMapping[(position.y + 200) / 100][(position.x - 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x - 100, position.y + 200));
			}
		}

		if (!(position.y + 200 > 700 || position.x + 100 > 700)) {
			if (boardMap[boardMapping[(position.y + 200) / 100][(position.x + 100) / 100]] == nullptr) {
				possible.push_back(sf::Vector2i(position.x + 100, position.y + 200));
			}
			//beat
			else if (boardMap[boardMapping[(position.y + 200) / 100][(position.x + 100) / 100]]->getColor() != color) {
				possible.push_back(sf::Vector2i(position.x + 100, position.y + 200));
			}
		}
	}
	//check if move prevent check, if not drop it vector
	for (sf::Vector2i pos : possible) {

	}

	return possible;
}
