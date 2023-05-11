#include "GameManager.h"
#include "iostream"
using std::cout;
using std::endl;
GameManager::GameManager()
{
    _currentPlayer =0;
    _player1.Id=1;
    _player2.Id=2;
    goalAdjacentNumber =3;
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
    goalAdjacentNumber =3;
}
bool GameManager::CanPlace(Vector2 cellPos)
{
    return _map[cellPos.x][cellPos.y].State==Empty;
}
Vector2 GameManager::GetSize()
{
    return Vector2(_map.size(),_map.size()>0?_map[0].size():0);
}
void GameManager::Place(Vector2 cellPos)
{
    if(_currentPlayer)
    {
        if(_currentPlayer->Id==Player1)
        {
            _map[cellPos.x][cellPos.y].State= Player1;
        }
        else
        {
            _map[cellPos.x][cellPos.y].State= Player2;
        }
        if(IsEndOfGame())
        {
            _endOfGameCallback(this);
        }
        else
        {
            NextTurn();
        }
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
}
void GameManager::Start()
{
    _currentPlayer = &_player1;
}
FieldState GameManager::GetState(Vector2 cellPos)
{
    return _map[cellPos.x][cellPos.y].State;
}
bool GameManager::IsEndOfGame()
{
    for(int i = 0; i<_map.size(); i++)
    {
        for ( int j = 0 ; j < _map[0].size();j++)
        {
            int countA = 0;
            int countB = 0;
            int countC = 0;
            int countD = 0;
            for(int k = 0;k<goalAdjacentNumber;k++)
            {
                if(_currentPlayer)
                {
                    if(i+k<_map.size()&&j+k<_map[0].size())
                    {
                        if(_map[i+k][j+k].State== _currentPlayer->Id)
                            countB++;
                        if(countB>= goalAdjacentNumber)
                            return true;
                    }
                    if(j+k<_map[0].size())
                    {
                        if(_map[i][j+k].State== _currentPlayer->Id)
                            countD++;
                        if(countD>= goalAdjacentNumber)
                            return true;
                    }
                    if(i+k<_map.size())
                    {
                        if(_map[i+k][j].State== _currentPlayer->Id)
                            countA++;
                        if(countA>= goalAdjacentNumber)
                            return true;
                    }
                    if(j-k>=0&&i+k<_map.size())
                    {
                        if(_map[i+k][j-k].State== _currentPlayer->Id)
                        countC++;
                        if(countC>= goalAdjacentNumber)
                            return true;
                    }
                }

            }
        }
    }
    return false;
}
