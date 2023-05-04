#include "GameManager.h"
#include "iostream"
using std::cout;
using std::endl;
GameManager::GameManager()
{
    _currentPlayer =0;
    _player1.Id=1;
    _player2.Id=2;
}
GameManager::GameManager(std::function<void(GameManager* sender)> endOfGameCallback, Vector2 mapSize):_endOfGameCallback(endOfGameCallback)
{
    for(int i = 0; i <mapSize.x;i++)
    {
        vector<Field> v;
        for ( int j =0 ; j<mapSize.y;j++)
        {
            v.push_back(Field());
        }
        _map.push_back(v);
    }
    _player1.Id=1;
    _player2.Id=2;
    _currentPlayer = 0;
}
bool GameManager::CanPlace(Vector2 cellPos)
{
    return _map[cellPos.x][cellPos.y].State==Empty;
}
void GameManager::Place(Vector2 cellPos)
{
    if(_currentPlayer)
    {
        cout<<cellPos.x<<" "<<cellPos.y<<endl;
        if(_currentPlayer->Id==Player1)
        {
            _map[cellPos.x][cellPos.y].State= Player1;
        }
        else
        {
            _map[cellPos.x][cellPos.y].State= Player2;
        }
        NextTurn();
    }

}
void GameManager::NextTurn()
{
    if(_currentPlayer)
    {

        if(*_currentPlayer == _player1)
        {
            _currentPlayer = &_player2;
        }
        else if (*_currentPlayer == _player2)
        {
            _currentPlayer = &_player1;

        }
    }
    cout<<"Next Turn"<<endl;
}
void GameManager::Start()
{
    _currentPlayer = &_player1;
}
Vector2 GameManager::GetSize()
{
    return Vector2(_map.size(),_map.size()>0?_map[0].size():0);
}
FieldState GameManager::GetState(Vector2 cellPos)
{
    return _map[cellPos.x][cellPos.y].State;
}
