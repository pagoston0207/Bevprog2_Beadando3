#include "graphics.hpp"
#include "iostream"
#include "TextButton.h"
#include "Project.h"
#include "Scene.h"
#include "Layer.h"
#include "CountingWidget.h"
#include "SelectingWidget.h"
#include "fstream"
#include "GameManagerController.h"
using namespace genv;
using namespace std;
const int XX=1000;
const int YY=1000;
int main()
{
    gout.open(XX,YY);
    event ev;


    bool gameOver=false;
    Project p= Project(Scene(Layer()));
    GameManagerController* GMC = new GameManagerController(Vector2(10,10),Vector2(1000,1000),[XX,YY, &gameOver,&p](GameManager* sender){gameOver = true;p.Update();gout<<move_to(XX/2,YY/2)<<color(0,0,0)<<text("GameOver");gout<<refresh;},"X.bmp.kep","O.bmp.kep");
    p.Add(GMC);
    p.Update();
    gin.timer(35);
    gout<<refresh;
    while(gin >> ev&& ev.keycode!= key_escape)
    {
        if(!gameOver)
        {


            p.Handle(ev);
            if(ev.type==ev_timer)
            {
                gout<<move_to(0,0)<<color(0,0,0)<<box(900,900);
                p.Update();
                gout<<refresh;
            }
        }
        else if(ev.button==btn_left)
        {
            delete GMC;
            GMC=  new GameManagerController(Vector2(10,10),Vector2(1000,1000),[XX,YY, &gameOver,&p](GameManager* sender){gameOver = true;p.Update();gout<<move_to(XX/2,YY/2)<<color(0,0,0)<<text("GameOver");gout<<refresh;},"X.bmp.kep","O.bmp.kep");
            p.Add(GMC);
            p.Update();
            gameOver = false;
        }

    }
    return 0;
}
