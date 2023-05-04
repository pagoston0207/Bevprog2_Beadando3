#include "Player.h"

Player::Player(int id, string name): Id(id), _name(name){}
bool Player:: operator == (const Player &other)
{
    return Id==other.Id;
}
