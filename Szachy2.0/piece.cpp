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

void Piece::setTexture() 
{
    sprite = sf::Sprite();
    switch (type)
    {
    case 'K':
        sprite.setTexture(PieceTex::bK);
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
    //    std::cerr << "Error piece type does not exist." << endl;
    //    break;
    }
    //m_sprite.setOrigin(sf::Vector2f(m_sprite.getTexture()->getSize().x / 2, m_sprite.getTexture()->getSize().y / 2));
    //m_sprite.setScale(sf::Vector2f(0.375f, 0.375f));
}