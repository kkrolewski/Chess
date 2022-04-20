#ifndef BISHOP_H
#define BISHOP_H

#include "ChessPiece.h"
class Bishop :
    public ChessPiece
{
public:
    Bishop(sf::Vector2i _position, int _color, std::string _pieceType);
    std::vector<sf::Vector2i> calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn);
};

#endif

