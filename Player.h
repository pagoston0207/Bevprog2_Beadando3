#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED
#include "string"

using std::string;
class Player
{
protected:
    string _name;
public:
    int Id;
    Player(int id=-1, string name="Johnson");
    bool operator== (const Player &other);
};
#endif
