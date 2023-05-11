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
    vector<vector<ImageButton>> _buttons;
    string _xGraphicPath;
    string _oGraphicPath;
    GameManager _gameManager;
public:
    GameManagerController(Vector2 mapSize, Vector2 screenSize,std::function <void(GameManager* sender)> endOfGameCallback, string xGraphicPath="",string oGraphicPath="");
    virtual void Print()override;
    virtual void Handle(event ev)override;
    string GetCurrentPlayerSymbol();
};
#endif // PLAYER_H_INCLUDED
