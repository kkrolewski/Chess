#include "Bishop.h"
#include "Board.h"

Bishop::Bishop(sf::Vector2i _position, int _color, std::string _pieceType) :
	ChessPiece(_position, _color, _pieceType) {}

std::vector<sf::Vector2i> Bishop::calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn) {
	std::vector<sf::Vector2i> possible;
	if (colorTurn == color) {
		int x = position.x;
		int y = position.y;

		//left up
		int temp = 100;
		for (int i = x - 100; i >= 0; i -= 100) {
			if (position.y - temp < 0) break;
			if (boardMap[boardMapping[(position.y - temp) / 100][i / 100]] != nullptr) {
				if (boardMap[boardMapping[(position.y - temp) / 100][i / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(i, y - temp));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(i, y - temp));
			temp += 100;
		}

		//left-down
		temp = 100;
		for (int i = x - 100; i >= 0; i -= 100) {
			if (position.y + temp > 700) break;
			if (boardMap[boardMapping[(position.y + temp) / 100][i / 100]] != nullptr) {
				if (boardMap[boardMapping[(position.y + temp) / 100][i / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(i, y + temp));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(i, y + temp));
			temp += 100;
		}

		//right up
		temp = 100;
		for (int i = x + 100; i <= 700; i += 100) {
			if (position.y - temp < 0) break;
			if (boardMap[boardMapping[(position.y - temp) / 100][i / 100]] != nullptr) {
				if (boardMap[boardMapping[(position.y - temp) / 100][i / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(i, y - temp));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(i, y - temp));
			temp += 100;
		}

		//right-down
		temp = 100;
		for (int i = x + 100; i <= 700; i += 100) {
			if (position.y + temp > 700) break;
			if (boardMap[boardMapping[(position.y + temp) / 100][i / 100]] != nullptr) {
				if (boardMap[boardMapping[(position.y + temp) / 100][i / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(i, y + temp));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(i, y + temp));
			temp += 100;
		}
	}
	return possible;
}
