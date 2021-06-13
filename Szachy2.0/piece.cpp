#include "piece.h"
#include "pieceTex.h"

//Piece::Piece() 
//{
//
//}
//Piece::Piece(int row, int col, bool color, char id, Sprite s)
//{
//	this->row = row;
//	this->col = col;
//	this->color = color;
//	this->id = id;
//	this->s = s;
//}
//
//void Update()
//{

Piece::~Piece()
{

}

void Piece::setPiece(char type, bool color, int x, int y) {
    this->type = type;
    this->color = color;
    this->x = x;
    this->y = y;
    this->setTexture();
    this->sprite.setPosition(x * 100.f, y * 100.f);
}

void Piece::setTexture() {

    switch (type)
    {
    case 'K':
        sprite.setTexture(color ? PieceTex::wK : PieceTex::bK);
        break;
    case 'Q':
        sprite.setTexture(color ? PieceTex::wQ : PieceTex::bQ);
        break;
    case 'R':
        sprite.setTexture(color ? PieceTex::wR : PieceTex::bR);
        break;
    case 'B':
        sprite.setTexture(color ? PieceTex::wB : PieceTex::bB);
        break;
    case 'N':
        sprite.setTexture(color ? PieceTex::wN : PieceTex::bN);
        break;
    case 'P':
        sprite.setTexture(color ? PieceTex::wP : PieceTex::bP);
        break;
    default:
        std::cerr << "Error piece type does not exist.\n";
        break;
    //case 'Q':
    //    m_sprite.setTexture(m_player ? PieceTex::whiteQueen : PieceTex::blackQueen);
    //    break;
    //case 'R':
    //    m_sprite.setTexture(m_player ? PieceTex::whiteRook : PieceTex::blackRook);
    //    break;
    //case 'B':
    //    m_sprite.setTexture(m_player ? PieceTex::whiteBishop : PieceTex::blackBishop);
    //    break;
    //case 'N':
    //    m_sprite.setTexture(m_player ? PieceTex::whiteKnight : PieceTex::blackKnight);
    //    break;
    //case 'P':
    //    m_sprite.setTexture(m_player ? PieceTex::whitePawn : PieceTex::blackPawn);
    //    break;
    //default:
    //    std::cerr << "Error piece type does not exist.\n";
    //    break;
    }
    //m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x / 2, m_sprite.getTexture()->getSize().y / 2));
    //m_sprite.setScale(sf::Vector2f(0.375f, 0.375f));
}