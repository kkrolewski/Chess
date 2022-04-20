#ifndef PIECE_H
#define PIECE_H

#include <SFML/Graphics.hpp>


class ChessPiece
{
protected:
	sf::Texture pieceTexture;
	sf::Vector2i position;

	int color; //0 - white, 1 - black
	//only important for pawn
	bool moved = false;
public:
	sf::Sprite pieceImage;

	ChessPiece(sf::Vector2i _position, int _color, std::string _pieceType);
	ChessPiece(ChessPiece* piece);
	inline int getColor() { return color; };
	inline sf::Vector2i getPosition() { return position; };

	virtual std::vector<sf::Vector2i> calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn)
	{
		std::vector<sf::Vector2i> empty; return empty;
	};
	virtual void move(sf::Vector2i movePos, std::map<int, ChessPiece*>& boardMap, bool testMove);
};

#endif

