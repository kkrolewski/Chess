#include "Queen.h"
#include "Board.h"

Queen::Queen(sf::Vector2i _position, int _color, std::string _pieceType) :
	ChessPiece(_position, _color, _pieceType) {}

std::vector<sf::Vector2i> Queen::calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn) {
	std::vector<sf::Vector2i> possible;
	if (colorTurn == color) {
		int x = position.x;
		int y = position.y;

		//BISHOP PART
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

		//ROOK PART
		//possible moves to right
		for (int i = x + 100; i <= 700; i += 100) {
			if (boardMap[boardMapping[position.y / 100][i / 100]] != nullptr) {
				if (boardMap[boardMapping[position.y / 100][i / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(i, position.y));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(i, position.y));
		}

		//possible moves to left
		for (int i = x - 100; i >= 0; i -= 100) {
			if (boardMap[boardMapping[position.y / 100][i / 100]] != nullptr) {
				if (boardMap[boardMapping[position.y / 100][i / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(i, position.y));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(i, position.y));
		}

		//possible moves down
		for (int i = y + 100; i <= 700; i += 100) {
			if (boardMap[boardMapping[i / 100][position.x / 100]] != nullptr) {
				if (boardMap[boardMapping[i / 100][position.x / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(position.x, i));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(position.x, i));
		}

		//possible moves up
		for (int i = y - 100; i >= 0; i -= 100) {
			if (boardMap[boardMapping[i / 100][position.x / 100]] != nullptr) {
				if (boardMap[boardMapping[i / 100][position.x / 100]]->getColor() != color) {
					possible.push_back(sf::Vector2i(position.x, i));
					break;
				}
				else break;
			}
			possible.push_back(sf::Vector2i(position.x, i));
		}
	}
	return possible;
}
