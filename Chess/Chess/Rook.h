#ifndef ROOK_H
#define ROOK_H

#include "ChessPiece.h"
class Rook :
    public ChessPiece
{
public:
    Rook(sf::Vector2i _position, int _color, std::string _pieceType);
    std::vector<sf::Vector2i> calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn);
};

#endif

