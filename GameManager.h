#ifndef GAMEMANAGER_H_INCLUDED
#define GAMEMANAGER_H_INCLUDED
#include "Field.h"
#include "vector"
#include "functional"
#include "Player.h"
#include "Vector2.h"
using std::vector;

class GameManager
{
protected:
    vector<vector<Field>> _map;
    Player _player1;
    Player _player2;
    Player* _currentPlayer;
    int goalAdjacentNumber;
    std::function <void (GameManager* sender)> _endOfGameCallback;
    void NextTurn();
    bool IsEndOfGame();

public:
    GameManager();
    GameManager(std::function<void (GameManager* sender)> endOfGameCallback, Vector2 mapSize= Vector2 (5,5));
    void Start();
    bool CanPlace(Vector2 cellPos);
    void Place(Vector2 cellPos);
    FieldState GetState(Vector2 cellPos);
    Vector2 GetSize();

};

#endif // PLAYER_H_INCLUDED
