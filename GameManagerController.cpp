#include "GameManagerController.h"
#include "iostream"
using std::cout;
using std::endl;
GameManagerController ::GameManagerController( Vector2 mapSize,Vector2 screenSize, std::function<void(GameManager* sender)> endOfGameCallback, string xGraphicPath, string oGraphicPath)
{
    _gameManager = GameManager(endOfGameCallback,mapSize);
    for(int i =0; i < _gameManager.GetSize().x; i++)
    {
        vector<ImageButton> v;
        for (int j = 0; j< _gameManager.GetSize().y; j++)
        {
            //ImageButton ib([this, &screenSize](ImageButton* sender){/*cout<<screenSize.x<<" "<<_gameManager.GetSize().x<<" "<<pos.x<<" "<<size.x<<endl;*/if(_gameManager.CanPlace((sender->GetWorldPos()-size/2)/(screenSize/_gameManager.GetSize())))_gameManager.Place((pos-size/2)/(screenSize/_gameManager.GetSize()));}, screenSize/_gameManager.GetSize(),this);
            ImageButton ib([this,i,j](ImageButton* sender){if(_gameManager.CanPlace(Vector2(i,j))){_gameManager.Place(Vector2(i,j));}}, screenSize/_gameManager.GetSize(),this);
            ib.MoveTo(Vector2((screenSize/_gameManager.GetSize()).x*(i+0.5f),(screenSize/_gameManager.GetSize()).y*(j+0.5f)));
            v.push_back(ib);
        }
        _buttons.push_back(v);
    }
    for(vector<ImageButton> &v:_buttons)
    {
        for(ImageButton &i: v)
        {
            children.push_back(&i);
        }
    }
    _gameManager.Start();
}
void GameManagerController::Print()
{
    Widget::Print();
}
