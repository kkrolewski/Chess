#ifndef PAWN_H
#define PAWN_H

#include <SFML/Graphics.hpp>
#include "ChessPiece.h"

class Pawn :
    public ChessPiece
{
public:
    inline bool hasMoved() { return moved; };

    Pawn(sf::Vector2i _position, int _color, std::string _pieceType);
    std::vector<sf::Vector2i> calculatePossibleMove(std::map<int, ChessPiece*> boardMap, int colorTurn);
    void move(sf::Vector2i movePos, std::map<int, ChessPiece*>& boardMap, bool testMove);
};

#endif

