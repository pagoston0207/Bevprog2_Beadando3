#include "GameManager.h"
#include "iostream"
using std::cout;
using std::endl;
GameManager::GameManager()
{
    currentPlayer =0;
    _player1.Id=1;
    _player2.Id=2;
    goalAdjacentNumber =5;
}
GameManager::GameManager(std::function<void(GameManager* sender)> endOfGameCallback, Vector2 mapSize,string machinePlayerPath):_endOfGameCallback(endOfGameCallback)
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
    if(machinePlayerPath!="")
    {
        machinePlayer = MachinePlayer();
        machinePlayer.Load(machinePlayerPath);
    }
    else
    {
        _machinePlayerEnabled = false;
    }
    _player1.Id=1;
    _player2.Id=2;
    currentPlayer = 0;
    goalAdjacentNumber =5;
}
bool GameManager::CanPlace(Vector2 cellPos)
{
    if(cellPos.x<0||cellPos.y<0||cellPos.x>_map.size()-1||cellPos.y>_map[0].size()-1)
    {
        return false;
    }
    return _map[cellPos.x][cellPos.y].State==Empty;
}
Vector2 GameManager::GetSize()
{
    return Vector2(_map.size(),_map.size()>0?_map[0].size():0);
}
void GameManager::Place(Vector2 cellPos)
{
    if(currentPlayer)
    {
        if(currentPlayer->Id==Player1)
        {
            _map[cellPos.x][cellPos.y].State= Player1;
        }
        else if(currentPlayer->Id==Player2)
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
            if(_machinePlayerEnabled&&currentPlayer->Id != machinePlayer.Id)
            {
                MachineStep();
            }

        }
    }

}
void GameManager::MachineStep()
{
    vector<double> step = machinePlayer.Run(GetState(false));
    if(CanPlace(Vector2(step[0],step[1])))
    {
        if(*currentPlayer == _player2)
        {

            _map[(int)step[0]][(int)step[1]].State = Player2;
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
    else
    {
        NextTurn();
        _endOfGameCallback(this);
    }
}
void GameManager::NextTurn()
{
    if(currentPlayer)
    {

        if(*currentPlayer == _player1)
        {
            currentPlayer = &_player2;
        }
        else if (*currentPlayer == _player2)
        {
            currentPlayer = &_player1;

        }
    }
}
void GameManager::Start()
{
    currentPlayer = &_player1;
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
                if(currentPlayer)
                {
                    if(i+k<_map.size()&&j+k<_map[0].size())
                    {
                        if(_map[i+k][j+k].State== currentPlayer->Id)
                            countB++;
                        if(countB>= goalAdjacentNumber)
                            return true;
                    }
                    if(j+k<_map[0].size())
                    {
                        if(_map[i][j+k].State== currentPlayer->Id)
                            countD++;
                        if(countD>= goalAdjacentNumber)
                            return true;
                    }
                    if(i+k<_map.size())
                    {
                        if(_map[i+k][j].State== currentPlayer->Id)
                            countA++;
                        if(countA>= goalAdjacentNumber)
                            return true;
                    }
                    if(j-k>=0&&i+k<_map.size())
                    {
                        if(_map[i+k][j-k].State== currentPlayer->Id)
                        countC++;
                        if(countC>= goalAdjacentNumber)
                            return true;
                    }
                }

            }
        }

    }
    return GetFieldCount(Empty)==0;
}
int GameManager::GetFieldCount(FieldState state)
{
    int count=0;
    for(vector<Field> v:_map)
    {
        for(Field f: v)
        {
            if(f.State==state)
            {
                count++;
            }
        }
    }
    return count;
}
void GameManager::EnableMachinePlayer(bool enable)
{
    _machinePlayerEnabled=enable;
}
vector<double> GameManager::GetState(bool invert)
{
    vector<double> res;
    for(int i =0; i<_map.size();i++)
    {
        for(int j=0;j<_map[0].size();j++)
        {
            if(_map[i][j].State == Player1)
            {
                res.push_back(1);
            }
            else if(_map[i][j].State== Player2)
            {
                res.push_back(-1);
            }
            else
            {
                res.push_back(0);
            }
        }
    }
    if(invert)
    {
        for(double & d: res)
        {
            d*=-1;
        }
    }
    return res;
}

