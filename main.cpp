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
int main()
{
    gout.open(1000,1000);
    event ev;


    Project p= Project(Scene(Layer()));
    GameManagerController GMC(Vector2(10,10),Vector2(600,600),[](GameManager* sender){gout<<move_to(100,100)<<color(230,20,10)<<box(200,200);});
    GMC.MoveTo(Vector2(200,200));
    p.Add(&GMC);

    p.Update();
    gin.timer(35);
    gout<<refresh;
    while(gin >> ev&& ev.keycode!= key_escape)
    {
        p.Handle(ev);
        if(ev.type==ev_timer)
        {
            gout<<move_to(0,0)<<color(0,0,0)<<box(800,600);
            p.Update();
            gout<<refresh;

        }
    }
    return 0;
}
