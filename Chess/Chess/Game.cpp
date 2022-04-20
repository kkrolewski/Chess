//include SFML
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

//include Logic
#include <iostream>
#include <map>
#include "Game.h"
#include "King.h"
#include "Pawn.h"

using namespace std;

int Game::play() {
	//initialize window
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");

	//inititialize new board
	Board* board = new Board();
	map<int, ChessPiece*> boardMap = board->getBoardMap();

	//vector to remember possible moves for selected piece
	vector<sf::Vector2i> possiblePos;

	//remeber which piece player want to move
	ChessPiece* toMove = nullptr;
	bool moveMade = false;

	//which turn is it
	int colorTurn = 0; //white starts

	//ending color
	int endingColor;
	//main loop of the game
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		//clear screen
		window.clear();

		//print board
		window.draw(board->boardImage);

		//print pieces
		for (map<int, ChessPiece*>::iterator it = boardMap.begin(); it != boardMap.end(); it++) {
			if (it->second != nullptr) {
				window.draw(it->second->pieceImage);
			}
		}

		//show possible moves for clicked piece
		if (event.type == sf::Event::MouseButtonPressed) {
			if (event.key.code == sf::Mouse::Left) {
				sf::Vector2i vektor = sf::Mouse::getPosition(window);

				//check if he clicked on red circle to make a move
				for (sf::Vector2i pos : possiblePos) {
					if (boardMapping[pos.y / 100][pos.x / 100] == boardMapping[vektor.y / 100][vektor.x / 100]) {
						toMove->move(pos, boardMap, false);
						if (typeid(*toMove) == typeid(King)) {
							if (toMove->getColor() == 0) whiteKingPos = pos;
							else blackKingPos = pos;
						}
						if (isCheckOn(boardMap, colorTurn)) {
							int defColor;
							if (colorTurn == 0) defColor = 1;
							else defColor = 0;
							if (isCheckmate(boardMap, defColor)) {
								if (defColor == 0) {
									cout << "Bialy przegrywa, MAT" << endl;
									endingColor = defColor;
									window.close();
									;
								}
								else {
									cout << "Czarny przegrywa, MAT" << endl;
									endingColor = defColor;
									window.close();
								}

							}
						}
						if (colorTurn == 0) colorTurn = 1;
						else colorTurn = 0;
					}
				}
				possiblePos.clear();

				int key = boardMapping[vektor.y / 100][vektor.x / 100];
				toMove = boardMap[key];
				if (boardMap[key] != nullptr) {
					possiblePos = boardMap[key]->calculatePossibleMove(boardMap, colorTurn);
					int attackingColor;
					if (colorTurn == 0) attackingColor = 1;
					else attackingColor = 0;
					possiblePos = deleteMovesThatDontPreventCheck(boardMap[key], possiblePos, boardMap, attackingColor);
				}
			}
		}

		//print possible moves
		for (sf::Vector2i pos : possiblePos) {
			sf::CircleShape a(50);
			a.setOutlineColor(sf::Color::Red);
			a.setFillColor(sf::Color::Transparent);
			a.setOutlineThickness(3.0);
			a.setPosition(sf::Vector2f(pos.x, pos.y));
			window.draw(a);
		}

		window.display();
	}
	for (map<int, ChessPiece*>::iterator it = boardMap.begin(); it != boardMap.end(); it++) {
		if (it->second != nullptr) {
			delete it->second;
		}
	}
	boardMap.clear();
	delete board;
	return endingColor;
}

bool Game::isCheckOn(std::map<int, ChessPiece*> boardMap, int attackingColor) {
	sf::Vector2i kingPos;
	if (attackingColor == 0) kingPos = blackKingPos;
	else kingPos = whiteKingPos;
	for (map<int, ChessPiece*>::iterator it = boardMap.begin(); it != boardMap.end(); it++) {
		if (it->second != nullptr && it->second->getColor() == attackingColor) {
			std::vector<sf::Vector2i> temp = it->second->calculatePossibleMove(boardMap, attackingColor);
			for (sf::Vector2i pos : temp) {
				if (pos == kingPos) {
					return true;
				}
			}
		}
	}
	return false;
}

std::vector<sf::Vector2i> Game::deleteMovesThatDontPreventCheck(ChessPiece* pieceToMove, std::vector<sf::Vector2i> possibleMoves,
	std::map<int, ChessPiece*> boardMap, int attackingColor) {

	std::map<int, ChessPiece*> boardMapCopy = boardMap;

	std::vector<sf::Vector2i> out;
	sf::Vector2i whiteKingPosRem = whiteKingPos;
	sf::Vector2i blackKingPosRem = blackKingPos;

	sf::Vector2i rememberPos = pieceToMove->getPosition();
	ChessPiece* remeberBeatingPiece = nullptr;

	for (sf::Vector2i pos : possibleMoves) {

		if (boardMap[boardMapping[pos.y / 100][pos.x / 100]] != nullptr) {
			remeberBeatingPiece = boardMap[boardMapping[pos.y / 100][pos.x / 100]];
			boardMapCopy[boardMapping[pos.y / 100][pos.x / 100]] = nullptr;
		}

		pieceToMove->move(pos, boardMapCopy, true);

		if (typeid(*pieceToMove) == typeid(King)) {
			if (pieceToMove->getColor() == 0) whiteKingPos = pos;
			else blackKingPos = pos;
		}
		if (!isCheckOn(boardMapCopy, attackingColor)) {
			out.push_back(pos);
		}

		pieceToMove->move(rememberPos, boardMapCopy, true);

		boardMapCopy[boardMapping[pos.y / 100][pos.x / 100]] = remeberBeatingPiece;
		whiteKingPos = whiteKingPosRem;
		blackKingPos = blackKingPosRem;
	}
	return out;
}

bool Game::isCheckmate(std::map<int, ChessPiece*> boardMap, int defendingColor) {
	int possibleMoveCount = 0;
	int attackingColor;
	if (defendingColor == 0) attackingColor = 1;
	else attackingColor = 0;

	for (map<int, ChessPiece*>::iterator it = boardMap.begin(); it != boardMap.end(); it++) {
		if (it->second != nullptr) {
			if (it->second->getColor() == defendingColor) {
				std::vector<sf::Vector2i> temp = it->second->calculatePossibleMove(boardMap, defendingColor);
				temp = deleteMovesThatDontPreventCheck(it->second, temp, boardMap, attackingColor);
				possibleMoveCount += temp.size();
			}
		}
	}

	return possibleMoveCount == 0 ? true : false;
}
