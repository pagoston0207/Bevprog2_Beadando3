#ifndef GAMEMANAGERCONTROLLER_H_INCLUDED
#define GAMEMANAGERCONTROLLER_H_INCLUDED
#include "ImageButton.h"
#include "GameManager.h"
#include "functional"
using std::vector;
using std::function;
class GameManagerController: public Widget
{
protected:
    GameManager _gameManager;
    vector<vector<ImageButton>> _buttons;
public:
    GameManagerController(Vector2 mapSize, Vector2 screenSize,std::function <void(GameManager* sender)> endOfGameCallback, string xGraphicPath="",string oGraphicPath="");
    virtual void Print()override;
};
#endif // PLAYER_H_INCLUDED
