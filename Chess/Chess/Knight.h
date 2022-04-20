#ifndef KNIGHT_H
#define KNIGHT_H

#include "ChessPiece.h"
class Knight :
    public ChessPiece
{
public:
    Knight(sf::Vector2i _position, int _color, std::string _pieceType);
    std::vector<sf::Vector2i> calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn);
};

#endif

