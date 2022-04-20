#ifndef KING_H
#define KING_H

#include "ChessPiece.h"
class King :
    public ChessPiece
{
public:
    King(sf::Vector2i _position, int _color, std::string _pieceType);
    std::vector<sf::Vector2i> calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn);
};

#endif

